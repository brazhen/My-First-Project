#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

struct Stud {
    std::string vardas, pavarde;
    std::vector<double> ND;
    double vid, med, egz, rez;
};

void ived(Stud &Lok, bool randomize = false);
void output(const Stud &Lok);
void val(Stud &Lok);
double galutinisVidurkis(const Stud &Lok);
double galutinisMediana(const Stud &Lok);

#endif // STUD_H_INCLUDED
