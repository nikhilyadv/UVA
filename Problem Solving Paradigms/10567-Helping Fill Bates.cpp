#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string s,q;
    cin >> s;
    vector<vector<int>> a(256);
    for(int i = 0; i < s.size(); i++){
        a[s[i]].push_back(i);
    }
    int Q;
    cin >> Q;
    while(Q--){
        cin >> q;
        int start = 0, b = -1;
        bool found = true;
        for(int i = 0; i < q.size(); i++){
            auto t = upper_bound(a[q[i]].begin(), a[q[i]].end(), b);
            b = t - a[q[i]].begin();
            if(t == a[q[i]].end()) found = false;
            b = a[q[i]][b];
            if(i == 0) start = b;
        }
        if(!found) cout << "Not matched\n";
        else cout << "Matched " << start << " " << b << "\n";
    }
    return 0;
}
