#include "wczytajIPrzefiltruj.hpp"
#include "Linia.hpp"
#include "kubelkowe.hpp"
#include "przezScalanie.hpp"

using namespace std;

int main() {
    //-------------------------
    //WYKONYWANE ZAWSZE
    int iloscWczytywanych = 1000;
    list<Linia> lista = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);
    //-------------------------
    
    //-------------------------
    //SORTOWANIE KUBELKOWE
    // list<Linia> posortowanaLista = sortowanieKubelkowe(lista);
    // for (const auto& i : tabDoSPS) {
    //     cout << i.film << " | " << i.rating << endl;
    // }
    //-------------------------

    //-------------------------
    //SORTOWANIE PRZEZ SCALANIE
    Linia tabDoSPS[lista.size()];
    Linia temp[lista.size()];

    int j = 0;
    for (const auto& i : lista) {
        tabDoSPS[j] = i;
        j++;
    }

    auto start = high_resolution_clock::now();

    sortowaniePrzezScalanie(tabDoSPS, temp, 0, lista.size()-1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "(Czas sortowania przez scalanie: "<< duration.count() << " mikrosekund)" << endl;

    for (int i = 0; i < lista.size(); i++) {
        cout << tabDoSPS[i].film << " | " << tabDoSPS[i].rating << endl;
    }
    //-------------------------

    return 0;
}