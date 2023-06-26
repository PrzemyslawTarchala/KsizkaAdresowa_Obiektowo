#ifndef ADRESATMENAGER_H
#define ADRESATMENAGER_H

#include <iostream>
#include <vector>

#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenager{

    PlikZAdresatami plikZAdresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;

    int pobierzIdNowegoAdresata();
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatMenager(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){
        idZalogowanegoUzytkownika = 0;
    };
    void dodajAdresata ();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wylogowanie();

    //gettery i settery
    int pobierzIdZalogowanegoUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika);
};
#endif
