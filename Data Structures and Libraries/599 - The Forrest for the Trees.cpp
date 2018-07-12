#include<bits/stdc++.h>

using namespace std;

vector<int> visited(26);

int dfsutil(vector<vector<int>> edgelist , vector<int> present , int v){
    if(visited[v] == 1){
        return -1;
    }
    else{
        int res = 1 , temp;
        visited[v] = 1;
        for(int i = 0 ; i < edgelist[v].size() ; i++){
            if(present[edgelist[v][i]] && !visited[edgelist[v][i]]) {
                temp = dfsutil(edgelist,present,edgelist[v][i]);
                if(temp >= 0)
                    res += temp;
                else
                    res = -1;
            }
        }
        return res;
    }
}

void dfs(vector<vector<int>> edgelist , vector<int> present){
    fill(visited.begin() , visited.end() , 0);
    int tree = 0 , acorn = 0 , num;
    for(int i = 0 ; i < 26 ; i++){
        if(present[i] && !visited[i]){
            num = dfsutil(edgelist,present,i);
            if(num > 1)
                tree++;
            else if(num == 1)
                acorn++;
        }
    }
    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;
}

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    cin >> n;
    getchar();
    while(n--){
        vector<int> present(26);
        vector<vector<int>> edgelist(26);
        string s;
        while(getline(cin,s)){
            if(s[0] == '*')
                break;
            int from , to;
            from = int(s[1])-int('A');
            to = int(s[3])-int('A');
            edgelist[from].push_back(to);
            edgelist[to].push_back(from);
        }
        getline(cin,s);
        for(int i = 0 ; i < s.size() ; i+=2)
            present[int(s[i])-int('A')] = 1;
        dfs(edgelist , present);
    }
    return 0;
}