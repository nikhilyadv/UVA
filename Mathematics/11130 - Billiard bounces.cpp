#include<bits/stdc++.h>

using namespace std;

#define PI 3.14159265

int main(){
    int a , b ,v , s;
    double A;
    while(cin>>a>>b>>v>>A>>s , a!=0 || b!=0 || v!=0 || s!=0){
        double dx , dy ;
        double countx = 0 , county =0 ;
        A = A * PI / 180;
        dx = v * cos(A) * s / 2;
        dy = v * sin(A) * s / 2;
        countx = dx / a;
        county = dy / b;
        cout<<fixed<<setprecision(0)<<countx<<" "<<county<<"\n";
    }
    return 0;
}
