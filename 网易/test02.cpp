#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    vector<int> r;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int ret = 0;
        bool flg = false; // ¼ÇÂ¼ÊÇ·ñÓÐ%
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '%') {
                if (flg) {
                    ret += 9;
                    flg = false;
                } else {
                    ret += 3;
                    flg = true;
                }
            } else if (flg && s[i] == 's') {
                ret += 3;
                flg = false;
            } else if (flg && s[i] == 'd') {
                ret += 4;
                flg = false;
            } else if (flg && s[i] == 'u') {
                ret += 5;
                flg = false;
            } else if (flg && s[i] == 'p') {
                ret += 6;
                flg = false;
            } else if (flg && s[i] == 'f') {
                ret += 7;
                flg = false;
            } else if (flg && s[i] >= '0' && s[i] <= '9') {
                ret += 8;
            } else {
                if(flg) {
                    ret += 9;
                    flg = false;
                }
                else {
                    ret+=3;
                }
            }
        }
        r.push_back(ret + 1);
    }
    for (int i = 0; i < r.size(); ++i) {
        cout << r[i];
        if (i != r.size() - 1) {
            cout << endl;
        }
    }
    return 0;
}