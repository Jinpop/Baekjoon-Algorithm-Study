#include <iostream>
using namespace std;
int num[2188][2188] = {0};
int total[3] = {0};

void check(int n, int x, int y)
{
    int check_num = num[x][y];
    bool right = 1;

    for (int i = x; i < x+n; i++)
    {
        for (int j = y; j < y+n; j++)
        {   
            if (num[i][j] != num[x][y])
            {
                right = 0;
                break;
            }
        }
    }

    // 확인한 범위가 전부 하나의 숫자 일 경우 카운트해줌
    if (right)
    {
        switch(check_num){
            case -1:
                total[0]++;
                break;
            case 0:
                total[1]++;
                break;
            case 1:
                total[2]++;
        }
    }
    else
    {
        for (int i = x; i < x+n; i+=n/3)
        {
            for (int j = y; j < y+n; j+=n/3)
            {
                check(n / 3, i, j);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num[i][j];
        }
    }

    check(n, 1, 1);

    for (int i =0; i < 3; i++){
        cout << total[i] << "\n";
    }

    return 0;
}