#include "MetodyPomocnicze.h"

string MetodyPomocnicze::wczytajLinie(){
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::konwerjsaIntNaString(int liczba){
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

bool MetodyPomocnicze::czyPlikJestPusty(fstream &plikTekstowy){

    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}

int MetodyPomocnicze::konwersjaStringNaInt(string liczba){

    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;
    return liczbaInt;
}

string MetodyPomocnicze::pobierzLiczbe(string tekst, int pozycjaZnaku){
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]))
    {
        liczba += tekst[pozycjaZnaku];
        ++pozycjaZnaku;
    }
    return liczba;
}
