/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "node.h"

node_t * addNode(data_struct data)
{
    //create a new node
    node_t *pHead = createNode();
    pHead->data=data;
}

/*It is in charge to create the memory spaces needed to hold a new node*/
node_t* createNode(void)
{
    //Creates a dinamic space of memory to hold the new node
    node_t* pNew = (node_t*)malloc(sizeof(node_t));
    pNew->pNext = NULL;
    return pNew;
}

void linkLists(node_t *pCurrent, node_t *pNext)
{
    pCurrent->pNext = pNext;
    return;
}

void printNodes(node_t *pHead)
{
    while( pHead->pNext != NULL)
    {
        printf("%d\n",pHead->data.id);
        printf("%s\n",pHead->data.message);          
        pHead = pHead->pNext;               
    }
    if(pHead->pNext == NULL)
    {
        printf("%d\n",pHead->data.id);
        printf("%s\n",pHead->data.message); 
    }
    return;
}


