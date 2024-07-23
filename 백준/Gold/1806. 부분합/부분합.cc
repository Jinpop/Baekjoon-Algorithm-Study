#include <iostream>
#include <algorithm>
using namespace std;
int num[100001] = {0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, s;
    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
        num[i] = num[i] + num[i - 1];
    }

    int min_length = 100000001;

    int i = 0, j = 1;

    while (j <= n && i != j)
    {
        //합이 s를 넘기지 못하면 j++ 넘기면 i++
        if (num[j] - num[i] >= s)
        {
            min_length = min(min_length, j-i);
            i++;
        }
        else
        {
            j++;
        }
    }

    if (min_length == 100000001)
    {
        cout << 0;
    }
    else
    {
        cout << min_length;
    }

    return 0;
}