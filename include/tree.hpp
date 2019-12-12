/**
 * @file tree.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief Class definitions.
 * @version 0.1
 * @date 2019-12-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>

#define ROWS 10
#define COLUMNS 10

/**
 * @brief The board has ROWS*COLUMNS squares and each square can be in either of the states specified in the enum class.
 * 
 */
enum class square{
    yellow, // Initial position.
    blue, // Possible moves.
    red, // Goal position.
    bomb, // Bomb/Mine position.
    bomb_row, // The row were a bomb/mine is in.
    bomb_column, // The column were a bomb/mine is in.
    white // The rest of the unoccupied boxes.
};

/**
 * @brief 
 * 
 */
class Node{
    public:
        square board[ROWS][COLUMNS];
        Node *top, *left, *right, *bottom;
        int prev_row, prev_col;
};

/**
 * @brief 
 * 
 */
class Tree{
        typedef class Node node;
        typedef node *node_ptr;
        node_ptr root;
        int source[2], destination[2]; // Structure {column,row}.
        int bombs[3][2]; // Structure { {column, row}, {column, row}, {column, row} }.
        node_ptr new_node();
        void create_bombs();
        bool bombs_verification()const;
        void create_root();
    public:
        Tree();
        void create_tree(std::vector<int>);
};

#endif