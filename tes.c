#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include "blockchain.h"
#include "tree.h"

int main(){
    Blockchain B;
    createBlockchain(&B);
    insertBlock(&B);
    // printHash(BHASH(B));
    // displayList(LIST(B), NEFF(B));
    insertBlock(&B);
    // insertBlock(B);
    displayBlockchain(B);
}