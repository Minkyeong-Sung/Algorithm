#include <iostream>
#include <cstdio>
#include <queue>
#define MAXNUM 100500

using namespace std;

bool check[MAXNUM];

int findTime(int n, int k){
    
    int time = 0;

    queue<int> q;
    
    q.push(n);
    
    while(!q.empty()){
        
        int size = q.size();
        
        for(int i=0; i< size; i++){
            
            int node = q.front();
            q.pop();
            
            // 정답을 찾는 경우
            if(node == k){
                return time;
            }
            
            // 3가지 경우를 판별
            // 범위내에 존재하며, 방문하지 않았을 경우에만 검사 -> 중복 검사를 피하기 위해
            if(node-1 >= 0 && check[node-1] != true){
                
                q.push(node-1);
                check[node-1] = true;
            
            }
            
            if(node+1 <= MAXNUM && check[node+1] != true){
                
                q.push(node+1);
                check[node+1] = true;
            
            }
            
            if(node*2 <= MAXNUM && check[node*2] != true){
                
                q.push(node*2);
                check[node*2] = true;
            }
        
        }
    
        time++;
    
    
    }
    



    return time;
}



int main(){
    
    ios_base::sync_with_stdio(false);

    int n, k;
    
    scanf("%d %d", &n , &k);
    
    if(n==k) {
        printf("0");
        return 0;
    }
    
    printf("%d", findTime(n,k));



    return 0;
}
