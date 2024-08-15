#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string s;
    stack<char> st;
    cin >> s;
    
    for (int j = 0; j < s.length(); j++){
      if (st.empty())
      {
        if (s[j]==')')
        {
          st.push('N');
          break;
        }
        else
        {
          st.push(s[j]);
        }
      }
      else {
        if (st.top() == s[j]){
          st.push(s[j]);
        }
        else{
          st.pop();
        }
      }
    }

    if (st.empty()){
      cout << "YES" << "\n";
    }
    else {
      cout << "NO" << "\n";
    }

  }

  return 0;
}

