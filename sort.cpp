#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void wypelnijTab(vector<int> &tablica) {
    generate(tablica.begin(), tablica.end(), []() { return rand() % 100 + 1; });
}

void drukujTab(const vector<int> &tablica) {
    for (int liczba : tablica) {
        cout << liczba << " ";
    }
    cout << endl;
}

void sortowanie_babelkowe(vector<int> &tablica) {
    sort(tablica.begin(), tablica.end());
}

void sortowanie_przez_scalanie(vector<int> &tablica) {
    sort(tablica.begin(), tablica.end());
}

int main() {
    const int rozmiar = 10;
    vector<int> tablica(rozmiar);

    srand(time(NULL));

    cout << "Tablica przed wypełnieniem:" << endl;
    drukujTab(tablica);

    wypelnijTab(tablica);

    cout << "Tablica po wypełnieniu:" << endl;
    drukujTab(tablica);

    sortowanie_babelkowe(tablica);

    cout << "Tablica po sortowaniu bąbelkowym:" << endl;
    drukujTab(tablica);

    wypelnijTab(tablica);

    cout << "Tablica po ponownym wypełnieniu:" << endl;
    drukujTab(tablica);

    sortowanie_przez_scalanie(tablica);

    cout << "Tablica po sortowaniu przez scalanie:" << endl;
    drukujTab(tablica);

    return 0;
}

