/*
906. 区间分组

给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

数据范围
1≤N≤105,
?109≤ai≤bi≤109
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/

// 将所有区间按照左端点从小到大排序
// 从前往后处理每个区间，判断能否将其放到某个现有的组中l[i] > max_r
// 如果不存在这样的组，就开新组，将其放进去
// 存在这样的组，将其放进去，并更新当前的max_r

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n;
struct Range{
    int l, r;
    bool operator < (const Range& w)const {
        return l < w.l;
    }
}range[N];


int main() {
    cin >>n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin>>l>>r;
        range[i] = {l, r};
    }

    sort(range, range + n);
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 0; i < n; ++i) {
        auto r = range[i];
        if (q.empty() || q.top() >= r.l) q.push(r.r);// 说明没有可以容纳当前区间的分组，需要新开一个分组
        else {
            // 更新堆顶
            q.pop();
            q.push(r.r);
        }
    }
    // 堆的大小就代表了有多少个区间
    printf("%d\n", q.size());
    return 0;
}
