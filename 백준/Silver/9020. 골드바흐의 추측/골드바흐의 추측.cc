#include <iostream>
#include <unordered_set>
using namespace std;
#define MAX 10001

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;

    // false로 초기화 되기 때문에 false일 경우 소수인걸로.
    bool table[MAX] {0};

    // 에라스토테네스의 체 알고리즘으로 소수가 아닌 수를 true로 바꿔준다.
    for (int i = 2; i * i < MAX; i++)
    {
        //소수일 경우 for문으로 들어가 그 배수를 전부 소수가 아닌 것으로 마킹함.
        if (table[i] == 0)
        {
            for (int j = i * i; j < MAX; j += i)
            {
                table[j] = 1;
            }
        }
    }

    // 테스트케이스가 제한이 없으므로 소수에 대한 접근의 시간 복잡도를 줄이기 위해 hash set 사용
    unordered_set<int> num;
    for (int i = 2; i < MAX; i++)
    {
        if (table[i] == false)
        {
            num.insert(i);
        }
    }

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
        // 만약 소수로 뺀 수가 소수인 경우 a, b, min_sub을 체크하고 기록함.
        int a, b, min_sub = MAX;
        for (int ele : num)
        {
            if (num.find(temp - ele) != num.end())
            {
                if (max(ele, temp - ele) - min(ele, temp - ele) < min_sub)
                {
                    a = max(ele, temp - ele);
                    b = min(ele, temp - ele);
                    min_sub = a - b;
                }
            }
        }

        cout << b <<" "<< a <<"\n";
    }

    

    return 0;
}