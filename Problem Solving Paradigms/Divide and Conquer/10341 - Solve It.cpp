#include<bits/stdc++.h>

using namespace std;

double foo(double x, int p, int q, int r, int s, int t, int u){
    return double(p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int p, q, r, s, t, u, iter;
    while(cin >> p >> q >> r >> s >> t >> u){
        iter = 0;
        double e = 1e-7, a = 0.0, b = 1.0, d;
        d = (a+b)/2;
        while(abs(foo(d,p,q,r,s,t,u)) > e){
            iter++;
            double temp = foo(d,p,q,r,s,t,u);
            if(temp > 0) a = d;
            else                       b = d;
            d = (a+b)/2;
            if(iter == 500) break;
        }
        if (iter == 500) cout << "No solution\n";
        else             cout << fixed << setprecision(4) << d << "\n";
    }
    return 0;
}
