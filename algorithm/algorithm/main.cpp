#include <iostream>


using namespace std;

int main(){

    int memo[1000001];
    int input;
    
    cin >> input;
    
    memo[1] = 0;
    
    for(int i=2; i<=input; i++)
    {
        
        memo[i] = memo[i-1] + 1;
        
        if(i%2 == 0  && memo[i] > memo[i/2] + 1 ){
            
            memo[i] = memo[i/2] + 1;
        }
        
        if(i%3 == 0 && memo[i] > memo[i/3] + 1  ){
            
            memo[i] = memo[i/3] + 1;
        }
    }
   
    cout << memo[input];
    

    return 0;
}
