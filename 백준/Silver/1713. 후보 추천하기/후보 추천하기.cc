#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, pair<int, int>> pic;

    int size, n;
    cin >> size >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;

        // 입력 값이 존재하지 않을 경우
        if (pic.find(temp) == pic.end())
        {
            // 사진틀에 공간이 있는 경우
            if (pic.size() < size)
            {
                // 추천수를 올린다.
                pic[temp].first = 1;
                // 들어온 순서를 기록한다.
                pic[temp].second = i;
            }
            else
            {
                pair<int, int> min;
                int min_index = pic.begin()->first;
                min = pic.begin()->second;

                // pic의 원소를 순회한 뒤 가장 추천수가 작으면서 들어온 순서가 오래된 인덱스를 찾는다.
                for (auto item : pic)
                {
                    // pair의 대소 비교는 첫번째부터 진행되고 같을 경우 두번째를 비교한다.
                    // 즉 추천수를 비교한 후 들어온 순서를 비교한다.
                    if (item.second < min)
                    {
                        min_index = item.first;
                        min = item.second;
                    }
                }

                pic.erase(min_index);

                // 추천 수를 올린다.
                pic[temp].first = 1;
                // 들어온 순서를 기록한다.
                pic[temp].second = i;
            }
        }
        // 입력 값이 존재할 경우 값만 올려주면 된다.
        else
        {
            pic[temp].first++;
        }
    }

    for (auto item : pic)
    {
        printf("%d ", item.first);
    }

    return 0;
}
