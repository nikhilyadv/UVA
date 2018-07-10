#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , flag;
    while(cin>>n){
        vector <int> a(n);
        vector <bool> status(n);
        for(int i = 0 ; i < n ; i++) {
            cin >> a[i];
            status[i] = false;
        }
        int diff;
        for(int i = 0 ; i < n - 1 ; i++){
            diff = abs(a[i+1] - a[i]);
            if(diff != 0 && diff <= n -1)
                status[diff] = true;
        }
        flag = 1;
        for(int i = n - 1 ; i > 0 ; i--)
            if(status[i] != true) {
                cout << "Not jolly" << endl;
                flag = 0;
                break;
            }
        if(flag == 1)
            cout<<"Jolly"<<endl;
    }
    return 0;
}
