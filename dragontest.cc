#include <iostream>
using namespace std;

void curve(const string& seed, int generations) {
    if (generations == 0) {
        cout << seed;
        return;
    }
    for (int i = 0; i < seed.size(); i++) {
        if(seed[i] == 'X') curve("X+YF", generations - 1);
        else if(seed[i] == 'Y') curve("FX-Y", generations - 1);
        else cout << seed[i];
    }
}

int main() {
    int gene;
    cin >> gene;
    curve("FX", gene);
    cout << endl;
}