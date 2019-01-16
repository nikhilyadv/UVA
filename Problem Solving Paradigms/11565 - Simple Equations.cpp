#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    cin >> n;
    int A, B, C;
    while(n--){
        cin >> A >> B >> C;
        bool solutionFound = false;
        int x, y, z;
        for( x = -58; x <= 58; ++x ){
            for( y = -22; y <= 22; ++y ){
                if( x != y && ( (x * x + y * y) + (A - x - y) * (A - x - y) == C )  ){
                    int temp = x * y;
                    if( temp == 0 ) continue;
                    z = B / temp;
                    if( z != x && z != y && x + y + z == A   ){
                        if(!solutionFound){
                            int tmpArray[3] = {x, y, z};
                            sort(tmpArray, tmpArray + 3);
                            cout << tmpArray[0] << " " << tmpArray[1] << " " << tmpArray[2] << endl;
                            solutionFound = true;
                            break;
                        }
                    }
                }
            }
        }
        if(!solutionFound) std::cout << "No solution." << endl;
    }
    return 0;
}