/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __      __     _______        __
 *     /  |    /  |   |  _____|   _  / /
 *     `| |    `| |   | |____    (_)/ /
 *      | |     | |   '_.____''.   / / _
 *     _| |_   _| |_  | \____) |  / / (_)
 *    |_____| |_____|  \______.' /_/
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    Nathan Bird, Brock Hoskins
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
   // 
   // Construct
   //
   BNode() : pParent(nullptr), pLeft(nullptr), pRight(nullptr) {}
   BNode(const T& t) : pParent(nullptr), data(t), pLeft(nullptr), pRight(nullptr) {}
   BNode(T&& t) : pParent(nullptr), data(std::move(t)), pLeft(nullptr), pRight(nullptr) {}

   //
   // Data
   //
   BNode<T>* pLeft;
   BNode<T>* pRight;
   BNode<T>* pParent;
   T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode<T>* p)
{
   if (p == nullptr)
      return 0;
   return size(p->pLeft) + 1 + size(p->pRight);
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, BNode<T>* pAdd)
{
   if (pAdd)
      pAdd->pParent = pNode;
   pNode->pLeft = pAdd;
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight(BNode<T>* pNode, BNode<T>* pAdd)
{
   if (pAdd)
      pAdd->pParent = pNode;
   pNode->pRight = pAdd;
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode<T>* pNode, const T& t)
{
   addLeft(pNode, new BNode<T>(t));
}

template <class T>
inline void addLeft(BNode<T>* pNode, T&& t)
{
   addLeft(pNode, new BNode<T>(std::move(t)));
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight(BNode<T>* pNode, const T& t)
{
   addRight(pNode, new BNode<T>(t));
}

template <class T>
void addRight(BNode<T>* pNode, T&& t)
{
   addRight(pNode, new BNode<T>(std::move(t)));
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode<T>*& pThis)
{
   if (!pThis)
      return;

   clear(pThis->pLeft);
   clear(pThis->pRight);
   delete pThis;
   // Can't just delete pThis because it's a reference which
   //   may still be active in the calling function.
   pThis = nullptr;
}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode<T>*& pLHS, BNode<T>*& pRHS)
{
   std::swap(pLHS, pRHS);
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode<T>* copy(const BNode<T>* pSrc)
{
   if (!pSrc)
      return nullptr;

   BNode<T>* pDest = new BNode<T>(pSrc->data);
   
   pDest->pLeft = copy(pSrc->pLeft);
   if (pDest->pLeft)
      pDest->pLeft->pParent = pDest;
   
   pDest->pRight = copy(pSrc->pRight);
   if (pDest->pRight)
      pDest->pRight->pParent = pDest;

   return pDest;
}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode<T>*& pDest, const BNode<T>* pSrc)
{
   // Case 1: Source is empty.
   if (!pSrc)
   {
      clear(pDest);
      return;
   }

   // Case 2: Destination is empty.
   if (!pDest)
   {
      pDest = copy(pSrc);
      return;
   }

   // Case 3: Both are non-empty.
   if (pSrc && pDest)
   {
      pDest->data = pSrc->data;
      assign(pDest->pLeft, pSrc->pLeft);
      if (pDest->pLeft)
         pDest->pLeft->pParent = pDest;
      
      assign(pDest->pRight, pSrc->pRight);
      if (pDest->pRight)
         pDest->pRight->pParent = pDest;
   }
}