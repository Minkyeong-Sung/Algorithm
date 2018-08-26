#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[1001][1001];
int check[1001][1001];
int n, m;

queue<pair<int, int>> q;


// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

void BFS(int i, int j){

    while(!q.empty()){
    
        i = q.front().first;
        j = q.front().second;
        q.pop();
        
        for(int z = 0; z<4; z++){
        
            int nx = i + dx[z];
            int ny = j + dy[z];
            
            if(nx >= 0 && ny >= 0 && nx  < m && ny < n){
            
                if(check[nx][ny] == -1 && arr[nx][ny] == 0){
                    
                    check[nx][ny] = check[i][j] + 1;
                    q.push(make_pair(nx, ny));
                    
                }
            
            }
        }
    } // while

}



int main(){

    
    // M은 상자의 가로 칸의 수, N 은 상자의 세로 칸의 수
    cin >> n >> m;
    
    memset(check, -1, sizeof(check));
    memset(arr, 0, sizeof(arr));
    
    for(int i=0 ; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 1){
                q.push(make_pair(i, j));
                // 토마토 익는 날짜가 하루씩 낮은 부분을 해결하기 위해 미리 0으로 초기화
                check[i][j] = 0;
            }
        }
    }
    
    
    BFS(q.front().first, q.front().second);
    
    
    // 토마토 익는 날짜 계산
    // 체크한 수 중, 가장 큰 수를 최종 익는 날짜로 지정한다.
    int ans = 0;
    for(int i=0; i<m; i++){
        for(int j=0;j<n; j++){
            
            if(ans < check[i][j]){
                ans = check[i][j];
            }
        }
    }
    
    for(int i=0 ; i<m; i++){
        for(int j=0; j<n; j++){
            // 단, 아직 익지 않은 토마토가 한개라도 있으면 -1
            if( arr[i][j] == 0 && check[i][j] == -1){
                ans = -1;
            }
        }
    }

    
    cout << ans;





    return 0;
}
