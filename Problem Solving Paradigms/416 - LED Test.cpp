#include<bits/stdc++.h>

using namespace std;

int n ;
bool res;
vector<string> a , b(11);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    b[0] = "YYYYYYN";
    b[1] = "NYYNNNN";
    b[2] = "YYNYYNY";
    b[3] = "YYYYNNY";
    b[4] = "NYYNNYY";
    b[5] = "YNYYNYY";
    b[6] = "YNYYYYY";
    b[7] = "YYYNNNN";
    b[8] = "YYYYYYY";
    b[9] = "YYYYNYY";
    while(cin >> n , n){
        a.clear() , a.resize(n);
        for(int i = 0 ; i < n ; i++)    cin >> a[i];
        for(int no = 9 ; no >= n - 1 ; no--){
            b[10] = "YYYYYYY";  res = true;
            for(int i = 0 ; i < n ; i++){
               for(int j = 0 ; j < 7 ; j++){
                    if(b[10][j] == 'N' && a[i][j] == 'Y')
                        res = false;
                    if(b[no-i][j] == 'N' && a[i][j] == 'Y')
                        res = false;
                    if(b[no-i][j] == 'Y' && a[i][j] == 'N')
                        b[10][j] = 'N';
               }
            }
            if(res)
                break;
        }
        if(res) cout << "MATCH" << endl;
        else    cout << "MISMATCH" << endl;
    }
    return 0;
}
//Almost correct
/*#include<bits/stdc++.h>

using namespace std;

int n;
bool res;
vector<string> a;

bool findpossibilty(string s , int k){
    if(k == 0){
        if(s[6] == 'N')
            return true;
    }
    else if(k == 1){
        if(s[0] == 'N' && s[3] == 'N' && s[4] == 'N' && s[5] == 'N' && s[6] == 'N')
            return true;
    }
    else if (k == 2){
        if(s[2] == 'N' && s[5] == 'N')
            return true;
    }
    else if (k == 3){
        if(s[4] == 'N' && s[5] == 'N')
            return true;
    }
    else if (k == 4){
        if(s[0] == 'N' && s[3] == 'N' && s[4] == 'N')
            return true;
    }
    else if (k == 5){
        if(s[1] == 'N' && s[4] == 'N')
            return true;
    }
    else if (k == 6){
        if(s[1] == 'N')
            return true;
    }
    else if (k == 7){
        if(s[3] == 'N' && s[4] == 'N' && s[5] == 'N' && s[6] == 'N')
            return true;
    }
    else if (k == 8){
        return true;
    }
    else if (k == 9){
        if(s[4] == 'N')
            return true;
    }
    return false;
}

void dfs(int m , int num){
    if(m == -1){
        res = true;
        return;
    }
    if(num == -1)   return;
    if(findpossibilty(a[m],num))    dfs(m - 1, num - 1);
    else                            dfs(n - 1 , num - 1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> n , n){
        a.clear() , a.resize(n);
        for(int i = n - 1 ; i >= 0 ; i--)    cin >> a[i];
        res = false;
        dfs(n-1 , 9);
        if(res) cout << "MATCH" << endl;
        else    cout << "MISMATCH" << endl;
    }
    return 0;
}*/