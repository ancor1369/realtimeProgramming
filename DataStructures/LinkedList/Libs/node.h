/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   node.h
 * Author: andres
 *
 * Created on November 20, 2019, 10:47 PM
 */


/*Definition of the functions to be used in the code*/



struct node_struct
{
    int id;
    char name;
    struct node_struct *pNext;
};    
typedef struct node_struct node_t;


void addNode(node_t *pHead, node_t data);
node_t* createNode(void);
void deleteNode(node_t * pHead,node_t data);
void insertNode(node_t * pHead, node_t data);
    


