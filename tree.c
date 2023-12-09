#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sha256.h"
#include "tree.h"

void printHash(BYTE hash[32]){
    for (int i = 0; i < 32; i++)
    {
        printf("%02X", hash[i]);
        if (i < 31)
            printf("-");
    }
    printf("\n");
}

void hash(data string, BYTE hash[32]){
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, string, strlen(string));
    sha256_final(&ctx, hash);
}

TAddress createMNode(data string) {
    TAddress node = (TAddress) malloc(sizeof(TreeNode));
    INFO(node) = string;
    hash(string, HASH(node)); 
    LEFT(node) = NULL;
    RIGHT(node) = NULL;
    return node;
}

void buildMTree(ListData list, int start, int end, MTree *p) {
    if (start == end) {
        *p = createMNode(list[start]);
    } else{  
    int mid = (start + end) / 2;
    TAddress leftNode; TAddress rightNode;
    buildMTree(list, start, mid, &leftNode);
    buildMTree(list, mid + 1, end, &rightNode);
        data concatHash = (data)malloc(64*sizeof(BYTE));
        memcpy(concatHash, HASH(leftNode), 32);
        memcpy(concatHash + 32, HASH(rightNode), 32);
        TAddress parentNode = createMNode(concatHash);
        LEFT(parentNode) = leftNode;
        RIGHT(parentNode) = rightNode;
        *p = parentNode;
        free(concatHash);
    }
}

void printPostOrder(MTree p){
    if(p != NULL){
        if(LEFT(p) == NULL && RIGHT(p) == NULL)
            printf("%s : ", INFO(p));
        printPostOrder(LEFT(p));
        printPostOrder(RIGHT(p));
        printHash(HASH(p));
    }
}