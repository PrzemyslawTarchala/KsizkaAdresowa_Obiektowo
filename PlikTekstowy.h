#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy{
    const string NAZWA_PLIKU;
    const string NAZWA_PLIKU_TYMCZASOWEGO; //Dodane pod klase PlikZAdsresatami
public:
    PlikTekstowy(string nazwaPlikuZAdresatami) : NAZWA_PLIKU(nazwaPlikuZAdresatami){};
    string pobierzNazwePliku();
    string pobierzNazwePlikuTymczasowego();
    void ustawNazwePlikuTymczasowego(string nowaNazwaPlikuTymczasowego);
    bool czyPlikJestPusty(string nazwaPliku);
};

#endif
