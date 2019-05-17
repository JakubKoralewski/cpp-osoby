#include <vector>
#include <string>
#include <iostream>

#include "lista.h"
#include "osoba.h"

void print_title(std::string title) {
    system("CLS");
    std::cout << title << std::endl << std::endl;
}

std::string input_imie() {
    std::string imie;
    std::cout << "Podaj imie:" << std::endl;
    std::cin >> imie;
    return imie;
}
std::string input_nazwisko() {
    std::string nazwisko;
    std::cout << "Podaj nazwisko:" << std::endl;
    std::cin >> nazwisko;
    return nazwisko;
}

void dodaj_osobe(Lista lista) {
    print_title("DODAWANIE POJEDYNCZEJ OSOBY");
    
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    Osoba osoba(imie, nazwisko);

    lista.dodaj_osobe(osoba);

    system("PAUSE");
}

void usun_osobe(Lista lista) {
    print_title("USUWANIE POJEDYNCZEJ OSOBY");
    
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    lista.usun_osobe(imie, nazwisko);

    system("PAUSE");
}

void wypisz_osobe(Lista lista) {
    print_title("WYPISANIE POJEDYNCZEJ OSOBY");
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    lista.wypisz_osobe(imie, nazwisko);

    system("PAUSE");
}

void wypisz_osoby(Lista lista) {
    print_title("WYPISANIE WSZYSTKICH OSÓB");

    lista.wypisz_osoby();

    system("PAUSE");
}

void wyczysc_liste(Lista lista) {
    print_title("WYCZYSZCZENIE LISTY");

    lista.wyczysc_liste();

    system("PAUSE");
}

int main()
{

    Lista lista;
    
    while(1) {
        system("CLS");
        std::cout<<"-------- ZARZĄDZANIE OSOBAMI ---------" << std::endl;
        std::cout<<"1. DODAJ OSOBĘ" << std::endl;
        std::cout<<"2. USUŃ OSOBĘ" << std::endl;
        std::cout<<"3. WYPISZ OSOBĘ" << std::endl;
        std::cout<<"4. WYPISZ OSOBY" << std::endl;
        std::cout<<"5. WYCZYŚĆ LISTĘ" << std::endl;
        std::cout<<"0. WYJDŹ" << std::endl;

        int input;

        std::cin >> input;

        bool should_exit = false;

        switch (input) {
            case 0: {
                should_exit = true;
                break;
            }
            case 1: {
                dodaj_osobe(lista);
                break;
            }
            case 2: {
                usun_osobe(lista);
                break;
            }
            case 3: {
                wypisz_osobe(lista);
                break;
            }
            case 4: {
                wypisz_osoby(lista);
                break;
            }
            case 5: {
                wyczysc_liste(lista);
                break;
            }
        }

        if (should_exit) break;
    }

    return 0;
}