#include<bits/stdc++.h>

using namespace std;

typedef vector <long long> vi;
typedef long long ll;

int factorial[1001][3000] = {};

int main(){

    int size[1001], j;
    memset(size , 0 , sizeof(size));
    factorial[0][0] = 1 ;
    size[0] = 1;
    for(int i = 1 ; i < 1001 ; i++){
        for(j = 0 ; j < 3000 ; j++){
            factorial[i][j] += factorial[i-1][j]*i;
            factorial[i][j+1] += factorial[i][j]/10;
            factorial[i][j] %=10;
        }
        j = 3000;
        while(!factorial[i][j]) j--;
        size[i] = j+1;
    }
    int n;
    while(cin>>n){
       cout<<n<<"!\n";
       for(int i = size[n]-1 ; i >= 0 ; i--){
           cout<<factorial[n][i];
       }
       cout<<endl;

    }
    return 0;
}
