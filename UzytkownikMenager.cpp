#include "UzytkownikMenager.h"

void UzytkownikMenager::rejestracjaUzytkownika(){

    cout << "-----REJESTRACJA-----" << endl << endl;

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();
    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie!" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenager::podajDaneNowegoUzytkownika(){

    Uzytkownik uzytkownik;
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    do
    {
        cout << "Podaj login: ";
        uzytkownik.ustawLogin(MetodyPomocnicze::wczytajLinie());
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    uzytkownik.ustawHaslo(MetodyPomocnicze::wczytajLinie());

    return uzytkownik;
}

int UzytkownikMenager::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenager::czyIstniejeLogin(string login){
    for (size_t i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenager::wypiszWszystkichUzytkownikow(){

    cout << "-----REJESTR UZYTKOWNIKOW-----" << endl << endl;
    if(!uzytkownicy.empty()){
        for (size_t i = 0; i < uzytkownicy.size(); ++i){
            cout << "Uzytkownik ID: " << uzytkownicy[i].pobierzId();
            cout << ", Login: " << uzytkownicy[i].pobierzLogin();
            cout << ", Haslo: " << uzytkownicy[i].pobierzHaslo() << endl;
        }
        cout << endl;
        system("pause");
    }
    else{
        cout << "Brak uzytkownikow" << endl << endl;
        system("pause");
    }
}

void UzytkownikMenager::wczytajUzytkownikowZPliku(){
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenager::logowanieUzytkownika(){

    if (idZalogowanegoUzytkownika == 0){

        Uzytkownik uzytkownik;
        string login = "", haslo = "";
        system ("cls");
        cout << "-----LOGOWANIE-----" << endl << endl;

        if (uzytkownicy.empty()){
            cout << "Brak uzytkownikow." << endl << endl;
            system ("pause");
            exit(0);
        }

        cout << "Podaj login: ";
        login = MetodyPomocnicze::wczytajLinie();

        for (size_t i = 0; i < uzytkownicy.size(); ++i)
        {
            if (uzytkownicy[i].pobierzLogin() == login)
            {
                for (int iloscProb = 3; iloscProb > 0; iloscProb--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                    haslo = MetodyPomocnicze::wczytajLinie();

                    if (uzytkownicy[i].pobierzHaslo() == haslo)
                    {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system("pause");
                        idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                        return 0; //SPRAWDZ EXIT
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                return 0;
            }
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        return 0;
    }
    else{
        cout << "Musisz sie najpierw wylogowac!" << endl;
        system ("pause");
    }
}

void UzytkownikMenager::wylogowanieUzytkownika(){

    system("cls");
    cout << "-----WYLOGOWANIE UZYTKOWNIKA-----" << endl << endl;
    if (idZalogowanegoUzytkownika != 0) {
        idZalogowanegoUzytkownika = 0;
        cout << "Wylogowano pomyslnie." << endl << endl;
        system("pause");
    }
    else{
        cout << "Najpierw wypadaloby sie zalogowac :)" << endl << endl;
        system("pause");
    }

}

void UzytkownikMenager::zmianaHaslaZalogowanegoUzytkownika(){

    system ("cls");
    cout << "-----ZMIANA HASLA-----" << endl << endl;
    string noweHaslo = "";

    if (idZalogowanegoUzytkownika != 0){
        cout << "Podaj nowe haslo: ";
        noweHaslo = MetodyPomocnicze::wczytajLinie();
        for (size_t i = 0; i < uzytkownicy.size(); ++i)
        {
            if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
            {
                uzytkownicy[i].ustawHaslo(noweHaslo);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }
        plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    }
    else{
        cout << "Wymagane zalogowanie\n" << endl;
        system("pause");
    }
}

//Gettery i Settery

int UzytkownikMenager::pobierzIdZalogowaneUzytkownika(){
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenager::ustawIdZalogowanegoUzytkownika(int noweId){
    idZalogowanegoUzytkownika = noweId;
}



