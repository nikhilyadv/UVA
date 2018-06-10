#include<bits/stdc++.h>

using namespace std;

int main(){
    double cow , car , show;
    double answer = 1;
    while(cin>>cow>>car>>show){
        answer = (cow/(cow + car))*(car/(cow + car - show - 1)) +  (car/(cow + car))*((car-1)/(cow + car - show - 1));
        cout<<fixed<<setprecision(5)<<answer<<endl;
    }
    return 0;
}
