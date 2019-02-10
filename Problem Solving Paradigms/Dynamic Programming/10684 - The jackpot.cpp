#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n , n){
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int sum = 0, ans = 0;
        for(int i = 0 ; i < n ; i++){
            sum += a[i];
            if (sum >= ans)
                ans = sum;
            if (sum <= 0)
                sum = 0;
        }
        if(ans == 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << ans << ".\n";
    }
    return 0;
}