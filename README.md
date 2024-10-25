v0.3 tai programos versija, kuri kurioje naudotojas gali pasirinkti kurį konteinerį nori naudoti - 
vector ar list. Siems abiems konteineriams buvo atlikta spartos analize, kuria atspindi sie rezultatai:

TESTAVIMO SISTEMOS PARAMETRAI:
-	OS: Windows 11 pro
-	CPU: 12th Gen Intel(R) Core(TM) i5-1235U, 1.30 GHz
-	RAM: 8 GB
-	SSD: 236 GB

VECTOR KONTEINERIO SPARTOS ANALIZĖ (PATEIKIAMI REZULTATAI YRA TRIJŲ BANDYMŲ VIDURKIS):
-	FAILO GENERAVIMAS:
1000 – 0.0180772 s
10000 – 0.047912 s
100000 – 0.290992 s
1000000 – 2.42048 s
10000000 – 23.8706 s

-	FAILO NUSKAITYMAS:
1000 – 0.0449938 s
10000 – 0.125772 s
100000 – 0.832698 s
1000000 – 6.78238 s
10000000 – 77.5632 s

-	RUŠIAVIMAS Į DVI KATEGORIJAS IR REZULTATŲ IŠVEDIMAS Į FAILUS:
1000 – 0.0155857 s
10000 – 0.0469001 s
100000 – 0.313824 s
1000000 – 2.0313 s
10000000 – 29.101 s

LIST KONTEINERIO SPARTOS ANALIZĖ (PATEIKIAMI REZULTATAI YRA TRIJŲ BANDYMŲ VIDURKIS):
-	FAILO GENERAVIMAS:
1000 – 0.0159428 s
10000 –  0.0625437 s
100000 – 0.284859 s
1000000 – 2.41735 s
10000000 – 22.3681 s

-	FAILO NUSKAITYMAS:
1000 –  0.0368939 s
10000 – 0.141447 s
100000 – 0.757305 s
1000000 – 6.97506 s
10000000 – 63.3761 s

-	RUŠIAVIMAS Į DVI KATEGORIJAS IR REZULTATŲ IŠVEDIMAS Į FAILUS:
1000 – 0.0156268 s
10000 – 0.0160965 s
100000 – 0.267398 s
1000000 – 1.75398 s
10000000 – 38.5908 s

ISVADOS: Vector konteineris yra efektyvesnis dirbant su dideliais duomenų kiekiais dėl greitesnio nuskaitymo, o list konteineris geriau tinka mažiems kiekiams ir rūšiavimo operacijoms. Pasirinkimas tarp šių dviejų konteinerių turėtų būti grindžiamas konkrečiu naudojimo atveju ir reikalavimais
