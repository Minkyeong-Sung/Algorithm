#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, M, K;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct{
    int data;
    int start_t;
    int end_t;
    int state; // -1(죽음) 0(아무것도 없음) 1(비활성) 2(활성)
    int input_t;
}Node;

int ans = 0;
Node arr[352][352];

void solve(){
    
    // 주어진 시간동안만 진행한다
    for(int T=1; T<=K; T++){
        
        for(int i=0 ; i < K + N; i++){
            for(int j= 0 ; j <K + M; j++){
                
                if(arr[i][j].data == 0) continue;
                
                // 활성화 상태도 바꾸기
                if(arr[i][j].start_t == T){
                    arr[i][j].state = 2;
                }
                
                // t초 시간 후 활성
                if(arr[i][j].state == 2 && arr[i][j].start_t == T-1){
                    
                    for(int d=0; d<4; d++){
                        
                        int nx = i + dx[d];
                        int ny = j + dy[d];
                        
                        // 원래 빈 공간으로 확장하거나
                        // t초가 지났을때 증식하는 경우
                        if(arr[nx][ny].state == 0 || (arr[nx][ny].state == 1 && arr[nx][ny].input_t == T && arr[nx][ny].data < arr[i][j].data)){
                            
                            arr[nx][ny].start_t = arr[i][j].data + T;
                            arr[nx][ny].end_t = arr[i][j].data * 2 + T;
                            arr[nx][ny].data = arr[i][j].data;
                            arr[nx][ny].state = 1;
                            arr[nx][ny].input_t = T;
                        }
                    }
                }
                
                // 죽은 시간일때
                if(arr[i][j].state == 2 && arr[i][j].end_t == T){
                    arr[i][j].state = -1;
                }
            }
        }
        // t초 경과
        /*
         cout << T << "초" << '\n';
         for(int i=0 ; i < K + N; i++){
         for(int j= 0 ; j <K + M; j++){
         cout << arr[i][j].data << ' ';
         }
         cout <<'\n';
         }*/
    }
}


int main(){
    
    int tc, input;
    cin >> tc;
    for(int t=1; t<= tc; t++){
        cin >> N >> M >> K;
        
        // init
        ans = 0;
        
        for(int i= K/2;  i< K/2 + N; i++){
            for(int j= K/2; j <K/2 + M; j++){
                cin >> input;
                
                if(input != 0){
                    arr[i][j].data = input;
                    arr[i][j].start_t = input;
                    arr[i][j].end_t = 2*input;
                    arr[i][j].state = 1;
                }
            }
        }
        
        solve();
        
        for(int i=0; i< N+K; i++){
            for(int j=0; j<M+K; j++){
                
                if(arr[i][j].state == 1 || arr[i][j].state == 2){
                    ans+=1;
                }
                arr[i][j].data =0;
                arr[i][j].end_t = 0;
                arr[i][j].state = 0;
                arr[i][j].start_t = 0;
                arr[i][j].input_t = 0;
            }
        }
        
        cout <<"#" << t << ' ' << ans << "\n";
        
    }
    return 0;
}
