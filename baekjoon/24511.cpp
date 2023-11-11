// queuestack

// #include <iostream>
// using namespace std;

// int main(void)
// {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);

//     int N, M, element, poped;
//     int* A; // 자료구조
//     int** B; // queuestack에 들어있는 자료구조 이차원 배열
//     int* C; //  queuestack에 삽입할 원소 배열
//     cin >> N;
//     A = new int[N];
//     B = new int*[N];

//     for (int i = 0; i < N; i++) // 이차원 배열 할당
//     {
//         B[i] = new int[2];
//     }

//     for (int i = 0; i < N; i++) // A
//     {
//         cin >> element;
//         A[i] = element;
//     }

//     for (int i = 0; i < N; i++) // B
//     {
//         cin >> element;
//         B[i][0] = element;
//     }

//     cin >> M;

//     for (int i = 0; i < M; i++) // c
//     {
//         cin >> element;
//         poped = element;
//         for (int i = 0; i < N; i++) // queuestack에 삽입
//         {

//             B[i][1] = poped;
//             if (A[i] == 0) // queue
//             {
//                 poped = B[i][0];
//                 B[i][0] = B[i][1];
//             }
//             // stack일 때는 poped 바뀌지 않음
//         }
//         cout << poped << ' ';
//     }

//     return 0;
// }

#include <iostream>
#include <deque>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> dq;
    int N, M, element;
    int* A; // 자료구조
    int* B; // queuestack에 들어있는 원소

    cin >> N;
    A = new int[N];
    B = new int[N];

    for (int i = 0; i < N; i++) // A
    {
        cin >> element;
        A[i] = element;
    }

    for (int i = 0; i < N; i++) // B
    {
        cin >> element;
        B[i] = element;
    }

    for (int i = 0; i < N; i++)
    {
        if (!A[i])
        {
            dq.push_back(B[i]);
        }
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> element; // C
        dq.push_front(element);
        cout << dq.back() << ' ';
        dq.pop_back();
    }

    return 0;
}