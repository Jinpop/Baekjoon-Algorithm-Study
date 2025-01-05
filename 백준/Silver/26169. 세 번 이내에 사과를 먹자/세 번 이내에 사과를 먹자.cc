#include <iostream>
using namespace std;

int board[5][5] = {};
int apple = 0;
bool finish = false;

void dfs(int r, int c, int cnt, int apple) {
    //범위나 카운트 초과시
    if (r > 4 || r < 0 || c > 4 || c < 0 || cnt > 4) {
        return;
    }

    //apple 두개 모았을때
    if (apple == 2) {
        finish = true;
        return;
    }

    //길이 막혀있을 때
    if (board[r][c] == -1) {
        return;
    }

    //사과획득
    if (board[r][c] == 1) {
        apple++;
    }

    //지나간 자리 다시 못지나가도록 
    int temp = board[r][c];
    board[r][c] = -1;

    dfs(r + 1, c, cnt + 1, apple);
    dfs(r - 1, c, cnt + 1, apple);
    dfs(r, c + 1, cnt + 1, apple);
    dfs(r, c - 1, cnt + 1, apple);

    board[r][c] = temp;
    //return 할 떄 1이었으면 사과 카운트 감소
    if (temp == 1) {
        apple--;
    }

}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    
    int a, b;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }
    cin >> a >> b;
   
    dfs(a, b, 0, 0);

    if (finish) cout << "1";
    else cout << "0";
    return 0;
}
