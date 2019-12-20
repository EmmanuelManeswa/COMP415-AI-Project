/**
 * @file main.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief Execution of the program starts here in the main function.
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
 * @brief Implementation in read_file.cpp. The function opens the text file and reads the information storing it into
 *  a 2d-vector (vector of vectors).
 * 
 * @return std::vector<std::vector<int>> 
 */
std::vector<std::vector<int>> read_file();

/**
 * @brief Implementation in write_file.cpp. The function create the text file and writes the solutions stored in the 
 * 2d-vector (vector of vectors).
 * 
 */
void write_file(std::vector<std::vector<int>>);

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(void){

    std::vector<std::vector<int>> problems = read_file();
    std::vector<std::vector<int>> solutions;

    Tree test[problems.size()];
    for(int i = 0; i < problems.size(); i++)
        solutions.push_back(test[i].create_tree(problems[i]));
    
    /*for(auto vv : solutions){
        for(auto v : vv)
            std::cout << std::endl << v << " ";
        std::cout << std::endl;
    }*/
    write_file(solutions);

    return 0;
}