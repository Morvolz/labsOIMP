///Shapo4ka
#include <iostream>
#include <algorithm>

using namespace std;

using ll = long long;
using ld = long double;

const int N  = 1e6+52;

bool f(int** , int , int , int );


int main() {
    int n;
    while(true) {
        cout << "choose the size of your matrix: ";
        cin >> n;
        if (n > 10 || n <= 0) {
            cout << "size of matrix isn't correct :(\n";
            continue;
        }
        else break;
    }
    cout << "type matrix " << n << "*" << n << ":\n"; 
	int** a = new int* [n+2];
    for (int i = 0; i <= n+1; i++) {
        a[i] = new int[n+2];
    }

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) { 
            cin >> a[i][j];
        }
    }
    
    cout << "\n";
    cout << "---------\n";
    
    ll product = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
            if (j > n-i+1)  product *= ll(a[i][j]);
        }
    }
    cout << "---------\n";
    
    int mx = -1e9;
    pair<int, int> mxi;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (f(a, n, i, j) && a[i][j] > mx){
                mx = a[i][j];
                mxi = {i, j};
            }
        }
    }    
    cout << "\n";
    cout << "mx, mx_i, mx_j: " << mx << " " << mxi.first << " " << mxi.second << "\n";
    cout << "\n";
   
    cout << "product: " << product << "\n";
    return 0;
}

bool f(int** a, int n, int i, int j) {
    return (a[i][j] > a[i-1][j] && a[i][j] > a[i+1][j] 
        && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]
        && a[i][j] > a[i-1][j+1] && a[i][j] > a[i-1][j-1] 
        && a[i][j] > a[i+1][j+1] && a[i][j] > a[i+1][j-1]);
}