#include "wczytajIPrzefiltruj.hpp"
#include "Linia.hpp"
#include "kubelkowe.hpp"
#include "przezScalanie.hpp"
#include "quicksort.hpp"

using namespace std;

// g++ -O2 -std=c++11 -Wall "-Wl,--stack=268435456" main.cpp -o a.exe

int main() {
    //-------------------------
    //WYKONYWANE ZAWSZE
    int iloscWczytywanych = 200000;
    list<Linia> lista = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);
    // for (const auto& i : lista) {
    //     cout << i.indeks << " | " << i.film << " | " << i.rating << endl;
    // }
    //-------------------------

    //-------------------------
    //SORTOWANIE KUBELKOWE
    list<Linia> posortowanaLista = sortowanieKubelkowe(lista);
    // for (const auto& i : posortowanaLista) {
    //     cout << i.film << " | " << i.rating << endl;
    // }
    //-------------------------

    //-------------------------
    //SORTOWANIE PRZEZ SCALANIE
    Linia tabDoSPS[lista.size()];
    Linia temp[lista.size()];

    int k = 0;
    for (const auto& i : lista) {
        tabDoSPS[k] = i;
        k++;
    }

    auto start1 = high_resolution_clock::now();

    sortowaniePrzezScalanie(tabDoSPS, temp, 0, lista.size()-1);

    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "(Czas sortowania przez scalanie: "<< duration1.count() << " mikrosekund)" << endl;

    // for (int i = 0; i < lista.size(); i++) {
    //     cout << tabDoSPS[i].film << " | " << tabDoSPS[i].rating << endl;
    // }
    //-------------------------

    //-------------------------
    //QUICKSORT
    Linia* tabDoQS = new Linia[lista.size()];

    int j = 0;
    for (const auto& i : lista) {
        tabDoQS[j] = i;
        j++;
    }

    auto start2 = high_resolution_clock::now();

    quicksort(tabDoQS, 0, lista.size()-1);

    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "(Czas quicksort'a: "<< duration2.count() << " mikrosekund)" << endl;

    delete[] tabDoQS;

    // for (int i = 0; i < lista.size(); i++) {
    //     cout << tabDoQS[i].film << " | " << tabDoQS[i].rating << endl;
    // }
    //-------------------------

    return 0;
}
