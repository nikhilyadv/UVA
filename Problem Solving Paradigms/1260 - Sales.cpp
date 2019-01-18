#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0 ; i < n ; i++)
            cin >> a[i];
        for(int i = 1 ; i < n ; i++){
            int count = 0;
            for(int j = 0 ; j < i ; j++)
                if(a[i] >= a[j])
                    count++;
            sum += count ;
        }
        cout << sum << endl;
    }
    return 0;
}