#include<bits/stdc++.h>

using namespace std;

int ans[92][8] , res[8] , ptr = -1 , used[8]={};

bool find(int a , int b){
    for(int i = 0 ; i < a ; i++)
        if(abs(i-a) == abs(res[i]-b))
            return false;
    return true;
}

void dfs(int index){
    if(index == 8){
        ptr++;
        for(int i = 0 ; i < 8 ; i++)
            ans[ptr][i] = res[i];
        return;
    }
    for(int i = 0 ; i < 8 ; i++){
        if(!used[i] && find(index , i)){
            used[i] = 1;
            res[index] = i;
            dfs(index+1);
            used[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    dfs(0);
    int tc = 1 , a[8] , move , best;
    while(cin >> a[0]){
        for(int i = 1 ; i < 8 ; i++)    cin >> a[i];
        best = 9;
        for(int i = 0 ; i <= ptr ; i++){
            move = 0;
            for(int j = 0 ; j < 8 ; j++)
                if(ans[i][j] != (a[j]-1))    move++;
            best = min(move,best);
        }
        cout << "Case " << tc++ << ": " << best << endl;
    }
    return 0;
}