#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    cin >> n;
    while(n--){
        char ch;
        int r , c;
        cin >> ch >> r >> c;
        switch(ch){
            case 'r' : cout << min(r,c) << endl;
                        break;
            case 'Q' : cout << min(r,c) << endl;
                        break;
            case 'k' : cout << ceil(float(r*c) / 2.0) << endl;
                        break;
            case 'K' : if(r%2 != 0) r++;
                       if(c%2 != 0) c++;
                       cout << ceil(r*c/4) << endl;
        }
    }
    return 0;
}