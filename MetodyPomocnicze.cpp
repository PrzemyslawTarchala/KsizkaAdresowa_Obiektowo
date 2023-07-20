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

void MetodyPomocnicze::czyUzytkownikJestZalogowany(int idZalogowanegoUzytkownika){
    if (idZalogowanegoUzytkownika == 0){
        cout << "Wymagane zalogowanie." << endl << endl;
        system ("pause");
        exit(0);
    }
}

int MetodyPomocnicze::wczytajLiczbeCalkowita(){
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);
        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}

char MetodyPomocnicze::wczytajZnak(){
    string wejscie = "";
    char znak  = {0};
    while (true)
    {
        getline(cin, wejscie);
        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "\nTo nie jest pojedynczy znak. Wpisz ponownie: ";
    }
    return znak;
}

string MetodyPomocnicze::przeksztalcNaDuzeLitery(string napis){
    transform(napis.begin(), napis.end(), napis.begin(), :: toupper);
    return napis;
}
