#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int d[1001] = {0};




int main(){
    
    cin >> n;
    
    d[0] = 1;
    d[1] = 1;
    
    // 재귀함수는 시간 복잡도가 커짐 -> 그래서 dp 사용
    for(int i=2; i<= n; i++){
        
        d[i] = (d[i-1] + d[i-2]) % 10007 ;
    }
    
    d[n] = d[n] % 10007;
    
    cout << d[n];
    

    return 0;
}
