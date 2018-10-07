#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, W, H;
int ans = 987654321;
int arr[15][12];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node{

    int x;
    int y;
    int depth;
};

void breakBlock(int x, int y, int depth){

    queue<Node> q;
    q.push({x, y, depth});
    arr[x][y] = 0;
    
    while(!q.empty()){
        
        int tx = q.front().x;
        int ty = q.front().y;
        int td = q.front().depth;
        q.pop();
        
        /*  여기서 깊이만큼 한번에 탐색 가능! */
        for(int i=1; i<td; i++){
            for(int d=0; d<4; d++){
                
                // 배열에 저장된 깊이만큼 바로 이동한지 탐색!
                int nx = tx + dx[d]*i;
                int ny = ty + dy[d]*i;
                int nd = arr[nx][ny];
                
                if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
                
                if(arr[nx][ny] !=0){
                    q.push({nx, ny, nd});
                    arr[nx][ny] = 0;
                }
            }
        
        }
    }
}

void moveBlock(){

    for(int i=0; i<W; i++){
    
        for(int j= H-2; j>= 0; j--){
        
            int x = j;
            int y = i;
            
            if(arr[x][y] == 0) continue;
            
            while(1){
                
                // 아래서 부터 거꾸로 비교!
                if(arr[x+1][y] == 0 && x+1 >= 0 && y >= 0 && x+1 < H && y <= W){
                 
                    arr[x+1][y] = arr[x][y];
                    arr[x][y] = 0;
                    x++;
                }else{
                    break;
                }
            }
        }
    }
}

void solve(int k){
    
    int tmp[15][12];
    
    // 백트래킹!
    for(int j=0; j<H; j++){
        for(int l = 0; l<W; l++){
            tmp[j][l] = arr[j][l];
        }
    }
    
    
    if(k == N){
    
        int cnt = 0;
        
        for(int i=0; i< H; i++){
            for(int j=0; j<W; j++){
                
                if(arr[i][j] != 0){
                    cnt += 1;
                }
            }
        }
        
        ans = min(ans, cnt);
    
        return;
    }
    
    
    // 구술 차는 경우의 수
    for(int i=0; i<W; i++){
        
        int x = 0;
        int y = i;
        
        // 제일 위에 있는 구술 찾기
        while(x>= 0 && y>= 0 && x < H && y < W && arr[x][y] == 0){
            x++;
        }
        
        // 구술 치기 시작!
        breakBlock(x, y, arr[x][y]);
    
        moveBlock();
        
        solve(k+1);
        
        // 백트래킹!
        for(int j=0; j<H; j++){
            for(int l = 0; l<W; l++){
                arr[j][l] = tmp[j][l];
            }
        }
        
    }
    
    

}

int main(){
    
    int tc;
    
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        cin >> N >> W >> H;
        
        ans = 987654321;
        
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> arr[i][j];
            }
        }
        
        solve(0);
        
        cout << "#" << t << ' ' << ans <<'\n';
    }



    return 0;
}
