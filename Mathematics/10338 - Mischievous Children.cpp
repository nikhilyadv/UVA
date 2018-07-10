#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int main(){
    unsigned long long factorial[21] , res;
    factorial[0] = 1;
    for(int i = 1 ; i < 21 ; i++)
        factorial[i] = factorial[i-1] * i;
    int n , count = 1;
    string s;
    cin>>n;
    while(n--){
        int alpha[26] = {};
        cin>>s;
        for(int i = 0 ; i < s.size() ; i++){
            alpha[s[i] - 'A']++;
        }
        res = factorial[s.size()];
        for(int i = 0 ; i < 26 ; i++){
            res /= factorial[alpha[i]];
        }
        cout<<"Data set "<<count<<": "<<res<<endl; count++;
    }
    return 0;
}
