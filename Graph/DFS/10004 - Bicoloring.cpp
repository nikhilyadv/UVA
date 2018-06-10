#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m;
    while(cin>>n , n){
        vector<int> adjlist[n];
        queue<int> q;
        int color[n];
        int flag = 0 , u , v;
        memset(color , -1 , sizeof(color));
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> u >> v;
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        q.push(0);  color[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0 ; i < adjlist[u].size() ; i++){
                if(color[adjlist[u][i]] == -1){
                    color[adjlist[u][i]] = 1 - color[u];
                    q.push(adjlist[u][i]);
                }
                else if(color[adjlist[u][i]] == color[u]){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)   cout << "BICOLORABLE.\n";
        else    cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}
