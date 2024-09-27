#include "Stud.h"
#include <algorithm> // std::sort
#include <random>    // std::rand, std::srand
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

void ived(Stud &studentas, bool randomize) {
    // Paprašome įvesti studento vardą ir pavardę
    std::cout << "Iveskite studento varda: ";
    std::cin >> std::ws; // Šaliname perteklinį baltą simbolį, jei toks yra
    std::getline(std::cin, studentas.vardas);

    std::cout << "Iveskite studento pavarde: ";
    std::cin >> std::ws; // Šaliname perteklinį baltą simbolį, jei toks yra
    std::getline(std::cin, studentas.pavarde);

    // Jei pasirinkta, kad namų darbų ir egzamino rezultatai bus generuojami atsitiktinai
    if (randomize) {
        int nd_count = rand() % 10 + 1; // Atsitiktinis namų darbų skaičius (1-10)
        for (int i = 0; i < nd_count; ++i) {
            studentas.ND.push_back(rand() % 10 + 1); // Namų darbų įvertinimai (1-10)
        }
        studentas.egz = rand() % 10 + 1; // Egzamino įvertinimas (1-10)
    } else {
        // Įvedame namų darbus rankiniu būdu
        std::cout << "Iveskite namu darbu rezultatus (iveskite tuscia eilute, kad baigtumete): \n";
        std::string input;
        int emptyCount = 0; // Skaičiuojame tuščių įvedimų skaičių

        while (true) {
            std::getline(std::cin, input);
            if (input.empty()) {
                emptyCount++; // Padidiname tuščių įvedimų skaičių
                if (emptyCount == 1) { // Dvigubas paspaudimas
                    break; // Baigiame įvedimą
                }
            } else {
                emptyCount = 0; // Jei buvo įvesta reikšmė, atstatome skaičių
                try {
                    double nd_rez = std::stod(input); // Bandome konvertuoti į double
                    studentas.ND.push_back(nd_rez); // Pridedame į namų darbų sąrašą
                } catch (std::invalid_argument&) {
                    std::cout << "Ivestas netinkamas skaicius, pabandykite dar karta.\n";
                }
            }
        }

        // Įvedame egzamino rezultatą
        std::cout << "Iveskite egzamino rezultata: ";
        std::cin >> studentas.egz;
    }
}





void output(const Stud &Lok) {
    cout << "Student data: Name: " << Lok.vardas << "; Surname: " << Lok.pavarde << endl;
    cout << "Exam points: " << Lok.egz << endl;
    cout << "Homework results: ";
    for (double nd : Lok.ND) {
        cout << nd << " ";
    }
    cout << endl;
}

void val(Stud &Lok) {
    Lok.vardas.clear();
    Lok.pavarde.clear();
    Lok.ND.clear();
}

double galutinisVidurkis(const Stud &Lok) {
    double sum = 0.0;
    for (double nd : Lok.ND) {
        sum += nd;
    }
    return 0.4 * (sum / Lok.ND.size()) + 0.6 * Lok.egz;
}

// Pakeičiame funkcijos parametrą į `const Stud &`
double galutinisMediana(const Stud &Lok) {
    std::vector<double> sortedND = Lok.ND;
    std::sort(sortedND.begin(), sortedND.end());
    size_t size = sortedND.size();
    double mediana;
    if (size % 2 == 0) {
        mediana = (sortedND[size / 2 - 1] + sortedND[size / 2]) / 2;
    } else {
        mediana = sortedND[size / 2];
    }
    return 0.4 * mediana + 0.6 * Lok.egz;
}
