#include <iostream>


using namespace std;

int main(){

    int memo[1001];
    int input, n;
    
    cin >> n;
    
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;

    for(int i=0; i<n; i++){
        
        cin >> input;
        
        for(int j=4; j<= input; j++){
      
            memo[j] = memo[j-1] + memo[j-2] + memo[j-3];
        
        }
        
        
        cout << memo[input] <<'\n';
    }
    
    
    

    return 0;
}
