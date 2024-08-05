#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<int> counting(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
    vector<int> result(2);
    int countApp = 0, countOrg = 0;

    for(int i = 0; i < apples.size(); i++)
    {
        if(apples[i]+a >= s && apples[i]+a <= t)
        {
            countApp++;
        }
    }
    result[0] = countApp;

    for(int i = 0; i < apples.size(); i++)
    {
        if(oranges[i]+b >= s && oranges[i]+b <= t)
        {
            countOrg++;
        }
    }
    result[1] = countOrg;
    
    return result;
}

int main(){
    system("cls");

    int s, t, a, b, m, n;
    cin >> s >> t;
    cin >> a >> b;
    cin >> m >> n;

    vector<int> apples(m);
    for(int i = 0; i < apples.size(); i++) cin >> apples[i];

    vector<int> org(n);
    for(int i = 0; i < org.size(); i++) cin >> org[i];

    vector<int> count = counting(s, t, a, b, apples, org);
    cout << count[0] << endl;
    cout << count[1] << endl;
    return 0;
}