#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Osoba {
private:
    std::string imie, nazwisko, klasa, telefon;

public:
    Osoba(std::string i, std::string n);

    std::string get_imie() const;
    std::string get_nazwisko() const;
    std::string get_klasa() const;
    std::string get_telefon() const;

    void print();
};

inline bool operator< (const Osoba & os1, const Osoba & os2) {
    unsigned int min_chars = std::min(os1.get_nazwisko().length(), os2.get_nazwisko().length());
    
    for(unsigned i = 0; i < min_chars; i++) {
        if (os1.get_nazwisko()[i] < os2.get_nazwisko()[i]) {
            return true;
        } else if (os1.get_nazwisko()[i] > os2.get_nazwisko()[i]) {
            return false;
        }
    }
    
    /* Są takie same! */
    return false;
}