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
#include <vector>
#include "../include/tree.hpp"

/**
 * @brief Implementation in read_file.cpp. The function opens the text file and reads  the information
 * storing it into a 2d-vector (vector of vectors).
 * 
 * @return std::vector<std::vector<int>> 
 */
std::vector<std::vector<int>> read_file();

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[]){

    std::vector<std::vector<int>> problems = read_file();

    Tree test[problems.size()];
    for(int i = 0; i < problems.size(); i++)
        test[i].create_tree(problems[i]);

    /*for(int i = 0; i < problems.size(); i++){
        for(int j = 0; j < problems[i].size(); j++)
            std::cout << problems[i][j] << " ";
        std::cout << std::endl;
    }*/

    return 0;
}