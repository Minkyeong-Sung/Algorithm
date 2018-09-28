#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool check[10000];

char dx[] = {'D' , 'S' , 'L' , 'R'};

int main(){


    int n;
    int num1, num2;
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        memset(check, false, sizeof(check));
    
        cin >> num1 >> num2;
        
        queue<pair<int, string>> q;
       
        q.push(make_pair(num1, ""));
        check[num1] = true;
        
        while(!q.empty()){
            
            int node = q.front().first;
            string ans = q.front().second;
            q.pop();
            
            
            if(node == num2){
                cout << ans <<'\n';
                break;
            }
            
            
            for(int j=0; j<4; j++){
                int next;
            
                if(dx[j] == 'D'){
                
                    next = (node*2)%10000;
                    
                    if(check[next] == false){
                        
                        q.push(make_pair(next, ans+ "D"));
                        check[next] = true;
                        
                    }
                }
                else if(dx[j] == 'S'){
                    
                    next = (node - 1) < 0 ? 9999 : node - 1;//   n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999
                
                    if(check[next] == false){
                        q.push(make_pair(next, ans + "S"));
                        check[next] = true;
                    }
                    
                }
                else if(dx[j] == 'L'){
                
                    next =  (node % 1000) * 10 + node / 1000;
                    if(check[next] == false){
                        q.push(make_pair(next, ans + "L"));
                        check[next] = true;
                    }
                }
                else{
                    
                    next =  (node % 10) * 1000 + (node / 10);
                    if(check[next] == false){
                        q.push(make_pair(next, ans + "R"));
                        check[next] = true;
                    }
                
                }
            }
        }
    
    }






    return 0;
}
