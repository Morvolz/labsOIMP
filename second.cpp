///Shapo4ka
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N  = 1e5+52;


int a[N];
int n; 

int main() {
    srand(time(0));
    cout << "Would you like to print the numbers by yourself or you would you like the PC to do it ? [Y/n] ";
    char type;
    cin >> type;
    if (type == 'Y') {
        cout << "n: ";
        cin >> n;
        cout << "a[1...n]: ";
        for (int i = 0; i < n; i++) cin >> a[i];
    }
    else {
        int l, r;
        cout << "Enter 3 numbers(length of array and array number range): ";
        cin >> n >> l >> r;
        for (int i = 0; i < n; i++) {
            a[i] = l + rand() % (r - l + 1);
            cout << a[i] << " \n" [i == n-1];
        }
    }

    int ans = 0, cnt = 0, l = 0, r = n-1;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < 0 && a[i+1] >= 0) ans++;
        if (a[i] >= 0 && a[i+1] < 0) ans++;
        if (a[i] == 0) {
            cnt++;
            if (cnt == 1) l = i;
            if (cnt == 2) r = i;
        }
    }
    cout << "Number of character changes: " << ans << "\n";

    ll product = 1;
    for (int i = l+1; i < r; i++) product *= a[i];
    cout << "Product: " << product << "\n";

    cout << "New array: \n";
    for (int i =  0; i < n; i++) {
        if (abs(a[i]) % 2 == 0) cout << a[i] << " ";
    }
    for (int i =  0; i < n; i++) {
        if (abs(a[i]) % 2 == 1) cout << a[i] << " ";
    }
    cout << "\n";


    return 0;
}