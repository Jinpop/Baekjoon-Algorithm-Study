#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // 양동이를 거리별로 정렬시키기 위해 map 사용
    map<int, int> list;

    // 입력
    while (n--)
    {
        int distance, amount;
        cin >> amount >> distance;
        list[distance] = amount;
    }

    // 첫 양동이와 끝 양동이의 위치
    int start = list.begin()->first;
    int end = list.rbegin()->first;

    // 초기 temp_sum
    int temp_sum = 0;
    for (int i = start; i <= start + 2 * m; i++)
    {
        // 해당위치에 양동이가 있을 경우 더해줌
        if (list.count(i))
        {
            temp_sum += list[i];
        }
    }
    int max_sum = temp_sum;

    // window silding기법
    for (int i = start + 1; i <= end - m; i++)
    {
        // 닿지 못하는 양동이가 생긴 경우 temp_sum에 반영
        if (list.count(i - 1))
            temp_sum -= list[i - 1];

        // 닿을 수 있는 양동이가 생긴 경우 temp_sum에 반영
        if (list.count(i + 2 * m))
            temp_sum += list[i + 2*m];

        // max_sum 갱신
        if (max_sum < temp_sum)
            max_sum = temp_sum;
    }

    cout << max_sum;

    return 0;
}