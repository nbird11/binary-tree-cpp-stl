# C++ Binary Tree Node Implementation

This project implements a binary tree node structure in C++. This implementation serves as the foundation for next week's Binary Search Tree implementation, providing the basic building blocks for tree-based data structures.

## Overview

The custom binary tree node is implemented through a BNode class template that supports a tree structure. Key features include:

- Template-based implementation supporting any data type
- Binary tree structure with left and right child pointers
- Parent pointer for upward traversal
- Memory-efficient node management
- Support for both copy and move semantics
- Comprehensive node manipulation utilities

## Class Structure

### `BNode<T>`
The main node class template with one parameter:
- T: Type of element stored in the node

Key attributes:
- `data`: The stored element
- `pLeft`: Pointer to the left child node
- `pRight`: Pointer to the right child node
- `pParent`: Pointer to the parent node

## Node Operations

The implementation includes several utility functions:

### Core Operations
- `addLeft()`: Add a node as the left child
- `addRight()`: Add a node as the right child
- `clear()`: Delete all nodes in a tree
- `swap()`: Exchange two trees
- `size()`: Count nodes in a tree
- `copy()`: Deep copy a tree
- `assign()`: Copy values while reusing existing nodes

### Memory Management
- Efficient node reuse in assignment operations
- Proper cleanup of unused nodes
- Prevention of memory leaks

## Usage Example

```cpp
#include "bnode.h"

// Create nodes with integers
BNode<int>* root = new BNode<int>(1);
addLeft(root, new BNode<int>(2));   // Add left child
addRight(root, new BNode<int>(3));  // Add right child

// Copy a tree
BNode<int>* newTree = copy(root);

// Clean up
clear(root);
clear(newTree);
```

## Testing

The implementation includes comprehensive unit tests in `testBNode.h` that verify:
- Node creation and deletion
- Left and right child operations
- Copy and assignment operations
- Memory management
- Edge cases

## Files

- `bnode.h`: Main binary node implementation with utility functions
- `testBNode.h`: Unit tests
- `testBNode.cpp`: Test driver
- `unitTest.h`: Unit testing framework

## Building

The project includes Visual Studio solution files for building on Windows. Open `LabBinaryTree.sln` and build using Visual Studio 2019 or later.

## Notes

- This is an educational implementation focused on demonstrating binary tree concepts
- The implementation provides a foundation for more complex tree structures like BST
- Special attention is paid to memory management and edge cases
- The node structure supports both downward and upward traversal through parent pointers

## License

This code is provided for educational purposes. See included license file for terms of use. [TODO: add LICENSE]

## Authors

Nathan Bird  
[nathanbirdka@gmail.com](mailto:nathanbirdka@gmail.com)

Brock Hoskins  
[]()