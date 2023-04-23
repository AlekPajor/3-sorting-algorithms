#include <iostream>
#include <list>
#include <cstring>
#include <cmath>
#include <chrono>
#include "wczytajIPrzefiltruj.hpp"

using namespace std; 

int iloscWczytywanych = 1000;

int main() {

    list<Linia> table = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);

    for (const auto& i : table)
        cout << i.film << " | " << i.rating << endl;

    return 0;
}