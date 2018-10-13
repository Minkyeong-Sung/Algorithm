#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct{
    int x;
    int y;
    int d;
    int e;
    
} Node;

int arr[4001][4001];
int check[4001][4001];
vector<Node> ball;

int dx[] = { 0 , 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int N, ans = 0;

void solve(){
    
    // 1개만 남았을 때는 더이상 변화 없다
    while( ball.size() >2){
        
        // 움직이기
        for(int i=0; i< ball.size(); ){
            
            // 원래 있던 자리는 아웃
            check[ball[i].y][ball[i].x] -=1;
            
            ball[i].x += dx[ball[i].d];
            ball[i].y += dy[ball[i].d];
            
            // overflow
            // 초과하면 더이상 고려하지 않는다
            if(ball[i].x < 0 || ball[i].y < 0 ||  ball[i].x >= 4000 || ball[i].y >= 4000){
                ball.erase(ball.begin()+ i);
               // i--;
            }
            else{
                check[ball[i].y][ball[i].x] += 1;
                i+= 1;
            }
        }
        
        // 충돌위치 확인
        vector<pair<int, int>> vt;
        for(int i=0; i<ball.size(); ){
            
            if(check[ball[i].y][ball[i].x] >=2){
            
                ans += ball[i].e;
                // 충돌 처리 완료 한 후
                vt.push_back({ball[i].x, ball[i].y});
                ball.erase(ball.begin()+i);
               // i--;
            }
            else{
                i++;
            }
        }
       
        for(int i=0; i< vt.size(); i++){
            check[vt[i].second][vt[i].first] = 0;
        }
        
    }
}

int main(){
    
    int tc;
    int x, y, d, e;
    cin >> tc;
    
    for (int t=1; t<= tc; t++) {
        cin >> N;
        
        
        ans = 0;
        memset(check,0,sizeof(check));
        
        for(int i=0; i<N; i++){
            cin >> x >> y >> d >> e;
            
            x = (x+1000)*2;
            y = (y+1000)*2;
            
            ball.push_back({x, y, d, e});
            check[y][x] = 1;
        }
    
        solve();
       
        
        cout <<"#" << t << ' ' << ans <<'\n';
    }
    
    
    return 0;
}
