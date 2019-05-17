#include <vector>
#include <string>
#include <iostream>

class Osoba;

class Lista {
private:
    std::vector<Osoba> lista;
    bool lista_compare(Osoba os1, Osoba os2);
    int znajdz_index_osoby(std::string imie, std::string nazwisko);

public:
    void dodaj_osobe(Osoba os);
    void usun_osobe(std::string imie, std::string nazwisko);
    void wyczysc_liste();
    void posortuj_liste();
    void wypisz_liste();
    void wypisz_osobe(std::string imie, std::string nazwisko);
    Osoba znajdz_osobe(std::string imie, std::string nazwisko);
    void wypisz_osoby();
};