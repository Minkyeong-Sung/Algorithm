#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[11];
int op[4];
int maxSum = -1000000000;
int minSum = 100000000;


void dfs(int index, int n, int plus, int minus, int mul, int div, int sum){
    
    if(index == n){
        
        maxSum = max(maxSum, sum);
        minSum = min(minSum, sum);
        return;
    }
    
    
    
    if(plus >0){
        dfs(index+1, n, plus -1 , minus, mul, div, sum + arr[index]);
    }
    
    if(minus >0){
        dfs(index+1, n, plus  , minus-1, mul, div, sum - arr[index]);
    }
    
    if(mul >0){
        dfs(index+1, n, plus  , minus, mul-1, div, sum * arr[index]);
    }
    
    if(div >0){
        dfs(index+1, n, plus , minus, mul, div-1, sum / arr[index]);
    }






}

int main(){
    ios::sync_with_stdio(false);
    
    
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int j=0; j<4; j++){
        scanf("%d", &op[j]);
    }
    
    dfs(1, n, op[0], op[1], op[2], op[3], arr[0]);
    
    printf("%d\n%d", maxSum, minSum);
    
    return 0;

}



