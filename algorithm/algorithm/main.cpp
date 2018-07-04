#include <iostream>


using namespace std;

int main(){

    int memo[1001];
    int input;
    
    cin >> input;
    
    memo[0] = 1;
    memo[1] = 1;
    
    
    for(int i=2; i<= input; i++){
      
        memo[i] = memo[i-1] + 2*memo[i-2];
    
        memo[i] %= 10007;
    }
    
    
    cout << memo[input];
    

    return 0;
}
