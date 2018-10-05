#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, L;
int arr[50][50][4];
bool check[50][50];

// 상 좌 하 우
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int pipe[8][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1}, // 상좌하우
    {1, 0, 1, 0}, // 상하
    {0, 1, 0, 1}, // 좌우
    {1 ,0, 0, 1}, // 상우
    {0, 0, 1, 1}, // 하우
    {0, 1, 1, 0}, // 하좌
    {1, 1, 0, 0}  // 상좌
    
};

struct Node{
    
    int x;
    int y;
    int time;

};

void solveTheEscape(int sx, int sy, int t){
    
    queue<Node> q;
    
    q.push({sx, sy, t});
    
    while (!q.empty()) {
        
        int tx = q.front().x;
        int ty = q.front().y;
        int tt = q.front().time;
        
        q.pop();
        
        // 시간 초과했다면 종료
        if(tt >= L ) break;
        
        
        check[tx][ty] = true;
        
        for(int d = 0; d<4; d++){
        
            int nx = tx + dx[d];
            int ny = ty + dy[d];
            int rd = (d + 2 ) % 4 ; // 반대 방향
            
            // 범위 초과
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            
            // 이미 방문했는지
            if(check[nx][ny] == true) continue;
            
            // 현재 위치에서 가는 방향이 연결되어있고
            // 다음 이동할 위치에서 현재위치로 오는 방향이 연결되어 있다면 이동
            if(arr[tx][ty][d] == 1 && arr[nx][ny][rd] == 1){
                q.push({nx, ny, tt+1});
                check[nx][ny] = true;
            
            }
        
        }
        
    }

    
}



int main(){

    int testCase;
    int R, C, input, ans = 0;
    
    cin >> testCase;
    
    for(int t=1; t<= testCase; t++){
        
        //세로 크기 N, 가로 크기 M, 맨홀 뚜껑이 위치한장소의 세로 위치 R, 가로 위치 C, 그리고 탈출 후 소요된 시간 L
        cin >> N >> M >> R >> C >> L;
        
        // init
        memset(check, false, sizeof(check));
        ans = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                
                cin >> input;
                
                // 파이프 방향 표시
                for(int d= 0; d<4; d++){
                    arr[i][j][d] =  pipe[input][d];
                }
            }
        }
        
        // BFS
        solveTheEscape(R, C, 1);
        
        
        // 갈수있는 방향의 개수를 세기
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(check[i][j] == true){
                    ans += 1;
                }
            }
        }
        
        // 갈수있는곳이 하나도 없었다면, 현재 위치만 가능하기때문에 1로 설정
        if(ans == 0){
            ans = 1;
        }
        cout << "#" << t << ' ' << ans <<'\n';
        
    }




    return 0;
}
