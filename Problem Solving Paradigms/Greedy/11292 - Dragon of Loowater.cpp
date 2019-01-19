#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    while(cin >> n >> m, n || m){
        vector<int> d(n), k(m);
        for(int i = 0 ; i < n ; i++)
            cin >> d[i];
        for(int i = 0 ; i < m ; i++)
            cin >> k[i];
        sort(d.begin(),d.end());
        sort(k.begin(),k.end());
        int i, j, res;
        res = i = j = 0;
        while(j != n){
            while(i != m and d[j] > k[i]) i++;
            if(i == m){
                res = -1;
                break;
            }
            res += k[i];
            j++;
            i++;
        }
        if(res == -1)   cout << "Loowater is doomed!\n";
        else            cout << res << "\n";
    }
    return 0;
}

