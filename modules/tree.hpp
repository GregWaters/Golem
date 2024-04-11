#ifndef __TREE_HPP
#define __TREE_HPP

#include <memory>

// For the abstract syntax tree used to calculate constant expressions

// Work (very much) in-progress

template <typename T>
class tree
{
    std::unique_ptr<tree<T>> left;
    std::unique_ptr<tree<T>> right;
    std::unique_ptr<tree<T>> parent;
}

#endif // __TREE_HPP