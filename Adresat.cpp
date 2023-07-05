#include "Adresat.h"

int Adresat::pobierzId(){
    return id;
}
int Adresat::pobierzIdUzytkownika(){
    return idUzytkownika;
}
string Adresat::pobierzImie(){
    return imie;
}
string Adresat::pobierzNazwisko(){
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu(){
    return numerTelefonu;
}
string Adresat::pobierzEmial(){
    return email;
}
string Adresat::pobierzAdres(){
    return adres;
}

void Adresat::ustawId(int id){
    this -> id = id;
}
void Adresat::ustawIdUzytkownika(int idUzytkownika){
    this -> idUzytkownika = idUzytkownika;
}
void Adresat::ustawImie (string imie){
    this -> imie = imie;
}
void Adresat::ustawNazwisko(string nazwisko){
    this -> nazwisko = nazwisko;
}
void Adresat::ustawNumerTelefonu(string numerTelefonu){
    this -> numerTelefonu = numerTelefonu;
}
void Adresat::ustawEmail(string email){
    this -> email = email;
}
void Adresat::ustawAdres(string adres){
    this -> adres = adres;
}
