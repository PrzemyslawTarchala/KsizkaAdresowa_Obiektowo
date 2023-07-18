#ifndef METODYPOMOCNICZNE_H
#define METODYPOMOCNICZNE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze{

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static void czyUzytkownikJestZalogowany(int idZalogowanegoUzytkownika);
    static int wczytajLiczbeCalkowita();
    static char wczytajZnak();
    static string przeksztalcNaDuzeLitery(string napis);
};

#endif
