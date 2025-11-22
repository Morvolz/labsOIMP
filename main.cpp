#include <bits/stdc++.h> 
#include "Fraction.h"

using namespace  std;

void razdel() {
    cout << "\n----------------\n\n";
}

int main() {
    Fraction FR(5, 3);
    Fraction FR_copy = Fraction(FR);
    FR_copy.print();

    razdel();
    Fraction FR1(-5, 10); 
    Fraction FR2(5, -10); 
    Fraction FR3(-1, -4);
    FR1.print(), FR2.print(), FR3.print();
    
    razdel();
    FR = FR.multiply(FR1);
    FR.print();
    FR = Fraction(FR_copy);

    FR = FR.divide(FR2);
    FR.print();
    FR = Fraction(FR_copy);

    FR = FR.add(FR3);
    FR.print();
    FR = Fraction(FR_copy);
    return 0;
}