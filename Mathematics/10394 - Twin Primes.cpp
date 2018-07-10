#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

vi primes;
pair< ll , ll > twinprime[1000005];

void sieve(ll n){
    bitset<20000001> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2 ; i <= n ; i++){
        if(bs[i]) {
            for (ll j = i * i; j <= n; j += i)
                bs[j] = 0;
            primes.push_back(int(i));
        }
    }
}

int main(){
    sieve(20000000);
    int n , k = 0;
    for(ll i = 0 ; i < primes.size() ; i++){
        if(primes[i+1] - primes[i] == 2){ twinprime[k].first = primes[i] , twinprime[k].second = primes[i+1] , k++;}
    }
    while(cin>>n){
        n--;
        cout<<"("<<twinprime[n].first<<", "<<twinprime[n].second<<")\n";
    }
    return 0;
}
