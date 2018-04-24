#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(){
    
    int n;
    long long dp[101][10]  = {0};
    long long mod = 1000000000;
    
    
    cin >> n;
    
    
    // 길이가 1인 경우
    for(int i=1; i<10; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
    
        for(int j=0; j<10; j++){
        
            // 초기화
            dp[i][j] = 0;
            
            if(j-1 >= 0){
                dp[i][j] += dp[i-1][j-1];
            }
            if(j + 1 <= 9){
                dp[i][j] += dp[i-1][j+1];
            }
            
            dp[i][j] = dp[i][j] % mod;
        }
    }
    
    
    long long cnt = 0;
    
    for(int i=0; i<10; i++){
        cnt += dp[n][i];
    }
    
    cnt = cnt % mod ;
    
    cout << cnt << endl;
    
    
    return 0;
}
