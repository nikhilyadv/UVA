#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    vector<int> v;
    int temp;
    while(cin >> temp){
        v.push_back(temp);
        sort(v.begin() , v.end());
        int n = v.size();
        if(n % 2 != 0){
            nth_element(v.begin(), v.begin() + n / 2, v.end());
            cout << v[n/2] << endl;
        }
        else{
            nth_element(v.begin(), v.begin() + n / 2, v.end());
            nth_element(v.begin(), v.begin() + (n - 1) / 2, v.end());
            cout << (v[n/2] + v[(n-1)/2])/2 << endl;
        }
        /*for(int i = 0 ; i < n ; i++)
            cout << v[i] << " ";
        cout << endl;*/
    }
    return 0;
}