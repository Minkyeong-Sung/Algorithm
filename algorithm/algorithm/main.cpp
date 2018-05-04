#include <iostream>

using namespace std;

int main(){

    int n;
    int check[1000001];
    int pn=0;
    int prime[1000000] ;
    
    
    for(int i = 2; i <= 1000000; i++){
        
        if(check[i] == false){
            
            prime[pn++] = i;
        
            for(int j= i*i; j<= 1000000; j += i){
                    check[j] = true;
            }
        }
    }
    
    check[2] = true;
    
    
    while(1){
        cin >> n;
        
        if(n==0){
            break;
        }
        
        
        for(int i=1; i< pn; i++){
            
            if(check[n-prime[i]] == false){
                cout << n << " = " << prime[i] <<  " + " << n-prime[i] << '\n';
                break;
            }
            
        }
        
    }


    return 0;
}
