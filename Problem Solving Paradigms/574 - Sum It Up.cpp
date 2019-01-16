#include<bits/stdc++.h>

using namespace std;
int n , m;
vector<int> p ,ans;

void dfs(int index , int sum , int bit){
    if(sum > n) return;
    if(sum == n){
        ans.push_back(bit);
        return ;
    }
    for(int i = index ; i < m ; i++){
        if(!(bit & (1<<i))) {
            dfs(i + 1, sum + p[i], bit | (1 << i));
            int go = p[i];
            while(go == p[i])   i++;
            i--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n >> m , n || m){
        ans.clear();
        p.resize(m);
        for(int i = 0 ; i < m ; i++)    cin >> p[i];
        cout << "Sums of " << n << ":" << endl;
        sort(p.begin() , p.end());
        dfs(0,0,0);
        if(ans.empty()) cout << "NONE" << endl;
        else {
            sort(ans.begin(), ans.end(), greater<int>());
            for(auto i:ans){
                int t = 0;
                for(int k = m-1 ; k >= 0 ; k--){
                    if(i & (1<<k)){
                        if(t == 0)  cout << p[k];
                        else        cout << "+" << p[k];
                        t++;
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}