#include <iostream>

using namespace std;


// 0 : 북  1 : 동
// 2 : 남  3 : 서

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int changeDir[] = {3, 0, 1, 2};

int bx[] = {1, 0, -1, 0};
int by[] = {0, -1, 0, 1};
int cnt, ans;

int solve(int arr[51][51], int x, int y, int dir, int flag){
    
    int tmpX, tmpY;
    // 청소
    if(flag == 1){
        arr[x][y] = 2;
        ans += 1;
    }
    
    tmpX = x + dx[dir];
    tmpY = y + dy[dir];
    
    if(cnt > 4){
        
        tmpX = x + bx[dir];
        tmpY = y + by[dir];
        
        // 뒤쪽이 벽일 경우
        if(arr[tmpX][tmpY] == 1){
            cout << ans;
            return 0;
        }
        
        cnt = 1;
        return solve(arr, tmpX, tmpY, dir, 0);
    
    }
    
    
    // 2-1
    if(arr[tmpX][tmpY] == 0){
        cnt = 1;
        return solve(arr, tmpX, tmpY, changeDir[dir], 1);
    }
    // 2-2
    else{
        cnt+=1;
        return solve(arr, x, y, changeDir[dir] , 0);
    }
    
}


int main(){

    int n, m;
    int r, c, d;
    int arr[51][51];
    
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i=0; i< n; i++){
        for(int j=0; j< m; j++){
            cin >> arr[i][j];
        }
    }
    cnt = 1;
    ans =0;
    solve(arr, r, c, d, 1);
    
    
    
    
    return 0;
}
