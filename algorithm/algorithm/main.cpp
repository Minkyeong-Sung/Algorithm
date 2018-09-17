#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-1 , 1, 0, 0};
int dy[] = {0, 0 ,-1, 1};
bool check[10000000];
int arr[4][4];
int result ;

void DFS(int x, int y ,string num){

    num += to_string(arr[x][y]);
    
    // 재귀 종료 조건
    if(num.size() == 7){
        
        int change = stoi(num);
        
        // 7자리 숫자가 완성되었을 떄 check 판단
        if(check[change] == false){
            result += 1;
            check[change] = true;
        }
        
        return;
    }
    
    // 숫자 중복 사용가능
    //check[x][y] = true;
    
    
    for(int i=0; i< 4; i++){
        
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        if(tx >= 0 && ty >= 0 && tx < 4 && ty<4){
            
            DFS(tx, ty, num);
            
        }
    }

}

int main(){

    int testCase;
    string num;
    cin >> testCase;
    
    for(int t=1; t<= testCase; t++){
        
        // 테스트 케이스마다 초기화 필요
        memset(check, false, sizeof(check));
        result = 0;
        
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                cin >> arr[i][j];
            }
        }
        
        // DFS 탐색 : 끝(7자리수)이 정해져 있어서 사용
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                DFS(i, j, "");
            }
        }
        
        cout << "#" << t << ' ' << result <<'\n';
    }
    


    return 0;
}
