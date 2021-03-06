#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Matrix.h"

const int SIZE = 10;

using namespace std;

void Swap(int& index1, int& index2)
{
    int temp = index1;
    index1 = index2;
    index2 = temp;
}

template<typename T>
void generateMatrix(Matrix<T>& matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}

template<typename T>
void showMatrix(const Matrix<T>& matrix)
{
    cout << matrix << endl << endl;
}

template<typename T>
void swapElements(Matrix<T>& matrix)
{
    for (int counter = 0; counter < SIZE; counter++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (matrix[i][j] > matrix[counter][counter])
                {
                    Swap(matrix[i][j], matrix[counter][counter]);
                }
            }
        }
    }
}

template<typename T>
void specialSituation(Matrix<T>& matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE - i; j++)
        {
            if (matrix[j][j] > matrix[j - 1][j - 1])
            {
                Swap(matrix[j - 1][j - 1], matrix[j][j]);
            }
        }
    }
}

int main()
{
    srand(time(0));

    Matrix<int> matrix(SIZE, SIZE);

    generateMatrix(matrix);

    showMatrix(matrix);

    swapElements(matrix);

    specialSituation(matrix);

    showMatrix(matrix);

    return 0;
}
