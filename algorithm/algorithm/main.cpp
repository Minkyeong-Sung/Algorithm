#include <iostream>
#include <queue>


using namespace std;

int N;
int arr[101][101];
int land[101][101];
int check[101][101];

// 상하좌우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int main(){

    cin >> N;
    int cnt = 0;

    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            cin >> arr[i][j];
        }
    }
    
    // 섬의 개수 표시
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        
            if(land[i][j] == 0 && arr[i][j] == 1){
                
                queue<pair<int, int>> q;
                
                q.push(make_pair(i, j));
                land[i][j] = ++cnt;
                
                while(!q.empty()){
                    
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int z = 0; z<4; z++){
                        
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        
                        if(nx >= 0 &&  ny >= 0 && nx < N && ny < N){
                            
                            // 아직 방문 하지 않았다면,
                            if(arr[nx][ny] == 1 && land[nx][ny] == 0 ){
                                
                                land[nx][ny] = cnt;
                                q.push(make_pair(nx, ny));
                                
                            }
                        }
                    }
                }
                
            }
        }
    } // check land
    
    
    queue<pair<int, int>> q;
    
    // 다른 섬까지의 거리를 기억하기 위해
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            
            check[i][j] = -1;
            
            if(arr[i][j] == 1){
                check[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    
    while(!q.empty()){
    
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            
            if(nx >= 0 && ny >= 0 && nx < N && ny <N){
                
                // 주변에 바다가 있다면, 다리를 세울 거리 +1 씩
                // 섬도 늘려감을 동시에 표시해줌
                if(check[nx][ny] == -1){
                
                    check[nx][ny] = check[x][y] + 1;
                    land[nx][ny] = land[x][y];
                    q.push(make_pair(nx, ny));
                    
                }
            }
        } // 주변 탐색
    } // while
    
    
    // 초기값 설정
    int ans = -1;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<4; k++) {
                
                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx >= 0 && ny >= 0 && nx < N && ny < N){
                
                    if(land[nx][ny] != land[i][j]){
                        
                        if (ans == -1 || ans > check[i][j] + check[nx][ny]) {
                            ans = check[i][j] + check[nx][ny];
                        }
                    }
                }
            }
        }
    }
    
    cout << ans ;
    




    return 0;
}
