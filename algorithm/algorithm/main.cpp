#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

int N, M;
int arr[8][8];
int cpyArr[8][8];
int ans = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void copyArr(int (*a)[8], int (*b)[8]){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            a[i][j] = b[i][j];
        }
    }
}

// BFS
void Virus(){
    
    int virusArr[8][8];
    queue<pair<int,int>> q;
    copyArr(virusArr, cpyArr);
    
    // 바이러스 저장 후 퍼트릴 예정
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            if(virusArr[i][j] ==2){
                q.push(make_pair(i, j));
            }
        }
    }
    
    while(!q.empty()){
        
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        
        for(int d=0; d<4; d++){
            int nx = tx + dx[d];
            int ny = ty + dy[d];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            if(virusArr[nx][ny] == 0){
                virusArr[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
    
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            if(virusArr[i][j] == 0){
                cnt += 1;
            }
        }
    }
    
    ans = max(cnt, ans);
    return;
}

void makeWall(int cnt){
    
    if(cnt == 3){
        Virus();
        return;
    }
    
    // 벽을 만드는 경우
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            if(cpyArr[i][j] == 0){
                
                cpyArr[i][j] = 1;
                makeWall(cnt+1);
                cpyArr[i][j] = 0;
            }
        }
    }
}

int main(){
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M;  j++){
            cin >>arr[i][j];
        }
    }
    
    // 벽을 세울 위치
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            
            if(arr[i][j] == 0){
                copyArr(cpyArr, arr);
                // 벽 세우고
                cpyArr[i][j] =1;
                makeWall(1);
                // 다시 원상 복구
                cpyArr[i][j] = 0;
            }
        }
    }
    
    cout << ans ;
    
    return 0;
}
