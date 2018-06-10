#include<bits/stdc++.h>

using namespace std;

int n , m ;
vector <string> a;

int dr[] = {1,1,0,-1,-1,-1,0,1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int r , int c , char ch1, char ch2){
    if( r<0 || r>=m || c>=n || c<0) return 0;
    if(a[r][c] != ch1)  return 0;
    int ans = 1;
    a[r][c] = ch2;
    for(int k = 0 ; k < 8 ; k++)
        ans += floodfill(r + dr[k] , c + dc[k] , ch1 , ch2);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("in.txt" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    int tc; cin>>tc;    cin.ignore();
    string s;
    while(tc--){
        cin.ignore();
        a.clear();
        while(cin.peek() > '9'){
            cin >> s; cin.ignore();
            a.push_back(s);
        }
        m = a.size();
        n = a[0].size();
        int r , c ,ans;
        vector <string> grid(a);
        while(cin.peek() != '\n' && cin.peek() != EOF){
            cin >> r >> c; cin.ignore();
            a = grid;
            ans = floodfill(r-1, c-1, 'W', '.');
            cout << ans << "\n";
        }
        if(tc!=0) cout << "\n";
    }
    return 0;
}
