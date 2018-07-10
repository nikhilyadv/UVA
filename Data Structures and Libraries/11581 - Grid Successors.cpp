#include<bits/stdc++.h>

using namespace std;
int f[3][3];

void cal(){
    int h[3][3];
    h[0][0] = (f[0][1] + f[1][0]) % 2;
    h[0][1] = (f[0][0] + f[1][1] + f[0][2]) % 2;
    h[0][2] = (f[0][1] + f[1][2]) % 2;

    h[1][0] = (f[0][0] + f[1][1] + f[2][0]) % 2;
    h[1][1] = (f[1][0] + f[0][1] + f[1][2] + f[2][1]) % 2;
    h[1][2] = (f[0][2] + f[1][1] + f[2][2]) % 2;

    h[2][0] = (f[2][1] + f[1][0]) % 2;
    h[2][1] = (f[2][0] + f[1][1] + f[2][2]) % 2;
    h[2][2] = (f[2][1] + f[1][2]) % 2;

    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            f[i][j] = h[i][j];
}

bool zero(){
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            if(f[i][j] > 0)
                return false;
    return true;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    cin >> n;
    while(n--){
        for(int i = 0 ; i < 3 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                scanf("%1d", &f[i][j]);
        int ans = -1;
        while(!zero()){
            cal();
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}