#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    map<int, int> num;
    vector<int> v;
    double sum = 0;

    int _max = -99999;
    int _min = 99999;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        num[temp]++;
        sum += temp;
        v.push_back(temp);

        _max = max(_max, temp);
        _min = min(_min, temp);
    }

    sort(v.begin(), v.end());
    pair<int, int> p = {0, 0};

    for (auto ele : num)
    {
        if (ele.second > p.second)
        {
            p = ele;
        }
    }
    int cnt = 0;
    for (auto ele : num)
    {
        if (ele.second == p.second)
        {
            cnt++;
        }
        if (cnt == 2)
        {
            p = ele;
            break;
        }
    }

    string endl = "\n";
    if (round(sum / n) == -0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << round(sum / n) << endl;
    }
    cout << v[(n - 1) / 2] << endl;
    cout << p.first << endl;
    cout << _max - _min << endl;

    return 0;
}