#ifndef STUD_H
#define STUD_H
#include "Mylib.h"
using namespace std;


//STUDENTO STRUKTURA
struct Stud {
    string vardas;
    string pavarde;
    vector<int> ND;
    double egz;
};


//FAILO GENERAVIMAS
void generuotiStudentuFaila(int kiekis);

//RUSIAVIMAS (VECTOR)
void rusiutiStudentus_Strategy1(const vector<Stud>& studentai);
void rusiutiStudentus_Strategy2(vector<Stud>& studentai);
void rusiutiStudentus_Strategy3(vector<Stud>& studentai);

//RUSIAVIMAS (LIST)
void rusiutiStudentus_Strategy1(const list<Stud>& studentaiList);
void rusiutiStudentus_Strategy2(list<Stud>& studentaiList);
void rusiutiStudentus_Strategy3(list<Stud>& studentaiList);

//FAILO NUSKAITYMAS (VECTOR IR LIST)
void skaitytiIsFailoSuKlaiduTikrinimu(vector<Stud>& studentai, const string& failo_pav);
void skaitytiIsFailoSuKlaiduTikrinimu(list<Stud>& studentaiList, const string& failo_pav);

//REZULTATU ISVEDIMAS (VECTOR IR LIST)
void isvestiRezultatus(const string& failoPav, const vector<Stud>& studentai);
void isvestiRezultatus(const string& failoPav, const list<Stud>& studentaiList);

//GALUTINIO SKAICIAVIMO BUDAI
double galutinisVid(const Stud& studentas);
double galutinisMediana(const Stud& studentas);
double median(const vector<int>& nd);

//ND IVEDIMAS
void ivestiNamudarbus(Stud& studentas);

//REZU SPAUSDINIMAS
void spausdintiRezultatus(const vector<Stud>& studentai, char skaiciavimo_budas);
void spausdintiRezultatus(const list<Stud>& studentai, char skaiciavimo_budas);


#endif

