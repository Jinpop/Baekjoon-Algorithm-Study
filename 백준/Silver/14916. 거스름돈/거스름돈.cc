#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    int cnt = 0;
    // 13
    // 2 3
    //  5로 나눈 나머지가 짝수인 경우
    if (n % 5 % 2 == 0 && n >= 5)
    {
        cnt += n / 5;
        n = n % 5;
    }
    else if (n > 5)
    {
        cnt += n / 5 - 1;
        n = n % 5 + 5;
    }
    else if (n==5)
    {
        cout <<1;
        return 0;
    }

    if (n % 2 == 0 && n >= 2)
    {
        cnt += n / 2;
        n = n % 2;
    }
    else if (n % 2 == 1)
    {
        cout << -1;
        return 0;
    }

    cout << cnt << "\n";

    return 0;
}