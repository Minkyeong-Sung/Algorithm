#include <iostream>
#include <algorithm>

using namespace std;

int arr[11][11];
bool check[11][11];
int N;
int ans = 987654321;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int calculation(){
    int sum =0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check[i][j] == true){
                sum += arr[i][j];
            }
        }
    }
    
    return sum;
}


void solve(int x, int y, int cnt){
    
    if(cnt == 3){
        // 계산해서 최소값 갱신
        ans = min(ans, calculation());
        return;
    }
    
    if(x >= N || y >= N) return;
    
    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            
            if(check[i][j] == true){
                continue;
            }
            else{
                // 꽃 만들수 있는지 확인하기
                int flag = 0;
                for(int d=0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    
                    if(check[nx][ny] == true) break;
                    flag++;
                }
                // 꽃 완성
                if(flag == 4){
                    for(int d=0; d<4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        
                        check[nx][ny] = true;
                    }
                    check[i][j] = true;
                    
                    // 꽃 만들고
                    solve(i, j, cnt+1);
                    
                    // 다시 해제하기
                    for(int d=0; d<4; d++){
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        
                        check[nx][ny] = false;
                    }
                    check[i][j] = false;
                }
            }
            
        }
    }
    
    
}

int main(){
    
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    solve(1, 1, 0);
    
    cout << ans ;
    
    return 0;
}
