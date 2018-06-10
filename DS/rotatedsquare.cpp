#include<bits/stdc++.h>

using namespace std;

int main(){
    int N , n;
    cin>>N>>n;
    while(N!=0 && n!=0){
        vector <string> A(N);
        vector <string> a(n);
        for(int I = 0 ; I < N ; I++)
            cin>>A[I];
        for(int i = 0 ; i < n ; i++)
            cin>>a[i];
        vector <int> count(4);
        vector <int> flag(4);
        fill(count.begin() , count.end() , 0);
        for(int I = 0 ; I < N - n + 1;  I++){
            for(int J =  0 ; J < N - n + 1 ; J++){
                fill(flag.begin() , flag.end() , 0);
                for(int i = 0 ; i < n ; i++){
                    for(int j = 0 ; j < n ; j++){
                        if(A[I+i][J+j] != a[i][j])
                            flag[0] = 1;
                        if(A[I+i][J+j] != a[n-1-j][i])
                            flag[1] = 1;
                        if(A[I+i][J+j] != a[n-1-i][n-1-j])
                            flag[2] = 1;
                        if(A[I+i][J+j] != a[j][n-1-i])
                            flag[3] = 1;

                    }
                }
                for(int i = 0 ; i < 4 ; i++){
                    if(flag[i] == 0)
                        count[i]++;
                }
            }
        }
        cout<<count[0]<<" "<<count[1]<<" "<<count[2]<<" "<<count[3]<<endl;
        cin>>N>>n;
    }
    return 0;
}
