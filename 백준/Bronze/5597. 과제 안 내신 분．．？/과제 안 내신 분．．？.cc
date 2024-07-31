#include <iostream>
using namespace std;
int main()
{
    int num[31] = {0};

    int i = 28;
    while (i--)
    {
        int temp;
        cin >> temp;
        num[temp] = 1;
    }

    i = 0;
    while (i++ != 30)
    {
        if (num[i] == 0)
        {
            cout << i << "\n";
        }
    }
}