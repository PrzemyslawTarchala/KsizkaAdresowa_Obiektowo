#include "KsiazkaAdresowa.h"
/*
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

void KsiazkaAdresowa::usunAdresata(){
    if(uzytkownikMenager.czyUzytkownikJestZalogowany()){
        adresatMenager -> usunAdresata();
    }
}

void KsiazkaAdresowa::edytujAdresata(){
    if(uzytkownikMenager.czyUzytkownikJestZalogowany()){
        adresatMenager -> edytujAdresata();
    }
}
*/

void KsiazkaAdresowa::mainMenu(){
    char wybor;
    while(true){
        if(uzytkownikMenager.pobierzIdZalogowaneUzytkownika() == 0){
            system("cls");
            cout << "          MENU GLOWNE\n";
            cout << "----------------------------\n";
            cout << "1. Zarejestruj sie\n";
            cout << "2. Zaloguj sie\n\n";
            cout << "9. Wyjdz\n";
            cout << "-----------------------------\n\n";
            cout << "Wybor: ";
            wybor = MetodyPomocnicze::wczytajZnak();
            switch (wybor){
                case '1': uzytkownikMenager.rejestracjaUzytkownika();
                    break;
                case '2': uzytkownikMenager.logowanieUzytkownika();
                        if (uzytkownikMenager.czyUzytkownikJestZalogowany()){
                            adresatMenager = new AdresatMenager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenager.pobierzIdZalogowaneUzytkownika());
                        }
                    break;
                case '9': exit(0);
                    break;
                default: cout << "Nieprawidlowy wybor!\n"; system ("pause");
            }
        }
        else{
            system("cls");
            cout << "         LOGGED\n";
            cout << "----------------------------\n\n";
            cout << "1. Dodaj adresata\n";
            cout << "2. Wyszukaj adresata po imieniu\n";
            cout << "3. Wyszukaj adresata po nazwisku\n";
            cout << "4. Wyswietl wszystkich adresatow\n";
            cout << "5. Usun adresata\n";
            cout << "6. Edytuj adresata\n\n";
            cout << "-----------------------------\n\n";
            cout << "8. Zmiana hasla\n";
            cout << "9. Wyloguj\n\n";
            cout << "-----------------------------\n\n";
            cout << "Wybor: ";
            wybor = MetodyPomocnicze::wczytajZnak();
            switch (wybor){
                case '1': adresatMenager -> dodajAdresata();
                    break;
                case '2': adresatMenager -> wyszukajAdresataPoImieniu();
                    break;
                case '3': adresatMenager -> wyszukajAdresataPoNazwisku();
                    break;
                case '4': adresatMenager -> wyswietlWszystkichAdresatow();
                    break;
                case '5': adresatMenager -> usunAdresata();
                    break;
                case '6': adresatMenager -> edytujAdresata();
                    break;
                case '8': uzytkownikMenager.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '9': uzytkownikMenager.wylogowanieUzytkownika();
                    break;
                default: cout << "Nieprawidlowy wybor!\n"; system ("pause");
            }
        }
    }
}





