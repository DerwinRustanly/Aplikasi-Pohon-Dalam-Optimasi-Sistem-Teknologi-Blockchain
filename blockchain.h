#include "sha256.h"
#include "boolean.h"
#include "tree.h"
#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H


typedef struct block* Address;
typedef struct block {
    ListData list;
    int NEff;
    data hash;
    Address prev;
} block;

#define LIST(p) (p)->list
#define NEFF(p) (p)->NEff
#define BHASH(p) (p)->hash
#define PREV(p) (p)->prev

typedef struct Blockchain{
    Address last;
    int length;
} Blockchain;

#define LAST(p) (p).last
#define len(p) (p).length

void createBlockchain(Blockchain *B);
boolean isEmpty(Blockchain B);
Address newBlock();
void insertBlock(Blockchain* B);
void displayList(ListData list, int n);
void displayBlockchain(Blockchain B);
#endif