#include<bits/stdc++.h>

using namespace std;

string a , b;

void print(string c , string d , string stack , string path , int n){
    if(n == 2 * a.length()){
        if(d == b)
            cout << path << endl;
        return;
    }
    if(c.length() > 0)
        print(c.substr(1 , c.length() - 1) , d , stack + c[0] , path + (n == 0 ? "i" : " i") , n + 1);
    if(stack.length() > 0 && stack[stack.length() - 1] == b[d.length()])
        print(c , d + stack[stack.length() - 1] , stack.substr(0 , stack.length()-1) , path + " o" , n + 1);
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    while(cin >> a >> b){
        cout << "[\n";
        if(a.size() == b.size())
            print(a , "" , "" , "" , 0);
        cout << "]\n";
    }
    return 0;
}