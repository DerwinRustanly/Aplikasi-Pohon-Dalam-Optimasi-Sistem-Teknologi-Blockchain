#include "sha256.h"
#ifndef TREE_H
#define TREE_H

typedef BYTE* data;
typedef data* ListData;

typedef struct treeNode* TAddress;
typedef struct treeNode { 
    data info;
    BYTE hash[32];
    TAddress left;
    TAddress right;
} TreeNode;

#define INFO(p) (p)->info
#define HASH(p) (p)->hash
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef TAddress MTree;
void hash(data string, BYTE hash[32]);
void printHash(BYTE hash[32]);

TAddress createMNode(data string);
void buildMTree(ListData list, int start, int end, MTree *p);
void printPostOrder(MTree p);
#endif