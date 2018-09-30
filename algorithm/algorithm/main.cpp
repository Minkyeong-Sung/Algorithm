#include <iostream>

using namespace std;

int n;
bool check[15][15];
bool colum[15];
bool diagonal1[40], diagonal2[40]; // / , \ 방향 체크


/*
 퀸은 8방향으로 움직인다.
 행의 갯수만큼만 판단을 해주며,
 그에 따른 대각선과 열 방향에서 체크만 해주며 파악하면 된다.
 */

bool checkQueen(int row, int col){

    // 이미 퀸의 방향에 해당된다면
    if(colum[col] == true){
        return false;
    }
    
    if(diagonal1[row+col] == true){
        return false;
    }
    
    if(diagonal2[row-col+n] == true){
        return false;
    }

    return true;
}


int BFS(int row){
    
    if(row == n){
        return 1;
    }
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        
        check[row][i] = true;
        
        // 8방향에 퀸이 존재하는지 여부 판단
        if(checkQueen(row, i) == true){
            colum[i] = true;
            diagonal1[row+i] = true;
            diagonal2[row-i+n] = true;
            check[row][i] = true;
            
            // 다음 위치 탐색
            ans += BFS(row+1);
            
            // 백트레킹으로 계속 탐색하기 위해 다시 false로 바꿔준다.
            check[row][i] = false;
            colum[i] = false;
            diagonal1[row+i] = false;
            diagonal2[row-i+n] = false;
            
        }
        
        
    }
    
    return ans;
}



int main(){
    
    cin >> n;
    
    cout <<BFS(0);
 
    return 0;

}
