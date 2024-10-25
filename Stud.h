#ifndef STUD_H
#define STUD_H

#include "Mylib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

struct Stud {
    string vardas;
    string pavarde;
    vector<int> ND; // Namu darbai
    double egz;     // Egzamino rezultatas
};


// Failo generavimo funkcija
void generuotiStudentuFaila(int kiekis);

// Rūšiavimo funkcijos (viena kiekvienam konteinerio tipui)
void rusiutiStudentus(const vector<Stud>& studentai);
void rusiutiStudentus(const list<Stud>& studentaiList);

// Failo skaitymo su klaidų tikrinimu funkcijos
void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav);
void skaitytiIsFailoSuKlaiduTikrinimu(list<Stud>& studentaiList, const string& failo_pav);

// Rezultatų išvesties funkcijos
void isvestiRezultatus(const string& failoPav, const vector<Stud>& studentai);
void isvestiRezultatus(const string& failoPav, const list<Stud>& studentaiList);

// Kitos funkcijos
double galutinisVid(const Stud& studentas);
void ivestiNamudarbus(Stud& studentas);
double galutinisVidurkis(const Stud& studentas);
double galutinisMediana(const Stud& studentas);
void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas);
void spausdintiRezultatus(const list<Stud>& studentai, char skaiciavimo_budas);
double median(const vector<int>& nd);

#endif

