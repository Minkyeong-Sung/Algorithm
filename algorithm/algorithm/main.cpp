#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int arr[4][8];
bool check[4];
int k;

void change(int array[], int direct){

    int tmp;
    
    if(direct == 1){
        // 시계방향
        tmp = array[7];
        
        for(int i=7; i>0 ; i--){
            array[i] = array[i-1];
        }
        
        array[0] = tmp;
    }
    else{
        // 반시계방향
        tmp = array[0];
        
        for(int i=0; i<7; i++){
            array[i] = array[i+1];
        }
        
        array[7] = tmp;
    }
}


void Rotate(int num, int direct){

    check[num] = true;
    
    // 이웃하는 톱니바퀴 체크
    if(num+1 < 4 && !check[num+1]){
        if(arr[num][2] != arr[num+1][6]){
            Rotate(num+1, -1 * direct);
        }
    }
    
    if(num-1 >= 0 && !check[num-1]){
        if(arr[num][6] != arr[num-1][2]){
            Rotate(num-1, -1 * direct);
        }
    }

    
    change(arr[num], direct);



}


int main(){
    
    // 톱니바퀴 정보
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    int n, num, dir;
    
    // 테스트 케이스 입력
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &num, &dir);
        
        memset(check, 0, sizeof(check));
        
        Rotate(num-1, dir);
    }
    
    
    int res = 0;
    
    for(int i=0; i<4; i++){
        
        int tmp = 1;
        
        if(arr[i][0] == 1){
            for(int j=0; j<i; j++){
                tmp *= 2;
            }
            res += tmp;
        }
        
        
        
    }
    
    printf("%d\n", res);
    
    return 0;
}
