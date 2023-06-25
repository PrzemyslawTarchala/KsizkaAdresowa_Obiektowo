#ifndef METODYPOMOCNICZNE_H
#define METODYPOMOCNICZNE_H

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class MetodyPomocnicze{

public:
    static string konwerjsaIntNaString(int liczba);
    static string wczytajLinie();
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static int konwersjaStringNaInt(string liczba);
};

#endif
