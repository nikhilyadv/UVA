#include<bits/stdc++.h>

using namespace std;
int n, m;
vector <int> lis[200] , top;
bitset<200> bs;

void dfsutil(int u){
    bs[u] = 0;
    for(int i = 0 ; i < lis[u].size() ; i++){
        if(bs[lis[u][i]])
            dfsutil(lis[u][i]);
    }
    top.push_back(u+1);
}

void dfs(){
    bs.set();
    for(int i = 0 ; i < n ; i++){
        if(bs[i])
            dfsutil(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n >> m , n && m){
        top.clear();
        for(int i = 0 ; i < 200 ; i++)
            lis[i].clear();
        int u ,v;
        for(int i = 0 ; i < m; i++){
            cin >> u >> v;
            u--; v--;
            lis[u].push_back(v);
        }
        dfs();
        for(int i = n - 1 ; i > 0 ; i--){
            cout << top[i] <<" ";
        }
        cout << top[0] << "\n";
    }
    return 0;
}
