#include <stdlib.h>
#include <stdio.h>
#include "node.h"

int main(int argc, char const *argv[])
{
    Node * root;

    root = makeTree(20);
    addno(root, 10);
    addno(root, 30);
    addno(root, 5);
    addno(root, 15);
    addno(root, 25);
    addno(root, 35);
    addno(root, 75);
    addno(root, 45);
    addno(root, 18);
    addno(root, 80);

    //setLeft(root, 6);
    //setRight(root, 5);
    //setLeft(left(root), 4);
    //setRight(left(root), 3);
    //setLeft(right(root), 2);
    //setRight(right(root), 1);

    printf("Não folhas = %d\n", nodeCount(root)); // Quest 1
    printf("Folhas = %d\n", leafCount(root)); // Quest 2
    printf("profundidade = %d\n", getDepth(root)); // Quest 3
    printf("is binary search ? = %d\n", isBinarySearchTree(root)); // Quest 4
    printf("Pre order\n");
    //Quest 5
    preOrder(root);
    printf("\nIn Order\n");
    inOrder(root);
    printf("\nPost order\n");
    postOrder(root);
    // Fim Quest 5
    printf("\nisHeap ? %d\n", isHeap(root)); //Quest 6

    return 0;
}
