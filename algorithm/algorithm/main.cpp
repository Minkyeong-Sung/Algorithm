#include <iostream>
#include <queue>
#include <map>
#include <string>

#define N 3

using namespace std;


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void BFS(int arrNum){

    queue<int> q;
    map<int, int> map;
    
    map[arrNum] = 0;
    q.push(arrNum);
    
    while(!q.empty()){
    
        int currentNum = q.front();
        string strNow = to_string(currentNum);
        q.pop();
        
        // 배열에 저장할 수 없기에 문자로 나타내줬던 부분을
        // 배열 좌표 값으로 변환
        // 3*3 배열이므로 각각 나누면 해당 좌표값이 나옴
        
        int tmp = strNow.find('9');
        
        int x = tmp/3;
        int y = tmp % 3;
    
        // 상하좌우 방향으로 swap할 수 있는지 탐색
        for(int i=0; i<4; i++){
            
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >=  0 && nx <  N && ny >= 0 && ny < N){
                // 위치를 바꿔서 탐색해줄 임시 변수
                string next =  strNow;
                
                swap(next[x*3 + y], next[nx*3 + ny]);
                
                int num = stoi(next);
                
                // map 에 num 숫자가 존재하지 않으면
                if(map.count(num)==0){
                    
                    map[num] = map[currentNum] + 1;
                    q.push(num);
                
                }
            }
        }
    }
    
    if(map.count(123456789) == 0){
        cout << -1 ;
    }
    else{
        cout << map[123456789] ;
    }
    









}

int main(){

    int input;
    int arrNum = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
        
            cin >> input;
            
            if(input == 0){
                
                /*
                 0-> 9로 바꾸면 123456789 항상 9자리가 만들어지기 때문에
                 편의상 바꿔준다
                 */
                input = 9;
            }
            
            arrNum =  (arrNum *10) + input ;
        }
    }
    
    BFS(arrNum);
    






    return 0;
}
