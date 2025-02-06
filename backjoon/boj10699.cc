#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main(void) {
    cout << put_time(
        [](time_t t) -> tm * { return localtime(&t); }(time(nullptr)),
        "%Y-%m-%d");
}
