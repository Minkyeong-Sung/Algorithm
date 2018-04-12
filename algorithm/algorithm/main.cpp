#include <cstdio>
#include <queue>

using namespace std;

int arr[1000][1000];
int check[1000][1000];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// BFS

int main(){

    int n, m;
    queue<pair<int, int>> q;
    
   
    scanf("%d %d", &n, &m);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
            check[i][j] = -1;
            
            if(arr[i][j] == 1){
                q.push(make_pair(i, j));
                check[i][j] = 0;
            }
        
        }
    }
    

    while(!q.empty()){
    
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        
        
        for(int i=0; i<4; i++){
        
            int tmp_x = dx[i] + x;
            int tmp_y = dy[i] + y;
            
            if(0<= tmp_x && tmp_x < m && 0<= tmp_y && tmp_y < n){
                
                if( arr[tmp_x][tmp_y] == 0 && check[tmp_x][tmp_y] == -1){
                    check[tmp_x][tmp_y] = check[x][y] + 1;
                    
                    q.push(make_pair(tmp_x, tmp_y));

                }
            }
        } // for
    }
    
    int max = 0;
    
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
        
            if(max < check[i][j]){
                max = check[i][j];
            }
        }
    }
    
    
    //예외처리, 아예 될 수 없는 경우를 위해 다시 처음부터 검사
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
        
            if(arr[i][j] == 0 && check[i][j] == -1){
                max = -1 ;
            }
        
        }
    }
    
    
    printf("%d\n", max);
    
    
    
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
 } // for
 } // while
 
 
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
