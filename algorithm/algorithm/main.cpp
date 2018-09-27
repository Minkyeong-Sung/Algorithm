#include <iostream>
#include <queue>

#define MAXNUM 1000001

using namespace std;

bool check[MAXNUM];

string pushButton(int F, int S, int G, int U, int D){
    
    queue<int> q;
    int cnt = 0;
    
    q.push(S);
    check[S] = true;
    
    while(!q.empty()){
        
        int size = q.size();
        
        for(int i=0; i< size; i++){
            
            int node = q.front();
            q.pop();
            
            // 도착했을때, 함수 종료
            if(node == G) return to_string(cnt);
            
            
            // 위로 가는 버튼을 누르는 경우
            if(node + U < MAXNUM && node+U <= F && check[node+U] == false ){
                
                q.push(node+U);
                check[node+U] = true;
            }
            
            // 아래로 가는 버튼을 누르는 경우
            if(node - D > 0  && check[node-D] == false){
                
                q.push(node-D);
                check[node-D] = true;
            
            }
        }
        
        cnt ++;
    }
    
    

    
    return "use the stairs";
}

int main(){

    int  F, S, G, U, D;

    // 총 층수 , 현재 층, 스타트링크, 업, 다운
    cin >>  F >>  S >>  G >> U >> D;
    
    if((S > G && D == 0) || (S < G && U == 0)){
        cout << "use the stairs";
        return 0;
    }
    
    
    cout << pushButton(F,S, G, U, D);





    return 0;
}
