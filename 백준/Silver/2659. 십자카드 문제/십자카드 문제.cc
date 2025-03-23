#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

int clocknum(int num)
{

    vector<int> temp;
    temp.push_back(num / 1000);
    temp.push_back((num % 1000) / 100);
    temp.push_back((num % 100) / 10);
    temp.push_back(num % 10);

    for (int i = 0; i < 3; i++)
    {
        temp.push_back(temp[0]);
        temp.erase(temp.begin());

        int temp_num = temp[0] * 1000 + temp[1] * 100 + temp[2] * 10 + temp[3];
        if (num > temp_num)
        {
            num = temp_num;
        }
    }

    return num;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    vector<int> v;
    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int num = v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3];
    int idx = clocknum(num);
    int cnt = 1;

    for (int i = 1111; i < idx; i++)
    {
        if (clocknum(i) == i)
        {
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}