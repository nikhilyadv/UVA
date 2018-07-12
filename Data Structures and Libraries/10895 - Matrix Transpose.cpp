#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m;
    pair<int , int> p;
    while(cin >> m >> n){
        vector<queue<pair<int,int>>> v(10005);
        int N;
        for(int i = 1 ; i <= m ; i++){
            cin >> N;
            vector<int> t(N+1) , val(N+1);
            for(int j = 1 ; j <= N ; j++)
                cin >> t[j];
            for(int j = 1 ; j <= N ; j++)
                cin >> val[j];
            p.first = i;
            for(int j = 1 ; j <= N ; j++){
                p.second = val[j];
                v[t[j]].push(p);
            }
        }
        cout << n << " " << m << endl;
        for(int i = 1 ; i <= n ; i++){
            cout << v[i].size();
            if(v[i].size())
                cout << " ";
            vector<int> val(v[i].size()+1);
            int N = v[i].size();
            for(int j = 1 ; j <= N ; j++){
                cout << v[i].front().first;
                if(j != N)
                    cout << " ";
                val[j] = v[i].front().second;
                v[i].pop();
            }
            cout << endl;
            for(int j = 1 ; j <= N ; j++) {
                cout << val[j];
                if(j != N)
                    cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}