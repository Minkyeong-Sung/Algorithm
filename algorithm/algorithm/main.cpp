#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;


vector<pair<int,int>> vt[1001][1001];
bool check[1001][1001];


void checkRoad(int x, int y, int toX, int toY){

    for(int i=x; i<= toX; i++){
        for(int j=y; j<= toY; j++){
            
            if((i== x || i == toX) && j < toY){
                
                vt[i][j].push_back(make_pair(i, j+1));
                vt[i][j+1].push_back(make_pair(i, j));
            }
            
            if((j==y || j== toY) && i < toX){
                
                vt[i][j].push_back(make_pair(i+1, j));
                vt[i+1][j].push_back(make_pair(i, j));
            }
            
        }
    }
}

void DFS(int x, int y){

    
    check[x][y] = true;
    
    for(int i=0; i< vt[x][y].size(); i++){
        
        int nx = vt[x][y][i].first;
        int ny = vt[x][y][i].second;
        
        if(check[nx][ny] == false){
            DFS(nx, ny);
        }
    }

    return;

}


int main(){
    
    int n, cnt = 0;
    int x1, x2, y1, y2;
    int sx = 500, sy = 500; // 음수를 없애기 위해
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        checkRoad(x1+500, y1+500, x2+500, y2+500);
    }
    
    
    
    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++){
        
            if(check[i][j] == false && vt[i][j].size() != 0){
            
                DFS(i, j);
                cnt++;
                
            }
            
        }
    }
    
    // 거북이의 출발점에서부터 줄을 그을 수 있는 경우
    if( vt[sx][sy].size() != 0){
        cnt -= 1;
    
    }
    
    cout << cnt;
    
    
    

    return 0;
}
