#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int f , r , index;
    vector<int> a(10) , b(10);
    vector<double> c(100);
    while(cin >> f , f){
        index = 0;
        cin >> r;
        for(int i = 0 ; i < f ; i++)    cin >> a[i];
        for(int i = 0 ; i < r ; i++)    cin >> b[i];
        for(int i = 0 ; i < f ; i++)
            for(int j = 0 ; j < r ; j++)
                c[index++] = double(b[j])/double(a[i]);
        sort(c.begin(),c.begin() + index);
        double maxi = 0;
        for(int i = 0 ; i < index - 1; i++){
            maxi = max(maxi , c[i+1]/c[i]);
        }
        cout << fixed << setprecision(2) << maxi << endl;

    }
    return 0;
}