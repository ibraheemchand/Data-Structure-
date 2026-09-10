#include <iostream>
using namespace std;

int main()
{
    int N, M;

    cout << "Enter number of students (N): ";
    cin >> N;

    cout << "Enter number of assessments (M): ";
    cin >> M;

    // Dynamically allocate N x M array
    int** marks = new int*[N];

    for (int i = 0; i < N; i++)
    {
        marks[i] = new int[M];
    }

    /*
    a) Populate the whole array by user input
       Asymptotic Upper Bound: O(N * M)
    */
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << "Enter marks for Student " << i + 1
                 << ", Assessment " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }


    /*
    b) Display total marks for each student
       Asymptotic Upper Bound: O(N * M)
    */
    for (int i = 0; i < N; i++)
    {
        int total = 0;

        for (int j = 0; j < M; j++)
        {
            total += marks[i][j];
        }

        cout << "Total marks of Student " << i + 1
             << " = " << total << endl;
    }


    /*
    c) Calculate:
       - Main diagonal
       - Above main diagonal
       - Below main diagonal

       We only visit elements relevant to each calculation.

       Asymptotic Upper Bound: O(N * M)
    */

    long long diagonalSum = 0;
    long long aboveDiagonalSum = 0;
    long long belowDiagonalSum = 0;

    // Main diagonal
    // Only possible when row and column indices are equal.
    // Number of elements = min(N, M)
    // Complexity: O(min(N, M))
    for (int i = 0; i < N && i < M; i++)
    {
        diagonalSum += marks[i][i];
    }

    // Elements above the main diagonal
    // j > i
    // Complexity: O(N * M) in the worst case
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            aboveDiagonalSum += marks[i][j];
        }
    }

    // Elements below the main diagonal
    // i > j
    // Complexity: O(N * M) in the worst case
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i && j < M; j++)
        {
            belowDiagonalSum += marks[i][j];
        }
    }

    cout << "\nMain Diagonal Sum = " << diagonalSum << endl;
    cout << "Above Main Diagonal Sum = " << aboveDiagonalSum << endl;
    cout << "Below Main Diagonal Sum = " << belowDiagonalSum << endl;


    /*
    d) Overall Combined Asymptotic Time Upper Bound

       Part (a) = O(N * M)
       Part (b) = O(N * M)
       Part (c) = O(N * M)

       Overall:
       O(N*M) + O(N*M) + O(N*M)
       = O(3NM)
       = O(N*M)

       Therefore, the overall asymptotic upper bound is:

       O(N * M)
    */


    // Deallocate dynamically allocated memory
    for (int i = 0; i < N; i++)
    {
        delete[] marks[i];
    }

    delete[] marks;

    return 0;
}