#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi cyclelen(1000001);

int checklen(int i){
    int n = i;
    if(cyclelen[i] != -1)
        return cyclelen[i];
    else{
        cyclelen[n] = 1;
        while(i != 1){
            if(i % 2 == 1)
                i = 3*i+1;
            else
                i = i / 2;
            cyclelen[n]++;
        }
    }
    return cyclelen[n];
}

int main(){
    fill(cyclelen.begin() , cyclelen.end() , -1);
    int i , j;
    while(cin>>i>>j){
        int max = INT_MIN;
        if(i <= j)
            for(int k = i ; k <= j ; k++){
                if(checklen(k) > max)
                    max = checklen(k);
            }
        else
            for(int k = j ; k <= i ; k++){
                if(checklen(k) > max)
                    max = checklen(k);
            }
        cout<<i<<" "<<j<<" "<<max<<endl;
    }
    return 0;
}
