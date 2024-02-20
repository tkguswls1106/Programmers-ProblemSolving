#include <iostream>

using namespace std;

// 행의 사자 배치 경우: XX, OX, XO
// => 이전행 XX일때 가능한 다음행: XX, OX, XO
// => 이전행 OX일때 가능한 다음행: XO, XX
// => 이전행 XO일때 가능한 다음행: OX, XX
// 밑의 주석은 위와 같은 말임.
// => 현재행 XX일때 가능한 이전행: XX, OX, XO
// => 현재행 OX일때 가능한 이전행: XO, XX
// => 현재행 XO일때 가능한 이전행: OX, XX

// dp[i][k] = i번째 행에 k방법의 동물을 놓는 경우의 수
int dp[100002][3] = { 0, };  // 인덱스 0: XX, 1: OX, 2: XO

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for(int i=2; i<=n; i++) {
        // 출력문에서만이 아닌, 여기서도 마찬가지로 아예 mod연산을 해줘야지 자료형 범위 초과를 막을 수 있다.
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    // 이 문제는 평소 다른 문제들과는 다르게, dp의 단일값을 출력하는 것이 아닌 dp의 추가연산값이 답 출력값이기때문에,
    // for문에서 mod연산을 해줬어도 출력문에서도 한번더 mod연산을 해주어야만 한다.
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;  // 이 문제의 경우에선 'cout << dp[n][0] + dp[n][1] + dp[n][2];'는 틀림.

    
    return 0;
}