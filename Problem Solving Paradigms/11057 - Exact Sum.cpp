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
    int n, m;
    while(cin >> n){
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cin >> m;
        int first, second;
        first = second = -1;
        for(int i = 0; i < n; i++){
            int check = lower_bound(a.begin()+i+1, a.begin()+n, m-a[i]) - a.begin();
            if(a[check] + a[i] == m && check != i){
                first = a[i];
                second = a[check];
            }
        }
        cout << "Peter should buy books whose prices are " << first << " and " << second << ".\n\n";
    }
    return 0;
}
