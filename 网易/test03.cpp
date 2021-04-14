#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<string>> str;
    vector<string> tmp;
    int n = 0;
    cin >> n;
    while (n--) {
        char c = 'a';
        string s;
        while (c != '\n') {
            c = getc(stdin);
            if (c == ' ' || c == '\n') {
                tmp.push_back(s);
                s.clear();
            }
            else if (c != '\n'){
                s += c;
            }
        }
        str.push_back(tmp);
    }
    for(auto v : str) {
        for (auto s : v) {
            cout<<s<<' ';
        }
        cout<<endl;
    }

    // string s;

    return 0;
}