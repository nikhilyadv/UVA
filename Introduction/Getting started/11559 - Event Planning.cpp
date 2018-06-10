#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n , h , b , w;
    while(cin >> n >> b >> h >> w){
        int cost[h] , flag = 0 , days[h][w] , min = INT_MAX , tempflag = 0;
        for(int i = 0 ; i < h ; i++){
            cin >> cost[i];
            tempflag = 0;
            for(int j = 0 ; j < w ; j++){
                cin >> days[i][j];
                if(days[i][j] >= n && days[i][j] * cost[i] <= b)
                    flag = 1 , tempflag = 1;
            }
            if(tempflag == 1 && cost[i] < min)
                min = cost[i];

        }
        if(flag == 0)
            cout << "stay home\n";
        else
            cout << min * n << endl;
    }
    return 0;
}