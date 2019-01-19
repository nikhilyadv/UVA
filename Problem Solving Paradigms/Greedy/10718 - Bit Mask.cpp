#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    unsigned long n,l,u;
    while(cin >> n >> l >> u){
        bitset<32> N(n),X;
        for(int i = 31 ; i >= 0 ; i--){
            if(N[i] == 1){
                X[i] = 0;
                if(X.to_ulong() - 1 + (1<<i) < l)
                    X[i] = 1;
            }
            else{
                X[i] = 1;
                if(X.to_ulong() > u)
                    X[i] = 0;
            }
            /*
            if(N[i] == 1){
                X[i] = 0;
                if(!(X.to_ulong() >= l and X.to_ulong() <= u))
                    X[i] = 1;
            }
            else{
                X[i] = 1;
                if(!(X.to_ulong() >= l and X.to_ulong() <= u))
                    X[i] = 0;
            }*/
        }
        cout << X.to_ulong() << "\n";
    }
    return 0;
}
