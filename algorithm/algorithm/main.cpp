#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
int ans;
int arr[115][115];

// 동 서 남 북
// 0 1 2 3
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// 도형에 따른 방향 전환
int changeDir[6][4]= {
    
    {0, 1, 2, 3},
    {1, 3, 0, 2},
    {1, 2, 3, 0},
    {2, 0, 3, 1},
    {3, 0, 1, 2},
    {1, 0, 3, 2}
};

void findPare(int &y, int &x, int number){
    
    for(int i=1; i<= N; i++){
        for(int j=1; j<=N; j++){
            
            if(arr[i][j] == number && ( j != x || i != y)){
                x = j;
                y = i;
                return;
            }
        }
    }
}

void DFS(int y, int x, int dir){
    
    int tx = x;
    int ty = y;
    int cnt = 0;
    
    while(1){
        
        int nx = tx + dx[dir];
        int ny = ty + dy[dir];
        
      //  if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        
        // 블랙홀이거나 시작점으로 올 경우 종료
        if(arr[ny][nx] == -1 || (nx == x && ny == y)){
            if(ans < cnt){
                ans = cnt;
            }
            return ;
        }
        
        if(arr[ny][nx] > 0){
            // 블록인 경우
            if(arr[ny][nx] <= 5){
                // 방향 갱신
                dir = changeDir[arr[ny][nx]][dir];
                cnt++;
            }
            // 웜홀인 경우
            else{
                int number = arr[ny][nx];
                // 해당 좌표로 웜홀 이동
                
                findPare(ny, nx, number);
            }
        }
        
        // 위의 두가지 케이스에 해당되지 않으면 다음 좌표로 이동
        tx = nx;
        ty = ny;
        
    }
}


int main(){
    
    int tc;
    cin >> tc;
    for(int t=1; t<= tc; t++){
      
        ans = 0;
        cin >> N;
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> arr[i][j];
            }
        }
        
        // 가장자리에 벽 설치
        // 반대방향으로 튕겨나가기 때문
        for(int i=0; i<=N+1;i++){
            arr[0][i] = 5;
            arr[i][0] = 5;
            arr[N+1][i] = 5;
            arr[i][N+1] = 5;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                
                if(arr[i][j]!= 0) continue;
                
                // 4가지 방향에 따라 모두 검색
                for(int d=0; d<4; d++){
                    DFS(i, j, d);
                }
            }
        }
        
        cout <<"#" << t << ' ' << ans << "\n";
        
    }
    return 0;
}
