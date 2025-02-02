#include <iostream>
using namespace std;

void print(int p) {
	int r = p % 6;
	if (r == 1 || r == 5) cout << 'F';
	else if (r == 2) cout << 'X';
	else if (r == 4) cout << 'Y';
	else if (r == 3) {
		if (p % 12 == 3) cout << '+';
		else cout << '-';
	} else print(p / 2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int C, n, p, l;
	cin >> C;
	while (C--) {
        cin >> n >> p >> l;
		for (int i = 0; i < l; i++)
			print(p + i);
		cout << endl;
	}
}