#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int area[52][52];

void print_rain(vector<pair<int, int>> rain)
{
    for (pair<int, int> ele : rain)
    {
        cout << ele.first << " " << ele.second << "\n";
    }
}

void print_area(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << area[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // 격자 입력
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> area[i][j];
        }
    }

    // 초기 비구름 위치
    vector<pair<int, int>> rain;
    rain.push_back({n, 1});
    rain.push_back({n, 2});
    rain.push_back({n - 1, 1});
    rain.push_back({n - 1, 2});

    // 구름 이동
    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;

        switch (d)
        {
        case 1:
            for (pair<int, int> &ele : rain)
            {
                ele.second -= s;
                while (ele.second <= 0)
                    ele.second += n;
            }
            break;
        case 2:
            for (pair<int, int> &ele : rain)
            {
                ele.second -= s;
                while (ele.second <= 0)
                    ele.second += n;
                ele.first -= s;
                while (ele.first <= 0)
                    ele.first = n + ele.first;
            }
            break;
        case 3:
            for (pair<int, int> &ele : rain)
            {
                ele.first -= s;
                while (ele.first <= 0)
                    ele.first += n;
            }
            break;
        case 4:
            for (pair<int, int> &ele : rain)
            {
                ele.first -= s;
                while (ele.first <= 0)
                    ele.first += n;
                ele.second += s;
                while (ele.second > n)
                    ele.second -= n;
            }
            break;
        case 5:
            for (pair<int, int> &ele : rain)
            {
                ele.second += s;
                while (ele.second > n)
                    ele.second -= n;
            }
            break;
        case 6:
            for (pair<int, int> &ele : rain)
            {
                ele.second += s;
                while (ele.second > n)
                    ele.second -= n;
                ele.first += s;
                while (ele.first > n)
                    ele.first -= n;
            }
            break;
        case 7:
            for (pair<int, int> &ele : rain)
            {
                ele.first += s;
                while (ele.first > n)
                    ele.first -= n;
            }
            break;
        case 8:
            for (pair<int, int> &ele : rain)
            {
                ele.first += s;
                while (ele.first > n)
                    ele.first -= n;
                ele.second -= s;
                while (ele.second <= 0)
                    ele.second += n;
            }
            break;
        }

        // 구름이 이동한 영역에 +1
        for (pair<int, int> ele : rain)
        {
            area[ele.first][ele.second]++;
        }


        //비가 왔던 영역을 체크하는 배열
        int rained[52][52] = {0};
        // 1칸 앞 대각선 영역에 물이 있으면 그만큼 +1
        while (rain.size())
        {
            if (area[rain.back().first + 1][rain.back().second + 1] > 0)
            {
                area[rain.back().first][rain.back().second]++;
            }
            if (area[rain.back().first - 1][rain.back().second + 1])
            {
                area[rain.back().first][rain.back().second]++;
            }
            if (area[rain.back().first + 1][rain.back().second - 1])
            {
                area[rain.back().first][rain.back().second]++;
            }
            if (area[rain.back().first - 1][rain.back().second - 1])
            {
                area[rain.back().first][rain.back().second]++;
            }
            rained[rain.back().first][rain.back().second] =1;
            rain.pop_back();
        }

        // 구름이 생기는 영역을 체크하고 rain vector에 추가해준다.
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (area[i][j] >= 2 && !rained[i][j])
                {
                    area[i][j] -= 2;
                    rain.push_back({i, j});
                }
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum+=area[i][j];
        }
    }

    cout << sum;

    return 0;
}