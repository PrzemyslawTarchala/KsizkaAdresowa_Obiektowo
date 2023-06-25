#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikMenager.logowanieUzytkownika();
    adresatMenager.ustawIdZalogowanegoUzytkownika(uzytkownikMenager.pobierzIdZalogowaneUzytkownika());
    adresatMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikMenager.wylogowanieUzytkownika();
    adresatMenager.wylogowanie();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUZytkownika(){
    uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatMenager.dodajAdresata( );
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatMenager.wyswietlWszystkichAdresatow();
}



