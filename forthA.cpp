///Shapo4ka
#include <iostream>
#include <iomanip>
#include <algorithm> 

#define  pb push_back

using namespace std;

using ll = long long;
using ld = long double;




char* itoa(int val, int radix) {
    char* s = new char[305];
    int i = 0;
    if (val == 0) {
        s[i++] = '0';
    }

    bool negative = 0;
    if (val < 0) {
        negative = 1;
        val = -val;
    }

    while(val != 0) {
        int x = val % radix;
        s[i++] = (x > 9) ? (x - 10) + 'A' : x + '0';
        val /= radix;
    }
    if (negative == 1) s[i++] = '-';
    reverse(s, s + i);
    s[i] = '\0';    
    return s;
}   

int main() {

    int val, radix;
    cout << "value, radix: ";
    cin >> val >>  radix;
    cout << itoa(val, radix) << "\n";
    return 0;
}
