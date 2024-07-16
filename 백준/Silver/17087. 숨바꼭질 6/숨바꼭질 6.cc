#include <iostream>
#include <cmath>
using namespace std;

int euclid(int a, int b)
{
    int x = max(a, b);
    int y = min(a, b);
    if (min(a, b) == 0)
    {
        return a;
    }
    else
    {
        return euclid(y, x % y);
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int before_num;
    cin >> before_num;
    int index = abs(before_num - m);

    before_num = abs(before_num - m);

    for (int i = 1; i < n; i++)
    {
        int temp;
        cin >> temp;
        int new_num = euclid(abs(temp - m), before_num);
        if (new_num < index)
        {
            index = new_num;
        }
        before_num = abs(temp - m);
    }

    cout << index;

    return 0;
}