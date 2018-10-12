#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, C;
int arr[11][11];
int maxCal = 0;
int ans = 0;

void selectBox(vector<int> box1, int sum, int mul, int idx){
    
    if(idx >= box1.size()){
        
        if(sum <= C){
            maxCal = max(maxCal , mul);
        }
        return;
    }
    
    selectBox(box1, sum ,mul, idx+1);
    selectBox(box1, sum + box1[idx], mul + ( box1[idx] * box1[idx]), idx+1);
}

void checkRangeOfHoney(vector<int> box1, vector<int> box2){
    
    int sum1 = 0, sum2 = 0;
    int ans1 = 0, ans2 = 0;
    int tmpAns=0;
    
    for(auto q: box1){
        sum1 += q;
        ans1 += (q*q);
    }
    
    
    if(sum1 > C){
        maxCal=0;
        selectBox(box1, 0,0, 0);
        tmpAns += maxCal;
    }
    else{
        tmpAns += ans1;
    }
    
    for(auto q : box2){
        sum2 += q;
        ans2 += (q*q);
    }
    
    if(sum2 > C){
        maxCal = 0;
        selectBox(box2, 0, 0,0);
        tmpAns += maxCal;
    }
    else{
        tmpAns += ans2;
    }
    
    ans = max(ans, tmpAns);
    
    return;
}


void combiBox2(vector<int> box1, vector<int> box2, int x, int y ){
    
    if(box2.size() == M){
        
        // 벌꿀 채취 시작
        checkRangeOfHoney(box1, box2);
        return;
    }
    
    if(y < N) {
        
        box2.push_back(arr[x][y]);
        combiBox2(box1, box2, x, y+1);
    }
    
    
}

void combiBox(vector<int> box1, int x, int y ){
    
    // 벌꿀 1을 뽑은 후, 2를 뽑자
    if(box1.size() == M){
        
        if(y >= N){
            y-=1;
        }
        vector<int> box2;
        bool flag = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                
                if(i == x && j == y) flag = true;
                
                if(flag == true){
                    combiBox2(box1, box2, i, j);
                }
            }
        }
        return;
    }
    
    if(y <N){
        
        box1.push_back(arr[x][y]);
        combiBox(box1, x, y+1);
    }
    
}

int main(){
    int tc;
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        
        cin >> N >> M >> C;
        ans = 0;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >>arr[i][j];
            }
        }
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                vector<int> box1;
                combiBox(box1, i, j);
            }
        }
        
        cout <<"#" << t << ' '<< ans <<'\n';
    }
    
    
    
    return 0;
}
