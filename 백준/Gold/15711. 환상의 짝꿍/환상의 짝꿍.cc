#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000001
bool table[MAX] = {0};

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> num;

    for (long long i = 2; i < MAX; i++)
    {
        if (!table[i])
        {
            num.push_back(i);
            for (long long j = i * i; j < MAX; j += i)
            {
                table[j] = 1;
            }
        }
    }

    while (n--)
    {
        long long a, b;
        cin >> a >> b;

        // 2보다 큰 짝수이면 400경까지는 다 소수 두개로 나눠진다고 한다. (증명됨)
        if (a + b < 4)
        {
            cout << "NO\n";
        }
        else if ((a + b) % 2 == 0)
        {
            cout << "YES\n";
        }
        else
        {
            bool check = 1;
            for (long long ele : num)
            {
                if (ele * ele > a + b - 2)
                    break;
                if ((a + b - 2) % ele == 0)
                {
                    cout << "NO\n";
                    check = 0;
                    break;
                }
            }

            if (check == 1)
            {
                cout << "YES\n";
            }
        }
    }

    return 0;
}