#include<bits/stdc++.h>

using namespace std;

int n , m;
char a[110][110];
int findnumber(int i , int j){
    int ans = 0;
    if(i > 0 && j > 0 && a[i-1][j-1] == '*')
        ans++;
    if(i > 0 && j < m - 1 && a[i-1][j+1] == '*')
        ans++;
    if(i < n - 1 && j < m - 1 && a[i+1][j+1] == '*')
        ans++;
    if(i < n - 1 && j > 0 && a[i+1][j-1] == '*')
        ans++;
    if(i > 0 && a[i-1][j] == '*')
        ans++;
    if(i < n - 1 && a[i+1][j] == '*')
        ans++;
    if(j > 0 && a[i][j-1] == '*')
        ans++;
    if(j < m - 1 && a[i][j+1] == '*')
        ans++;
    return ans;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    long long tc = 0;
    while(cin >> n >> m , n || m){
        tc++;
        if(tc != 1)
            cout << endl;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                cin >> a[i][j];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j] != '*'){
                    a[i][j] = char(findnumber(i , j) + int('0'));
                }
            }
        }
        cout << "Field #" << tc << ":\n";
        for(int i = 0 ; i < n ; i++) {
            for (int j = 0; j < m; j++)
                cout << a[i][j];
            cout << endl;
        }
    }
    return 0;
}