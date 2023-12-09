#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blockchain.h"

void createBlockchain(Blockchain *B){
    LAST(*B) = NULL; len(*B) = 0 ;
}
boolean isEmpty(Blockchain B){
    return (LAST(B) == NULL);
}

Address newBlock(){
    int n; data temp; ListData list; Address p;
    p = (Address) malloc (sizeof(block));
    if(p != NULL){
        printf("Masukkan banyaknya transaksi yang akan disimpan: ");
        scanf("%d", &n);
        LIST(p) = (ListData) malloc (n*sizeof(data));
        if(LIST(p) != NULL){
            for(int i = 0; i < n; i++){
                temp = (data) malloc (32*sizeof(BYTE));
                printf("Masukkan transaksi ke-"); printf("%d", i+1); printf(": ");
                scanf("%s", temp);
                LIST(p)[i] = temp;
            }
        }
        PREV(p) = NULL;
        NEFF(p) = n;
    }
}

void displayList(ListData list, int n){
    for(int i = 0; i < n; i++){
        printf("%s ", list[i]);
    }
    printf("\n");
}

void insertBlock(Blockchain* B){
    Address p; TAddress t;
    p = newBlock();
    buildMTree(LIST(p), 0, NEFF(p)-1, &t);
    PREV(p) = LAST(*B);
    HASH(p) = (data) malloc (256*sizeof(BYTE));
    if(!isEmpty(*B)){
        data concatHash = (data)malloc(64*sizeof(BYTE));
        memcpy(concatHash, HASH(t), 32);
        memcpy(concatHash + 32, BHASH(PREV(p)), 32);
        hash(concatHash, BHASH(p));
    } else{
        strcpy(BHASH(p), HASH(t));
    }
    LAST(*B) = p;
    len(*B)++;
}

void displayBlockchain(Blockchain B){
    Address p = LAST(B); int n = len(B);
    while(p != NULL){
        printf("Block-%d\n", n);
        printf("Current Hash: "); 
        printHash(BHASH(p));
        if(PREV(p) != NULL){
            printf("Previous Hash: "); 
            printHash(BHASH(PREV(p)));
        }
        printf("\n");
        p = PREV(p); n--;
    }
}


