#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans = 987654321;
vector<pair<int, int>> vt;

void upArr(int (*cpyArr)[8], int x, int y, int n){
    
    for(int i=x-1; i >=0; i--){
        if(cpyArr[i][y] == 6) break;
        if(cpyArr[i][y] >= 1 && cpyArr[i][y] <= 5) continue;
        cpyArr[i][y] = n;
    
    }
}

void downArr(int (*cpyArr)[8], int x, int y, int n){
    
    for(int i=x+1; i < N; i++){
        if(cpyArr[i][y] == 6) break;
        if(cpyArr[i][y] >= 1 && cpyArr[i][y] <= 5) continue;
        cpyArr[i][y] = n;

    }
}

void leftArr(int (*cpyArr)[8], int x, int y, int n){
    
    for(int i=y-1; i >=0 ; i--){
        if(cpyArr[x][i] == 6) break;
        if(cpyArr[x][i] >= 1 && cpyArr[x][i] <= 5) continue;
        
        cpyArr[x][i] = n;
        
    }
}

void rightArr(int (*cpyArr)[8], int x, int y, int n){
    
    for(int i=y+1; i < M ; i++){
        if(cpyArr[x][i] == 6) break;
        if(cpyArr[x][i] >= 1 && cpyArr[x][i] <= 5) continue;
        
        cpyArr[x][i] = n;
        
    }
}

void copyarr(int (*a)[8], int (*b)[8]){
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            a[i][j] = b[i][j];
        }
    }
}

int calculation(int (*a)[8]){
    int cnt = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //cout << a[i][j] << ' ';
            if(a[i][j] == 0){
                cnt+=1;
            }
        }
        //cout <<'\n';
    }
    return cnt;
}


void solve(int (*arr)[8], int (*cpyArr)[8], int idx){
    
    if(idx == vt.size()){
        ans = min(ans, calculation(cpyArr));
        
     //   cout <<"\n";
        return;
    }
    
    int tmp[8][8];
    
    
    if(idx> vt.size()) return;
    
    int i = vt[idx].first;
    int j = vt[idx].second;
    
    if(arr[i][j] == 1 ){
        // 상
        /*   백 트레킹   */
        /* 실행하기 전값을 저장해두고, 함수 종료후, 그 이전값을 다시 적용하기 */
        copyarr(tmp, cpyArr);
        upArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        
        copyarr(cpyArr, tmp);
        
        // 하
        downArr(cpyArr, i, j, -1);
    
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        // 좌
        leftArr(cpyArr, i, j, -1);

        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        // 우
        rightArr(cpyArr, i, j, -1);
    
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
    }
    else if(cpyArr[i][j] == 2){
        copyarr(tmp, cpyArr);
        upArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        leftArr(cpyArr, i, j , -1);
        rightArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx + 1);
        
        copyarr(cpyArr, tmp);

        
    }
    else if(arr[i][j] == 3){
        copyarr(tmp, cpyArr);
        upArr(cpyArr, i, j, -1);
        rightArr(cpyArr, i, j, -1);
        
        
        solve(arr, cpyArr, idx + 1);
        
        copyarr(cpyArr, tmp);
        
        
        leftArr(cpyArr, i, j, -1);
        upArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        leftArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        rightArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
    }
    else if(arr[i][j] == 4){
        copyarr(tmp, cpyArr);
        upArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        rightArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        upArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        leftArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        upArr(cpyArr, i, j, -1);
        leftArr(cpyArr, i, j, -1);
        rightArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
        copyarr(cpyArr, tmp);
        
        downArr(cpyArr, i, j, -1);
        leftArr(cpyArr, i, j, -1);
        rightArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
       copyarr(cpyArr, tmp);
    }
    else{
        copyarr(tmp, cpyArr);
        upArr(cpyArr, i, j, -1);
        downArr(cpyArr, i, j, -1);
        rightArr(cpyArr, i, j, -1);
        leftArr(cpyArr, i, j, -1);
        
        solve(arr, cpyArr, idx+1);
    }
}


int main(){
    
    int arr[8][8];
    cin >> N >> M;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] >= 1 && arr[i][j] <= 5){
                vt.push_back({i, j});
            }
        }
    }
    
    // copy
    int cpyArr[8][8];
    copyarr(cpyArr, arr);
    
    solve(arr, cpyArr, 0);
    
    cout << ans ;
    return 0;
}
