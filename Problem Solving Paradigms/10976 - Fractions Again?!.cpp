#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int k;
    while(cin >> k){
        vector<pair<int,int>> res;
        for(int y = k + 1 ; y <= 2*k ; y++){
            if((y*k)%(y-k) == 0)
                res.push_back(make_pair((y*k)/(y-k), y));
        }
        cout << res.size() << endl;
        for(int i = 0 ; i < res.size() ; i++)
            cout << "1/" << k << " = 1/" << res[i].first << " + 1/" << res[i].second << endl;
    }
    return 0;
}