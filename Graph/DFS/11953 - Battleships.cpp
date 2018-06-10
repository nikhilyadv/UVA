#include<bits/stdc++.h>

using namespace std;
#define maxn 150
int dr[] = {-1,0,1,0};
int dc[] = {0,-1,0,1};
int n;
vector <string> a;

void floodfill(int r , int c){
    if(r<0 || c<0 || r==n ||c==n)   return ;
    if(a[r][c] == '.')  return ;
    a[r][c] = '.';
    for(int k = 0 ; k < 4 ; k++)
        floodfill(r + dr[k] , c + dc[k]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int tc , cas = 1;
    cin >> tc;
    while(tc--){
        cin >> n;
        a.resize(n);
        for(int i = 0 ; i < n ; i++)
            cin>>a[i];
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(a[i][j] == 'x'){
                    floodfill(i ,j);
                    ans++;
                }
            }
        }
        cout<<"Case "<<cas++<<": "<<ans<<"\n";

    }

    return 0;
}
