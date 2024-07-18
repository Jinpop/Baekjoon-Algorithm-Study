#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int num[200001];

    unordered_map<int, int> count;
    int j = 0;
    int length = 0;
    int max_length = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        count[num[i]]++;

        // count를 초과한경우
        if (count[num[i]] > m)
        {
            // j포인터의 위치를 count를 넘긴 숫자 +1로 조정
            while (count[num[i]] > m)
            {
                count[num[j]]--;
                j++;
            }
        }

        length = i - j + 1;
        if (max_length < length)
            max_length = length;
    }

    cout << max_length;

    return 0;
}
