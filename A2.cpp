#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<stack>
#include<stdlib.h>
using namespace std;

class Solution{
    public:
    int sumArr(vector<int> v)
    {
        int sum = 0;
        for(int i = 0; i < v.size(); i++)
        {
            sum += v[i];
        }
        return sum;
    }

    int sSum(vector<int> v)
    {
        int sum = sumArr(v), index6 = 0, index7 = 0, result = 0;
        bool is6 = false, is7 = false;

        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == 6)
            {
                is6 = true;
                index6 = i;
                break;
            }
        }

        if (is6)
        {
            for(int i = index6; i < v.size(); i++)
            {
                result += v[i];
                if(v[i] == 7)
                {
                    is7 = true;
                    index7 = i;
                    break;
                }
            }
        }
        return is7? (sum - result):sum;
    }
};

int main(){
    system("cls");
    vector<int> v={10, 3, 6, 1, 2, 7, 9};
    Solution s;
    cout<<s.sumArr(v)<<endl;
    cout<<s.sSum(v)<<endl;
    return 0;
}