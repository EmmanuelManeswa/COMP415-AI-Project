/**
 * @file read_file.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief Only to read problems information from the problem.txt file
 * @version 0.1
 * @date 2019-12-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/**
 * @brief The function opens the text file and reads the information storing it into a
 * 2d-vector (vector of vectors).
 * 
 * @return std::vector<std::vector<int>> 
 */
std::vector<std::vector<int>> read_file(){
    int number_of_problems, initial_col, initial_row, destination_col, destination_row; 
    std::string line;
    std::vector<std::vector<int>> problems;
    std::ifstream input_file("../data/problem.txt");

    if(input_file.is_open()){
        input_file >> number_of_problems;
        std::vector<int> temp;

        for(int i = 0; i < number_of_problems && std::getline(input_file, line); i++){
            input_file >> initial_col >> initial_row >> destination_col >> destination_row;
            temp.push_back(initial_col);
            temp.push_back(initial_row);
            temp.push_back(destination_col);
            temp.push_back(destination_row);
            problems.push_back(temp);
            temp.clear();
        }
    }

    input_file.close();
    return problems;
}