#include "Adresat.h"

int Adresat::pobierzId() const {
    return id;
}
int Adresat::pobierzIdUzytkownika() const{
    return idUzytkownika;
}
string Adresat::pobierzImie() const{
    return imie;
}
string Adresat::pobierzNazwisko() const{
    return nazwisko;
}
string Adresat::pobierzNumerTelefonu() const{
    return numerTelefonu;
}
string Adresat::pobierzEmial() const{
    return email;
}
string Adresat::pobierzAdres() const{
    return adres;
}

void Adresat::ustawId(int id) {
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
