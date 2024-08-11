#include <iostream>
#include <vector>
using namespace std;

class Calculator
{
public:
    int calc(int grade)
    {
        int result, d;
        if (grade >= 38)
        {
            d = (grade / 5 + 1) * 5;
            if (d - grade < 3)
            {
                result = d;
            }
            else
                result = grade;
        }
        else
        {
            result = grade;
        }
        return result;
    }
};

int main()
{
    Calculator C;

    int n;
    cin >> n;
    vector<int> grades(n);
    vector<int> result;
        

    for (int i = 0; i < grades.size(); i++)
    {
        cin >> grades[i];
        result.push_back(C.calc(grades[i]));
    }
    for (int i = 0; i < result.size(); i++) cout << result[i] << "  ";

    cout << endl;
    return 0;
}