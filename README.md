v1.0 yra galutinė pirmosios užduoties versija. Joje yra papildoma galimybė pasirinkti iš trijų
duomenų rušiavimo būdų (dviejų konteineriu, vieno konteinerio ir optimizuoto) abiems konteineriams
(vector ir list). Taip pat kiekvienai iš rušiavimo strategijų atliekama spartos analizė.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


SPARTOS ANALIZES TYRIMAS (pateikti laikai yra 3 bandymų vidurkiai):
Zymejimai:

G-FAILO GENERVIMAS, N-FAILO NUSKAITYMAS, R-STUDENTU RUSIAVIMAS, I-REZULTATU ISSAUGOJIMAS FAILUOSE
![image](https://github.com/user-attachments/assets/2179955f-79f0-498b-8ae4-3d6debbec6d4)


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


ATSISIUNTIMO INSTRUKCIJA:

Atsisiųskite V1.0 leidimą:

spustelėkite „V1.0“ leidimą ir pasirinkite Source code (zip), kad atsisiųstumėte programos šaltinio kodą. Išarchyvuokite atsisiųstą failą į pasirinktą katalogą.

Atsisiunte ispleskite zip faila ir paspaude desniji klavisa ant programos aplanko pasirinkite "atidaryti naudojant terminala"

Atsidarius terminalui, komandineje eiluteje irasykite:

mkdir build

Paspaude enter, irasykite:

cd build

ir galiausiai dar karta paspaude enter irasykite:

cmake -G "CodeBlocks - MinGW Makefiles" ..


Po sėkmingo kompiliavimo make sukuria vykdomąjį failą „v1.0”.

Ji rasite atsidare programos aplanka ir paspaude ant build aplanko.


Ijungus mineta v1.0 faila, salia "build" ir "run" mygtuku, vietoje "all" pasirinkite opcija "v1.0"

Tada paspauskite build

Na ir kai sis veiksmas atliekamas, galite spausti "run" mygtuka ir pradeti naudotis programa.


--------------------------------------------------------------------------------------------------------------------------------------------------------------------


NAUDOJIMO IMSTRUKCIJA:

Paleiskite programą – programa inicijuojama funkcijoje main, kuri kviečia naudotoją pasirinkti veiksmus.

 Pasirinkite duomenų įvedimo būdą. Galimos pasirinktys yra šios: rankinis įvedimas, failo nuskaitymas arba failo generavimas.

 Jei pasirinksite rankinį įvedimą, turėsite įvesti studentų vardus ir pažymius ranka, čia taip pat yra galimybė pasirinkti kad ND ir EGZ rezultatai būtų sugeneruoti.

 Jei pasirinksite failo nuskaitymą, turėsite nurodyti esamo failo pavadinimą, kuriame yra studentų duomenys.

Pasirinkę tiek rankinį duomenų įvedimą, tiek nuskaitymą iš failo, toliau turėsite pasirinkti rezultatų skaičiavimo metodą. Galutinis balas gali būti apskaičiuojamas pagal vidurkį arba medianą, priklausomai nuo pasirinkto metodo.

Galutiniai rezultatai pateikiami lentelės pavidalu


 Pasirinkus failo generavimą turesite pasirinkti kurį konteinerį norite naudoti (vector arba list) bei kiek studentų turi būti generuojamame faile (1000, 10000, 100000, 1000000, 10000000), programa automatiškai sugeneruos failą su atsitiktiniais studentų ND ir EGZ balais.
Pasirinkite studentų rūšiavimo strategiją. Galimos strategijos yra trys:
1.	Strategija 1 – kuria du atskirus sąrašus, kuriuose studentai suskirstyti pagal vidutinį įvertinimą.
2.	Strategija 2 – pašalina „tinginukus“ (studentus su vidutiniu įvertinimu mažesniu nei 5) ir palieka tik „moksliukus“.
3.	Strategija 3 – naudoja partition funkciją, kuri greitai suskirsto studentus į atskiras grupes.

Rezultatų spausdinimas. Programa išveda rūšiuotus studentus į atskirus failus, pavadintus tinginukai.txt ir moksliukai.txt kurie bus laikomi tame paciame aplanke, kaip ir jusu programa.

Galiausiai, atlikus visus veiksmus, naudotojui pateikiamas klausimas, ar programa turėtų būti paleista iš naujo.


