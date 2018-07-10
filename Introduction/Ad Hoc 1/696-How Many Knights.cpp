#include<bits/stdc++.h>

using namespace std;

int solve(int n, int m){
    if(n > m) swap(n,m);
    if(n == 1) return m;
    if(n == 2) return m / 4 * 4 + (m % 4 == 1? 2 : (m % 4 >= 2? 4 : 0));
    return (n*m + 1) / 2;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m;
    while(cin >> n >> m , n || m){
        cout << solve(n,m) << " knights may be placed on a " << n << " row " << m << " column board." << endl;
    }
    return 0;
}