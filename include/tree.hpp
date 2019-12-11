#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>

#define ROW 10
#define COL 10

enum class color{
    white,
    yellow,
    blue,
    red,
    bomb
};

class Node{
    public:
        color board[ROW][COL];
        Node *top, *left, *right, *bottom;
        int prev_row, prev_col;
};

class Tree{
        typedef class Node node;
        typedef node *node_ptr;
        node_ptr root;
        node_ptr new_node();
        
    public:
        Tree();
};

#endif