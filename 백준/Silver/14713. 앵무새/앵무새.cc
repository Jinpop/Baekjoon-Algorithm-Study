#include <iostream>
#include <sstream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore(); // 남아 있는 개행 문자를 getline이 받지 못하게 처리

    queue<string> s[101];

    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        istringstream iss(temp);

        string word;
        while (iss >> word)
        {
            s[i].push(word);
        }
    }

    string temp;
    getline(cin, temp);
    istringstream iss(temp);
    string word;

    while (iss >> word)
    {
        bool check = false;
        for (int i = 0; i < n; i++)
        {
            if (!s[i].empty() && s[i].front() == word)
            {
                check = true;
                s[i].pop();
                break;
            }
        }

        if (!check)
        {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!s[i].empty())
        {
            cout << "Impossible\n";
            return 0;
        }
    }

    cout << "Possible\n";

    return 0;
}
