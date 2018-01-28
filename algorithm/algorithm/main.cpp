//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//

// 1914
// 하노이탑

#include <iostream>

using namespace std;


void hanoi(string *arr, int n, int from, int by, int to, int* cnt){
    
    if(n == 1){
        arr->append(to_string(from) + " " + to_string(to) + '\n');
        (*cnt)++;
        
    }
    else{
        //(*cnt)++;
        hanoi(arr, n-1, from, to, by, cnt);
        
        arr->append(to_string(from) + " " + to_string(to)+ '\n');
        //cout << from << ' ' << by << '\n';
        (*cnt)++;
        hanoi(arr, n-1, by, from , to, cnt);
    }
    
}

int main(int argc, const char * argv[]) {
    int n, cnt = 0;
    string arr;
    
    cin >> n;
    
    hanoi(&arr, n, 1, 2, 3, &cnt);
    
    cout << cnt << '\n';
    
    cout << arr;
    
    
    return 0;
}

