//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//
// 1662
// 압축


#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    string str;
    
    
    while(getline(cin, str)){
    
        int lower=0, uppper=0, number=0, zero=0;
        int cnt = str.size();
        for(int i=0; i< cnt; i++){
        
            if(str[i] >= '0' && str[i] <= '9'){
                number++;
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                lower++;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                uppper++;
            }
            else{
                zero++;
            }
        }
        
        cout << lower << ' ' << uppper << ' ' << number <<' ' << zero << '\n';
    
    }
    return 0;
}






