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
 * @brief To check if there are 2 or 3 bombs/mines on the same row and column.
 * 
 * @return true : If there are bombs/mines on the same row and column.
 * @return false : If there are no bombs/mines on the same row and column.
 */
bool Tree::bombs_verification()const{
    if(bombs[0][0] == bombs[1][0] && bombs[0][1] == bombs[1][1]) return true;
    if(bombs[0][0] == bombs[2][0] && bombs[0][1] == bombs[2][1]) return true;
    if(bombs[1][0] == bombs[2][0] && bombs[1][1] == bombs[2][1]) return true;
    return false;
}

/**
 * @brief The following tests if there is a possible move to the top.
 * 
 * @param move 
 * @param row_no 
 * @param col_no 
 * @return true : If there is a possible move.
 * @return false : If there is no possible move.
 */
bool Tree::if_top(node_ptr move, int row_no, int col_no)const{
    if(row_no < 0) return false;
    if(move->board[row_no][col_no] == square::bomb_row)
        return if_top(move, row_no-1, col_no);
    return true;
}

/**
 * @brief The following function tests if there is a possible move to the left.
 * 
 * @param move 
 * @param row_no 
 * @param col_no 
 * @return true : If there is a possible move.
 * @return false : If there is no possible move.
 */
bool Tree::if_left(node_ptr move, int row_no, int col_no)const{
    if(col_no < 0) return false;
    if(move->board[row_no][col_no] == square::bomb_column)
        return if_left(move, row_no, col_no-1);
    return true;
}

/**
 * @brief The following function tests if there is a possible move to the right.
 * 
 * @param move 
 * @param row_no 
 * @param col_no 
 * @return true : If there is a possible move.
 * @return false :If there is no possible move.
 */
bool Tree::if_right(node_ptr move, int row_no, int col_no)const{
    if(col_no >= COLUMNS) return false;
    if(move->board[row_no][col_no] == square::bomb_column)
        return if_right(move, row_no, col_no+1);
    return true;
}

/**
 * @brief The following function tests if there is a possible move to the bottom.
 * 
 * @param move 
 * @param row_no 
 * @param col_no 
 * @return true : If there is a possible move.
 * @return false : If there is no possible move.
 */
bool Tree::if_bottom(node_ptr move, int row_no, int col_no)const{
    if(row_no >= ROWS) return false;
    if(move->board[row_no][col_no] == square::bomb_row)
        return if_bottom(move, row_no+1, col_no);
    return true;
}

/**
 * @brief 
 * 
 */
void Tree::create_root(){
    root = new_node();
    /**
     * @brief The following nested loop sets all the squares on the board to white.
     * 
     */
    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLUMNS; j++)
            root->board[i][j] = square::white;
    /**
     * @brief The following 2 line of code sets up the start and goal position on the.
     * 
     */
    root->board[source[1]][source[0]] = square::yellow; 
    root->board[destination[1]][destination[0]] = square::red;
    /**
     * @brief The following for loop sets up the bombs/mines to their respective squares on the board.
     * 
     */
    for(int i = 0; i < 3; i++)
        root->board[bombs[i][1]][bombs[i][0]] = square::bomb;
    /**
     * @brief The following nested loop sets all the squares in the same columns as the bombs/mines to bomb_columns.
     * 
     */
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < ROWS; j++)
            if(root->board[j][bombs[i][0]] != square::bomb)
                root->board[j][bombs[i][0]] = square::bomb_column;
    /**
     * @brief The following nested loop sets all the squares in the same row as the bombs/mines to bomb_rows.
     * 
     */
    for(int i = 0; i < 3; i++)
        for(int j= 0; j < ROWS; j++){
            for(int k = 0; k < COLUMNS; k++){
                if(j != bombs[i][1])
                    break;
                if(root->board[j][bombs[i][0]] != square::bomb)
                    root->board[i][bombs[i][0]] = square::bomb_row;
            }
        }
    /**
     * @brief Should add possible moves to board.
     * 
     */
    
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
    do{
        create_bombs();
    }while(bombs_verification());
    create_root();

    std::cout << source[0] << " " << source[1] << " " << destination[0] << " " << destination[1] << std::endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++)
            std::cout << "[" << bombs[i][j] << "]";
        std::cout << std::endl;
    }
}