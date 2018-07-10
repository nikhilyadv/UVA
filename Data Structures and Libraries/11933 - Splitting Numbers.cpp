#include<bits/stdc++.h>

using namespace std;

bitset<50> num , a , b;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    unsigned int n;
    while(cin >> n , n){
        num = n;
        a.reset();
        b.reset();
        int index = 0 , counter = 0;
        while(index < 32){
            if(num.test(index)){
                if(counter % 2 == 0)
                    a.set(index);
                else
                    b.set(index);
                counter++;
            }
            index++;
        }
        cout << a.to_ulong() << " " << b.to_ulong() << endl;
    }
    return 0;
}