#include <iostream>


using namespace std;

char arr[21][21];
bool alpha[26];
int r, c, maxNum=1;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void DFS(int x, int y, int cnt){
    
    if(maxNum < cnt){
        maxNum = cnt;
    }
    
    for(int i=0; i<4; i++){
    
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >=0 && ny >= 0 && nx < r && ny < c && alpha[arr[nx][ny] - 65] == false ){
        
            alpha[arr[nx][ny] - 65] = true;
            
            DFS(nx, ny, cnt+1);
            
            alpha[arr[nx][ny] - 65] = false;
        
        }
    }
}



int main(){
    
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    
    alpha[arr[0][0] - 65] = true;
    
    DFS(0,0, 1);
    
    
    cout << maxNum;



    return 0;
}
