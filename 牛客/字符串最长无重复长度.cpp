
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
  public:
    /**
     *
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int> &arr) {
        // write code here

        map<int, int> nm;
        int i = 0, j = 0;
        int ret = 0;
        int tmp = 0;
        while (i < arr.size() && j < arr.size()) {
            while (j < arr.size() && nm[arr[j]] == 0) {
                nm[arr[j]] = 1;
                j++;
                tmp++;
            }
            ret = max(ret, tmp);
            while (i <= j && nm[arr[j]] == 1) {
                nm[arr[i]] = 0;
                i++;
                tmp--;
            }
            cout<<"i = "<<i<<endl;
            cout<<"j = "<<j<<endl;
        }
        return ret;
    }
};

int main() {
    Solution s;

    vector<int> a{2,2,3,4,3};
    s.maxLength(a);


    return 0;
}