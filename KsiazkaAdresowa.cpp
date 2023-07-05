#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenager.logowanieUzytkownika();
    if (uzytkownikMenager.czyUzytkownikJestZalogowany()){
        adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowaneUzytkownika());
    }
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenager.wylogowanieUzytkownika();
    delete adresatMenager;
    adresatMenager = NULL; //usuwamy to na co wskazuje wskaznik!
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUZytkownika(){
    if(uzytkownikMenager.czyUzytkownikJestZalogowany()){
        uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
    }
}

void KsiazkaAdresowa::dodajAdresata(){
    if(uzytkownikMenager.czyUzytkownikJestZalogowany()){
        adresatMenager -> dodajAdresata();
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    if(uzytkownikMenager.czyUzytkownikJestZalogowany()){
        adresatMenager -> wyswietlWszystkichAdresatow();
    }
}



