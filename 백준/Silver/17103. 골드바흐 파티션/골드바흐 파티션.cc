#include <iostream>
using namespace std;
#define MAX 1000001



int main(){
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool table[MAX];
	for (int i = 2; i < MAX; i++){
	  table[i] = true;
  }

	for (int i = 2; i * i < MAX; i++) //true값인 값의 제곱이 MAX이하면 굳이 체크할 필요가 없음
	{
		if (table[i]) {  //소수일 경우
			for (int j = i * i; j < MAX; j += i){ //true값인 값의 제곱이 MAX이하면 굳이 체크할 필요가 없음, j+=i 는 중복되는 수가 포함되지만 넘어감.
			  table[j] = false;
      }
    }
	}

  int n;
  cin >> n;

  for (int i = 0; i < n; i++){
    int temp;
    int count = 0;

    cin >> temp;

    for (int j = 2; j <= temp/2; ++j){
      if (table[j]){
        if (table[temp-j]){
          count++;
        }
      }
    }

    cout << count << "\n";
  }

  return 0;
}