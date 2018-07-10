#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    long long n , s , d;
    cin >> n;
    while(n--){
        cin >> s >> d;
        if((s < d) || (s%2 == 0 && d%2 == 1) || (s%2 == 1 && d%2 == 0))   cout << "impossible\n";
        else    cout << (s + d) / 2 << " " << (s - d) / 2 << endl;
    }
    return 0;
}