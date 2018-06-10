#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , k;
    while(cin>>n>>k){
        int ciggi = 0 , butts = 0;
        while(n > 0){
            ciggi += n;
            butts += n;
            n = butts / k;
            butts %= k;
        }
        cout<<ciggi<<"\n";
    }
    return 0;
}
