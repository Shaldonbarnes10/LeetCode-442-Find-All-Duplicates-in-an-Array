#include<iostream>
#include<vector>
using namespace std;
int main(){
    int nums[8] = {4, 3, 2, 7, 8, 2, 3, 1};  //example input
    vector<int> a;
    for (int num:nums){
        int idx = abs(num)-1;
        if (nums[idx]<0){
            a.push_back(abs(num));
        }else{
            nums[idx] = -nums[idx];
        }
    }
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
}