#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int N, K, L;
int arr[102][102];
vector<pair<int, int>> snake;
queue<pair<int, char>> q;

int dir = 1;

// 상 우 하 좌
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void changeDir(char d){
    
    if(d == 'L'){
        dir = (dir + 3)%4;
    }
    else{
        dir = (dir + 1 ) %4;
    }
}

void findsnakeTime(){
    
    int t = 0;
    
    while(1){
        // 방향 전환
        if(!q.empty()){
            if(q.front().first == t){
                changeDir(q.front().second);
                q.pop();
            }
        }
        int nx = snake[snake.size()-1].first + dx[dir];
        int ny = snake[snake.size()-1].second + dy[dir];
        
        t++;
        
        // 벽에 부딪히거나, 자시자신과 부딪히면 종료
        if((nx <1 || ny < 1 || nx > N || ny > N) || arr[nx][ny] == 1){
            cout << t ;
            return;
        }
        
        // 사과가 없다면 꼬리 줄이기
        if(arr[nx][ny] != 2){
            
            // 벡터의 가장 처음이 뱀의 꼬리를 나타내므로 없애주기
            arr[snake[0].first][snake[0].second] = 0;
            snake.erase(snake.begin());
        }
        
        snake.push_back({nx, ny});
        arr[nx][ny] = 1;
        
    }
}

int main(){
    int x, y, t;
    char dir;
    
    cin >> N;
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> x>> y;
        // 사과
        arr[x][y] = 2;
    }
    
    cin >> L;
    for(int i=0; i<L; i++){
        cin >> t >> dir;
        
        q.push({t, dir});
    }
    
    // 뱀 표시
    snake.push_back({1,1});
    //snake.push_back({1,2});
    arr[1][1] = 1; //arr[1][2] = 1;
    
    findsnakeTime();

    
    return 0;
}
