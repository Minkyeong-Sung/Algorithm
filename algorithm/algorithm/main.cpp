#include <iostream>

using namespace std;

int main(){

    int dp[1001][10] = {0};
    int n, cnt =0;
    
    cin >> n;
    
    
    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
        
            int tmp = j;
            while(tmp>=0){
                dp[i][j] += (dp[i-1][tmp]);
                tmp--;
            }
            
            dp[i][j] %= 10007;
        }
    }



    for(int i=0; i<10; i++){
        cnt += dp[n][i];
    }
    
    cnt = cnt % 10007;
    
    cout << cnt << endl;
    
    return 0;
}
