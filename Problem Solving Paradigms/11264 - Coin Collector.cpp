#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, n;
    cin >> tc;
    while(tc--){
        cin >> n;
        vector<int> c(n);
        for(int i = 0 ; i < n ; i++)
            cin >> c[i];
        /*
        sort(c.begin(),c.end());
        int max_ = c[n-1] - 1, res = 0, min_ = c[0];
        for(int i = max_; i >= min_ ; i--){
            int unique = 0, amount = i;
            vector<bool> check(n);
            fill(check.begin(),check.end(), false);
            while(amount != 0){
                int coin = lower_bound(c.begin(),c.end(),amount) - c.begin();
                if(c[coin] != amount) coin--;
                if(coin == -1)  coin = 0;
                amount -= c[coin];
                if(!check[coin]){
                    check[coin] = true;
                    unique++;
                }
            }
            if(unique > res)
                res = unique;
        }
        cout << res+1 << "\n";
         */
        int res = 1, sum = c[0];
        for(int i = 1 ; i < n-1 ; i++){
            if(sum+c[i] < c[i+1]){
                sum += c[i];
                res++;
            }
        }
        cout << res+1 << "\n";
    }
    return 0;
}
