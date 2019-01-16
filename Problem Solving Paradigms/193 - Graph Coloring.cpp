#include<bits/stdc++.h>

using namespace std;

int n , k , res;
vector<int> color , ans;
vector<vector<int>> edgelist;

void dfs(int vertex){
    if(vertex == n){
        int count = 0;
        for(int i = 0 ; i < n ; i++)
            if(color[i] == 1)
                count++;
        if(count > res){
            res = count;
            ans.clear();
            for(int i = 0 ; i < n ; i++)
                if(color[i] == 1)
                    ans.push_back(i+1);
        }
        return;
    }
    bool col = true;
    for(int i = 0 ; i < edgelist[vertex].size() ; i++)
        if(color[edgelist[vertex][i]] == 1){
            col = false;
            break;
        }
    if(col){
        color[vertex] = 1;
        dfs(vertex + 1);
    }
    color[vertex] = 2;
    dfs(vertex + 1);
    color[vertex] = 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int m , a , b;
    cin >> m;
    while(m--){
        edgelist.clear();
        color.clear();  ans.clear();
        cin >> n >> k;
        color.resize(n);
        edgelist.resize(n);
        for(int i = 0 ; i < k ; i++){
            cin >> a >> b;  a-- , b--;
            edgelist[a].push_back(b);
            edgelist[b].push_back(a);
        }
        res = 0;
        dfs(0);
        cout << res << endl;
        for(int i = 0 ; i < res ; i++)
            cout << ans[i] << (i == res - 1 ? "" : " ");
        cout << endl;
    }
    return 0;
}