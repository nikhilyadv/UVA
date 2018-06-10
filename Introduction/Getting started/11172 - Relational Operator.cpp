#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    long long t , a , b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(a == b){
            cout << "=" << endl;
        }
        else
            a > b ? cout << ">\n" : cout << "<\n";
    }
}