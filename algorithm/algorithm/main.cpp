#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int D, W, K;

int arr[13][20];
int ans = 987654321;

bool checkFilm(){
    
    for(int i=0; i<W; i++){ // 열

        int check = 0;
        
        for(int j=1; j<D; j++){ // 행
            
            if(arr[j][i] == arr[j-1][i]){
                check += 1;
            }
            else{
                check = 0;
            }
            
            // 만족하므로 더 탐색할 필요없다
            if(check >= K-1){
                break;
            }
        }
        
        if(check < K-1 ){
            return false;
        }
    }
    
    return true;
}

void solve(int depth, int cnt){
    
    // 현재 답보다 더 큰 경우라면, 더 탐색할 필요가 없음
    if(cnt >= ans){
        return;
    }
    
    // 종료조건1 : 마지막 행까지 본경우 종료
    if(depth == D ){
    
        if(checkFilm()== true){
            ans = min(cnt, ans);
        }
        return;
    }
    
    int copyArr[20] = {0};
    
    // 아무것도 하지 않는 경우
    solve(depth+1, cnt);
    
    // 0 투입하는 경우
    // 초기 상태 저장
    // 그 후, 해당 행을 약품 투입한 것으로 변경
    for(int i=0; i<W; i++){
        copyArr[i] = arr[depth][i];
        arr[depth][i] = 0;
    }
    
    solve(depth+1, cnt+1);
    
    // 1 투입하는 경우
    // 그 후, 해당 행을 약품 투입한 것으로 변경
    for(int i=0; i<W; i++){
        arr[depth][i] = 1;
    }
    solve(depth+1, cnt+1);
    
    // 백트래킹
    // 원상 복구
    for(int i=0; i<W; i++){
        arr[depth][i] = copyArr[i];
    }
    
}

int main(){
    int tc;
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        
        cin >> D >> W >> K;
        
        for(int i=0; i<D; i++){
            for(int j=0; j<W; j++){
                cin >> arr[i][j];
            }
        }
        
        ans = 987654321;
        solve(0, 0);
        
        cout << "#" << t << ' ' << ans <<'\n';
    }
    
    return 0;
}
