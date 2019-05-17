#include <vector>
#include <string>
#include <iostream>
#include <locale>


#include "lista.h"

void print_title(std::string title) {
    system("CLS");
    std::cout << title << std::endl << std::endl;
}

std::string input_imie() {
    std::string imie;
    std::cout << "Podaj imi©:" << std::endl;
    std::cin >> imie;
    return imie;
}
std::string input_nazwisko() {
    std::string nazwisko;
    std::cout << "Podaj nazwisko:" << std::endl;
    std::cin >> nazwisko;
    return nazwisko;
}


void dodaj_osobe(Lista& lista) {
    print_title("DODAWANIE POJEDYNCZEJ OSOBY");
    
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    Osoba osoba(imie, nazwisko);

    lista.dodaj_osobe(osoba);
}

void usun_osobe(Lista& lista) {
    print_title("USUWANIE POJEDYNCZEJ OSOBY");
    
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    lista.usun_osobe(imie, nazwisko);
}

void wypisz_osobe(Lista& lista) {
    print_title("WYPISANIE POJEDYNCZEJ OSOBY");
    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    lista.wypisz_osobe(imie, nazwisko);

    system("PAUSE");
}

void wypisz_osoby(Lista& lista) {
    print_title("WYPISANIE WSZYSTKICH OS‡B");

    lista.wypisz_osoby();

    system("PAUSE");
}

void wyczysc_liste(Lista& lista) {
    print_title("WYCZYSZCZENIE LISTY");

    std::string odp;
    std::cout << "Na pewno chcesz to zrobiÜ (N\\y)?" << std::endl;
    std::cin >> odp;
    if (odp == "y") {
        lista.wyczysc_liste();
        std::cout << "Usuni©to wszystkich uczni¢w!" << std::endl;

        system("PAUSE");
    } 
}

void zmodyfikuj_osobe(Lista& lista) {
    print_title("ZMODYFIKUJ OSOB®\nNajpierw znajd´my osob©.");

    std::string imie = input_imie();
    std::string nazwisko = input_nazwisko();

    if (!lista.czy_osoba_istnieje(imie, nazwisko)) {
        std::cout << "Niepoprawne dane." << std::endl;

        system("PAUSE");
        return;
    }

    system("cls");

    Osoba os = lista.ostatnio_znaleziona();

    std::cout << "Znaleziono tak• osob©:" << std::endl;

    os.print();
    
    std::cout << "\n\nJeòli to ta osoba podaj, co chcesz zmieniÜ (np. \"telefon\"). Uæywaj maàych liter." 
        << std::endl << "Wpisz cokolwiek innego, aby wr¢ciÜ do MENU." << std::endl;
    
    std::string property;
    std::cin >> property;
    
    if (property != "imie" && property != "imi©" && property != "nazwisko" && property != "klasa" && property != "telefon") {
        std::cout << "Niepoprawna wartoòÜ. Jedna z: \"imi©\", \"nazwisko\", \"klasa\", \"telefon\"!\nChcesz spr¢bowaÜ raz jeszcze (N\\y)?";
        std::string try_again;
        std::cin >> try_again;
        if (try_again == "y") {
            zmodyfikuj_osobe(lista);
        } else {
            return;
        }
    } 
    std::string nowa_wartosc;
    std::cout << "Podaj now• wartoòÜ wàaòciwoòci \""<< property << "\":" << std::endl;
    std::cin >> nowa_wartosc;

    os = lista.set_prop_on_last(property, nowa_wartosc);

    system("cls");

    std::cout << "Zmieniona osoba:" << std::endl;
    lista.ostatnio_znaleziona().print();

    system("PAUSE");
}

int main()
{
    Lista lista;
    
    while(1) {
        system("CLS");
        std::cout<<"-------- ZARZ§DZANIE OSOBAMI ---------" << std::endl;
        std::cout<<"1. DODAJ OSOB®" << std::endl;
        std::cout<<"2. USU„ OSOB®" << std::endl;
        std::cout<<"3. WYPISZ OSOB®" << std::endl;
        std::cout<<"4. WYPISZ OSOBY" << std::endl;
        std::cout<<"5. WYCZYóè LIST®" << std::endl;
        std::cout<<"6. ZMODYFIKUJ OSOB®" << std::endl;
        std::cout<<"0. WYJDç\n" << std::endl;

        int input;

        while (std::cout << "Podaj numer: " && !(std::cin >> input)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "To nie liczba. Spr¢buj ponownie.\n";
        }

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
            case 6: {
                zmodyfikuj_osobe(lista);
                break;
            }
        }

        if (should_exit) break;
    }

    return 0;
}