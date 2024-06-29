#include <iostream>
#include <algorithm>
using namespace std;
int medals[1001][3];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    m--;
    for (int i = 0; i < n; i++)
    {
        int index;
        cin >> index >> medals[index-1][0] >> medals[index-1][1] >> medals[index-1][2];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (medals[m][0] > medals[i][0])
        {
            count++;
        }
        else if (medals[m][0] == medals[i][0])
        {
            if (medals[m][1] > medals[i][1])
            {
                count++;
            }
            else if (medals[m][1] == medals[i][1]){
                if (medals[m][2] > medals[i][2]){
                    count++;
                }
            }
        }
    }

    cout << count+1;

    return 0;
}