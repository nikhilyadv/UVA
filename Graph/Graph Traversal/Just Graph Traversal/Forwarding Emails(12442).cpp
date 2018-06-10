#include<bits/stdc++.h>

using namespace std;
#define max 5005
int n;
int lis[max] , visited[max] , c[max] ;

int dfs(int u){
    int v = lis[u] , r = 0;
    visited[u] = 1;
    if(visited[v] == 0)
        r = dfs(v) + 1;
    visited[u] = 0;
    c[u] = r;
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    int tc , cas = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        memset(lis , 0 , sizeof(lis));
        memset(visited , 0 , sizeof(visited));
        memset(c , 0 , sizeof(c));
        int u , v;
        for(int i = 0 ; i < n ; i++){
            cin >> u >> v ; u-- , v--;
            lis[u] = v;
            visited[u] = 0;
            c[u] = -1;
        }
        int k = 0 , index = -1;
        for(int i = 0 ; i < n ; i++){
            if(c[i] == -1)  dfs(i);
            if(c[i] > k){
                k = c[i];
                index = i;
            }
        }
        cout << "Case " << cas++ <<": " << index + 1 << endl;
    }
    return 0;
}
