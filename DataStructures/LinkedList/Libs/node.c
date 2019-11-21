/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>

#include "node.h"


void addNode(node_t *pHead, node_t data)
{
    //create a new node
    node_t *pNode = createNode();
    pNode->id = data.id;
    pNode->name = data.name;
    
    node_t *pw; //Working pointer
    pw = pHead; //Assume we have at least one node
    while(pw->pNext != NULL)
    {
        pw=pw->pNext;
    }
    pw->pNext = pNode;
    return;
}

/*It is in charge to create the memory spaces needed to hold a new node*/
node_t* createNode(void)
{
    //Creates a dinamic space of memory to hold the new node
    node_t* pNew = (node_t*)malloc(sizeof(node_t));
    pNew->pNext = NULL;
    return pNew;
}



