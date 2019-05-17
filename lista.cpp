#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "lista.h"
#include "osoba.h"

int Lista::znajdz_index_osoby(std::string imie, std::string nazwisko) {
    for(int i = 0; i != lista.size(); i++) {
        Osoba os = lista[i];
        if (os.get_imie() == imie && os.get_nazwisko() == nazwisko) {
            return i;
        }
    }
}

void Lista::dodaj_osobe(Osoba os) {
    lista.push_back(os);
}

void Lista::usun_osobe(std::string imie, std::string nazwisko) {
    for(std::vector<Osoba>::size_type i = 0; i != lista.size(); i++) {
        Osoba os = lista[i];
        if (os.get_imie() == imie && os.get_nazwisko() == nazwisko) {
            lista.erase(lista.begin() + i);
        }
    }
}

void Lista::posortuj_liste() {
    std::sort(lista.begin(), lista.end());
}

void Lista::wypisz_liste() {
    std::cout << "Osoby: " << std::endl;
    for(Osoba& os : lista) {
        os.print();
        std::cout << ",";
    }
}

Osoba Lista::znajdz_osobe(std::string imie, std::string nazwisko) {
    for(std::vector<Osoba>::size_type i = 0; i != lista.size(); i++) {
        Osoba os = lista[i];
        if (os.get_imie() == imie && os.get_nazwisko() == nazwisko) {
            return os;
        }
    }
}


void Lista::wypisz_osoby() {
    for(Osoba& os : lista) {
        os.print();
        std::cout << ",";
    }
}

void Lista::wypisz_osobe(std::string imie, std::string nazwisko) {
    Osoba osoba = znajdz_osobe(imie, nazwisko);
    osoba.print();
}

void Lista::wyczysc_liste() {
    lista.erase(lista.begin(), lista.end());
}