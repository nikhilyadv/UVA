#include<bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef long long ll;

int main(){
    ll num = 131071 , len;
    char ch;
    ll ans = 0;
    while(cin>>ch){
        if(ch == -1)
            break;
        if(ch == '1' || ch == '0'){
            ans = (ans<<1) + ch - '0';
            if(ans >= num)
               ans %= num;
        }
        else if(ch == '#'){
            cout<<(ans ? "NO" : "YES");
            cout<<endl;
            ans = 0;
        }
    }
    return 0;
}
