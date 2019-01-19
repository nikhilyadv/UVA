#include<bits/stdc++.h>

using namespace std;
int n , m , x[15] , y[15] , s , e , t , res , u[15];

void dfs(int len , int last){
    if(len == n){
        if(last == e)
            res = 1;
        return;
    }
    for(int i = 0 ; res == 0 && i < m ; i++){
        if(!u[i]){
            if(last == x[i]){
                u[i] = 1;
                dfs(len+1 , y[i]);
                u[i] = 0;
            }
            if(last == y[i]){
                u[i] = 1;
                dfs(len+1 , x[i]);
                u[i] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n , n){
        memset(u , 0 , sizeof(u));
        res = 0;
        cin >> m;
        cin >> t >> s >> e >> t;
        for(int i = 0 ; i < m ; i++)    cin >> x[i] >> y[i];
        dfs(0,s);
        if(res) cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}