#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("in.txt" , "r" ,stdin);
    freopen("out.txt" , "w" , stdout);
    int a , b , c , d;
    long long sum , pro;
    for(a = 1 ; a+a+a+a <= 2000 ; a++)
        for(b = a ; a+b+b+b <= 2000 ; b++)
            for(c = b ; a+b+c+c <= 2000 ; c++) {
                pro = (long long) a * b * c;
                if (pro <= 1000000)
                    continue;
                sum = a + b + c;
                if ((sum * 1000000) % (pro - 1000000))
                    continue;
                d = (sum * 1000000) / (pro - 1000000);
                sum += d;
                if (sum > 2000 || d < c)
                    continue;
                printf("%d.%02d %d.%02d ", a/100, a%100, b/100, b%100);
                printf("%d.%02d %d.%02d\n", c/100, c%100, d/100, d%100);
            }
    return 0;
}