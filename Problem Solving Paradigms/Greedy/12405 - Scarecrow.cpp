#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, t = 0, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        string field;
        cin >> field;
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            if(field[i] == '.'){
                res++;
                i += 2;
            }
        }
        cout << "Case " << ++t << ": " << res << "\n";
    }
    return 0;
}

