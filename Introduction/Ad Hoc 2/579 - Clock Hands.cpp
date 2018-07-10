#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    char h1 , h2 , ch , m1 , m2;
    int flag;
    while(1){
        flag = 0;
        cin >> h1 >> h2;
        if(h2 != ':') {
            cin >> ch;
            flag = 1;
        }
        cin >> m1 >> m2;
        double angle;
        int H , M;
        M = int(m1 - '0') * 10 + int(m2 - '0');
        if(flag == 1)
            H = int(h1 - '0') * 10 + int(h2 - '0');
        else
            H = int(h1 - '0');
        if(H == 0 && M == 0)
            break;
        angle = fabs((30.0 * H + M/2.0) - 6.0 * M);
        cout << fixed << setprecision(3) << min(angle , 360.000 - angle) << endl;
    }
    return 0;
}