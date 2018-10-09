#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

typedef struct {
    int x;
    int y;
    int n;
    int dir;

}Node;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

vector<int> map[100][100]; // 충돌나는 미생물을 저장하기 위해
vector<Node> bug(1005); // 미생물 저장

int reversDir(int dir){
    
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else return 3;
}


void solve(){
    // 격리시간만큼만
    for(int t=0; t<M; t++){
        
        // init
        for(int i=0; i<K; i++){
            // 미생물이 없다면 그냥 넘어감
            if(bug[i].n == 0){
                continue;
            }
            map[bug[i].x][bug[i].y].clear();
        }
        
        // 미생물 이동
        for(int i=0; i<K; i++){
            
            if(bug[i].n == 0) continue;
            // 이동
            bug[i].x += dx[bug[i].dir];
            bug[i].y += dy[bug[i].dir];
            map[bug[i].x][bug[i].y].push_back(i); // i번째 미생물 넣어줌
        }
        
        // 이동시킨 미생물이 충돌하는지, 가장자리에 있는지 확인하여 정렬
        for(int i=0; i<K; i++){
            
            if(bug[i].n == 0) continue;
            
            // 가장자리에 있는 경우
            if(bug[i].x == 0 || bug[i].y == 0 || bug[i].x == N-1 || bug[i].y == N-1){
                /* 미생물 수 절반, 반대 방향  */
                bug[i].n /= 2;
                bug[i].dir = reversDir(bug[i].dir);
                
            }
            // 충돌 나는 경우
            else if(map[bug[i].x][bug[i].y].size() > 1){
                /* 두개 이상인 경우면 충돌 */
                int x = bug[i].x;
                int y = bug[i].y;
                
                int tmpMax = 0;
                int tmpDir = 0;
                int tmpSum =0;
                int tmpIndex = 0;
                // 해당 좌표에 존재하는 미생물 수만큼 충돌 해결한다!
                for(int j=0; j< map[x][y].size() ; j++){
                    
                    tmpSum += bug[map[x][y][j]].n;
                    
                    // 해당 좌표에 존재하는 미생물들 중, j번째 미생물과 비교
                    if(tmpMax <  bug[map[x][y][j]].n){
                        tmpMax = bug[map[x][y][j]].n;
                        tmpDir = bug[map[x][y][j]].dir;
                        tmpIndex = map[x][y][j];
                    }
                    
                    // 합친 후, 해당 값은 0으로 !
                    bug[map[x][y][j]].n = 0;
                    
                }
                // 충돌 합친 후, 새로운 값으로 갱신
                bug[tmpIndex].n = tmpSum;
                bug[tmpIndex].dir = tmpDir;
                
            }
            
        }
        
    }
}

int main(){
    
    int tc;

    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        
        cin >> N >> M >> K;
        
        for(int i=0; i<K; i++){
            cin >> bug[i].x >> bug[i].y >> bug[i].n >> bug[i].dir;
            map[bug[i].x][bug[i].y].push_back(i);
        }
        
        solve();
        
        int ans = 0;
        for(int i=0;i<K; i++){
            
            ans += bug[i].n;
        }
        
        // 초기화
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                map[i][j].clear();
            }
        }
        
        
        cout << "#" << t << ' ' <<ans <<'\n';
        
    }
    
    
    
    
    
    return 0;
}



