#include<bits/stdc++.h>

using namespace std;

int dr[] = {-1,0,1,0,-1,-1,1,1};
int dc[] = {0,-1,0,1,-1,1,-1,1};
int n , m , used[21][21];
vector <string> a;

int floodfill(int r , int c , char c1){
    if(r < 0 || r == n)
        return 0;
    if(c < 0)
        c = m - 1;
    if(c == m)
        c = 0;
    if(used[r][c] != 0 || a[r][c] != c1)  return 0;
    int ans = 1;
    used[r][c] = 1;
    for(int k = 0 ; k < 4 ; k++)
        ans += floodfill(r + dr[k] , c + dc[k] , c1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int  x , y;
    char c1 ;
    while(cin >> n >> m){
        memset(used , 0 , sizeof(used));
        a.resize(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        cin >> x >> y;
        c1 = a[x][y];
        floodfill(x , y , c1);
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                    ans = max(ans , floodfill(i , j , c1));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
