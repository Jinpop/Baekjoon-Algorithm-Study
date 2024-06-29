#include <iostream>
#include <algorithm>
using namespace std;
int medals[1001][3];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, target;
    cin >> n >> target;
    target--;
    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index >> medals[index-1][0] >> medals[index-1][1] >> medals[index-1][2];
    }

    int count = n;
    for (int i = 0; i < n; i++)
    {
        if (medals[target][0] > medals[i][0])
        {
            count--;
        }
        else if (medals[target][0] == medals[i][0])
        {
            if (medals[target][1] > medals[i][1])
            {
                count--;
            }
            else if (medals[target][1] == medals[i][1]){
                if (medals[target][2] >= medals[i][2]){
                    count--;
                }
            }
        }
    }

    cout << count+1;

    return 0;
}