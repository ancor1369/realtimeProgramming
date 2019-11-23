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

struct data_structure
{
    int id;
    char message[10];
};
typedef struct data_structure data_struct;

struct node_struct
{
    data_struct data;
    struct node_struct *pNext;
};    
typedef struct node_struct node_t;





void addNode(node_t *pHead, data_struct data);
void linkLists(node_t *pCurrent, node_t *pNext);
node_t* createNode(void);
void printNodes(node_t *pHead);
void deleteNode(node_t * pHead,node_t data);
void insertNode(node_t * pHead, node_t data);
    


