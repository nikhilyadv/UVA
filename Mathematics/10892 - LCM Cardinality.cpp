#include<bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef long long ll;

int gcd(int a , int b){ return b == 0 ? a : gcd(b , a%b);}

int lcm(int a , int b){ return a * (b / gcd(a,b));}

vi Calculatefactors(ll n){
    vi factors;
    ll temp = n;
    ll nn = sqrt(n);
    for(ll i = 1 ; i <= nn ; i++){
        if(temp % i == 0)
            factors.push_back(i) , factors.push_back(n/i);
    }
    if(nn * nn == n)
        factors.pop_back();
    return factors;
}

int main(){
    ll n ;
    while(cin>>n, n != 0){
        vi factors;
        factors = Calculatefactors(n);
        ll count = 0;
        for(ll i = 0 ; i < factors.size() ; i++){
            for(ll j = i ; j < factors.size() ; j++){
                if(lcm(factors[i],factors[j]) == n)
                    count++;
            }
        }
        cout<<n<<" "<<count<<endl;

    }
    return 0;
}
