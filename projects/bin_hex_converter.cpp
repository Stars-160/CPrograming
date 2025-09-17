#include <iostream>
#include <cmath>
#include <deque>
#include <string>
//int for bin and strings for hex.
using namespace std;

deque<int> bin_conv(int dec){
    int in = dec;
    bool exit = 1;
    int temp;
    deque<int> out;
    while (exit != 0){
        temp = in % 2;
        out.push_front(temp);
        in = (in - temp) / 2;
        if (in == 0) {
            exit = 0;
        }
    }
    return out;
}

int main(void) {
    int dec;

    cout << "Input your decimal number: ";
    cin >> dec;

    deque<int> bin = bin_conv(dec);

    cout << "Decimal: " << dec << endl;
    cout << "Binary: ";
    for (int index : bin) {
        cout << index;
    }
    cout << endl;

    return 0;
}