#include<bits/stdc++.h>

using namespace std;

unordered_map<char , char> mp;

void setmap(){
    mp['A'] = 'A';
    mp['E'] = '3'; mp['3'] = 'E';
    mp['H'] = 'H';
    mp['I'] = 'I';
    mp['J'] = 'L'; mp['L'] = 'J';
    mp['M'] = 'M';
    mp['0'] = '0'; mp['O'] = 'O';
    mp['S'] = '2'; mp['2'] = 'S';
    mp['T'] = 'T';
    mp['U'] = 'U';
    mp['V'] = 'V';
    mp['W'] = 'W';
    mp['X'] = 'X';
    mp['Y'] = 'Y';
    mp['Z'] = '5'; mp['5'] = 'Z';
    mp['A'] = 'A';
    mp['1'] = '1';
    mp['8'] = '8';
}

int checkpal(string s){
    int flag = 1;
    for(long long i = 0 , j = s.size() - 1 ; i < j ; i++ ,j--){
        if(s[i] != s[j]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int notcheckmir(char ch1 , char ch2){
    if(mp[ch1] == ch2)
        return 0;
    return 1;
}

int checkmir(string s){
    int flag = 1;
    for(long long i = 0 , j = s.size() - 1 ; i <= j ; i++ ,j--){
        if(notcheckmir(s[i] , s[j])){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);
    setmap();
    string s;
    while(cin >> s){
        int flagpal = 0 , flagmir = 0;
        flagpal = checkpal(s);
        flagmir = checkmir(s);
        cout << s << " -- is ";
        if(flagpal == 0 && flagmir == 0)
            cout << "not a palindrome.";
        else if (flagpal == 1 && flagmir == 0)
            cout << "a regular palindrome.";
        else if (flagpal == 0 && flagmir == 1)
            cout << "a mirrored string.";
        else
            cout << "a mirrored palindrome.";
        cout << endl << endl;
        s.erase();
    }
    return 0;
}