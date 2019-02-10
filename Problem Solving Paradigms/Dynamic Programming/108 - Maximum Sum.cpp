#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n) {
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++)
            a[i].resize(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (i > 0) a[i][j] += a[i - 1][j];
                if (j > 0) a[i][j] += a[i][j - 1];
                if (i > 0 and j > 0) a[i][j] -= a[i - 1][j - 1];
            }
        long long maxsum = INT_MIN, sum_ = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        sum_ = a[k][l];
                        if (i > 0) sum_ -= a[i - 1][l];
                        if (j > 0) sum_ -= a[k][j - 1];
                        if (i > 0 and j > 0) sum_ += a[i - 1][j - 1];
                        maxsum = max(maxsum, sum_);
                    }
                }
            }
        }
        cout << maxsum << "\n";
    }

    return 0;
}