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
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:
    UzytkownikMenager(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami){
        idZalogowanegoUzytkownika = 0;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void wczytajUzytkownikowZPliku();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    //Gettery i Settery
    int pobierzIdZalogowaneUzytkownika();
    void ustawIdZalogowanegoUzytkownika(int noweId);
};
#endif
