#ifndef QS_HPP
#define QS_HPP
#include<iostream>
#include"Linia.hpp"

using namespace std;

void quicksort(Linia *tab, int lewy, int prawy)
{
	if(prawy <= lewy) return;
    
	int i = lewy - 1;
    int j = prawy + 1; 
	int pivot = tab[(lewy+prawy)/2].rating;

	while(true)
	{
		while(pivot>tab[++i].rating);
		while(pivot<tab[--j].rating);

		if( i <= j)
			swap(tab[i],tab[j]);
		else
			break;
	}

	if(j > lewy)
	    quicksort(tab, lewy, j);
	if(i < prawy)
	    quicksort(tab, i, prawy);
}

#endif