#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int u1, u2, u3, u4;
int month[13];
bool check[13];
int ans;

// 백트래킹
void solve(int cnt , int sum){
    
    // 12 이상이 되면 무조건 최소값을 구하고 종료시키면 된다!
    // 12이상일때 i 를 다시 1월달로 옮기면 문제발생! ** 주의 할 것
    
    if(cnt >= 12){
        ans = min(ans, sum);
        return;
    }
    
    
    if(month[cnt] > 0 && check[cnt] == false){
    
        check[cnt] = true;
        
        //1일권
        solve(cnt+1, sum + (u1 * month[cnt]));
        
        //1달권
        solve(cnt+1, sum + u2);
        
        //3달권
        solve(cnt+3, sum + u3);
    
    
    }
    else{
        
        solve(cnt+1, sum);
    }
    
    
    check[cnt] = false;
}


int main(){
    
    int testCase;
    
    cin >> testCase;

    for(int  t= 1; t<= testCase; t++){
        
        cin >> u1 >> u2 >> u3 >> u4;
        
        // init
        // 1년권을 사용하는 것을 잡아두기
        ans = u4;
        
        memset(check, false, sizeof(check));
        
        for(int i=1; i<=12; i++){
            cin >> month[i];
        }
        
        solve(1, 0);
        
        //가장 적은 비용으로 수영장을 이용할 수 있는 방법을 찾고 그 비용을 정답으로 출력
        cout << '#' << t << ' ' << ans <<'\n';
        
    }

    return 0;
}


