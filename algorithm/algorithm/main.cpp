#include <iostream>

using namespace std;

int main(){

    int n, ans = 0;
    int data[1001];
    int dp_up[1001] = {0};
    int dp_down[1001] = {0};
    
    cin >> n;
    
    for(int i=1; i<= n; i++){
        cin >> data[i];
    }
    
    for(int i=1; i<= n; i++){
        
        dp_up[i] = 1;
        // 증가
        for(int j=1; j<i; j++){
            
            if(data[i] > data[j]){
                dp_up[i] = max(dp_up[i], dp_up[j] +1 );
                
            }
        }
        
        // 감소
        for(int k=n; k>=i; k--){
            
            dp_down[k] = 1;
            
            for(int j=n; j>k; j--){
            
                if(data[k] > data[j]){
                    
                    dp_down[k] = max(dp_down[k], dp_down[j]+1);
                }
            }
        }
        
        ans = max(ans, dp_up[i]+ dp_down[i]);
        
    }
    
    

    cout << ans -1 << endl;


    return 0;
}
