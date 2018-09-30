#include <iostream>
#include <vector>

using namespace std;

int arr[50];
int ans[50];
int N;

void lotto(int s, int n){

    if(n == 6){
        
        for(int i=0; i<6; i++){
            cout << ans[i] << ' ';
        }
        cout <<'\n';
        return;
    }
    
    for(int i=s; i<N; i++){
    
        ans[n] = arr[i];
        lotto(i+1, n+1);
    }
    

}

int main(){
    
    
    while(1){
        
        cin >> N;
        
        if(N==0) break;
        
        for(int i=0; i<N; i++){
            cin >> arr[i];
        }
    
        lotto(0, 0);
        cout <<'\n';
    
    }

    return 0;
}
