#include <iostream>
using namespace std;

int main()
{
    int N ;
    int M ;

    cout << "Enter number of students : ";
    cin >> N;
    cin.ignore();
    cout << "Enter number of assessments : ";
    cin >> M;
    cin.ignore();
    
    int** marks = new int*[N];

    for (int i = 0; i < N; i++)
    {
        marks[i] = new int[M];
    }

  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << "Enter marks for Student " << i + 1 << ", Assessment " << j + 1 << " ";
            cin >> marks[i][j];
        }
    }


    for (int i = 0; i < N; i++)
    {
        int total = 0;

        for (int j = 0; j < M; j++)
        {
            total += marks[i][j];
        }

        cout << "Total marks of Student no. " << i + 1 << "   =     " << total << endl;
    }

    int diagonalSum = 0;          //A
   

    /*
  The sum of diagonal elements will run till the smallest number in between M and N, n = min(M,N)  , thus BigO Notation becomes O(n)
  */
    for (int i = 0; i < N && i < M; i++)
    {
        diagonalSum += marks[i][i];
    }




 int aboveDiagonalSum = 0;         //B
    /*
To find the sum of elements above the diagonal outer loop runs N times while inner loop runs M times , which results in the time Complexity and Big O notation O (N*M)  
*/
    
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < M; j++)
        {
            aboveDiagonalSum += marks[i][j];
        }
    }


int belowDiagonalSum = 0;          //C

/*
To find the sum of elements Below the diagonal outer loop runs N times while inner loop runs M times , which results in the time Complexity and Big O notation O (N*M)
*/
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j<i  && j < M; j++)
        {
            belowDiagonalSum += marks[i][j];
        }
    }

    cout << "main diagonal sum = " <<  diagonalSum  << endl;

    cout << "above main diagonal sum = "  << aboveDiagonalSum << endl;
    cout << "below main diagonal sum = " <<  belowDiagonalSum << endl;



    for (int i = 0; i < N; i++)
    {
        delete[] marks[i];
    }

    delete[] marks;

    return 0;
}