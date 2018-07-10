#include<bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef long long ll;

ll calcmod(ll b , ll p , ll m){
  ll res1 , res2;
    if(p == 0)
        return 1;
    if(p % 2 == 0) {
        res1 = (calcmod(b, p / 2, m) % m);
        return (res1 * res1) % m;
    }
    else{
        res1 = (calcmod(b, p - 1 , m) % m);
        res2 = b % m;
        return (res1 * res2) % m;
    }
}

int main(){
    ll b , p ,m;
    while(cin>>b>>p>>m){
        ll res;
        res = calcmod(b,p,m);
        cout<<res<<endl;
    }
    return 0;
}
