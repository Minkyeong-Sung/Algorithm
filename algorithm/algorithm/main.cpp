#include <iostream>
#include <queue>
#include <cstring>


using namespace std;

int arr[50][50];
int ans[51];
bool check[50][50];
int w, h;

// 상하좌우 + 대각선
int dx[] = {-1, -1, -1,  0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1,0,  1};

// 1은 땅, 0은 바다
void BFS(int i, int j, int cnt){
    
    queue<pair<int, int>> q;
    
    q.push(make_pair(i, j));
    check[i][j] = true;
    
    
    while(!q.empty()){
        
        i = q.front().first;
        j = q.front().second;
        q.pop();
        
        for(int z = 0; z<8; z++){
        
            int nx = i + dx[z];
            int ny = j + dy[z];
        
            if(nx >=0 && ny >= 0 && nx < h && ny < w ){
            
                if(check[nx][ny] == false && arr[nx][ny] == 1){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
        
            }
        }
    }
}



int main(){
    
    int cnt = 0;
    
    while(1){
        
        cin >> w >> h;
        cnt = 0;
        
        memset(arr, 0, sizeof(arr));
        memset(check, false, sizeof(check));
        
        // 종료 구문
        if( w == 0 && h == 0) break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w ; j++){
                cin >> arr[i][j];
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w ; j++){
                
                if(check[i][j] == false && arr[i][j] == 1){
                    BFS(i, j, ++cnt);
                    
                }
            }
        }
        
        cout << cnt <<'\n';

    }

    return 0;
}



