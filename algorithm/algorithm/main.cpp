#include <iostream>
#include <vector>
#include <cstring>


using namespace std;


// 만들 암호 길이 , 현재까지 만든 암호 , 사용가능한 알파벳, 사용할지말지 결정해야하는 인덱스
void makePassword(int n, string password, vector<char> &vt, int index){

    if(password.length() == n){
        
        int jaum=0, moum=0;
        
        for(char x : password){
        
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
                moum += 1;
            }
            else{
                jaum += 1;
            }
        }
        
        // 암호 생성 조건 만족
        if(moum >= 1  && jaum >= 2){
        
            cout << password <<'\n';
            return;
        }
    }
    
    // 배열 크기를 넘어가는 경우 (기저사례)
    if(index >= vt.size()){
        return;
    }
    

    // index번째 알파벳을 사용하는 경우
    makePassword(n, password + vt[index], vt, index+1);
    // 사용하지 않는 경우
    makePassword(n, password, vt, index+1);
    


}

int main(){
    
    vector<char> vt;
    int L, C;
    char ch;
    // L개의 알파벳 생성
    cin >> L >> C;
    
    for(int i=0; i<C; i++){
        cin >> ch;
        
        vt.push_back(ch);
    }
    
    sort(vt.begin(), vt.end());


    makePassword(L,"", vt, 0);


    return 0;
}
