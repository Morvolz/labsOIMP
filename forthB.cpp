///Shapo4ka
#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm> 
#include <ncurses.h>
// #include <bits/stdc++.h>
#define  pb push_back

using namespace std;

using ll = long long;
using ld = long double;

char ans[305], s[305];
bool p[150];

int main() {

    int cnt = 0;
    int i = 0;
    int sz = 300;
    while(true) {
        s[i] = char(getchar());
        if (s[i] == 10) {  /// enter
            break;
        } 
        if (s[i] == ' ') {
            s[i] = '\0';
            int x = 0;
            for (int j = 0; j < 150; j++) {
                x += p[j];
                p[j] = 0;
            }
            if (x > cnt) {
                for (int j = 0; j < i; j++) {
                    ans[j] = s[j];
                }
                ans[i] = '\0';
                cnt = x;
            }
            i = 0;
            continue;
        }
        p[int(s[i])] = 1;
        i++;
    }
    cout << "\n";


    s[i] = '\0';
    int x = 0;
    for (int j = 0; j < 150; j++) {
        x += p[j];
        p[j] = 0;
    }
    if (x > cnt) {
        cnt = x;
        for (int j = 0; j < i; j++) {
            ans[j] = s[j];
        }
        ans[i] = '\0';
    }

    cout << cnt << "\n";
    cout << ans << "\n";
    return 0;
}
