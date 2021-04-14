#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n = 0;
    vector<long> ret;
    cin>>n;
    while (n--) {
        int M = 0, N = 0, X = 0, Y = 0;
        long P = 0;
        scanf("%d", &M);
        scanf("%d", &N);
        scanf("%d", &X);
        scanf("%d", &Y);
        scanf("%d", &P);

        // cin>>M;
        // cin>>N;
        // cin>>X;
        // cin>>Y;
        // cin>>P;
        if (X * M <= Y * N && (P - 100000) > X * M) ret.push_back(-1);
        else if (M*X >= P - 100000)
        {
            int sum = P - 100000;
            int r = 0;
            for(int i = 0; i < M; ++i) {
                sum -= X;
                r++;
                if(sum <= 0){
                    break;
                }
            }
            ret.push_back(r);
        }
        else {
            int pro = X - Y;
            int sum = P - 100000;
            int r = 0;
            int times = 0;
            times = (sum - M * X) / (M * X - N * Y);
            if (times >= 0) 
            {
                if ((sum - M * X) % (M * X - N * Y)) times++;
                r += times*(M + N);
                sum -= (M * X - N * Y)*times;
            }
            
            for(int i = 0; i < M; ++i) {
                sum -= X;
                r++;
                if(sum <= 0){
                    break;
                }
            }
            ret.push_back(r);
        }
    }
    for (int i = 0; i < ret.size(); ++i) {
        cout<<ret[i];
        if (i != ret.size() - 1) {
            cout<<endl;
        }
    }
    return 0;
}