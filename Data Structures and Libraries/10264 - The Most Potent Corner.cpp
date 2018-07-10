#include<bits/stdc++.h>

using namespace std;

int w[32769] , p[32769];

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    while(cin >> n){
        int m;  m = 1<<n;
        for(int i = 0 ; i < m ; i++)
            cin >> w[i];
        memset(p , 0 , sizeof(p));
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                p[i] += w[i^(1<<j)];
        int ans = INT_MIN;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(ans < p[i] + p[i^(1<<j)])
                    ans = p[i] + p[i^(1<<j)];
        cout << ans << endl;
    }
    return 0;
}