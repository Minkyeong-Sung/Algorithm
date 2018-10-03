#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int arr[22][22];
bool number[101];

// 오른쪽 아래 - 왼쪽 아래 - 왼쪽 위 - 오른쪽 위
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};
int ans ,maxCnt;


void DFS(int x, int y, int sx, int sy, int dir ){
    
    // 방향 도착
    if(dir == 4){
    
        if(x == sx && y == sy){
           
            ans = 0;
            for(int i=0; i<101; i++){
                
                if(number[i]== true){
                    ans += 1;
                }
            }
            maxCnt = max(maxCnt, ans);
            
            return;
            
        }
    }
    
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    // 범위 초과
    if(nx <0 || ny < 0 || nx >= N || ny >= N) return;
    else{
    
        // 처음 방문하는 디저트 카페 집이라면
        if(number[arr[nx][ny]] == false){
            
            number[arr[nx][ny]] = true;
            
            // 이 방향 그대로 하는 경우
            DFS(nx, ny, sx, sy, dir);
            
            // 방향을 바꿔서 탐색해보는 경우
            DFS(nx, ny, sx, sy, dir+1);
            
            /* 백 트 래 킹 */
            number[arr[nx][ny]] = false;
            
            
        }
        else{
            // 방문 했지만, 다음 방향으로 돌려서 탐색하는 경우
            /* 다른 경우로 재 탐색 하는 경우, "처음" 좌표에서 가는 것   */
            DFS(x, y, sx, sy, dir+1);
        }

    }
}



int main(){

    int testCase;
    
    cin >> testCase;
    
    for(int t=1; t<= testCase; t++){
    
        cin >> N;
        
        
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N ; j++){
                cin>> arr[i][j];
                
            }
        }
        
        // 백트래킹
        for(int i=0; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                
                number[arr[i][j]] = true;
                DFS(i, j, i+1, j-1, 0);
                number[arr[i][j]] = false;
            
            }
        }

        if(maxCnt == 0) maxCnt = -1;
        
        cout << "#" << t << ' ' << maxCnt <<'\n';
        
        ans = 0;
        maxCnt = 0;
        memset(number, false, sizeof(number));
        
    }





    return 0;
}
