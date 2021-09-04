/*
907. 区间覆盖

给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出 ?1。

输入格式
第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。

第二行包含整数 N，表示给定区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。

如果无解，则输出 ?1。

数据范围
1≤N≤105,
?109≤ai≤bi≤109,
?109≤s≤t≤109
输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2


*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
int ll, rr;
struct Range{
    int l, r;
    bool operator < (const Range& w)const {
        return l < w.l;
    }
}range[N];


int main() {
    scanf("%d%d", &ll, &rr);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);
    int ed = ll;
    int tr = -2e9;
    int res = 0;
    bool suc = false;
    for(int i = 0; i < n; ++i) {
        if (range[i].l <= ed) {
            tr = max(tr, range[i].r);
            if (tr >= rr) {
                suc = true;
                res++;
                break;
            }
        }
        else {
            if (tr < ed) {
                break;
            }
            res++;
            ed = tr;
            --i;
        }
    }
    if (!suc) printf("%d\n", -1);
    else printf("%d\n", res);
    return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l, r;
    bool operator< (const Range &W)const
    {
        return l < W.l;
    }
}range[N];

int main()
{
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i ++ )
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j ++ ;
        }

        if (r < st)
        {
            res = -1;
            break;
        }

        res ++ ;
        if (r >= ed)
        {
            success = true;
            break;
        }

        st = r;
        i = j - 1; 
    }

    if (!success) res = -1;
    printf("%d\n", res);

    return 0;
}



*/
