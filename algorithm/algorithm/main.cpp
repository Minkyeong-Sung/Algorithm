#include <iostream>
#include <vector>

using namespace std;


// 우 상 좌 하
int dx[] = {1, 0,-1, 0};
int dy[] = {0, -1, 0, 1};

int arr[101][101];
vector<int> vt;

int cntSqaure(){

    int ans = 0;
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
        
            if(arr[i][j] == 1&& arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] ==1){
                    ans += 1;
                
            }
        }
    }
    
    return ans;
}


void solve(int x , int y, int dir, int g){

    int cnt = 0;
    arr[x][y] = 1;
    
    vt.push_back(dir);
    
    // 회전
    while(cnt <= g){
        int start_x = x;
        int start_y = y;
        
        int len = vt.size();
    
        // x 세대만큼 회전!
        for(int i=0; i< len; i++){
            int nX = start_x + dx[vt[i]];
            int nY = start_y + dy[vt[i]];
            
            start_x = nX;
            start_y = nY;
            
            arr[start_x][start_y] = 1;
        }
        
        // 다음 세대수 회전을 위한 값 넣기
        for(int i= len-1; i>=0; i--){
            vt.push_back((vt[i]+1) %4);
        }
        
        cnt++;
    }
    
    return;
}


int main(){

    int n;
    int x, y, g, d;
    
    cin >> n;
    
    for(int i=0; i<n ;i++){
        
        // 초기화
        vt.clear();
        
        cin >> x >> y >> d >> g;
        
        arr[x][y] = 1;
        
        solve(x, y , d, g);
    
    }
    
    cout << cntSqaure() ;
    
    
    return 0;
}







