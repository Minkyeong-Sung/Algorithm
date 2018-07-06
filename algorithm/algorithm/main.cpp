#include <iostream>

using namespace std;

int main(){

    int n;
    long long result = 0;
    long long memo[91][2] = {0};
    
    cin >> n;
    
    // 한자리인 경우
    for(int i=0; i<2; i++){
        // 0으로 시작할 수 없다
        if(i != 0){
            memo[1][i] = 1;
        }
    }
    
    
    for(int i=2; i<= n; i++){
        for(int j=0; j<2; j++){
         
            if(j==0){
                memo[i][j] += memo[i-1][j];
            
                memo[i][j] += memo[i-1][j+1];
            }
            else{
                memo[i][j] += memo[i-1][j-1];
            }
        }
    }
    
    for(int i=0; i<2; i++){
        result += memo[n][i];
    }
    
    cout << result;
    

    return 0;
}
