#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int m , temp;
    string s;
    vector<pair<int,int>> o , t;
    while(cin >> m){
        o.clear();
        t.clear();
        getline(cin, s);
        for(int i = 0 ; i < m ; i++) {
            getline(cin, s);
            for (int j = 0; j < s.size(); j++)
                if (s[j] == '1')
                    o.push_back(make_pair(i + 1, j + 1));
                else if (s[j] == '3')
                    t.push_back(make_pair(i + 1, j + 1));
        }
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i = 0 ; i < o.size() ; i++){
            mini = INT_MAX;
            for(int j = 0 ; j < t.size() ; j++)
                mini = min(mini , abs(o[i].first - t[j].first) + abs(o[i].second - t[j].second));
            maxi = max(maxi , mini);
        }
        cout << maxi << endl;
    }
    return 0;
}