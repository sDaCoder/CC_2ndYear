#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution{
    public:
        vector<int> withoutTen(vector<int> arr)
        {
            int n = arr.size();
            int i = 0;
            while(i < n)
            {
                if(arr[i] == 10)
                {
                    arr.erase(arr.begin() + i);
                    n--;
                }
                else
                {
                    i++;
                }
            }
            return arr;
        }
};

int main(){
    system("cls");
    vector<int> arr = {1,10,10,2};

    Solution s;
    s.withoutTen(arr);
    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
}