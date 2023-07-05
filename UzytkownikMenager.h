#ifndef UZYTKOWNIKMENAGER_H
#define UZYTKOWNIKMENAGER_H

#include <iostream>
#include <vector>

#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikMenager{

    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;
    int idZalogowanegoUzytkownika;

    Uzytkownik podajDaneNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika = 0;
    };
    int pobierzIdZalogowaneUzytkownika();

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdNowegoUzytkownika();
};
#endif
