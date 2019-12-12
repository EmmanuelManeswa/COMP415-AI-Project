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
 * @brief 
 * 
 */
enum class color{
    white,
    yellow,
    blue,
    red,
    bomb
};

/**
 * @brief 
 * 
 */
class Node{
    public:
        color board[ROWS][COLUMNS];
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
        int source[2], destination[2];
        int bombs[3][2];
        node_ptr new_node();
        void create_bombs();
    public:
        Tree();
        void create_tree(std::vector<int>);
};

#endif