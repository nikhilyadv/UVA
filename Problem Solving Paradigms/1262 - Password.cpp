#include<bits/stdc++.h>

using namespace std;
int k;
char x[5][6] , y[5][6];

int main(){
    //ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> k;
        for(int i = 0 ; i < 6 ; i++) {
            for(int j = 0 ; j < 5 ; j++){
                scanf("%c" , &x[j][i]);
                if(x[j][i] == '\n') j--;
            }
        }
        for(int i = 0 ; i < 6 ; i++) {
                for(int j = 0 ; j < 5 ; j++){
                    scanf("%c" , &y[j][i]);
                    if(y[j][i] == '\n') j--;
                }
            }
        for(int i = 0 ; i < 5 ; i++){
            sort(x[i] , x[i] + 6);
            sort(y[i] , y[i] + 6);
        }
        char p1 , p2 , p3 , p4 , p5;
        int count = 0;
        for(int a = 0 ; a < 6 ; a++){
            if(a > 0 && x[0][a] == x[0][a-1]) continue;
            for(int b = 0 ; b < 6 ; b++){
                if(b > 0 && x[1][b] == x[1][b-1]) continue;
                for(int c = 0 ; c < 6 ; c++){
                    if(c > 0 && x[2][c] == x[2][c-1]) continue;
                    for(int d = 0 ; d < 6 ; d++){
                        if(d > 0 && x[3][d] == x[3][d-1]) continue;
                        for(int e = 0 ; e < 6 ; e++){
                            if(e > 0 && x[4][e] == x[4][e-1]) continue;
                            p1 = x[0][a];
                            p2 = x[1][b];
                            p3 = x[2][c];
                            p4 = x[3][d];
                            p5 = x[4][e];
                            if(binary_search(y[0] , y[0] + 6 , p1) && binary_search(y[1] , y[1] + 6 , p2) && binary_search(y[2] , y[2] + 6 , p3) && binary_search(y[3] , y[3] + 6 , p4) && binary_search(y[4] , y[4] + 6 , p5))
                                count++;
                            if(count == k)
                                goto lb;
                        }
                    }
                }
            }
        }
        lb:
            if(count == k)
                cout << p1 << p2 << p3 << p4 << p5;
            else
                cout << "NO";
        cout << endl;
    }
    return 0;
}