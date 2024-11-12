#include <iostream>

using namespace std;

// - 풀이 및 점화식 도출 방법:
// * 과정 1. DP테이블 정의하기:
// DP[i]는 i를 1,2,3의 합으로 나타내는 방법의 수
// * 과정 2. 점화식 찾기:
// 예시로 DP[4]는? (참고로 밑의 +1의 의미는 단순합+1이다.)
// 합이 3인것(1,2,3의 합으로 만든 3의 가짓수)에 +숫자1을 하면, 합이 4가 됨. => DP[3]
// 합이 2인것(1,2,3의 합으로 만든 2의 가짓수)에 +숫자2를 하면, 합이 4가 됨. => DP[2]
// 합이 1인것(1,2,3의 합으로 만든 1의 가짓수)에 +숫자3를 하면, 합이 4가 됨. => DP[1]
// 위를 쉽게말하면, 4를 만드는 경우의 수는 단순히 1에서 3을 더한 경우, 2에서 2를 더한 경우, 3에서 1을 더한 경우의 수를 모두 더해주면 됨.
// ==> 'DP[4] = DP[3] + DP[2] + DP[1]' => 점화식은 'DP[k] = DP[k-1] + DP[k-2] + DP[k-3]'
// * 과정 3. 초기값 정의하기:
// 이 문제의 경우에는, 'DP[k] = DP[k-1] + DP[k-2] + DP[k-3]' 처럼 항이 세가지이므로, 세가지의 초기값 할당을 해야한다.
// ==> DP[1]=1, DP[2]=2, DP[3]=4

int dp[13] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // DP 점화식 초기값 할당.
    // 이 문제의 경우에는, 점화식이 'DP[i] = DP[i-1] + DP[i-2] + DP[i-3]'으로써 세가지의 초기값 할당이 필요하다.
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    // DP 테이블에 미리 값을 채워줌. (바텀업 방식이므로 재귀함수 대신 반복문 사용으로 미리 값들을 세팅)
    for(int i=4; i<11; i++) {  // 어차피 n은 양수이며 11보다 작다.
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        cout << dp[n] << "\n";
    }


    return 0;
}