#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    //스위치 갯수
    int n;  
    cin >> n;
    //스위치 배열 초기화, 0번 인덱스는 사용하지 않음.
    bool *switches = new bool[n+1];
    for (int i = 1; i< n+1; i++){
        cin >> switches[i];
    }

    //학생 수
    int num;
    cin >> num;
    //학생 수 만큼 반복
    for (int i = 0; i < num; i++){
        int gender, index;
        cin >> gender >> index;
        //초기 인덱스 값을 저장할 temp변수
        int temp = index;

        //남자일 경우
        if (gender == 1){
            //index를 증가 시키며 반복하고 n+1보다 커지면 break
            while (index <= n){
                switches[index] = !switches[index];
                index+=temp;
            }
        }
        else{
            int count = 1;
            //입력 받은 인덱스는 무조건 바꾼다.
            switches[index] = !switches[index];
            //입력 받은 인덱스의 양 옆으로 count변수를 이용해서 같은지 체크하고 바꾼다.
            //out of bound에러를 방지하지 위한 조건도 추가한다.
            while(index - count > 0 && index + count <= n && switches[index-count] == switches[index+count]){
                switches[index-count] = !switches[index-count];
                switches[index+count] = !switches[index+count];
                count++;
            }
        }
    }

    for (int i = 1; i< n+1; i++){
        cout << switches[i] << " ";
        if (i% 20 == 0 && i != 1){
            cout << "\n";
        }
    }

    delete []switches;

    return 0;
}