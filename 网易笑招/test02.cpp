#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 输入多个城市之间的距离，返回到其他城市最近的城市的标号，如果无法从这几个城市之间选出满足条件的城市，那么返回-1。
     * @param distancePairs int整型vector<vector<>> 二维数组，每个子数组都是三个整数组成的，前两个整数代表城市的标号，第三个整数代表两个城市的距离
     * @param CityNum int整型 城市的数量，每个城市的标号分别是0~CityNum-1
     * @return int整型
     */
    long long dij(vector<vector<int>>& distance, vector<bool>& isV, vector<int>& dis, int start) {
        int n = isV.size();
        for (int i = 0; i < n; ++i) {
            int m = -1, mm = INT_MAX;
            for (int j = 0; j < n; ++j) {
                if (isV[j] == false && dis[j] < mm) {
                    mm = dis[j];
                    m = j;
                }
            }
            if (m == -1) return -1;
            else {
                isV[m] = true;
            }
            for (int k = 0; k < n; ++k) {
                if (isV[k] == false && distance[m][k] != INT_MAX && dis[m] + distance[m][k] < dis[k]) {
                    dis[k] = dis[m] + distance[m][k];
                }
            }
        }
        long long ret = 0;
        for (int i = 0; i < n; ++i) {
            ret+=dis[i];
        }
        return ret;
    }

    int GetBestWarehouseLocate(vector<vector<int> >& distancePairs, int CityNum) {
        // write code here
        vector<vector<int>> distance(CityNum, vector<int>(CityNum,INT_MAX));
        for (int i = 0; i < distancePairs.size(); ++i) {
            distance[distancePairs[i][0]][distancePairs[i][1]] = distancePairs[i][2];
            distance[distancePairs[i][1]][distancePairs[i][0]] = distancePairs[i][2];
        }

        vector<bool> isV(CityNum, false);
        vector<int> dis(CityNum, INT_MAX);
        
        long long ret = INT_MAX;

        int rr = 0;
        for (int i = 0; i < CityNum; ++i) {
            dis.assign(CityNum, INT_MAX);
            isV.assign(CityNum, false);
            dis[i] = 0;
            long long e = dij(distance, isV, dis, i);
            if (e == -1) continue;
            if (e < ret) {
                ret = e;
                rr = i;
            }
        }
        return (int)ret;
    }
};


int main() {
    vector<vector<int>> distancePairs{{0, 1, 3}, {1, 2, 2}};
    int city = 3;
    Solution s;
    s.GetBestWarehouseLocate(distancePairs,city);

}