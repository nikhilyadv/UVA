#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int t , tc = 0 , n;
    cin >> t;
    while(t--){
        tc++;
        cin >> n;
        int temp , max = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            if(temp > max)
                max = temp;
        }
        cout << "Case " << tc << ": " << max << endl;
    }
    return 0;
}