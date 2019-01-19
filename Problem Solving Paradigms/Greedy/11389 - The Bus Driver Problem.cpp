#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, r, d;
    while(cin >> n >> d >> r, n || r || d){
        vector<int> routem(n), routee(n);
         for(int i = 0 ; i < n ; i++)
            cin >> routem[i];
         for(int i = 0 ; i < n ; i++)
            cin >> routee[i];
        sort(routem.begin(),routem.end());
        sort(routee.begin(),routee.end());
        int extra = 0;
        for(int i = 0 , j = n - 1; i < n ; i++ , j--){
            if(routem[i] + routee[j] > d){
                extra += routem[i] + routee[j] - d;
            }
        }
        cout << extra * r << "\n";
    }
    return 0;
}

