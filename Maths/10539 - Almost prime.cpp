#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector <int> vi;

ll M = (long long int) 1000000000000;
vi prime;
vector <long long int> almostprime;
void seive(){
    vector <bool> bs(1000001);
    fill(bs.begin() , bs.end() , 1);
    for(ll i = 2 ; i < 1000001 ; i++){
        if(bs[i]){
            for(ll k = i * i ; k <= M ; k *=i)
                almostprime.push_back((long long int) k);
            for(ll j = i * i ; j < 1000001 ; j+=i){
                bs[j] = 0;
            }
            prime.push_back(int(i));
        }
    }

}

int main(){
    seive();
    sort(almostprime.begin() , almostprime.end());
    ll i , j;
    int n;
    cin>>n;
    while(n--){
        cin>>i>>j;
        ll count = 0 , l , h;
        l = lower_bound(almostprime.begin() , almostprime.end() , i) - almostprime.begin();
        h = lower_bound(almostprime.begin() , almostprime.end() , j) - almostprime.begin();
        if(h == almostprime.size() || almostprime[h]!=j)
            h--;
        count = h - l + 1;
        cout<<count<<"\n";
    }
    return 0;
}
