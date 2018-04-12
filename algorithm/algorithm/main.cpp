#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
bool check[1001];


void dfs(int x){ // x 를 방문

    check[x] = true;
    printf("%d ", x);
    
    for(int i=0; i< a[x].size() ; i++){
        
        int next = a[x][i];
        
        if(check[next] == false){
            dfs(next);
        }
    }
}


void bfs(int x){

    queue<int> q;
    
    // 앞에서 check배열을 사용했기때문에 초기화 필요
    memset(check, false, sizeof(check));
    
    // 시작점을 먼저 넣고!
    check[x] = true;
    q.push(x);
    
    while(!q.empty()){
    
        int node = q.front();
        q.pop();
        printf("%d ", node);
        
        for(int i=0; i< a[x].size(); i++){
            int next = a[x][i];
            
            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
    }
    

}


int main(){

    
    int n, m, start;
    int u, v;
    
    scanf("%d %d %d", &n, &m, &start);
    
    
    for(int i=0; i<m; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    for(int i=1; i<= n; i++){
        sort(a[i].begin(), a[i].end());
    }
    
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    
    
    return 0;
}
