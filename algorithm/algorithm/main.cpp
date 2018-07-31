#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int check[101]; // 경사로를 만들었는지 확인


// 시작점 , n개, 경사로 길이 , 배열
int solve(int start, int n,int L, int arr[101][101]){

    
    for(int i=1; i<n; i++){
    
        // 경사로 차이가 2 이상인 경우
        if( abs(arr[start][i]-arr[start][i+1]) > 1 ){
            return 0;
        }
    
        int tmp = 0;
        
        // 왼쪽이 더 큰 수일 경우
        if(arr[start][i] > arr[start][i+1]){
            
            tmp = arr[start][i+1];
            
            // 범위 초과
            if(i+L > n ) return 0;
            
            for(int j=i+1; j<= i+L; j++){
                
                // 이미 경사로
                if(check[j] == -1){
                    return 0;
                }
                
                if(tmp != arr[start][j]){
                    return 0;
                }
            }
            
            // 경사로 표시
            for(int j=i+1; j <= i + L; j++){
                check[j] = -1;
            }
            i = i + L -1;
        
        }
        else if(arr[start][i] < arr[start][i+1]){
        
            if(i-L+1 < 1) return 0;
            
            tmp = arr[start][i];
            
            for(int j=i; j >= i-L+1; j--){
                
                if(check[j] == -1){
                    return 0;
                }
                
                if(tmp != arr[start][j]){
                    return 0;
                }
            }
            
            for(int j=i; j>= i-L+1; j--){
                check[j] = -1;
            }
        
        }
    }

    return 1;
}



int main(){
    
    int arr[101][101];
    int reverseArr[101][101];
    int n, L;
    
    cin >> n >> L;

    for(int i=1; i<= n; i++){
        for(int j=1; j<= n; j++){
            cin >> arr[i][j];
            reverseArr[j][i] = arr[i][j];
        }
    }
    
    int ans = 0;
    
    for(int i=1; i<= n; i++){
        
        memset(check, 0, sizeof(check));
        ans += solve(i,n, L, arr);
        memset(check, 0, sizeof(check));
        ans += solve(i, n, L, reverseArr);
    
    
    }
    
    cout << ans ;
    
    return 0;
}
