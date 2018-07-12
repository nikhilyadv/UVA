#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m , q , tc = 1 , min , flag;
    while(cin >> n , n){
        vector<int> a(n);
        for(int  i = 0 ; i < n ; i++)
            cin >> a[i];
        cin >> m;
        cout << "Case " << tc++ << ":" << endl;
        for(int i = 0 ; i < m ; i++){
            cin >> q;
            min = INT_MAX;
            for(int j = 0 ; j < n ; j++){
                for(int k = j+1 ; k < n ; k++){
                    if(q - (a[k]+a[j]) >= 0 && q - (a[k]+a[j]) < min)
                        min = q - (a[k]+a[j]) , flag = 0;
                    if(q - (a[k]+a[j]) < 0 && (a[k]+a[j]) - q < min)
                        min = (a[k]+a[j]) - q , flag = 1;
                }
            }
            cout << "Closest sum to " << q << " is " << (flag ? q+min : q-min) << "." << endl;
        }
    }
    return 0;
}