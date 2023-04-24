#ifndef SPS_HPP
#define SPS_HPP
#include <iostream>
#include <list>
#include "Linia.hpp"

using namespace std;

void scal(Linia tab[], Linia temp[], int lewy, int srodek, int prawy)  {
    
    int i, j;
    for(i = srodek + 1; i>lewy; i--) {
        temp[i-1] = tab[i-1];
    }
     
    for(j = srodek; j<prawy; j++) {
        temp[prawy+srodek-j] = tab[j+1]; 
    }

    for(int k=lewy;k<=prawy;k++) {
        if(temp[j].rating < temp[i].rating)
            tab[k] = temp[j--];
        else
            tab[k] = temp[i++];
    }
}

void sortowaniePrzezScalanie(Linia tab[], Linia temp[], int lewy, int prawy) {
    if(prawy<=lewy) {
        return;
    } 

	int srodek = (prawy+lewy)/2;
	sortowaniePrzezScalanie(tab, temp, lewy, srodek); 
	sortowaniePrzezScalanie(tab, temp, srodek+1, prawy);
	scal(tab, temp, lewy, srodek, prawy);
}

#endif