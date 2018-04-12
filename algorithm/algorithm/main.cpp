#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int arr[101][101];
int check[101][101];
int dist[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


int main(){

    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    
    
    /* BFS */
    queue<pair<int, int>> q;
    // 가장 처음 값 넣음
    q.push(make_pair(0, 0));
    check[0][0] = true;
    dist[0][0] = 1;
    
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        
        // dx, dy
        for(int i=0; i<4; i++){
            
            int tmp_x = dx[i] + x;
            int tmp_y = dy[i] + y;
        
            if(0<= tmp_x && tmp_x < n && 0<= tmp_y && tmp_y< m){
                
                if(check[tmp_x][tmp_y] == false && arr[tmp_x][tmp_y] == 1){
                    
                    q.push(make_pair(tmp_x, tmp_y));
                    dist[tmp_x][tmp_y] = dist[x][y] + 1;
                    check[tmp_x][tmp_y] = true;
            
                }
            }
        }
    }
    
    printf("%d\n", dist[n-1][m-1]);
    
    
    
    
    return 0;
}

/*
 
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
 
 */
