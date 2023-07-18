#include "PlikZAdresatami.h"

int PlikZAdresatami::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}

void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat){

    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        ++ idOstatniegoAdresata;

        if (czyPlikJestPusty(pobierzNazwePliku())){
            plikTekstowy << liniaZDanymiAdresata;
        }
        else{
            plikTekstowy << endl << liniaZDanymiAdresata;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat){

    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmial() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika){

    Adresat adresat;

    vector <Adresat> adresaci;
    int pozycjaZnaku = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good())
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    idOstatniegoAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneOstaniegoAdresataWPliku, pozycjaZnaku));   //zwraca ID ostatniego uzytkownika
    plikTekstowy.close();
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami){
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami){
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (size_t pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); ++pozycjaZnaku)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            ++numerPojedynczejDanejAdresata;
        }
    }
    return adresat;
}

void PlikZAdresatami::usunAdresataWPliku(vector <Adresat> adresaci, int idUsuwanegoAdresata){
    bool tempPlikPusty = true;
    int pozycjaZnaku, tempId;
    string line;
    string tempLine = "";

    fstream plikTekstowy, tempPlikTekstowyt;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tempPlikTekstowyt.open(pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    if(plikTekstowy.good()){
        while (getline(plikTekstowy, line)){
            pozycjaZnaku = 0;
            tempLine = "";
            while (line[pozycjaZnaku] != '|'){
                tempLine += line[pozycjaZnaku];
                ++ pozycjaZnaku;
            }
            tempId = stoi(tempLine);
            if (tempId != idUsuwanegoAdresata){
                if(tempPlikPusty == true){
                    tempPlikTekstowyt << line;
                }
                else{
                    tempPlikTekstowyt << endl << line;
                }
            }
            else{
                continue;
            }
            tempPlikPusty = false;
        }
    }
    cout << "\nAdresat zostal usuniety" << endl << endl;
    plikTekstowy.close();
    tempPlikTekstowyt.close();
    remove(pobierzNazwePliku().c_str());
    rename(pobierzNazwePlikuTymczasowego().c_str(),pobierzNazwePliku().c_str());
}

void PlikZAdresatami::edytujAdresataWPliku(int idEdytowanegoAdresata, string daneAdresataDoZmiany){

    bool tempPlikPusty = true;
    int idAdresataDoZaminy;
    string linia;
    fstream plikTekstowy, tempPlikTekstowyt;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tempPlikTekstowyt.open(pobierzNazwePlikuTymczasowego().c_str(), ios::out | ios::app);

    if(plikTekstowy.good()){
        while(getline(plikTekstowy, linia)){
            idAdresataDoZaminy = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(linia,0));
            if(tempPlikPusty == true){
                if (idAdresataDoZaminy == idEdytowanegoAdresata){
                    tempPlikTekstowyt << daneAdresataDoZmiany;
                }
                else{
                    tempPlikTekstowyt << linia;
                }
            }
            else{
                if (idAdresataDoZaminy == idEdytowanegoAdresata){
                    tempPlikTekstowyt << endl << daneAdresataDoZmiany;
                }
                else{
                    tempPlikTekstowyt << endl << linia;
                }
            }
            tempPlikPusty = false;
        }
        cout << "\nAdresat zostal Edytowany" << endl << endl;
        system ("pause");
    }
    else{
        cout << "Nie udalo sie otworzyc pliku\n\n";
        system ("pause");
    }
    plikTekstowy.close();
    tempPlikTekstowyt.close();
    remove(pobierzNazwePliku().c_str());
    rename(pobierzNazwePlikuTymczasowego().c_str(), pobierzNazwePliku().c_str());
}
