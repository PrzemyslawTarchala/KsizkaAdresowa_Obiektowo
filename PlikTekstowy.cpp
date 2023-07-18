#include "PlikTekstowy.h"

bool PlikTekstowy::czyPlikJestPusty(string nazwaPliku){

    fstream plikTekstowy;
    plikTekstowy.open(nazwaPliku, ios::out | ios::app);
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

string PlikTekstowy::pobierzNazwePliku(){
    return NAZWA_PLIKU;
}

string PlikTekstowy::pobierzNazwePlikuTymczasowego(){
    return NAZWA_PLIKU_TYMCZASOWEGO;
}

void PlikTekstowy::ustawNazwePlikuTymczasowego(string nowaNazwaPlikuTymczasowego){
    this -> NAZWA_PLIKU_TYMCZASOWEGO = nowaNazwaPlikuTymczasowego;
}
