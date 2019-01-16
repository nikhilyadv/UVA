#include<bits/stdc++.h>

using namespace std;

int binsearch(vector<int> a, int item, int start, int end){
    if(end >= start) {
        int mid = start + (end - start) / 2;
        if (a[mid] == item) return mid;
        else if (a[mid] > item) return binsearch(a, item, start, mid - 1);
        else return binsearch(a, item, mid + 1, end);
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m, q, r1, r2;
    while(cin >> n >> m, n || m){
        vector<vector<int>> a(n);
        //int a[n][m], b[m][n];
        for(int i = 0 ; i < n ; i++){
            a[i].resize(m);
            for(int j = 0 ; j < m ; j++){
                cin >> a[i][j];
            }
        }
        cin >> q;
        for(int i = 0 ; i < q ; i++){
            cin >> r1 >> r2;
            vector<pair<int,int>> res;
            for(int i = 0 ; i < n ; i++)
                res.push_back({(lower_bound(a[i].begin(),a[i].end(),r1)-a[i].begin()),(--upper_bound(a[i].begin(),a[i].end(),r2))-a[i].begin()});
            int max_ = 0,temp;
            for(int i = 0; i < n; i++){
                for(int j = i; j < n; j++){
                    if(res[j].second < res[j].first) break;
                    temp = min(j-i,res[j].second-res[i].first)+1;
                    if(temp>max_)    max_ = temp;
                }
            }
            cout << max_ << "\n";
       }
       cout << "-\n";
    }

    return 0;
}
