#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    while(cin >> n , n){
        multiset<int> s;
        multiset<int>:: iterator a , b;
        int m , temp;
        unsigned long long cost = 0;
        for(int i = 0 ; i < n ; i++){
            cin >> m;
            for(int j = 0 ; j < m ; j++){
                cin >> temp;
                s.insert(temp);
            }
            a = s.begin();
            b = s.end();    b--;
            cost += *b - *a;
            s.erase(a); s.erase(b);
            m = 2*(n-i+1);
            if(s.size() > m){
                temp = n-i+1;
                a = s.begin();
                b = s.end();
                while(temp){
                    a++;
                    b--;
                    temp--;
                }
                s.erase(a,b);
            }
        }
        cout << cost << endl;
    }
    return 0;
}