#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

int n, m;
int arr[101][101];
int check[101][101];

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

using namespace std;


// 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸

void BFS(int sx, int sy, int fx, int fy){

    queue<pair<int, int>> q;
    
    // 처음 시작 값 입력
    q.push(make_pair(sx, sy));
    check[sx][sy] = 1;
    
    while(!q.empty()){
        
        sx = q.front().first;
        sy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
        
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            
            // 상하좌우 방향 탐색
            if(nx >0 && ny >0 && nx <= n &&  ny <= m){
                
                // 아직 탐색하지 않았고, 갈 수 있는 길(1) 이라면 더 탐색
                if(check[nx][ny] == -1 && arr[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = check[sx][sy] + 1;
                }
            }
        }
    } // while
    
    

}


int main(){

    cin >> n >> m;
    
    memset(check, -1, sizeof(check));
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    BFS(1, 1, n, m);
    
    
    cout << check[n][m];


    return 0;
}





