#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[11][11];
bool check[11];
int per[11];
int ans  = 2147483647;

void calculator(int per[], int n){

    int sum = 0;
    
    for(int i=0; i<n; i++){
        
        if(arr[per[i]][per[i+1]]==0) return;
        
        sum += arr[per[i]][per[i+1]];
    }
    
    ans = min(ans , sum);
    
    
}


void permutation(int n, int k, int num){

    per[k] = num;
    
    if(n-1==k){
        
        per[n] = per[0];
        
        calculator(per, n);
        
        
        
        return ;
    }
    
    for(int i=0; i<n; i++){
        
        if(check[i] == true) continue;
        
        check[i] = true;
        
        permutation(n, k+1, i);
        
        check[i] = false;
    }

    
}

int main(){
    
    ios_base::sync_with_stdio(false);
    
    int n;
    
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
   
    for(int i=0; i<n; i++){
        
        check[i] = true;
        
        permutation(n, 0, i);
        
        check[i] = false;
    
    }
    
    printf("%d", ans);
    
    return 0;
}





