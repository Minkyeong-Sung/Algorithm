#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int arr[30][30];
int check[30][30];
int ans[25*25];
int n;
int cnt;

// 주변에 1이 있는지 확인 후, 계속 탐색
void DFS(int i , int j){

    check[i][j] = cnt;
    
    for(int z = 0; z<4; z++){
    
        int tx = i + dx[z];
        int ty = j + dy[z];
        
        if(tx >=0 && ty >= 0 && tx < n && ty <n &&  check[tx][ty] == 0 && arr[tx][ty] == 1){
            DFS(tx, ty);
            ans[cnt] += 1;
        }
    }
}


int main(){

    
    cin >> n;
    
    memset(ans, 0, sizeof(ans));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 0 && arr[i][j] == 1){
                // 가장 먼저 발견된 것 카운트
                ans[++cnt] += 1;
                
                // 주변 탐색 시작
                DFS(i, j);
            }
        }
    }
    
    cout << cnt <<'\n';
    
    // 문제 조건 중, 오름차순으로 출력하기 위해
    sort(ans+1, ans+1+ cnt);
    
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << '\n';
    }
    

    return 0;
}
