#include "wczytajIPrzefiltruj.hpp"
#include "Linia.hpp"
#include "kubelkowe.hpp"

using namespace std;
using namespace std::chrono;

int main() {

    int iloscWczytywanych = 1000;
    list<Linia> lista = wczytajIPrzefiltruj("projekt2_dane.csv", iloscWczytywanych);
    list<Linia> posortowanaLista = sortowanieKubelkowe(lista);

    for (const auto& i : posortowanaLista) {
        cout << i.film << " | " << i.rating << endl;
    }

    return 0;
}