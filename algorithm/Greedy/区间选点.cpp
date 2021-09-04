/*
905. 区间选点

给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。

输出选择的点的最小数量。

位于区间端点上的点也算作区间内。


输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需的点的最小数量。

数据范围
1≤N≤105,
109≤ai≤bi≤109

输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/ 

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range{
    int l, r;
    bool operator < (const Range& w) const {
        return r < w.r;
    }
}range[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);
    int res = 0, ed = -2e9;

    for (int i = 0; i < n; ++i) {
        // 刚开始时，选一个左端点，然后更新ed，如果下一段的左端点小于等于ed那么说明有重合，不用管
        // 如果大于的话说明是新的一段，需要res++，而且更新ed
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }
    }
    printf("%d\n", res);
    return 0;
}