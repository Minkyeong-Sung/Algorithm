#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int arr[17][17];
bool check[17];
int N, minNum ;

//  요리 그룹의 최대 시너지 값 계산
int cal(vector<int> &a){
    
    int sum = 0;
    
    // 모든 경우의 수 중, 절반만 확인하면 되기 떄문에
    // ex) 1 3 = 3 1
    for(int i=0; i< N/2; i++){
        for(int j=0; j<N/2; j++){
        
            if(i==j) continue;
            
            sum += arr[a[i]][a[j]];
        }
    }
    
    return sum;
    

}

// 두 요리 그룹으로 나누는 작업
// 절반만 선택하면 나머지는 다른 그룹이기때문에
// 한가지로만 확인해준다
int divideGroup(){

    vector<int> v1, v2;
    
    for(int i=0; i< N; i++){
        
        if(check[i] == true){
            v1.push_back(i);
        }
        else{
            v2.push_back(i);
        }
    }

    return abs(cal(v1) - cal(v2));

}

// 백트래킹
void checkGroup(int cnt, int num){

    check[num] = true;
    
    if(cnt == N/2){
        
        // 계산
        minNum = min(minNum, divideGroup());
    
    }
    else{
        
        for(int i=num+1; i<N; i++){
            checkGroup(cnt+1, i);
        }
    
    }
    
    // 백트래킹사용시 필수!
    check[num] = false;



}


int main(){

    int testCase;
    
    cin >> testCase;
    
    for(int t= 1; t<= testCase; t++){
        cin >> N;
        
        minNum = 1000000;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }
        
        checkGroup(1, 0);
        
        cout << "#" << t << ' ' << minNum <<'\n';
        
        
        
    }

    
    return 0;
}



