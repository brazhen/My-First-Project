#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <limits>
#include "Stud.h"

void ivestiNamudarbus(Stud &studentas) {
    std::string input;
    std::cout << "Pradekite vesti namu darbu rezultatus (ivedus du kartus Enter, ivestis bus baigta):" << std::endl;

    while (true) {
        std::cout << "ND: ";
        std::getline(std::cin, input);

        // Jei paspaustas tuščias Enter du kartus, nutraukiame įvestį
        if (input.empty()) {
            std::cout << "Ivedimas baigtas." << std::endl;
            break;
        }

        try {
            double nd = std::stod(input); // Konvertuojame į skaičių
            if (nd < 1 || nd > 10) {
                std::cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << std::endl;
            } else {
                studentas.ND.push_back(nd); // Pridedame pažymį, jei jis tinkamas
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Neteisingas formatas. Iveskite skaiciu nuo 1 iki 10." << std::endl;
        }
    }
}

int main() {
    srand(time(0));  // Sėkla atsitiktinių skaičių generavimui

    char testi;  // Kintamasis, skirtas programos valdymui
    do {
        std::vector<Stud> studentai;

        // Pasirinkimas, ar duomenis įvesti ranka, ar nuskaityti iš failo
        char pasirinkimas;
        do {
            std::cout << "Ar norite ivest studentu duomenis rankiniu budu ar nuskaityt is failo? (r/f): ";
            std::cin >> pasirinkimas;

            if (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F') {
                std::cout << "Neteisingas pasirinkimas. Prasom pasirinkti 'r' arba 'f'." << std::endl;
            }
        } while (pasirinkimas != 'r' && pasirinkimas != 'R' && pasirinkimas != 'f' && pasirinkimas != 'F');

        if (pasirinkimas == 'f' || pasirinkimas == 'F') {
            std::string failo_pav;
            std::cout << "Iveskite failo pavadinima: ";
            std::cin >> failo_pav;

            skaitytiIsFailoSuKlaiduTikrinimu(studentai, failo_pav);  // Skaitome iš failo su klaidų tikrinimu
        } else {
            int studentu_skaicius;
            std::cout << "Kiek studentu norite ivesti? ";
            std::cin >> studentu_skaicius;

            while(std::cin.fail()) { // Patikrinimas dėl neteisingo įvedimo
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Netinkama ivestis. Prasome ivesti skaiciu: ";
                std::cin >> studentu_skaicius;
            }

            std::cin.ignore();  // Išvalome '\n' po skaičiaus įvedimo
            studentai.resize(studentu_skaicius);

            // Pasirinkimas, ar ND ir egzamino rezultatus norite ivesti rankiniu budu, ar generuoti
            char generuoti;
            do {
                std::cout << "Ar norit, kad namu darbu ir egzamino rezultatai butu sugeneruoti? (y/n): ";
                std::cin >> generuoti;

                if (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N') {
                    std::cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'y' arba 'n'." << std::endl;
                }
            } while (generuoti != 'y' && generuoti != 'Y' && generuoti != 'n' && generuoti != 'N');

            if (generuoti == 'y' || generuoti == 'Y') {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    std::cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    std::cin >> studentai[i].vardas;
                    std::cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    std::cin >> studentai[i].pavarde;

                    // Generuojame ND ir egzaminų rezultatus
                    for (int j = 0; j < 15; ++j) {
                        studentai[i].ND.push_back(rand() % 10 + 1);  // Generuojame pažymius (1-10)
                    }
                    studentai[i].egz = rand() % 10 + 1;  // Generuojame egzamino pažymį (1-10)
                }
            } else {
                for (int i = 0; i < studentu_skaicius; ++i) {
                    std::cout << "Iveskite studento Nr. " << i + 1 << " varda: ";
                    std::cin >> studentai[i].vardas;
                    std::cout << "Iveskite studento Nr. " << i + 1 << " pavarde: ";
                    std::cin >> studentai[i].pavarde;

                    std::cin.ignore();  // Čia išvalome buferį prieš naudojant getline
                    ivestiNamudarbus(studentai[i]);

                    std::cout << "Iveskite egzamino rezultata (skaicius nuo 1 iki 10): ";
                    while (true) {
                        std::cin >> studentai[i].egz;
                        if (std::cin.fail() || studentai[i].egz < 1 || studentai[i].egz > 10) {
                            std::cin.clear(); // Išvalome klaidos vėliavėlę
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Išvalome likusią įvestį
                            std::cout << "Neteisinga ivestis. Iveskite skaiciu tarp 1 ir 10: ";
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // Pasirinkimas, kaip skaičiuoti galutinį balą
        char skaiciavimo_budas;
        do {
            std::cout << "Ar norite skaiciuoti galutini bala su vidurkiu ar mediana? (v/m): ";
            std::cin >> skaiciavimo_budas;

            if (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M') {
                std::cout << "Neteisingas pasirinkimas. Prašome pasirinkti 'v' arba 'm'." << std::endl;
            }
        } while (skaiciavimo_budas != 'v' && skaiciavimo_budas != 'V' && skaiciavimo_budas != 'm' && skaiciavimo_budas != 'M');

        // Spausdiname rezultatus
        spausdintiRezultatus(studentai, skaiciavimo_budas);

        std::cout << "Ar norite dar karta vykdyti programa? (y/n): ";
        std::cin >> testi;
    } while (testi == 'y' || testi == 'Y');

    return 0;
}


