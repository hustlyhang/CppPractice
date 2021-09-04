#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
// ÓÃ×Ö·û´®±£´æ×´Ì¬
int bfs(string stat) {
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(stat);
    d[stat] = 0;
    int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
    while (q.size()) {
        auto k = q.front();
        q.pop();
        int dist = d[k];
        cout<<k.c_str()<<endl;
        if (k == end) return dist;

        int p = k.find('x');
        cout<<p<<endl;
        int x = p / 3, y = p % 3;
        for (int i = 0; i < 4; ++i) {
            int xt = dx[i] + x, yt = dy[i] + y;
            if (xt >= 0 && xt < 3 && yt >= 0 && yt < 3) {
                swap(k[p], k[xt * 3 + yt]);
                if (!d.count(k)) {
                    d[k] = dist + 1;
                    q.push(k);
                }
                swap(k[p], k[xt * 3 + yt]);
            }
        }
    }
    return -1;
}

int main() {
    string stat;
    for (int i = 0; i < 9; ++i) {
        char c;
        cin>>c;
        stat += c;
    }
    printf("%s", stat.c_str());
    cout<<bfs(stat)<<endl;
}