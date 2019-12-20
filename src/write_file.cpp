/**
 * @file write_file.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief Only to write the solutions information to solution.txt file
 * @version 0.1
 * @date 2019-12-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <vector>
#include <fstream>

/**
 * @brief The following function opens/creates the solution.txt file and writes the solutions into the file.
 * 
 * @param solutions 
 */
void write_file(std::vector<std::vector<int>> solutions){
    std::ofstream output_file("../data/solution.txt");
    if(output_file.is_open()){
        for(int i = 0; i < solutions.size(); i++){
            if(solutions[i].size() != 1){
                for(int j = 0; j < solutions[i].size(); j++){
                    if(j == 0)
                        output_file << solutions[i][j] << " ";
                    else if(j > 0 && j <= 6){
                        if(j % 2 == 1)
                            output_file << "(" << solutions[i][j] << ",";
                        if(j % 2 == 0){
                            output_file << solutions[i][j] << ")";
                            if(j < 6)
                                output_file << "-";
                            if(j == 6)
                                output_file << "; ";
                        }
                    }
                    else{
                        if(j % 2 == 1)
                            output_file << "(" << solutions[i][j] << ",";
                        if(j % 2 == 0)
                            output_file << solutions[i][j] << ")";
                    }
                }
            }
            else
                output_file << solutions[i][0];
            output_file << std::endl;
        }
    }
    output_file.close();
}