#include "AdresatMenager.h"

AdresatMenager::AdresatMenager(){
    idZalogowanegoUzytkownika = 0;
}

void AdresatMenager::dodajAdresata(){

    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    if (idZalogowanegoUzytkownika != 0){
        adresat = podajDaneNowegoAdresata();
        adresaci.push_back(adresat);
        plikZAdresatami.dopiszAdresataDoPliku(adresat);
    }
     else{
        cout << "Wymagane zalogowanie\n" << endl;
        system("pause");
    }
}

Adresat AdresatMenager::podajDaneNowegoAdresata(){

    Adresat adresat;

    adresat.ustawId(pobierzIdNowegoAdresata());
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

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

int AdresatMenager::pobierzIdNowegoAdresata(){
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}

void AdresatMenager::wyswietlWszystkichAdresatow()
{
    system("cls");
    cout << "-----ADRESACI-----" << endl;

    if (idZalogowanegoUzytkownika == 0){
        cout << endl << "Wymagane zalogowanie." << endl << endl;
        system ("pause");
        exit(0);
    }

    if (!adresaci.empty())
    {
        for (size_t i = 0; i < adresaci.size(); ++i)
            if (adresaci[i].pobierzIdUzytkownika() == idZalogowanegoUzytkownika){
                wyswietlDaneAdresata(adresaci[i]);
            }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenager::wyswietlDaneAdresata(Adresat adresat){
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmial() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenager::wczytajAdresatowZalogowanegoUzytkownikaZPliku(){
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void AdresatMenager::wylogowanie(){
    idZalogowanegoUzytkownika = 0;
    adresaci.clear();
}

//gettery i settery

int AdresatMenager::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}
void AdresatMenager::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika){
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}


