#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    cin.ignore();

    map<string, int> map;

    string names;
    getline(cin, names);
    vector<string> words;

    stringstream ss(names);
    string word;

    while (ss >> word)
    {
        map[word] = 0;
        words.push_back(word);
    }

    for (int i = 0; i < n; i++)
    {
        string temp;
        getline(cin, temp);
        stringstream ss(temp);

        while (ss >> word)
        {
            map[word]++;
        }
    }

    vector<pair<string, int>> sorted_map(map.begin(), map.end());

    sort(sorted_map.begin(), sorted_map.end(),
         [](const auto &a, const auto &b)
         {
            if (a.second == b.second)
            {
                return b.first > a.first;
            }
             return b.second < a.second; // 내림차순 정렬
         });

    for (auto ele : sorted_map)
    {
        cout << ele.first << " " << ele.second << "\n";
    }

    return 0;
}