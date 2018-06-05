#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define wide 100
#define high 100

int main(){
    
    int arr[high][wide] = {0};
    int max = 0;
    int sum = 0;
    int n;
    
    for(int k=0; k<10; k++){
        
        cin >> n;
        
        memset(arr, 0, sizeof(arr));
        max = 0;
        sum = 0;
        
        // input
        for(int i=0; i< high; i++){
            sum = 0;
            
            for(int j= 0; j< wide; j++){
                int input;
                cin >> input;
            
                arr[i][j] = input;
                
                sum += input;
            }
            
            // 행
            if(max < sum){
                max = sum;
            }
        }
        
        // 대각선
        sum = 0;
        int sum1 = 0;
        
        for(int i=0; i<high; i++){
            sum += arr[i][i];
            sum1 += arr[i][high-1-i];
        }
        
        
        if(sum> max){
            max = sum;
        }
        if(sum1 > max){
            max = sum1;
        }
        
        // 열
        for(int i=0; i<high; i++){
            sum = 0;
            for(int j=0; j<wide; j++){
                sum += arr[j][i];
            }
            
            if(sum > max){
                max = sum;
            }
        }
        
        cout << "#" <<n << ' ' << max << '\n';
        
    }

    return 0;
    
}
