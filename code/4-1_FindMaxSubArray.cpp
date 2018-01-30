//
// Created by vkdne on 2018-01-30.
//
#include <iostream>
#include <algorithm>
using namespace std;

int dp[10];


struct sol{
    int low;
    int high;
    int sum;
};
sol FMCSA(int* a,int low,int mid, int high) {

    sol temp;
    int left_sum = -2000000000;
    int right_sum = -2000000000;
    int left_pos = 0;
    int right_pos = 0;

    int sum = 0;
    //left
    for(int i = mid;i>low-1;i--){
        sum += a[i];
        if(left_sum <sum){
            left_sum = sum;
            left_pos = i;
        }
    }
    sum = 0;
    //right
    for(int i = mid+1;i<high+1;i++){
        sum += a[i];
        if(right_sum <sum){
            right_sum = sum;
            right_pos = i;
        }
    }
    /*
    cout<<"======================="<<endl;
    cout<<"cross_sum"<<endl;
    cout<<"low : "<<low<<endl;
    cout<<"mid : "<<mid<<endl;
    cout<<"high : "<<high<<endl;
    cout<<"right pos : "<<right_pos<<endl;
    cout<<"left pos : "<<left_pos<<endl;
    cout<<"right sum : "<<right_sum<<endl;
    cout<<"left sum : "<<left_sum<<endl;
    */
    temp.low = left_pos;
    temp.high = right_pos;
    temp.sum = right_sum+left_sum;
    return temp;
}
sol FMSA(int* a,int low,int high){
    sol temp;
    sol left;
    sol right;
    sol cross;
    int mid;

    //base case
    if(high == low){
        temp.low = low;
        temp.high = high;
        temp.sum = a[low];
        return temp;
    }

    else{
        mid = (low + high)/2;
        //find solution low<=i <= j <= mid
        left = FMSA(a,low,mid);
        //find solution mid+1 <= i <= j<= high
        right = FMSA(a,mid+1,high);
        //find solution low <= i <= mid <= j <= high
        cross = FMCSA(a,low,mid,high);
        if((left.sum >= right.sum) && (left.sum >= cross.sum))
            return left;
        else if((right.sum >= left.sum) && (right.sum >= cross.sum))
            return right;
        else
            return cross;
    }
}
//dynamic programming
//**in the future, add the range
int calc_dynamic(int*a ,int length){
    dp[0] = a[0];
    int maxsum = dp[0];
    //calc dp array
    for(int i = 1; i < length ; i++){
        dp[i] = max(dp[i-1]+a[i],a[i]);
        if(maxsum < dp[i])
            maxsum = dp[i];
    }
    //print dp array
    for(int i = 0; i < length ; i++){
        cout<<"dp["<<i<<"] = "<<dp[i]<<endl;
    }
    return maxsum;
}

int main(){
    //int arr[10] = {-10,-7,-4,-3,-2,-1,-12,-17,-25,-1};
    int arr[10] = {-10,-7,5,-7,10,5,-2,17,-25,1};

    //solve with Divide and conquer
    //N(lnN)
    sol s = FMSA(arr,0,9);
    cout<<"left pos :"<<s.low<<endl;
    cout<<"right pos :"<<s.high<<endl;
    cout<<"max sum :"<<s.sum<<endl<<endl;

    //solve with dynamic programming
    //N
    int _sol = calc_dynamic(arr,10);
    cout<<"dynamic solution : "<<_sol<<endl;
    return 0;
}