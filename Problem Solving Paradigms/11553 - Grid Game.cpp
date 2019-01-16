#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int t , n , grid[8][8] , mini , sum;
    vector<int> per;
    cin >> t;
    while(t--){
        cin >> n;
        per.clear();
        per.resize(n);
        for(int i = 0 ; i < n ; i++) {
            per[i] = i;
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }
        mini = INT_MAX;
        do{
            sum = 0;
            for(int i = 0 ; i < n ; i++)
                sum += grid[i][per[i]];
            mini = min(mini , sum);
        }while(next_permutation(per.begin(),per.end()));
        cout << min << endl;
    }
    return 0;
}