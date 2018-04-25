#include <iostream>
#include <algorithm>

using namespace std;


long long dp[100000][3] = {0};
long long data[2][100000] = {0};




int main(){

    int testCase, n;
    
    cin >> testCase;
    
    for(int i=0; i<testCase; i++){
    
        cin >> n;
        // input
        for(int h=0; h<2; h++){
            for(int j=1; j<= n; j++){
        
                cin >> data[h][j];
            }
        }
        
        int l=0, k=0;
        for( l=1; l<= n; l++){
            for( k=0; k<3; k++){
            
            
                if(k==0){ // X X
                    dp[l][k] = max(dp[l-1][0], max(dp[l-1][1] , dp[l-1][2]));
                }
                
                if(k==1){ // X O
                    dp[l][k] = max(dp[l-1][0], dp[l-1][2] ) + data[0][l]  ;
                }
                
                if(k==2){ // O X
                    dp[l][k] = max(dp[l-1][0] , dp[l-1][1] ) +  data[1][l] ;
                }
                
            }
        }
        
        
        
        long long ans = 0;
        for(int j=1; j<= n; j++){
            ans = max(dp[j][0], max( dp[j][1], dp[j][2]));
        }
        
        cout << ans << endl;
    }
    
    

    return 0;
}













