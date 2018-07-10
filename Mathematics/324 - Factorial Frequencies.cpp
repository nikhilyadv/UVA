#include<bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef long long ll;

int main(){
    ll factorial[367][801] ={} , d[367][10] , j;
    memset(d , 0 , sizeof(d));
    factorial[0][0] = 1 ;
    d[0][1] = 1 ;
    for(ll i = 1 ; i < 367 ; i++){
        for(j = 0 ; j < 800 ; j++){
            factorial[i][j] += factorial[i-1][j]*i;
            factorial[i][j+1] += factorial[i][j]/10;
            factorial[i][j] %=10;
        }
        j = 800;
        while(!factorial[i][j]) j--;
        for( ; j >= 0 ; j--)
            d[i][factorial[i][j]]++;

    }
    int n;
    while(cin>>n , n){
       cout<<n<<"! --\n";
       for(int i = 0 ; i < 5; i++){
           if(i)   cout<<"    ";
           else    cout<<"   ";
           cout<<"("<<i<<")"<<"     "<<d[n][i];
       }
       cout<<endl;
       for(int i = 5 ; i < 10; i++){
           if(i != 5)   cout<<"    ";
           else    cout<<"   ";
           cout<<"("<<i<<")"<<"     "<<d[n][i];
       }
       cout<<endl;

    }
    return 0;
}
