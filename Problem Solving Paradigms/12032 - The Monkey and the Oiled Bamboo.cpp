#include<bits/stdc++.h>

using namespace std;

bool sim(vector<int> a, int k){
    int height = 0, curr = 0;
    if(a[0] > k) return false;
    if(a[0] == k) k--;
    height = a[0];
    while(height != a[a.size()-1]){
        if(a[curr+1] - a[curr] > k) return false;
        else if (a[curr+1] - a[curr] == k) k--;
        height = a[curr+1];
        curr++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int tc, t = 1;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        int k, res;
        int low = 0, high = 1e7;
        while(high != low){
            int mid = low + (high-low)/2;
            if(sim(a,mid)) {res = mid , high = mid;}
            else low = mid+1;
        }
        cout << "Case " << t++ << ": " << res << "\n";
    }


    return 0;
}
