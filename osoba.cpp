#include <vector>
#include <string>
#include <iostream>

#include "osoba.h"

Osoba::Osoba(std::string i, std::string n)
{
    imie = i;
    nazwisko = n;
    klasa = "";
    telefon = "";
}

std::string Osoba::get_imie() const { return imie; };
std::string Osoba::get_nazwisko() const { return nazwisko; };
std::string Osoba::get_klasa() const { return klasa; };
std::string Osoba::get_telefon() const { return telefon; };

void Osoba::print() {
    std::cout << "<Osoba Imie=\"" << imie << "\" Nazwisko=\"" << nazwisko;/*  
        << "\" Telefon=\"" << telefon << "\" Klasa=\"" << klasa << "\" " 
        << ">"; */
}