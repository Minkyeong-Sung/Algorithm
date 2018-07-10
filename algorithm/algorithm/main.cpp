#include <iostream>
#include <cstdio>

using namespace std;

int main(){


    int n, m, a, b;
    int data[2001];
    int dp[2001][2001];
    
    scanf("%d", &n);
    
    for(int i=1; i<= n; i++){
        scanf("%d", &data[i]);
    }
    
    
    // 길이가 1인경우
    for(int i=1; i<= n; i++){
        dp[i][i] = 1;
    }
    
    // 길이가 2인 경우
    for(int i=1; i<= n-1; i++){
        if(data[i] == data[i+1]){
            dp[i][i+1] = 1;
        }
    }
    
    // 길이가 3 이상
    for(int k=3; k<= n; k++){
        for(int i = 1; i <= n - k + 1; i++){
            int j = i + k -1;
            
            if(data[i] == data[j] && dp[i+1][j-1] == 1 ){
                dp[i][j] = 1;
            }
        }
    }
    
    scanf("%d", &m);
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a][b]);
    }

    return 0;
}
