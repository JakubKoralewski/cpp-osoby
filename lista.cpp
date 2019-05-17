#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#include "lista.h"
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
    posortuj_liste();
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

bool Lista::czy_osoba_istnieje(std::string imie, std::string nazwisko) {
    for(std::vector<Osoba>::size_type i = 0; i != lista.size(); i++) {
        Osoba os = lista[i];
        if (os.get_imie() == imie && os.get_nazwisko() == nazwisko) {
            ostatnio_znaleziony_index = i;
            return true;
        }
    }
    return false;
}


void Lista::wypisz_osoby() {
    std::size_t lista_size = lista.size();
    for(std::size_t i=0; i<lista_size; i++) {
        Osoba os = lista[i];
        bool is_last = i == lista_size - 1;
        os.print();
        std::cout << (!is_last ? ",\n" : "\n");
    }
}

Osoba Lista::set_prop_on_last(std::string property, std::string wartosc) {
    Osoba* os = &lista[ostatnio_znaleziony_index];

    if (property == "imię" || property == "imie") {
        os->set_imie(wartosc);
    } else if (property == "nazwisko") {
        os->set_nazwisko(wartosc);
    } else if (property == "klasa") {
        os->set_klasa(wartosc);
    } else if (property == "telefon") {
        os->set_telefon(wartosc);
    }

    return *os;
}

void Lista::wypisz_osobe(std::string imie, std::string nazwisko) {
    if(czy_osoba_istnieje(imie, nazwisko)) {
        ostatnio_znaleziona().print();
    } else {
        std::cout << "Nie znaleziono takiej osoby!"<<std::endl;
    }
}

Osoba Lista::ostatnio_znaleziona() {
    return lista[ostatnio_znaleziony_index];
}

void Lista::wyczysc_liste() {
    lista.erase(lista.begin(), lista.end());
}