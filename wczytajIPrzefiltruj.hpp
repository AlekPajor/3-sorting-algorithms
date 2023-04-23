#ifndef WIP_HPP
#define WIP_HPP
#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include "Linia.hpp"

using namespace std;
using namespace std::chrono;

list<Linia> wczytajIPrzefiltruj(string filename, int iloscLinii) {
    ifstream inputFile(filename);
    list<Linia> linie;
    auto start = high_resolution_clock::now();
    
    if(inputFile.is_open()) {

        string line;
        int counter = 0;
        while(getline(inputFile, line) && counter < iloscLinii) {
            
            stringstream s(line);
            string indeks;
            string film;
            string rating;
            float float_rating;

            getline(s, indeks, ',');
            getline(s, film, ',');
            getline(s, rating, ',');

            rating.pop_back();
            rating.pop_back();
            rating.pop_back();

            try
            {
                float_rating = stof(rating);
            }
            catch(const invalid_argument& ia)
            {
                continue;
            }

            linie.push_back({indeks, film, float_rating});
            counter++;
        }
    }
    inputFile.close();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "(Czas wczytywania i odfiltrowywania: "<< duration.count() << " mikrosekund)" << endl;

    return linie;
}

#endif