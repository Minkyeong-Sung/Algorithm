#include <iostream>

using namespace std;

int main(){

    int n;
    long long dp[101][101] = {0};
    long long data[101][101] = {0};
    
    cin >>n;
    
    for(int i=1; i<= n; i++){
        for(int j=1; j<= n; j++){
            cin>> data[i][j];
        }
    }
    
    dp[1][1] = 1;
    
    for(int i=1; i<= n; i++){
        for(int j=1; j<= n; j++){
            
            if(data[i][j] != 0){
            
                if(j + data[i][j] <= n){
                    // 오른쪽 이동
                    dp[i][j + data[i][j]] += dp[i][j];
                }
                
                if(i+ data[i][j] <= n){
                    // 왼쪽 이동
                    dp[i+ data[i][j]][j] += dp[i][j];
                }
            }
        }
    }
    
    cout << dp[n][n] ;
    
    




    return 0;
}
