#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

vi primes;

void sieve(int max){
    bitset<1000001> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i = 2 ; i < max ; i++){
        if(bs[i])
            for(ll j = i * i ; j < max ; j++)   bs[j] = 0;
        primes.push_back(i);
    }
}

int numDiv(int n){
    int pfindex = 0 , pf = primes[pfindex] , N = n , ans = 0;
    while(pf * pf <= n){
        int flag = 0;
        while(N % pf == 0) {
            N /= pf;
            if(flag == 0){
                ans++;
                flag = 1;
            }
        }
        pf = primes[++pfindex];
    }
    if(N != 1)  ans++;
    return ans;
}

int main(){
    sieve(1000001);
    int n;
    while(cin>>n , n){
        cout<<n<<" : "<<numDiv(n)<<endl;
    }
    return 0;
}
