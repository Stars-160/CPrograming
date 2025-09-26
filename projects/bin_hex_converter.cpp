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

string hex_conv(deque<int> in) {
    deque<int> bin = in;
    int i;
    int temp;
    int sum = 0;
    string out = "0x";
    if (size(bin) % 4 != 0) {
        while (size(bin) % 4 != 0) {
            bin.push_front(0);
        }
    }
    for (i = 0; i <= (size(bin) - 1); i++) {
        temp = 3 - (i % 4);
        if (temp == 3) {
            sum = 0;
        }
        if (bin.at(i) == 1) {
            sum = sum + pow(2, temp);
        }
        if (temp == 0) {
            out = out + to_string(sum);
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

    string hex = hex_conv(bin);
    cout << "Hexidecimal: " << hex << endl;
    
    return 0;
}