#include "Stud.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <sstream>

// Funkcija skaičiuoti galutinį balą naudojant vidurkį
double galutinisVidurkis(const Stud& s) {
    double sumND = std::accumulate(s.ND.begin(), s.ND.end(), 0.0);
    double vidurkis = sumND / s.ND.size();
    return 0.4 * vidurkis + 0.6 * s.egz;
}

// Funkcija skaičiuoti galutinį balą naudojant medianą
double galutinisMediana(const Stud& s) {
    std::vector<double> pazymiai = s.ND;
    std::sort(pazymiai.begin(), pazymiai.end());

    double mediana;
    if (pazymiai.size() % 2 == 0) {
        mediana = (pazymiai[pazymiai.size() / 2 - 1] + pazymiai[pazymiai.size() / 2]) / 2.0;
    } else {
        mediana = pazymiai[pazymiai.size() / 2];
    }

    return 0.4 * mediana + 0.6 * s.egz;
}

// Funkcija spausdinti studentų rezultatus
void spausdintiRezultatus(const std::vector<Stud>& studentai, char skaiciavimo_budas) {
    std::cout << std::setw(20) << "Pavarde"
              << std::setw(20) << "Vardas"
              << std::setw(20);

    if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
        std::cout << "Galutinis (Vid.)";
    } else {
        std::cout << "Galutinis (Med.)";
    }

    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    for (const Stud& s : studentai) {
        double galutinis;
        if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
            galutinis = galutinisVidurkis(s);  // Naudojame vidurkį
        } else {
            galutinis = galutinisMediana(s);  // Naudojame medianą
        }

        std::cout << std::setw(20) << s.pavarde
                  << std::setw(20) << s.vardas
                  << std::setw(20) << std::fixed << std::setprecision(2) << galutinis
                  << std::endl;
    }
}

// Funkcija nuskaityti studentus iš failo su klaidų tikrinimu
void skaitytiIsFailoSuKlaiduTikrinimu(std::vector<Stud>& studentai, std::string& failo_pav) {
    std::ifstream input;

    // Bandome atidaryti failą tol, kol vartotojas nesuteiks teisingo pavadinimo
    while (true) {
        input.open(failo_pav);  // Atidarome failą

        if (!input) {
            std::cerr << "Nepavyko atidaryti failo: " << failo_pav << std::endl;
            std::cout << "Iveskite nauja failo pavadinima: ";
            std::cin >> failo_pav;  // Prašome vartotojo įvesti naują failo pavadinimą
        } else {
            break;  // Jei failas atidarytas sėkmingai, išeiname iš ciklo
        }
    }

    std::string eilute;
    std::getline(input, eilute);  // Praleidžiame antraštę

    while (std::getline(input, eilute)) {
        std::istringstream iss(eilute);  // Naudojame stringstream eilutės nuskaitymui
        Stud studentas;
        iss >> studentas.vardas >> studentas.pavarde;  // Skaitome vardą ir pavardę

        double nd;
        std::vector<double> namuDarbai;

        // Nuskaitome visus pažymius iki egzamino pažymio
        while (iss >> nd) {
            namuDarbai.push_back(nd);  // Dedame pažymius į laikino sąrašo vektorių
        }

        // Paskutinį nuskaitome kaip egzamino pažymį
        studentas.egz = namuDarbai.back();
        namuDarbai.pop_back();  // Pašaliname paskutinį elementą (egzaminą) iš ND sąrašo

        studentas.ND = namuDarbai;  // Priskiriame likusius ND pažymius studentui

        studentai.push_back(studentas);  // Pridedame studentą į sąrašą
    }

    input.close();
}


