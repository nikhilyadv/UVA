#include<bits/stdc++.h>

#define ll long long;

using namespace std;

int main(){
    int n,m,s,iindex,jindex,count;
    char currentdirection;
    while(cin>>n>>m>>s,n||m||s){
        count=0;
        char arr[n][m],ins[s];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='N' || arr[i][j]=='S' || arr[i][j]=='L' || arr[i][j]=='O'){
                    iindex=i;
                    jindex=j;
                    currentdirection=arr[i][j];
                }
            }
        }
        for(int i=0;i<s;i++) {
            cin>>ins[i];
            if(ins[i]=='D') {
                switch (currentdirection) {
                    case 'N' :
                        currentdirection = 'L';
                        break;
                    case 'L' :
                        currentdirection = 'S';
                        break;
                    case 'S' :
                        currentdirection = 'O';
                        break;
                    case 'O' :
                        currentdirection = 'N';
                        break;

                }
            }
            else if(ins[i]=='E') {
                switch (currentdirection) {
                    case 'N' :
                        currentdirection = 'O';
                        break;
                    case 'L' :
                        currentdirection = 'N';
                        break;
                    case 'S' :
                        currentdirection = 'L';
                        break;
                    case 'O' :
                        currentdirection = 'S';
                        break;

                }
            }
            else {
                switch (currentdirection) {
                    case 'N' :
                        if (iindex > 0 && arr[iindex - 1][jindex] != '#')
                            iindex--;
                        break;
                    case 'L' :
                        if (jindex < m-1 && arr[iindex][jindex + 1] != '#')
                            jindex++;
                        break;
                    case 'S' :
                        if (iindex < n-1 && arr[iindex + 1][jindex] != '#')
                            iindex++;
                        break;
                    case 'O' :
                        if (jindex > 0 && arr[iindex][jindex - 1] != '#')
                            jindex--;
                        break;
                }
                if(arr[iindex][jindex]=='*'){
                    count++;
                  //  cout<<iindex<<" "<<jindex<<endl;
                    arr[iindex][jindex]='.';
                  //  cout<<arr[iindex][jindex]<<endl;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
