#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main(){
    int n;
    int k = 0;
    vi prime;
    vector <bool> bs(1000001);
    fill(bs.begin() , bs.end() , 1);
    //calculating prime numbers between 2 to 1000000
    for(ll i = 2 ; i < 1000001 ; i++){
        if(bs[i]){
            for(ll j = i * i ; j < 1000001 ; j+=i){
                bs[j] = 0;
            }
            prime.push_back(int(i));
            k++;
        }
    }
//    for(int i = 0 ; i < k ; i++)
//        cout<<prime[i]<<" ";
    while(cin>>n, n!=0){
        int l = 0 , r = k - 1;
        int sum;
        sum = prime[l] + prime[r];
        while(sum != n){
            if(sum > n)
                r--;
            else if(sum < n)
                l++;
            sum = prime[l] + prime[r];
        }
        cout<<n<<" = "<<prime[l]<<" + "<<prime[r]<<endl;
    }
    return 0;
}
