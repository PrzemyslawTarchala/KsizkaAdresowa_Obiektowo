#include "AdresatMenager.h"

int AdresatMenager::pobierzIdZalogowanegoUzytkownika(){
    return ID_ZALOGOWANEGO_UZYTKOWNIKA;
}

void AdresatMenager::dodajAdresata(){

    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}

Adresat AdresatMenager::podajDaneNowegoAdresata(){

    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata() + 1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    //adresat.imie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.imie);

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    //adresat.nazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.nazwisko);

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenager::wyswietlWszystkichAdresatow(){
    system("cls");
    cout << "-----ADRESACI-----" << endl << endl;


    MetodyPomocnicze::czyUzytkownikJestZalogowany(ID_ZALOGOWANEGO_UZYTKOWNIKA); //ta metoda zostanie domyslnie usunieta
    if (!adresaci.empty())
    {
        for (const Adresat adresat : adresaci){
            wyswietlDaneAdresata(adresat);
        }
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat){
    cout << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmial() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl << endl;
}
