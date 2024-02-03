#include <iostream>


int** New_array(int col, int row) {
    int** Array = new int* [col];
    for (int i = 0; i < col; ++i) {
        Array[i] = new int[row];
    }
    return Array;
}

void Input(int** Array, int col, int row) {
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout << "Array[" << i << "][" << j << "] = ";
            std::cin >> Array[i][j];
        }
    }
}

void RandomNumbersInArray(int** Array, const int col, const int row)
{
    srand(unsigned int(9));
    for (int c = 0; c < col; c++)
        for (int r = 0; r < row; r++)
            Array[c][r] = rand() % 70;
}

void PrintArray(int** Array, int col, int row) {
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout << Array[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void Sum_poboch(int** Array, int col, int row) {
    int sum_pob = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (i+j==col+1)
            {
                sum_pob += Array[i][j];
            }
        }
    }
    std::cout << "Sum of pobochnaya diagonal: " << sum_pob;
}

int main()
{
    int col, row;

    std::cout << "Enter number of columns: ";
    std::cin >> col;
    std::cout << "Enter number of rows: ";
    std::cin >> row;

    int** Array = New_array(col, row);

    RandomNumbersInArray(Array, col, row);

    PrintArray(Array, col, row);

    Sum_poboch(Array, col, row);

    for (int i = 0; i < col; i++) {
        delete[] Array[i];
    }
    
}
