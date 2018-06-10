#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int k , n , m , x , y;
    while(cin >> k , k){
        cin >> n >> m;
        while(k--){
            cin >> x >> y;
            x -= n;
            y -= m;
            if(x == 0 || y == 0)
                cout << "divisa" << endl;
            else
                if(x > 0 && y > 0)
                    cout << "NE" << endl;
                else if(x > 0 && y < 0)
                    cout << "SE" << endl;
                else if(x < 0 && y > 0)
                    cout << "NO" << endl;
                else
                    cout << "SO" << endl;
        }
    }
}