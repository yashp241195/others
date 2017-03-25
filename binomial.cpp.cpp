#include <iostream>
using namespace std;

int binomial(int n, int r);
int memo[20][21];

int main() {
    int n, r, i, j, k,lim,power;
    power=19;//upto what power of (a+b) max power =19
    n=power+1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n+1; j++) {
            if(j == 0 || j == i) {
                memo[i][j] = 1;
            }
            else {
                memo[i][j] = 0;
            }
        }
    }

    
    for(i=0;i<((n/2)+1);i++)
    binomial(n, i);//traverse half bcz we already have duplicate right as we coded in binomial function

    for (i = 0; i < n; i++) {
        
        lim=(5/2)*(n-i);// left side spacing factor
        
        for (k=0;k<=lim;k++)
           cout<<" ";
        
        for (j = 0; j < n+1; j++) {
             
             if(memo[i][j] != 0)
            cout<<memo[i][j]<<" ";
        }
        cout << endl;
    }
}

int binomial(int n, int r) {
    if (memo[n][r] != 0) {
        memo[n][n-r]=memo[n][r];//left-right mirror image code
        return memo[n][r];
    }
    if (r == 0 || r == n) {
        memo[n][r] = 1;
        return memo[n][r];
    }
    else {
        memo[n][r] = binomial(n - 1, r - 1) + binomial(n - 1, r);
        return memo[n][r];
    }
}
