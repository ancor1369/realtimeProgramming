/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include "node.h"

void addNode(node_t* pHead, data_struct data)
{
    //Create new node
    node_t *pNode = createNode();
    pNode->data = data;
    
    //Find the attatchement point for the new node
    //to be inserted
    
    node_t *pw; //working pointer
    pw = pHead;    
    while(pw->pNext != NULL)
    {
        pw = pw->pNext;
    }    
    pw->pNext = pNode;
    return;
}

node_t* createHead(data_struct data)
{
    //creates the head of the whole
    node_t *pHead = createNode();
    pHead->data=data;
}

node_t* createNode(void)
{
    //Creates a dinamic space of memory to hold the new node
    node_t* pNew = (node_t*)malloc(sizeof(node_t));
    pNew->pNext = NULL;
    return pNew;
}

void deleteNode(node_t* pHead, data_struct target)
{
    node_t* pw= pHead; //Working pointer
    node_t* ppw=pHead; //Working parent's pointer
    
    while((pw->data.id != target.id))
    {
        ppw=pw;
        pw=pw->pNext;
    }    
    if((pw->pNext)!= NULL)    
    {
        node_t *pSave = pw->pNext;
        free((void*)pw);
        ppw->pNext = pSave;
    }
    else
    {
        printf("Node not found");
    }
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

node_t* getNode(node_t* pHead, data_struct target)
{
    node_t* pw; //Worker pointer
    pw = pHead;
    
    while(pw->data.id != target.id)
    {
        pw = pHead->pNext;
    }
    //Making sure the selected target is the one we are seeking
    if(pw->data.id == target.id)       
    {
        return pw;
    }
    //It it is not, just return a null pointer.
    else
    {
        return NULL;
    }
}


