///Shapo4ka
#include <bits/stdc++.h>
#define  pb push_back

using namespace std;

using ll = long long;
using ld = long double;


int main() {

    cout << "type name of inputfile: ";
    string inputname = "input.txt";
    cin >> inputname;
    
    cout << "type name of first outputfile: ";
    string output1name = "output.txt";
    cin >> output1name;
    
    cout << "type name of second outputfile: ";
    string output2name = "output2.txt";
    cin >> output2name;
    
    ifstream in(inputname);
    ofstream out1(output1name);
    ofstream out2(output2name);

    cout << "Do you want to see inputfile content [Y/n]: ";
    string WOF;
    cin >> WOF;

    vector <string> lines;
    string str;
    while (getline(in, str) ) {
        lines.push_back(str);
    }

    if (WOF == "Y" || WOF == "y") {
        cout << "\n\n-----------\n";
        for (auto str: lines) {
            cout << str << "\n";
        }    
        cout << "-----------\n";
    }

    vector<string> strings;
    for (auto line : lines) {
        line += " ";
        string str = "";
        for (auto ch : line) {
            if (ch == ' ') {
                strings.push_back(str);
                str = "";
                continue;
            }
            str += ch;
        }
    }

    for (auto str : strings) {
        int sz = str.size(); 
        bool f = 0;
        for (int i = 0; i < sz / 2; i++) {
            if (str[i] != str[sz - i - 1]) {
                f = 1;
                break;
            }
        }
        if (f == 0)  
            out1 << str << "\n";
    }

    for (auto str : strings) {
        char ch = str[0];
        bool f = 0;
        for (auto c : str) {
            if (c != ch) {
                f = 1;
                break;
            }
        }
        if (f == 0) 
            out2 << str << "\n";
    }


    return 0;
}
