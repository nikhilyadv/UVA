#include<bits/stdc++.h>

using namespace std;

int main(){
    int a ,b ,c;
    while(cin>>a>>b>>c , a!=0 || b!=0 || c!=0){
        int numberx , numbery ;
        numberx = (a - 7);
        numbery = (b - 7) ;
        if(c == 0)
            cout<<numberx * numbery / 2<<endl;
        else
            cout<<(numberx * numbery + 1 )/2<<endl;
    }
    return 0;
}
