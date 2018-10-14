#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M;
int ans = 0;
int arr[20][20];
bool check[20][20];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


typedef struct{
    int x;
    int y;
    int depth;
}Node;

void BFS(int x, int y){
    
    queue<Node> q;
    q.push({x, y, 1});
    check[x][y] = true;
    int house = arr[x][y];
    
    /*  BFS를 깊이 몇까지 실행할지 알 수 없을때 사용하는 방법  */
    /*
        현재 탐색하는 깊이 D= 1로 지정한다.
        큐에 저장된 깊이와 현재 탐색하는 깊이가 같으면 BFS 수행 완료
        그 후, 크기를 한개씩 증가해가며 계속 탐색한다
     */
    int D = 1;
    
    while(!q.empty()){
        
        int tx = q.front().x;
        int ty = q.front().y;
        int td = q.front().depth;
        q.pop();
        
        /*  여기가 다음 깊이로 가는 방법 */
        if(td == D){
            if((M*house) - ((D*D) + (D-1)*(D-1)) >= 0){
                ans = max(ans, house);
            }
            D++;
        }
        
        for(int d=0; d<4; d++){
            
            int nx = tx + dx[d];
            int ny = ty + dy[d];
            
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(check[nx][ny] == true) continue;
            
            q.push({nx, ny, td+1});
            check[nx][ny] = true;
            
            if(arr[nx][ny] == 1){
                house++;
            }
        }
    }
    
    return;
}

int main(){
    
    int tc;
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        cin >> N >> M;
        ans = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >>arr[i][j];
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                memset(check, false, sizeof(check));
                BFS(i, j);
            }
        }
        
        cout << "#" << t << ' ' << ans <<"\n";
    }

    return 0;
}
