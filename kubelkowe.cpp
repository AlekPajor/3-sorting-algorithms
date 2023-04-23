#include <iostream>
#include <list>
#include <cstring>
#include <cmath>
#include <chrono>
#include "wczytajIPrzefiltruj.hpp"

using namespace std; 

int iloscWczytywanych = 1000;

list<Linia> sortowanieKubelkowe(list<Linia> lista) {
    list<Linia> table[10];
    list<Linia> lista2;
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
    lista2.reverse(); 
    //just because im to lazy to change all numbers in switch case, it was supoosed to be Highest->Lowest

    return lista2;
} 

int main() {

    list<Linia> lista = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);

    list<Linia> posortowanaLista = sortowanieKubelkowe(lista);

    for (const auto& i : posortowanaLista) {
        cout << i.film << " | " << i.rating << endl;
    }

    return 0;
}