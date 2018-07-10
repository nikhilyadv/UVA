#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int frosh;
    while(cin >> frosh , frosh){
        map<vector<int> , int> mp;
        map<vector<int> , int>:: iterator it;
        vector<int> t(5);
        for(int i = 0 ; i < frosh ; i++){
            for(int j = 0 ; j < 5 ; j++)
                cin >> t[j];
            sort(t.begin() , t.end());
            mp[t]++;
        }
        int max = 0 , maxno = 0;
        for(it = mp.begin() ; it != mp.end() ; it++){
            if(max < (*it).second){
                max = (*it).second;
                maxno = 0;
            }
            if(max == (*it).second)
                maxno += max;
        }
        cout << maxno << endl;
    }
    return 0;
}