#include<bits/stdc++.h>

using namespace std;
vector<int> track;
int n , l , mini , ans;

void dfs(int sum , int res , int index){
    if(sum > n || mini == 0) return;
    if(n - sum < mini)
        mini = n - sum, ans = res;
    for(int i = index ; i < l ; i++)
        dfs(sum + track[i] , res | (1<<i) , i+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n >> l){
        track.resize(l);    mini = INT_MAX;
        for(int i = 0 ; i < l ; i++)    cin >> track[i];
        dfs(0,0,0);
        for(int i = 0 ; i < l ; i++)
            if(ans & (1<<i))
                cout << track[i] << " ";
        cout << "sum:" << n-mini << endl;
    }
    return 0;
}
//FANCY TECH	2.140s
/*
#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , l , lim , min , sum , ans;
    unordered_map<int,int> track;
    while(cin >> n >> l){
        track.clear();
        for(int i = 0 ; i < l ; i++)    cin >> track[(1<<i)];
        lim = 1<<l;
        ans = 0;
        min = INT_MAX;
        for(int i = 1 ; i < lim ; i++){
            sum = 0;
            for(int j = 0 ; j < l ; j++)    sum += track[(i&(1<<j))];
            if(n-sum >= 0 && n-sum < min){
                min = n-sum;
                ans = i;
            }
        }
        for(int i = 0 ; i < l ; i++)
            if(ans & (1<<i))
                cout << track[1<<i] << " ";
        cout << "sum:" << n-min << endl;
    }
    return 0;
}
*/