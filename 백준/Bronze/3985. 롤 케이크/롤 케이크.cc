#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    bool canTake[1001];
    int l, n;
    int expectNum = 0, expectIdx, realNum = 0, realIdx;

    cin >> l >> n;
    int left, right, temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> left >> right;

        if (expectNum < right - left + 1)
        {
            expectNum = right - left + 1;
            expectIdx = i;
        }

        temp = 0; 
        for (int i = left; i <= right; i++)
        {
            if (!canTake[i])
            {
                temp++;
                canTake[i] = true;
            }
        }
        
        if (realNum < temp)
        {
            realNum = temp;
            realIdx = i;
        }
    }

    cout << expectIdx << '\n'<< realIdx;
}