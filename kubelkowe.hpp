#ifndef SK_HPP
#define SK_HPP
#include <iostream>
#include <list>
#include <cstring>
#include <cmath>
#include <chrono>
#include "Linia.hpp"

using namespace std;
using namespace std::chrono;

int iloscWczytywanych = 1000;

list<Linia> sortowanieKubelkowe(list<Linia> lista) {
    list<Linia> table[10];
    list<Linia> lista2;
    auto start = high_resolution_clock::now();

    for (const auto& i : lista) {
        int f = static_cast<int>(i.rating);
        switch(f) {
        case 1:
            table[0].push_back(i);
            break;
        case 2:
            table[1].push_back(i);
            break;
        case 3:
            table[2].push_back(i);
            break;
        case 4:
            table[3].push_back(i);
            break;
        case 5:
            table[4].push_back(i);
            break;
        case 6:
            table[5].push_back(i);
            break;
        case 7:
            table[6].push_back(i);
            break;
        case 8:
            table[7].push_back(i);
            break;
        case 9:
            table[8].push_back(i);
            break;
        case 10:
            table[9].push_back(i);
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        auto iterator = table[i].begin();
        for(; iterator != table[i].end(); iterator++) {
            lista2.emplace_back(*iterator);
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "(Czas sortowania kubelkowego: "<< duration.count() << " mikrosekund)" << endl;

    return lista2;
} 

#endif