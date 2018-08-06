#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dice[7] = {0, 0, 0, 0, 0, 0, 0};
int arr[21][21];
vector<int> vt;

// 공백 우 좌 상 하
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int change[] = {0, 6,5,4,3,2,1};
int x, y;

// 처음은 1번에서 시작!
void moveDice(int n){

    int t1,t2 ,t3, t4;
    
    if(n==1){
    
        t1 = dice[3];
        t2 = dice[1];
        t3 = dice[4];
        t4 = dice[6];
        
        dice[3] = t2;
        dice[1] = t3;
        dice[4] = t4;
        dice[6] = t1;
    }
    else if(n==2){
        
        t1 = dice[3];
        t2 = dice[1];
        t3 = dice[4];
        t4 = dice[6];
        
        dice[3] = t4;
        dice[1] = t1;
        dice[4] = t2;
        dice[6] = t3;
    }
    else if(n==3){
        
        t1 = dice[2];
        t2 = dice[1];
        t3 = dice[5];
        t4 = dice[6];
        
        dice[2] = t2;
        dice[1] = t3;
        dice[5] = t4;
        dice[6] = t1;
    }
    else{
        
        t1 = dice[2];
        t2 = dice[1];
        t3 = dice[5];
        t4 = dice[6];
        
        dice[2] = t4;
        dice[1] = t1;
        dice[5] = t2;
        dice[6] = t3;
    }

}


int main(){
    
    int n, m,  k, num;
    
    cin >> n>> m >> x >> y >> k;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    // 주사위 굴리기
    for(int i=0; i<k; i++){
    
        cin >> num;
        
        int next_x = x + dx[num];
        int next_y = y + dy[num];
        
        // 다음 좌표가 범위 내에 있을 때,
        if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m){
            
            moveDice(num);
            
            // 바닥이 0이라면, 칸에는 주사위의 바닥 수가 복사된다.
            if(arr[next_x][next_y] == 0){
            
                arr[next_x][next_y] = dice[6];
            }
            // 바닥이 0이 아니라면, 칸의 수가 주사위로 복사되고 칸은 0 으로!
            else{
                dice[6] = arr[next_x][next_y];
                arr[next_x][next_y] = 0;
            }
            
            x = next_x;
            y = next_y;
            
            cout << dice[1] << '\n';
            
        }
        
        
        
    }



    return 0;
}















