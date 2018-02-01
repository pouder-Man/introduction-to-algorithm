//
// Created by vkdne on 2018-02-01.
//
#include <iostream>
#include <math.h>
using namespace std;

int dp[1001];

int main(){

    int N;
    int arr[1001];

    cin >> N;
    for(int i = 1; i <= N ; i++){
        cin >> arr[i];
    }

    dp[1] = arr[1];

    for(int i = 2; i <= N ; i++){
        int temp = arr[i];
        for(int j = 1; j < i ; j++){
            if(temp < dp[i-j] + dp[j])
                temp = dp[i-j] + dp[j];
        }
        dp[i] = temp;
        cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }
    cout << dp[N];
    return 0;
}