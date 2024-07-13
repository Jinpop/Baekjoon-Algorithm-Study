#include <iostream>
#include <set>
using namespace std;
#define MAX 1000001
bool table[MAX];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    set<long long> num;

    // 소수를 set에 순서대로 넣어준다.
    for (long long i = 2; i < MAX; i++)
    {
        if (!table[i])
        {
            num.insert(i);
            for (long long j = i * i; j < MAX; j += i)
            {
                table[j] = 1;
            }
        }
    }

    long long n;
    cin >> n;

    // 입력 값이 8보다 작을 경우 불가능하다.
    if (n < 8)
    {
        cout << -1;
    }
    else
    {
        // 홀수일 경우 2,3을 출력해서 n을 2보다 큰 짝수로 만들어준다.
        if (n % 2 == 1)
        {
            cout << "2 3 ";
            n -= 5;
        }
        else
        {
            cout << "2 2 ";
            n -= 4;
        }

        for (long long ele : num)
        {
            if (num.find(n - ele) != num.end())
            {
                cout << ele << " " << n - ele;
                break;
            }
        }
    }

    return 0;
}