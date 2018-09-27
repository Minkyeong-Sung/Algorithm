#include <iostream>
#include <cstring>
#include <queue>

#define MAXNUM 10001

using namespace std;


bool check[MAXNUM];
bool prime[MAXNUM];
int cnt[MAXNUM];

string findPrime(int num1, int num2){
    
    cnt[num1] = 0;
    queue<int> q;
    
    q.push(num1);
    check[num1] = true;
    
    while(!q.empty()){
        
        for(int i=0; i<q.size(); i++){
            
            int node = q.front();
            q.pop();
            
            
            if(node == num2){
                return to_string(cnt[node]);
            }
            
            for(int j=0; j<4; j++){
                string tmp = to_string(node);
                int change = 0;
                
                // next case number
                for(int changeNum = 0; changeNum<10; changeNum++){
                    
                    if(j==0 && changeNum == 0) continue;
                    
                    tmp[j] = changeNum + '0';
                    
                    change = stoi(tmp);
                    
                    if(prime[change] == false && check[change] ==false ){
                        
                        q.push(change);
                        check[change] = true;
                        
                        // 무작정 count를 해주면, 최소 변환 횟수를 알 수 없다.
                        // 지금 node 값에서 change 값으로 가는 횟수를 더해 주는 것이기 때문!
                        // 왜 min() 을 쓰지 않는가?
                        // queue 는 first In first Out 즉, 들어온 순서대로 나가기 때문에
                        // 최종적으로 바뀔 소수에 도달했을 때 최초로 카운팅 된 것이 현재 소수에서 바뀔 소수로 가는 최소 카운팅 값이기때문이다.
                        cnt[change] = cnt[node] + 1;
                        
                    }
                }
            }
        }
    }
    

    return "Impossible";
}

int main(){

    int n, num1, num2;
    
    // find prime
    // false : 소수
    prime[0] = prime[1] = true;
    
    for(int i=2; i*i< MAXNUM; i++){
        
        if(prime[i] == false){
            
            for(int j=i+i; j< MAXNUM; j+= i){
                prime[j] = true;
            }
        }
    }
    
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        memset(check, false, sizeof(check));
        
        cin >> num1 >>num2;
        
        cout << findPrime(num1, num2) <<'\n';
    
    }
    return 0;
}





