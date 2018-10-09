#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int digit[29];
vector<int> vt;

void rotation(){
    
    int tmp = digit[N-1];
    
    for(int i= N-1; i>0 ; i--){
        digit[i] = digit[i-1];
    }
    digit[0] = tmp;
}

void calculate(){
    
    for(int i=0; i<N; i+= N/4){
        int tmp = 0;
        int l = 0;
        
        for(int j=i; j< i+ N/4; j++){
            tmp += digit[j] * pow(16, (N/4) -1 - l);
            l++;
        }
        
        vt.push_back(tmp);
    }
    
}

int main(){
    
    int tc;
    string input;
    
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        cin >> N >> K;
        cin >> input;
        
        // 숫자로 변환
        for(int i=0; i<N; i++){
            
            if(input[i] <'A'){
                digit[i] = input[i] - '0';
            }
            else{
                digit[i] = input[i] - 'A' + 10;
            }
        }
        
        // 한 변의 길이만큼 회전
        for(int i=0; i<N/4; i++){
            rotation();
            calculate();
        }
        
        // 내림차순 정렬
        sort(vt.begin(), vt.end(), greater<int>());
        
        /* 중복되는 수가 있으면, 그 해당 수만큼 늘리기
         단, 전체 반복문은 찾는 인덱스까지로 설정하고 돌릴 것!!
         왜냐면, 그 이후의 수들까지 카운트를 해버리면 오류 발생 ** */
        for(int i=0; i<K; i++){
            
            if(i >= 0 && vt[i] == vt[i-1]){
                K++;
            }
        }
        
        cout << "#" << t << ' ' << vt[K-1] <<'\n';
        
        vt.clear();
    }
    return 0;
}
