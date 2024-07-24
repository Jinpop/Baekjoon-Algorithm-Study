#include <iostream>
#include <string>
using namespace std;

class stack
{
public:
    void push(int n);
    void pop();
    void siz();
    void empty();
    void top();

private:
    int list[10001];
    int index = 0;
};

void stack::push(int n)
{
    list[index] = n;
    index++;
}

void stack::top()
{
    if (index == 0)
    {
        cout << "-1\n";
    }
    else
    {
        cout << list[index - 1] << "\n";
    }
}

void stack::pop()
{
    if (index > 0)
    {
        index--;
        cout << list[index] << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
}

void stack::empty()
{
    if (index == 0)
    {
        cout << "1\n";
    }
    else
    {
        cout << "0\n";
    }
}

void stack::siz()
{
    cout << index << "\n";
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    stack s;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        switch (temp[0])
        {
        case 'p':
            if (temp[1] == 'o')
            {
                s.pop();
            }
            else
            {
                int tem;
                cin >> tem;
                s.push(tem);
            }
            break;
        case 's':
            s.siz();
            break;
        case 'e':
            s.empty();
            break;
        case 't':
            s.top();
            break;
        default:
            break;
        }
    }

    return 0;
}