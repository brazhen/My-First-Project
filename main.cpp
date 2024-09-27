#include "Stud.h"
#include <iomanip> // For std::setw, std::setprecision

int main() {
    srand(time(0)); // Sėkla atsitiktinių skaičių generavimui

    char testi; // Kintamasis, skirtas programos valdymui

    do {
        int studentu_skaicius;
        std::cout << "Kiek studentu norite ivesti? ";
        std::cin >> studentu_skaicius;
        std::cin.ignore(); // Išvalome '\n' po skaičiaus įvedimo

        std::vector<Stud> studentai(studentu_skaicius);

        // Pasirinkimas, ar naudoti atsitiktinį duomenų generavimą tik namų darbams ir egzaminui
        char pasirinkimas;
        std::cout << "Ar norite generuoti namu darbu ir egzamino rezultatus atsitiktinai? (y/n): ";
        std::cin >> pasirinkimas;
        bool randomize = (pasirinkimas == 'y' || pasirinkimas == 'Y');
        std::cin.ignore(); // Ignoruojame '\n' po pasirinkimo įvedimo

        for (int i = 0; i < studentu_skaicius; ++i) {
            std::cout << "Iveskite studento Nr. " << i + 1 << " duomenis:\n";
            ived(studentai[i], randomize); // Tik namų darbai ir egzaminas gali būti generuojami atsitiktinai
        }

        // Pasirinkimas, ar naudoti vidurkį ar medianą
        char skaiciavimo_budas;
        std::cout << "Ar norite skaiciuoti galutini bala su vidurkiu ar mediana? (v/m): ";
        std::cin >> skaiciavimo_budas;

  // Spausdiname antrašte
std::cout << std::setw(20) << "Pavarde"  // Pakeista į 20 vietoj 15
          << std::setw(20) << "Vardas"   // Pakeista į 20 vietoj 15
          << std::setw(20);

// Patikriname, ar pasirinktas vidurkis ar mediana
if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
    std::cout << "Galutinis (Vid.)";
} else {
    std::cout << "Galutinis (Med.)";
}

std::cout << std::endl;
std::cout << "---------------------------------------------------------------" << std::endl;

// Spausdiname studentų duomenis
for (const Stud &s : studentai) {
    double galutinis;
    if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
        galutinis = galutinisVidurkis(s); // Naudojame vidurki
    } else {
        galutinis = galutinisMediana(s); // Naudojame medianą
    }

    std::cout << std::setw(20) << s.pavarde   // Pakeista į 20 vietoj 15
              << std::setw(20) << s.vardas    // Pakeista į 20 vietoj 15
              << std::setw(20) << std::fixed << std::setprecision(2) << galutinis
              << std::endl;
}


        // Paklausiame, ar naudotojas nori tęsti programą
        std::cout << "\nAr norite testi? (y/n): ";
        std::cin >> testi;

    } while (testi == 'y' || testi == 'Y'); // Kartoti, jei pasirinktas 'y'

    std::cout << "Programa baigta.\n";

    return 0;
}



