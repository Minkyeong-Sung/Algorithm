#include <iostream>

using namespace std;

int arr[10][10];

void printN(int n){
    
    int N = n;
    int dir = 1;
    int x = 0;
    int y = -1;
    int num = 1;
    
    while (1) {
        
        // 가로
        for(int i=0; i<n; i++){
            y = y + dir;
            arr[x][y] = num++;
        }
        
        // 횟수 줄임
        n--;
        
        if(n<0 ) break;
        
        // 세로
        for(int i=0; i<n; i++){
            x = x + dir;
            arr[x][y] = num++;
        }
        
        dir *= -1;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j] <<  ' ';
        }
        cout <<'\n';
    }


}

int main(){

    int tc, N;
    
    cin >> tc;
    
    for(int t=1; t<= tc; t++){
        
        cin >>N;
    
        cout << "#"<< t << '\n';;
        printN(N);
    
    }


    return 0;
}
