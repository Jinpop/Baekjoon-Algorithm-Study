#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> count_map;

// Trie에 사용되는 노드를 정의합니다.
class TrieNode
{
public:
    // a부터z까지 인덱스 저장
    TrieNode *children[26];
    // 단어 완성 여부
    bool is_end;

    TrieNode()
    {
        is_end = false;
        // 우선 nullptr로 초기화
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

// root 생성
TrieNode *root = new TrieNode();
// 동일 문자열 입력 체크를 위한 map

void insert_s(string s);
void make_nick(string s);

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        make_nick(temp);
        count_map[temp]++;
        insert_s(temp);
    }

    return 0;
}

void insert_s(string s)
{
    // root에서 시작.
    TrieNode *t = root;
    for (int i = 0; i < (int)s.size(); i++)
    {
        // 'a'부터 'z'까지 0부터 25까지의 index로 매핑.
        int index = s[i] - 'a';
        // 해당하는 노드가 아직 없다면 새로운 노드를 만들어줍니다.
        if (t->children[index] == nullptr)
            t->children[index] = new TrieNode();
        // index에 해당하는 노드로 옮겨갑니다.
        t = t->children[index];
    }
    // 최종 위치에 단어의 끝임을 표시해줍니다.
    t->is_end = true;
}

void make_nick(string s)
{
    TrieNode *cur = root;
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        // 만약 하위 문자가 존재할 경우 옮겨감
        if (cur->children[index])
        {
            cur = cur->children[index];
        }
        // 하위 문자가 존재하지 않을 경우
        else
        {
            string nick = "";
            // 타 문자열과 겹친 횟수만큼 nick에 붙여줌
            for (int j = 0; j <= i; j++)
            {
                nick += s[j];
            }
            // 이전에 입력되지 않은 닉네임일 경우
            if (count_map[nick] == 0)
            {
                cout << nick << "\n";
            }
            // 이전에 입력된 닉네임의 경우
            else
            {
                cout << nick << count_map[nick] + 1 << "\n";
            }
            return;
        }
    }
    // 입력 받은 문자열과 완벽하게 prefix가 
    // 겹치는 문자열이 있는 경우 출력 없이 for문을 벗어나게 됨.
    // 그 경우 전체를 출력하고, 2회 이상의 입력인 경우 횟수도 같이 출력함.
    if (count_map[s] == 0)
    {
        cout << s << "\n";
    }
    else
    {
        cout << s << count_map[s] + 1 << "\n";
    }
}
