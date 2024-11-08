#include "Mylib.h"
#include "Stud.h"
#include <random>

//FAILO GENERAVIMAS
void generuotiStudentuFaila(int kiekis) {
    ofstream outFile("studentai.txt");
    outFile << "Vardas Pavarde ";
    for (int i = 1; i <= 10; ++i) outFile << "ND" << i << " ";
    outFile << "EgzaminoBalas\n";

    for (int i = 1; i <= kiekis; ++i) {
        outFile << "Vardas" << i << " Pavarde" << i << " ";
        for (int j = 0; j < 10; ++j) outFile << rand() % 10 + 1 << " ";
        outFile << rand() % 10 + 1 << "\n";
    }

    outFile.close();
}

//1 STRATEGIJA (VECTOR)
void rusiutiStudentus_Strategy1(const vector<Stud>& studentai) {
    vector<Stud> tinginukai;
    vector<Stud> moksliukai;

    for (const auto& stud : studentai) {
        if (galutinisVid(stud) < 5.0) {
            tinginukai.push_back(stud);
        } else {
            moksliukai.push_back(stud);
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

//2 STRATEGIJA (VECTOR)
void rusiutiStudentus_Strategy2(vector<Stud>& studentai) {
    vector<Stud> tinginukai;

    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](Stud& stud) {
        if (galutinisVid(stud) < 5.0) {
            tinginukai.push_back(stud);
            return true;
        }
        return false;
    });

    studentai.erase(it, studentai.end());

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", studentai);
}

//3 PARTITION STRATEGIJA (VECTOR)
void rusiutiStudentus_Strategy3(vector<Stud>& studentai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Stud& stud) {
        return galutinisVid(stud) < 5.0;
    });

    vector<Stud> tinginukai(studentai.begin(), it);
    vector<Stud> moksliukai(it, studentai.end());

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}


//1 STRATEGIJA (LIST)
void rusiutiStudentus_Strategy1(const list<Stud>& studentaiList) {
    list<Stud> tinginukai;
    list<Stud> moksliukai;

    for (const auto& stud : studentaiList) {
        if (galutinisVid(stud) < 5.0) {
            tinginukai.push_back(stud);
        } else {
            moksliukai.push_back(stud);
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}

//2 STRATEGIJA (LIST)
void rusiutiStudentus_Strategy2(list<Stud>& studentaiList) {
    list<Stud> tinginukai;

    for (auto it = studentaiList.begin(); it != studentaiList.end(); ) {
        if (galutinisVid(*it) < 5.0) {
            tinginukai.push_back(*it);
            it = studentaiList.erase(it);
        } else {
            ++it;
        }
    }

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", studentaiList);
}

//3 PARTITION_COPY STRATEGIJA (LIST)
void rusiutiStudentus_Strategy3(list<Stud>& studentaiList) {
    list<Stud> tinginukai;
    list<Stud> moksliukai;

    std::partition_copy(studentaiList.begin(), studentaiList.end(),
                        std::back_inserter(tinginukai), std::back_inserter(moksliukai),
                        [](const Stud& stud) { return galutinisVid(stud) < 5.0; });

    isvestiRezultatus("tinginukai.txt", tinginukai);
    isvestiRezultatus("moksliukai.txt", moksliukai);
}



//SKAITYMAS IS FAILO (VECTOR)
void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav) {
    ifstream inFile(failo_pav);
    if (!inFile) {
        cerr << "Klaida atidarant faila: " << failo_pav << endl;
        return;
    }

    studentai.clear();

    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        Stud student;
        istringstream iss(line);
        iss >> student.vardas >> student.pavarde;

        for (int i = 0; i < 10; ++i) {
            int nd;
            iss >> nd;
            student.ND.push_back(nd);
        }

        iss >> student.egz;

        studentai.push_back(student);
    }

    inFile.close();
}

//SKAITYMAS IS FAILO (LIST)
void skaitytiIsFailoSuKlaiduTikrinimu(list<Stud>& studentaiList, const string& failo_pav) {
    ifstream inFile(failo_pav);
    if (!inFile) {
        cerr << "Klaida atidarant faila: " << failo_pav << endl;
        return;
    }

    studentaiList.clear();

    string line;
    getline(inFile, line);
    while (getline(inFile, line)) {
        Stud student;
        istringstream iss(line);
        iss >> student.vardas >> student.pavarde;

        for (int i = 0; i < 10; ++i) {
            int nd;
            iss >> nd;
            student.ND.push_back(nd);
        }

        iss >> student.egz;
        studentaiList.push_back(student);
    }

    inFile.close();
}

//REZULTATU ISVEDIMAS (VECTOR)
void isvestiRezultatus(const string& failoPav, const vector<Stud>& studentai) {
    ofstream outFile(failoPav);
    for (const auto& stud : studentai) {
        outFile << stud.vardas << " " << stud.pavarde << " " << galutinisVid(stud) << "\n";
    }
}

//REZULTATU ISVEDIMAS (LIST)
void isvestiRezultatus(const string& failoPav, const list<Stud>& studentaiList) {
    ofstream outFile(failoPav);
    for (const auto& stud : studentaiList) {
        outFile << stud.vardas << " " << stud.pavarde << " " << galutinisVid(stud) << "\n";
    }
}


//ND IVEDIMAS
void ivestiNamudarbus(Stud &studentas) {
    string input;
    cout << "Pradekite vesti namu darbu rezultatus (ivedus du kartus Enter, ivestis bus baigta):" << endl;

    while (true) {
        cout << "ND: ";
        getline(cin, input);

        // Jei paspaustas tuščias Enter du kartus, nutraukiame įvestį
        if (input.empty()) {
            cout << "Ivedimas baigtas." << endl;
            break;
        }

        try {
            double nd = stod(input); // Konvertuojame į skaičių
            if (nd < 1 || nd > 10) {
                cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
            } else {
                studentas.ND.push_back(nd); // Pridedame pažymį, jei jis tinkamas
            }
        } catch (const invalid_argument&) {
            cout << "Neteisingas formatas. Iveskite skaiciu nuo 1 iki 10." << endl;
        }
    }
}


//VIDURKIS
double galutinisVid(const Stud& student) {
    double suma = std::accumulate(student.ND.begin(), student.ND.end(), 0.0);
    double vidurkis = suma / student.ND.size();
    return 0.4 * vidurkis + 0.6 * student.egz;
}


//MEDIANA
double galutinisMediana(const Stud& studentas) {
    double med = median(studentas.ND);
    return med * 0.4 + studentas.egz * 0.6;
}


//REZULTATU LENTELE
void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas) {
    cout << setw(20) << "Pavarde"
              << setw(20) << "Vardas"
              << setw(20);

    if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
        cout << "Galutinis (Vid.)";
    } else {
        cout << "Galutinis (Med.)";
    }

    cout << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (const Stud& s : studentai) {
        double galutinis;
        if (skaiciavimo_budas == 'v' || skaiciavimo_budas == 'V') {
            galutinis = galutinisVid(s);  // Naudojame vidurkį
        } else {
            galutinis = galutinisMediana(s);  // Naudojame medianą
        }

        cout << setw(20) << s.pavarde
                  << setw(20) << s.vardas
                  << setw(20) << fixed << setprecision(2) << galutinis
                  << endl;
    }
}


//MEDIANA
double median(const vector<int>& nd) {
    vector<int> copy = nd; // Copy to sort
    sort(copy.begin(), copy.end());
    size_t size = copy.size();
    if (size % 2 == 0)
        return (copy[size / 2 - 1] + copy[size / 2]) / 2.0;
    else
        return copy[size / 2];
}

