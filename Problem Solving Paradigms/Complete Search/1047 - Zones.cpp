#include<bits/stdc++.h>

using namespace std;

int choose(int a , int b){
    for(int i = 0 ; i < 32 ; i++) {
        if (a & (1 << i) && !(b & (1 << i)))
            return a;
        if (!(a & (1 << i)) && b & (1 << i))
            return b;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , c , m , t1 , t2 , tc = 0 , p , lim , sum , max , ans;
    map<int,int> ca;
    vector<int> tower;
    while(cin >> n >> c , n || c){
        tower.resize(n);
        ca.clear();
        for(int i = 0 ; i < n ; i++)
            cin >> tower[i];
        cin >> m;
        for(int i = 0 ; i < m ; i++){
            cin >> t1;
            p = 0;
            for(int j = 0 ; j < t1 ; j++){
                cin >> t2;
                p |= (1<<(t2-1));
            }
            cin >> ca[p];
        }
        lim = 1<<n;
        max = INT_MIN;
        ans = 0;
        for(int i = 0 ; i < lim ; i++){
            if(__builtin_popcount(i) == c){
                sum = 0;
                for(int j = 0 ; j < n ; j++)
                    if(i&(1<<j))
                        sum += tower[j];
                for(auto it = ca.begin() ; it != ca.end() ; it++){
                    int a = __builtin_popcount(i & it->first);
                    if(a >= 2)
                        sum -= (a-1) * it->second;
                }
                if(sum > max){
                    ans = i;
                    max = sum;
                }
                else if(sum == max){
                    ans = choose(i,ans);
                }
            }
        }
        cout << "Case Number  " << ++tc << endl;
        cout << "Number of Customers: " << max << endl;
        cout << "Locations recommended:" ;
        for(int i = 0 ; i < n ; i++)
            if(ans & (1 << i))
                cout << " " << i+1;
        cout << endl << endl;
    }
    return 0;
}