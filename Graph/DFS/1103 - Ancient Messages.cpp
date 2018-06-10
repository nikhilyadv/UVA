#include<bits/stdc++.h>

using namespace std;

int dr[] = {-1,0,1,0,-1,-1,1,1};
int dc[] = {0,-1,0,1,-1,1,-1,1};
int n , m , counter;
vector <string> a;
unordered_map <char , string> mp1;
unordered_map <int , char> mp2;

void floodfill(int r , int c , char c1 , char c2){
    if(r < 0 || r == n || c < 0 || c == m) return ;
    if(a[r][c] != c1)  return ;
    a[r][c] = c2;
    for(int k = 0 ; k < 4 ; k++)
       floodfill(r + dr[k] , c + dc[k] , c1 , c2);
}

void floodfill1(int r , int c){
    if(r < 0 || r == n || c < 0 || c == m) return ;
    if(a[r][c] == '2')  return ;
    if(a[r][c] == '0'){
        counter++;
        floodfill(r , c , '0' , '2');
        return ;
    }
    a[r][c] = '2';
    for(int k = 0 ; k < 4 ; k++)
        floodfill1(r + dr[k] , c + dc[k]);
}

void initialize(){
    mp1['0'] = "0000"; mp1['1'] = "0001"; mp1['2'] = "0010";
    mp1['3'] = "0011"; mp1['4'] = "0100"; mp1['5'] = "0101";
    mp1['6'] = "0110"; mp1['7'] = "0111"; mp1['8'] = "1000";
    mp1['9'] = "1001"; mp1['a'] = "1010"; mp1['b'] = "1011";
    mp1['c'] = "1100"; mp1['d'] = "1101"; mp1['e'] = "1110";
    mp1['f'] = "1111";
    mp2[0] = 'W'; mp2[1] = 'A'; mp2[2] = 'K'; mp2[3] = 'J';
    mp2[4] = 'S'; mp2[5] = 'D';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    initialize();
    int cas = 1; string ans;
    while(cin >> n >> m , n && m){
        a.clear();  ans.clear();
        a.resize(n);
        char ch;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                cin>>ch;
                a[i] += mp1[ch];
            }
        }
        m *= 4;
        for(int i = 0 ; i < n ; i++){
            floodfill(i , m-1 , '0' , '2');
            floodfill(i , 0 , '0' , '2');
        }
        for(int j = 0 ; j < m ; j++){
            floodfill(n-1 , j , '0' , '2');
            floodfill(0 , j , '0' , '2');

        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(a[i][j] == '1'){
                    counter = 0;
                    floodfill1(i , j);
                    ans += mp2[counter];
                }
            }
        }
        sort(ans.begin() , ans.end());
        cout << "Case " << cas++ <<": ";
        for(int i = 0 ; i < ans.size() ; i++)
             cout<< ans[i];
        cout << "\n";
    }
    return 0;
}
