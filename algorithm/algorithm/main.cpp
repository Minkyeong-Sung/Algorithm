#include <iostream>

using namespace std;

int main(){
    
    int n;
    long long data[100001];
    long long dp[100001];
    
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> data[i];
    }
    
    dp[1] = data[1];
    
    for(int i=2; i<= n; i++){
        
        dp[i] = data[i];
        
        if(dp[i] > dp[i-1] + data[i]){
            continue;
        }
        dp[i] = max(dp[i], dp[i-1] + data[i]);
        
    }
    
    
    long long ans = dp[1];
    for(int i=1; i<= n; i++){
        ans = max(ans, dp[i]);
    }
    
    cout << ans;




    return 0;
}
