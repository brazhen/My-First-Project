#ifndef MYLIB_H
#define MYLIB_H

#include <vector>
#include <string>
#include <iostream>


void spausdintiRezultatus(const std::vector<Stud>& studentai, char skaiciavimo_budas);
void skaitytiIsFailo(std::vector<Stud>& studentai, const std::string& failo_pav);
double galutinisVidurkis(const Stud& s);
double galutinisMediana(const Stud& s);

#endif
