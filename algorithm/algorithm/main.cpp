#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

int map[10][10];
bool check[10][10];
int N, K, maxRoad = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


// flag : 산을 깎는 여부 (T : 깍을 수 있다 , F : 깎을 수 없다 (이미 깎았다))
void DFS(int x, int y, bool flag, int cnt){
    
    check[x][y] = true;
    
    for(int i=0; i<4; i++){
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 범위를 벗어난 경우
        if(nx < 0  || ny < 0 || nx >= N || ny >= N) continue;
        if(check[nx][ny] == true) continue;
        
     
        // 높 -> 낮 이면 그대로 탐색 진행
        if(map[x][y] > map[nx][ny]){
            
            DFS(nx, ny, flag, cnt+1);
            
            // 빠져 나온 후, 백트레킹을 위해
            check[nx][ny] = false;
        }
        // 깎을 수 있는 경우
        else if(map[x][y] <= map[nx][ny] && flag != true){
        
            // 최대 K 깊이 만큼 산을 깎아본다
            for(int j=1; j<=K; j++){
                
                if(map[nx][ny] - j < map[x][y]){
                
                    map[nx][ny] -= j;
                    flag = true;
                    
                    DFS(nx, ny, flag, cnt+1);
                
                    map[nx][ny] += j;
                    check[nx][ny] = false;
                    flag = false;
                }
            }
        }
        
        if(cnt > maxRoad){
            maxRoad = cnt ;
        }
    }
}



int main(){

    int testCase;
    
    cin >> testCase;
    
    for(int t=1; t<= testCase; t++){
        
        // input
        cin >> N >> K;
        maxRoad = 0;
        
        queue<pair<int, int>> q;
        int maxI=0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];
            
                if(maxI < map[i][j]){
                    maxI = map[i][j];
                }
            }
        }
        
        // 가장 높은 곳 저장
        // 이 지점을 기준으로 DFS 탐색
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                if(maxI == map[i][j] ){
                    q.push(make_pair(i, j));
                }
            }
        }
        
        
        
        // DFS 탐색 시작
        
        while(!q.empty()){
            
            // init
            memset(check, false, sizeof(check));
            
            // 시작점부터 카운트를 하기떄문
            DFS(q.front().first, q.front().second, false, 1);
            q.pop();
            
        }
        
        cout << "#" << t <<  ' ' << maxRoad  <<'\n';
        
        
    
    }

    return 0;
}




