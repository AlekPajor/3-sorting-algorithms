#ifndef WIP_HPP
#define WIP_HPP
#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Linia {
    string indeks;
    string film;
    string rating;
};

list<Linia> wczytajIPrzefiltruj(string filename, int iloscLinii) {
    ifstream inputFile(filename);
    list<Linia> linie;
    
    if(inputFile.is_open()) {

        string line;
        int counter = 0;
        while(getline(inputFile, line) && counter < iloscLinii) {
            
            stringstream s(line);
            string indeks;
            string film;
            string rating;

            getline(s, indeks, ',');
            getline(s, film, ',');
            getline(s, rating, ',');

            rating.pop_back();
            rating.pop_back();
            rating.pop_back();

            linie.push_back({indeks, film, rating});
            counter++;
        }
    }
    inputFile.close();
    return linie;
}

#endif