#include<bits/stdc++.h>

using namespace std;
int n , ring[20] , tc = 1 , used[20];

bool yoprime(int a){
    for(int i = 2 ; i <= sqrt(a) ; i++)
        if(a%i == 0)    return false;
    return true;
}

void dfs(int index){
    if(index == n-1 && yoprime(ring[n-1] + ring[n])){
        for(int i = 0 ; i < n ; i++)
            cout << ring[i] << (i == n - 1 ? "" : " ");
        cout << endl; return;
    }
    for(int i = 2 ; i <= n ; i++)
        if(!used[i] && yoprime(ring[index]+i)){
            used[i] = 1;
            ring[index+1] = i;
            dfs(index+1);
            used[i] = 0;
        }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    ring[0] = 1;
    while(cin >> n){
        memset(used , 0 , sizeof(used));
        if(tc > 1)  cout << endl;
        cout << "Case " << tc++ << ":" << endl;
        ring[n] = 1;
        dfs(0);
    }
    return 0;
}