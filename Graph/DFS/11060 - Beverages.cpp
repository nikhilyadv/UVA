#include<bits/stdc++.h>

using namespace std;

unordered_map <string , int>mp1;
unordered_map <int , string>mp2;
vector <int> top , adjlist[200];
priority_queue <int , vector<int> , greater<int>> yo;
int n , m , incomingedge[200] , visited[200];

void addedge(int u , int v){
    adjlist[u].push_back(v);
}

void kahn(){
    for(int i = 0 ; i < n ; i++){
        if(incomingedge[i] == 0)
            yo.push(i) , visited[i] = 1;
    }
    while(!yo.empty()){
        int u = yo.top();   yo.pop();
        top.push_back(u);
        for(int i = 0 ; i < adjlist[u].size() ; i++){
            incomingedge[adjlist[u][i]]--;
        }
        for(int i = 0 ; i < n ; i++){
            if(incomingedge[i] == 0 && visited[i] == 0)
                yo.push(i) , visited[i] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int cas = 1;
    while(cin>>n){
        top.clear();
        memset(incomingedge , 0 , sizeof(incomingedge));
        memset(visited , 0 , sizeof(visited));
        for(int i = 0 ; i < 200 ;i++)
            adjlist[i].clear();
        string s1 , s2;
        for(int i = 0 ;  i < n ; i++) {
            cin >> s1;
            mp1[s1] = i;
            mp2[i] = s1;
        }
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> s1 >> s2;
            incomingedge[mp1[s2]]++;
            addedge(mp1[s1],mp1[s2]);
        }
        kahn();
        cout << "Case #" << cas <<": Dilbert should drink beverages in this order: ";
        for(int i = 0 ; i < n - 1 ; i++)
            cout << mp2[top[i]] <<" ";
        cout << mp2[top[n-1]] << ".\n\n";  cas++;
    }
    return 0;
}
