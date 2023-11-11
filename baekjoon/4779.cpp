// 칸토어 집합 (재귀, 분할정복)
#include <iostream>
#include <cmath>
using namespace std;

int N;
char array[531500];

void cantorian_set (int n, int power)
{
    if (n == 0)
    {
        return ;
    }

    for (int i = 0; i < power;  i++)
    {
        if (!((i / n) % 2 == 0))
        {
            array[i] = ' ';
        }
    }

    cantorian_set(n / 3, power);
}

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int power;

    while (cin >> N)
    {
        power = pow(3, N);
        for (int i = 0; i < power; i++)
        {
            array[i] = '-';
        }
        cantorian_set(power / 3, power);
        
        for (int j = 0; j < power; j++)
        {
            cout << array[j];
        }
        cout << '\n';
    }
    
    return 0;
}

// 예제 입력
// 0
// 1
// 3
// 2

//예제 출력
// -
// - -
// - -   - -         - -   - -
// - -   - -