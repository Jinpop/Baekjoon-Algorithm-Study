#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int sum = 0, max = 0;

    for (int i = 0; i < 4; i++)
    {
        int temp;
        cin >> temp;

        sum -= temp;
        
        cin >> temp;
        sum += temp;

        if (sum > max) max = sum;
    }

    cout << max;

    return 0;
}