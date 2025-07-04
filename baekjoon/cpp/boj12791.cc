#include <algorithm>
#include <iostream>
#include <vector>
#define fastIO cin.tie(0)->sync_with_stdio(0)
using namespace std;

vector<string> list[2017];

void precalc() {
    list[1967].push_back("DavidBowie");
    list[1969].push_back("SpaceOddity");
    list[1970].push_back("TheManWhoSoldTheWorld");
    list[1971].push_back("HunkyDory");
    list[1972].push_back("TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars");
    list[1973].push_back("AladdinSane");
    list[1973].push_back("PinUps");
    list[1974].push_back("DiamondDogs");
    list[1975].push_back("YoungAmericans");
    list[1976].push_back("StationToStation");
    list[1977].push_back("Low");
    list[1977].push_back("Heroes");
    list[1979].push_back("Lodger");
    list[1980].push_back("ScaryMonstersAndSuperCreeps");
    list[1983].push_back("LetsDance");
    list[1984].push_back("Tonight");
    list[1987].push_back("NeverLetMeDown");
    list[1993].push_back("BlackTieWhiteNoise");
    list[1995].push_back("1.Outside");
    list[1997].push_back("Earthling");
    list[1999].push_back("Hours");
    list[2002].push_back("Heathen");
    list[2003].push_back("Reality");
    list[2013].push_back("TheNextDay");
    list[2016].push_back("BlackStar");
}

int main() {
    fastIO;
    precalc();
    int q;
    cin >> q;
    while (q--) {
        int a, b, cnt = 0;
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            cnt += list[i].size();
        }
        cout << cnt << '\n';
        for (int i = a; i <= b; i++) {
            for (string &a : list[i]) {
                cout << i << ' ' << a << '\n';
            }
        }
    }
    return 0;
}