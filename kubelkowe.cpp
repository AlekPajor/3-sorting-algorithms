#include <iostream>
#include <list>
#include <cstring>
#include <cmath>
#include <chrono>
#include "wczytajIPrzefiltruj.hpp"

using namespace std; 

int iloscWczytywanych = 100;

int main() {
    
    list<Linia> table = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);

    for (const auto& i : table)
        cout << i.film << " | " << i.rating << std::endl;



    // table[0].push_back(10);
    // table[0].push_back(20);
    // table[0].push_back(30);
    // table[0].push_back(40);
    // table[0].push_back(10);
    // table[0].push_back(20);
    // table[0].push_back(90);

    // for(auto i = table[0].begin(); i != table[0].end(); i++) {
    //     cout<<*i;
    // }
    return 0;
}