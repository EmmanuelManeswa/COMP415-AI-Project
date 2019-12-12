/**
 * @file tree.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief Class implementations.
 * @version 0.1
 * @date 2019-12-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "../include/tree.hpp"

/**
 * @brief Construct a new Tree:: Tree object.
 * 
 */
Tree::Tree(){ }

/**
 * @brief Create a new node for the tree.
 * 
 * @return Tree::node_ptr 
 */
Tree::node_ptr Tree::new_node(){
    node_ptr temp_node = new Node;
    if(temp_node == nullptr){
        std::cout << "Error: Memory Allocation Failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    temp_node->top = temp_node->left = temp_node->right = temp_node->bottom = nullptr;
    return temp_node;
}

/**
 * @brief Creates 3 random bombs/mines and storing their loctions in a 2-d array [3][2].
 * 
 */
void Tree::create_bombs(){
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937_64 generator(seed); // Mersene twister pseudo-random generator of 64 bit numbers. An instantiation of mersene_twister_engine.
    std::uniform_int_distribution<int> distribution(0, 9); // Uniform discrete distribution. produces random integers in a range [0,9].
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            int temp_bomb;
            do{
                temp_bomb = distribution(generator);
            }while(temp_bomb == source[0] || temp_bomb == source[1] ||  temp_bomb == destination[0] || temp_bomb == destination[1]);
            bombs[i][j] = temp_bomb;
        }
    }
}

/**
 * @brief 
 * 
 * @param problem 
 */
void Tree::create_tree(std::vector<int> problem){
    source[0] = problem[0];
    source[1] = problem[1];
    destination[0] = problem[2];
    destination[1] = problem[3];
    create_bombs();
    std::cout << source[0] << " " << source[1] << " " << destination[0] << " " << destination[1] << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++)
            std::cout << "[" << bombs[i][j] << "]";
        std::cout << std::endl;
    }
}