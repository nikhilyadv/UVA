#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int t , n , p , lim , count;
    unordered_map<int,int> bar;
    cin >> t;
    while(t--){
        cin >> n >> p;
        bar.clear();
        for(int i = 0 ; i < p ; i++)
            cin >> bar[(1<<i)];
        lim = 1<<p;
        for(int i = 0 ; i < lim ; i++){
            count = 0;
            for(int j = 0 ; j < p; j++)
                count += bar[(i&(1<<j))];
            if(count == n)
                break;
        }
        if(count == n)  cout << "YES" << endl;
        else            cout << "NO" << endl;
    }
    return 0;
}