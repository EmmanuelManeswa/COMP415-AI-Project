/**
 * @file main.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief 
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
 * @brief the function opens the text file and read the information storing it into a
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


/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]){

    std::vector<std::vector<int>> problems = read_file();


    for(int i = 0; i < problems.size(); i++){
        for(int j = 0; j < problems[i].size(); j++)
            std::cout << problems[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}