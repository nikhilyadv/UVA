#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m , k , v , num;
    while(cin >> n >> m){
        vector<vector<int>> vec(1000005);
        for(int i = 1 ; i <= n ; i++){
            cin >> num;
            vec[num].push_back(i);
        }
        for(int i = 0 ; i < m ; i++){
            cin >> k >> v;
            if(k-1 < vec[v].size())
                cout << vec[v][k-1];
            else
                cout << "0";
            cout << endl;
        }
    }
    return 0;
}