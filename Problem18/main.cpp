#include <vector>
#include <iostream>
#include <cstdint>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstring>

int max_sum(std::vector<std::vector<int>> triangle)
{
    int max = 0; // to hold the actual result
    int sum1 = 0; // to hold the intermediate result
    int sum2 = 0; // to hold the other intermediate result

    for(int i = triangle.size() - 2; i >= 0; i--) // loop through lines
    {
        for(int j = 0; j < triangle[i].size(); j++) // loop through line elements
        {
            // get the max sum and put it directly into the next-to-last line
            sum1 = triangle[i][j] + triangle[i+1][j];
            sum2 = triangle[i][j] + triangle[i+1][j+1];

            if(sum1 > sum2)
            {
                triangle[i][j] = sum1;
            }
            else
            {
                triangle[i][j] = sum2;
            }
        }
    }

    return triangle[0][0];
}

std::vector<std::vector<int>> build_easy(void)
{
    std::vector<std::vector<int>> triangle;
    triangle.push_back({3});
    triangle.push_back({7, 4});
    triangle.push_back({2, 4, 6});
    triangle.push_back({8, 5, 9, 3});

    return triangle;
}

void print_triangle(std::vector<std::vector<int>> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void read_input(std::string filename, std::vector<std::vector<int>>& values)
{
    // reading the input file
    std::fstream newfile;
    newfile.open(filename, std::ios::in);
    std::string line;

    std::stringstream _stream;

    std::vector<int> line_int;

    int element = 0;

    while(getline(newfile, line))
    {
        _stream << line;
        while(_stream >> element)
        {
            line_int.push_back(element);
        }
        values.push_back(line_int);
        _stream.str("");
        _stream.clear();
        line_int.clear();
    }
}

void print_2d_vector(std::vector<std::vector<int>>& values)
{
    for (int i = 0; i < values.size(); i++)
    {
        for (int j = 0; j < values[i].size(); j++)
        {
            std::cout << values[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    std::vector<std::vector<int>> values;
    std::vector<std::vector<int>> values2;
    std::vector<std::vector<int>> values3;
    read_input("file1.txt", values); // the vector now has elements as they are in the file
    read_input("file2.txt", values2);
    read_input("file3.txt", values3);
    print_2d_vector(values);

    std::cout << max_sum(values) << std::endl;

    
    int value = max_sum(values2);
    std::cout << value << std::endl;
    value = max_sum(values3);
    std::cout << value << std::endl;

    return 0;

}
