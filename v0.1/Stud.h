#ifndef STUD_H
#define STUD_H

#include <vector>
#include <string>

struct Stud {
    std::string vardas;
    std::string pavarde;
    std::vector<double> ND;
    double egz;
};


double galutinisVidurkis(const Stud& s);
double galutinisMediana(const Stud& s);
void spausdintiRezultatus(const std::vector<Stud>& studentai, char skaiciavimo_budas);
void skaitytiIsFailoSuKlaiduTikrinimu(std::vector<Stud>& studentai, std::string& failo_pav);

#endif // STUD_H

