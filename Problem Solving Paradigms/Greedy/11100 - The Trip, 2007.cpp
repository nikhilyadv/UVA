#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    bool init = true;
    while(cin >> n, n){
        if(init == false)   cout << "\n";
        if(init == true)    init = false;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int max = 1, count = 1;
        sort(a.begin(),a.end());
        for(int i = 1 ; i < n ; i++){
            if(a[i] == a[i-1])  count++;
            else                count = 1;
            if(count > max)     max = count;
        }
        cout << max << "\n";
        for(int i = 0 ; i < max ; i++){
            cout << a[i];
            for(int j = i+max ; j < n ; j += max)
                cout << " " << a[j];
            cout << "\n";
        }
    }
    return 0;
}

