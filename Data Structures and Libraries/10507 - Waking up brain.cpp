#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int n , m;
    while(cin >> n >> m){
        string s;
        vector<int> present(26) , awake(26);
        vector<vector<int>> edgelist(26);
        cin >> s;
        present[int(s[0]-'A')] = 1  , awake[int(s[0]-'A')] = 1;
        present[int(s[1]-'A')] = 1  , awake[int(s[1]-'A')] = 1;
        present[int(s[2]-'A')] = 1  , awake[int(s[2]-'A')] = 1;
        getline(cin , s);
        while(getline(cin , s)){
            if(s.empty())
                break;
            int from = int(s[0]-'A') , to = int(s[1]-'A');
            present[from] = 1;
            present[to] = 1;
            edgelist[from].push_back(to);
            edgelist[to].push_back(from);
        }
        int years = 0 , flag = 1 , count = 3;
        while(count < n && flag){
            vector<int> nw;
            for(int i = 0 ; i < 26 ; i++){
                if(!present[i] || awake[i])
                    continue;
                int neg = 0;
                for(int j = 0 ; j < edgelist[i].size() ; j++) {
                    if (awake[edgelist[i][j]])
                        neg++;
                    if(neg > 2)
                        break;
                }
                if(neg > 2) nw.push_back(i);
            }
            if(nw.empty())
                flag = 0;
            for(int i : nw) {
                awake[i] = 1;
                count++;
            }
            years++;
        }
        if(flag)
            cout << "WAKE UP IN, "<< years <<", YEARS";
        else
            cout << "THIS BRAIN NEVER WAKES UP";
        cout << endl;
    }
    return 0;
}