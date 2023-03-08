#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

void ReadInput(std::string filename, std::vector<std::vector<int>>& matrix)
{
    // reading the input file
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    std::string line;

    std::stringstream _stream;

    std::string element;

    std::vector<int> matrix_line;

    while(getline(newfile, line))
    {
        _stream << line;
        int i = 0;
        int j = 0;
        while(std::getline(_stream, element, ','))
        {
            matrix_line.push_back(stoi(element));
        }
        matrix.push_back(matrix_line);

        matrix_line.clear();

        _stream.str("");
        _stream.clear();
    }
}

void Print2DMatrix(std::vector<std::vector<int>> matrix)
{
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            std::cout << matrix[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

int CalculateMax(std::vector<std::vector<int>> &matrix)
{
    int max_sum = matrix[0][0];
    int size_x = matrix.size();
    int size_y = matrix[0].size();
    //int x_pos = matrix.size()-1;
    //int y_pos = matrix[0].size()-1;

    // need to put the min of intermediate sum going into opposite directions

    // do the last row
    for(int i = matrix.size()-2; i >= 0; i--)
    {
        matrix[i][size_y-1] += matrix[i+1][size_y-1];
    }
    // do the last column
    for(int i = matrix[0].size()-2; i >= 0; i--)
    {
        matrix[size_x-1][i] += matrix[size_x-1][i+1];
    }
    
    // normal
    for(int i = size_x-2; i >= 0; i--)
    {
        for(int j = size_y-1; j >= 0; j--)
        {
            matrix[i][j] += std::min({matrix[i+1][j], matrix[i][j+1]});
        }
    }
    return matrix[0][0];
}

int main(void)
{
    std::vector<std::vector<int>> input_matrix;

    ReadInput("file1.txt", input_matrix);
    //ReadInput("file2.txt", input_matrix);

    //Print2DMatrix(input_matrix);

    std::cout << "Min sum " << CalculateMax(input_matrix) << std::endl;
    return 0;
}