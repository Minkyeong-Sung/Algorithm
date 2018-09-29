#include <iostream>
#include <queue>

using namespace std;


bool check[201][201];
bool ans[201];

int a, b, c;

void DFS(int move_a, int move_b, int move_c){

    // 탈출
    if(check[move_a][move_b] == true){
        return;
    }
    
    // A 가 비었을 때, C물통의 양을 출력
    // 비었을 당시 C의 양을 인덱스에 저장하여 표시
    if(move_a == 0){
        ans[move_c] = true;
    }
    
    // 방문 상태 체크
    check[move_a][move_b] = true;
    
    
    
    /*
    // 물통을 옮길 때,
    // 가득 채우거나 완전히 물통이 빌 때까지 담는다
    */
    
    // a-> b 물토 옮기는 경우
    if(b < move_a + move_b){
    
        DFS( (move_a + move_b)-b , b, move_c);
    }
    else{
        
        DFS(0, move_a + move_b, move_c);
    }
    
    // b-> a
    if(a < move_a + move_b){
        
        DFS( a, (move_a + move_b)-a ,  move_c);
    }
    else{
        
        DFS( move_a + move_b, 0, move_c);
    }

    
    // c-> a
    if(a < move_a + move_c){
        
        DFS( a, move_b ,  (move_a + move_c)-a);
    }
    else{
        
        DFS((move_a + move_c), move_b, 0);
    }
    
    
    // c-> b
    if(b < move_b + move_c){
        
        DFS( move_a, b ,  (move_b + move_c)-b);
    }
    else{
        
        DFS(move_a, (move_b + move_c) , 0);
    }
    
    // a-> c
    // b-> c
    // C가 가득 차있는 상태에서 옮기는 상황으로
    // C로 옮길때는 어떤 상황에서도 a+ b = c가 된다!
    DFS(0, move_b, move_a+ move_c);
    DFS(move_a, 0, move_b+ move_c);

}

int main(){
    
    
    cin >> a >> b >> c;
    
    DFS(0, 0, c);

    
    
    for(int i=0; i<201; i++){
        
        if(ans[i] == true){
            cout << i << ' ' ;
        }
    
    }



    return 0;
}
