#include<bits/stdc++.h>

using namespace std;

int main(){
    int n , k ;
    double sum;
    vector <int> in(256);
    cin>>n;
    while(n--){
        fill(in.begin() , in.end() , -2);
        char ch;
        sum = 0;
        cin>>k;
        for(int i = 0 ; i < k ; i++){
            cin>>ch;
            cin>>in[int(ch)];
        }
        string line;
        cin>>k;
        cin.ignore();
        for(int i = 0 ; i < k ; i++){
            getline(cin , line);
            for(int j = 0 ; j < line.size() ; j++){
                if(in[int(line[j])] != -2)
                    sum += in[int(line[j])];
            }
        }
        cout<< fixed <<setprecision(2)<< sum/100.0 <<"$\n";

    }
    return 0;
}
