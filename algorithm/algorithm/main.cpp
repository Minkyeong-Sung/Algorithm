#include <iostream>


using namespace std;

int main(){

    int n, m;
    int data[1001][1001] = {0};
    int dp[1001][1001] = {0};
    
    cin >> n >> m;
    
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
            cin >> data[i][j];
        }
    }
    
    for(int i=1; i<= n; i++){
        for(int j=1; j<= m; j++){
        
            dp[i][j] += max(dp[i-1][j] , dp[i][j-1]) + data[i][j];
         
        }
    }
    
    cout << dp[n][m];
    





    return 0;
}
