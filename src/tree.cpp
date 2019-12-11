#include <iostream>
#include "../include/tree.hpp"

Tree::Tree(){ }

Tree::node_ptr Tree::new_node(){
    node_ptr temp_node = new Node;
    if(temp_node == nullptr){
        std::cout << "Error: Memory Allocation Failed!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return temp_node;
}

