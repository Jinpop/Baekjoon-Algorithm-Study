#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n <= 1)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << 0;
        return 0;
    }

    int max_x = -10000, min_x = 10000, max_y = -10000, min_y = 10000;

    while (n--)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;

        if (temp1 > max_x)
            max_x = temp1;
        if (temp1 < min_x)
            min_x = temp1;

        if (temp2 > max_y)
            max_y = temp2;
        if (temp2 < min_y)
            min_y = temp2;
    }

    cout << (max_x - min_x) * (max_y - min_y);

    return 0;
}