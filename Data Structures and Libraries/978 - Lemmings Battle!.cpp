#include<bits/stdc++.h>

using namespace std;

int mini(int a , int b , int c){
    int d = min(a,b);
    return min(c,d);
}

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n;
    cin >> n;
    while(n--){
        int battlefields , sg , sb , temp;
        cin >> battlefields >> sg >> sb;
        multiset<int> g , b;
        multiset<int>:: iterator G , B;
        for(int i = 0 ; i < sg ; i++) {
            cin >> temp;
            g.insert(temp);
        }
        for(int i = 0 ; i < sb ; i++) {
            cin >> temp;
            b.insert(temp);
        }
        int result;
        while(true){        //rounds
            if(g.empty() && b.empty()){
                result = 1;
                break;
            }
            else if(g.empty()){
                result = 2;
                break;
            }
            else if(b.empty()){
                result = 3;
                break;
            }
            battlefields = mini(battlefields , g.size() , b.size());
            vector<int> r(battlefields);
            for(int i = 0 ; i < battlefields ; i++){
                G = g.end();    G--;
                B = b.end();    B--;
                r[i] = *G - *B;
                g.erase(G);
                b.erase(B);
            }
            for(int i = 0 ; i < battlefields ; i++)
                if(r[i] > 0)
                    g.insert(r[i]);
                else if(r[i] < 0)
                    b.insert(-1*r[i]);
        }
        switch(result){
            case 1: cout << "green and blue died" << endl; break;
            case 2: cout << "blue wins" << endl;
                    B = b.end();
                    do{
                        B--;
                        cout << *B << endl;
                    }while(B != b.begin());
                    break;
            case 3: cout << "green wins" << endl;
                    G = g.end();
                    do{
                        G--;
                        cout << *G << endl;
                    }while(G != g.begin());
                    break;
        }
        if(n)
            cout << endl;
    }
    return 0;
}