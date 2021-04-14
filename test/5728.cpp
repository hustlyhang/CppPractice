#include <queue>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int fst = 0, sec = 0, thr = 0; // 分别记录三条赛道可以前进多少距离
        vector<int> ob(4, 0); // 记录 三条赛道在青蛙位置之后最近的障碍位置
        int cur = 2; // 记录青蛙当前赛道
        int ret = 0;
        /*
          每一次青蛙跳，选择ob中最远的阻碍， 同时青蛙当前位置该赛道无阻碍物， 跳了之后更新ob
        */
        
        //利用map来储存最近障碍
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        for (int i = 0; i < obstacles.size(); ++i) {
            if (obstacles[i] != 0){
                m[obstacles[i]].push(i);
            }
        }
        for (int i = 1; i < 4; ++i) {
            if (m.count(i) == 0) {
                if(i == 2) return 0;
                else return 1;
            }
        }
        
        
        int i = 0; //记录青蛙当前的位置
        while (i < obstacles.size() - 1) {
            // 青蛙选择赛道
            
            int tmp = 0, dis = 0;
            for (auto d : m) {
                int td = 0;
                if (d.second.empty()) {
                    td = obstacles.size() - i;
                    //cout<<"is empty"<<endl;
                }
                else{
                    td = d.second.top() - i;
                }
                
                if (td > dis && obstacles[i] != d.first) {
                    dis = td;
                    tmp = d.first;
                }
            }
            
            if (tmp != cur) {
                ret++;
                cur = tmp;
            }
            // 更新m得值；
            //cout<<"i =" <<i<<endl;
            
            // 更新青蛙的位置
            i += (dis - 1);
            for (auto &d : m) {
                while (!d.second.empty() && d.second.top() <= i) {
                    //cout<<d.first<<"top ="<<d.second.top()<<endl;
                    d.second.pop();
                    //cout<<"pop"<<endl;
                }
            }
            //cout<<"i =" <<i<<endl;
        }
        return ret;
    }
};
//! dp
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(obstacles.size(), vector<int>(3, 0));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 1;
        for (int i = 1; i < obstacles.size(); ++i) {
            for (int j = 0; j < 3; ++j) {
                // 分别考虑每一个位置
                // 如果当前位置有障碍,不可达，设为最大值
                int m = 10000000;
                if (obstacles[i] == j + 1) {dp[i][j] = 10000000;}
                else {
                    // 当前位置没有障碍，那么就取决于前面的最小侧跳次数
                    
                    for (int k = 0; k < 3; ++k) {
                        if (k == j) m = min(dp[i - 1][k], m);
                        else {
                            // 判断能不能跳
                            if (obstacles[i - 1] != j + 1) m = min(dp[i - 1][k] + 1, m);
                        }
                    } 
                }
                
                dp[i][j] = m;
                //cout<<"dp["<<i<<']'<<'['<<j<<"] ="<<dp[i][j]<<endl;
                
            }
        }
        return min({dp[obstacles.size()-1][0],dp[obstacles.size()-1][1],dp[obstacles.size()-1][2]});
    }
};