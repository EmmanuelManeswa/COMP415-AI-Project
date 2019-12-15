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
    white, // The rest of the unoccupied boxes.
    /**
     * @brief The following enum list member is used to specify which states/cells/squares we've visited before like its parent,
     * grandparents, great-grandparents and ancestors etc. This is to create a loop-free search tree.
     * 
     */
    visited_square
};

/**
 * @brief 
 * 
 */
class Node{
    public:
        square board[ROWS][COLUMNS];
        Node *top, *left, *right, *bottom;
        int prev_row, prev_col, current_row, current_column;
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
        bool if_top(node_ptr, int, int)const;
        bool if_left(node_ptr, int, int)const;
        bool if_right(node_ptr, int, int)const;
        bool if_bottom(node_ptr, int, int)const;
        bool is_goal(node_ptr)const;
        int possible_top_move(node_ptr, int, int)const;
        int possible_left_move(node_ptr, int, int)const;
        int possible_right_move(node_ptr, int, int)const;
        int possible_bottom_move(node_ptr, int, int)const;
        void create_root();
    public:
        Tree();
        template <typename enum_class>
        auto as_integer(enum_class const value)-> typename std::underlying_type<enum_class>::type;
        void create_tree(std::vector<int>);
};

#endif