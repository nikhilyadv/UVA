#include<bits/stdc++.h>

using namespace std;

int gcd(int a , int b){ return b == 0 ? a : gcd(b , a%b);}

int main(){
    int a[1001];
    while(1){
        cin>>a[0];
        if(a[0] == 0)
            break;
        int size =1;
        while(1){
            cin>>a[size];
            if(a[size] == 0)
                break;
            size++;
        }
        int ans;
        ans = abs(a[1] - a[0]);
        for(int i = 2 ; i < size ; i++){
            ans = gcd(ans , abs(a[i] - a[i-1]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
