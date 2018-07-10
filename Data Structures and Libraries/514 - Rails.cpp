#include<bits/stdc++.h>

using namespace std;

void Y(){
    cout << "Yes" << endl;
}

void N(){
    cout << "No" << endl;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    int n , a[5000];
    while(cin >> n , n){
        while(cin >> a[0] , a[0]){
            for(int i = 1 ; i < n ; i++)
                cin >> a[i];
            stack<int> s;
            int counter = 1 , index = 0;
            while(counter <= n){
                s.push(counter);
                while(!s.empty() && s.top() == a[index]){
                    s.pop();
                    index++;
                    if(index >= n)
                        break;
                }
                counter++;
            }
            if(s.empty())   Y();
            else            N();
        }
        cout << endl;
    }
    return 0;
}