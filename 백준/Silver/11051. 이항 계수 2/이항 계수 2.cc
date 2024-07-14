#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int num[1001][1000] = {0};

    int n, k;

    cin >> n >> k;

    if (k == 0 || n == k)
    {
        cout << 1;
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if(i == j){
                num[i][j] = 1;
            }
            else if (i - 1 == j || j == 1)
            {
                num[i][j] = i;
            }
            else
            {
                num[i][j] = (num[i-1][j] + num[i-1][j-1])%10007 ;
            }

        }
    }

    cout << num[n][k];

    return 0;
}
