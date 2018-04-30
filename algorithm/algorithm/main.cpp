#include <iostream>

using namespace std;

int main(){

    long long dp[101] = {0};
    int n, index=0;
    
    cin >> n;
    
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    
    
    for(int i=0; i<n; i++){
        cin >> index;
        
        for(int j=4; j<= index; j++){
            
            dp[j] = dp[j-2] + dp[j-3];
        }
        
        cout << dp[index] << endl;
        
    }



    return 0;
}
