#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main(){

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wybor;
    while(true){
        if(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0){
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
                case '1': ksiazkaAdresowa.rejestracjaUzytkownika();
                    break;
                case '2': ksiazkaAdresowa.logowanieUzytkownika();
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
                case '1': ksiazkaAdresowa.dodajAdresata();
                    break;
                case '2': ksiazkaAdresowa.wyszukajAdresataPoImieniu();
                    break;
                case '3': ksiazkaAdresowa.wyszukajAdresataPoNazwisku();
                    break;
                case '4': ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                case '5': ksiazkaAdresowa.usunAdresata();
                    break;
                case '6': ksiazkaAdresowa.edytujAdresata();
                    break;
                case '8': ksiazkaAdresowa.zmianaHaslaZalogowanegoUZytkownika();
                    break;
                case '9': ksiazkaAdresowa.wylogowanieUzytkownika();
                    break;
                default: cout << "Nieprawidlowy wybor!\n"; system ("pause");
            }
        }
    }
    return 0;
}

