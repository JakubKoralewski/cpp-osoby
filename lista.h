#include <vector>
#include <string>
#include <iostream>

#include "osoba.h"

class Lista {
private:
    std::vector<Osoba> lista;
    bool lista_compare(Osoba os1, Osoba os2);
    int znajdz_index_osoby(std::string imie, std::string nazwisko);
    int ostatnio_znaleziony_index;

public:
    Osoba ostatnio_znaleziona();
    Osoba set_prop_on_last(std::string property, std::string wartosc);
    void dodaj_osobe(Osoba os);
    void usun_osobe(std::string imie, std::string nazwisko);
    void wyczysc_liste();
    void posortuj_liste();
    void wypisz_liste();
    void wypisz_osobe(std::string imie, std::string nazwisko);
    bool czy_osoba_istnieje(std::string imie, std::string nazwisko);
    void wypisz_osoby();
};