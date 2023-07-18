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
    adresat.ustawImie(MetodyPomocnicze::przeksztalcNaDuzeLitery(MetodyPomocnicze::wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::przeksztalcNaDuzeLitery(MetodyPomocnicze::wczytajLinie()));

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
    cout << "\nId:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmial() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl << endl;
}

void AdresatMenager::usunAdresata(){

    int idUsuwanegoAdresata = 0;
    bool czyUsunietoAdresata = false;
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID adresata do usuniecia: ";
    idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
        if (itr -> pobierzId() == idUsuwanegoAdresata){
            cout << "Czy na pewno chcesz usunac Adresata? t/n -> ";
            if(MetodyPomocnicze::wczytajZnak() == 't'){
                plikZAdresatami.usunAdresataWPliku(adresaci, idUsuwanegoAdresata);
                adresaci.erase(itr);
                czyUsunietoAdresata = true;
                system("pause");
                return;
            }
            else{
                cout << "\nAdresata nie usunieto" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if(czyUsunietoAdresata == false){
        cout << "\nBrak adresata o podanym ID" << endl << endl;
        system("pause");
    }
}

void AdresatMenager::edytujAdresata(){
    char wybor;
    int idEdytowanegoAdresata = 0;
    bool czyEdytowanoAdresata = false;
    string noweImie, noweNazwisko, nowyNumerTelfonu, nowyMail, nowyAdres;
    string daneAdresataDoZmiany;
    system("cls");
    cout << ">>> EDYTOWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "Podaj ID adresata do edycji: ";
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    for (const Adresat &adresat : adresaci){
        if (adresat.pobierzId() == idEdytowanegoAdresata){
            cout << "\nWybierz: \n" << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu" << endl;
            cout << "4. Mail" << endl;
            cout << "5. Adress" << endl;
            cout << "6. Back to menu" << endl;
            cout << "\nEnter choice: "; wybor = MetodyPomocnicze::wczytajZnak();
            switch (wybor){
                case '1': cout << "Wprowadz nowe imie: "; noweImie = MetodyPomocnicze::przeksztalcNaDuzeLitery(MetodyPomocnicze::wczytajLinie()); adresat.ustawImie(noweImie); break;
                case '2': cout << "Wprwoadz nowe nazwisko: "; noweNazwisko = MetodyPomocnicze::przeksztalcNaDuzeLitery(MetodyPomocnicze::wczytajLinie()); adresat.ustawNazwisko(noweNazwisko); break;
                case '3': cout << "Wprowadz nowy numer telefonu: "; nowyNumerTelfonu = MetodyPomocnicze::wczytajLinie(); adresat.ustawNumerTelefonu(nowyNumerTelfonu); break;
                case '4': cout << "Wprwoadz nowy mail: "; nowyMail = MetodyPomocnicze::wczytajLinie(); adresat.ustawEmail(nowyMail); break;
                case '5': cout << "Wprwoadz nowy adres: "; nowyAdres = MetodyPomocnicze::wczytajLinie(); adresat.ustawAdres(nowyAdres); break;
                case '6': return;
                default: cout << "Nieprawidlowy wybor!\n"; system("pause");
            }
            daneAdresataDoZmiany = MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + "|" +  MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + "|" + adresat.pobierzImie() + "|" + adresat.pobierzNazwisko() + "|" + adresat.pobierzNumerTelefonu() + "|" + adresat.pobierzEmial() + "|" + adresat.pobierzAdres() + "|";
            plikZAdresatami.edytujAdresataWPliku(idEdytowanegoAdresata, daneAdresataDoZmiany);
            czyEdytowanoAdresata = true;
        }
    }
    if(czyEdytowanoAdresata == false){
        cout << "\nBrak adresata o podanym ID" << endl << endl;
        system("pause");
    }
}

void AdresatMenager::wyszukajAdresataPoImieniu(){
    bool znaleziono = false;
    string imie;
    system ("cls");
    cout << ">>> WYSZUKIWANIE ADRESATA PO IMIENIU <<<\n\n";
    if(adresaci.size() != 0){
        cout << "Podaj imie adresata: ";
        cin >> imie;
        for (const Adresat adresat : adresaci){
            if(adresat.pobierzImie() == MetodyPomocnicze::przeksztalcNaDuzeLitery(imie)){
                wyswietlDaneAdresata(adresat);
                znaleziono = true;
            }
        }
        if (znaleziono == false){
            cout << "\nAdresat o podanym imieniu nie istnieje\n\n";
        }
        system("pause");
    }
    else{
        cout << "Brak adresatow.\n\n";
        system("pause");
    }
}

void AdresatMenager::wyszukajAdresataPoNazwisku(){
    bool znaleziono = false;
    string nazwisko;
    system ("cls");
    cout << ">>> WYSZUKIWANIE ADRESATA PO NAZWISKU <<<\n\n";
    if(adresaci.size() != 0){
        cout << "Podaj nazwisko adresata: ";
        cin >> nazwisko;
        for (const Adresat adresat : adresaci){
            if(adresat.pobierzNazwisko() == MetodyPomocnicze::przeksztalcNaDuzeLitery(nazwisko)){
                wyswietlDaneAdresata(adresat);
                znaleziono = true;
            }
        }
        if (znaleziono == false){
            cout << "\nAdresat o podanym imieniu nie istnieje\n";
        }
        system("pause");
    }
    else{
        cout << "Brak adresatow.\n\n";
        system("pause");
    }
}
