// 2156. 포도주 시식 (다이나믹 프로그래밍, 동적 계획법)

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int wine[10003];
    int dp[10003];

    cin >> n;

    wine[0] = wine[1] = wine[2]; // 처음 세 잔 0으로 초기화
    dp[0] = dp[1] = dp[2];

    for (int i = 3; i < n + 3; i++)
    {
        cin >> wine[i];
    }

    for (int i = 3; i < n + 3; i++)
    {
        // 점화식
        // i-1번 째 잔을 마신 경우 dp[i] = dp[i-3]+wine[i-1]+wine[i]
        // i-1번 째 잔을 안마신 경우  dp[i] = dp[i-2]+wine[i]
        int temp = max(dp[i-3]+wine[i-1]+wine[i], dp[i-2]+wine[i]);
        
        // i번 째 잔을 마신 경우와 안마신 경우중 MAX
        dp[i] = max(temp, dp[i-1]);
    }

    cout << dp[n+2];

    return 0;
}

// 예제 입력
// 6
// 6
// 10
// 13
// 9
// 8
// 1

// 예제 출력
// 33