///Shapo4ka
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N  = 1e5+52;


int main() {

    ld x = 0.1;
    int k = 5;
    
    cin >> x >> k;
    ld ans = x;
    for (ld i = 2 ; i < N; i++) {
        x *= x;
        if (int(i) % 2 == 0) ans -= (x)/i;
        else ans += (x)/i;
        if (x < pow(10, -k)) break;
    }       
    cout << setprecision(5);
    cout << ans << "\n";
    return 0;
}