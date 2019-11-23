/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: andres rogelio  cordoba
 *
 * Created on November 20, 2019, 10:43 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Libs/node.h"

/*
 * 
 */
int main(int argc, char** argv) 
{    
    node_t *Head = createNode();
    node_t *Second = createNode();
    node_t *Third = createNode();
    
    
    data_struct one;
    one.id = 0;
    strcpy(one.message,"Zero");
    
    data_struct two;
    two.id = 1;
    strcpy(two.message,"One");
    
    data_struct three;
    three.id = 2;
    strcpy(three.message,"Two");

    Head->data = one;
    Head->pNext = Second;
    Second->data = two;
    Second->pNext = Third;
    Third->data = three;   
    
    
    
    
    //printNodes(Head);
    int i = 0;
    
    node_t *pw = Head;
    
    while(i<3)
    {
        i++;
        printf("%d\n",pw->data.id);
        printf("%s\n",pw->data.message);   
        
        pw = pw->pNext;
        if(pw->pNext == NULL)
        {
            i=2;
        }
    }    
    return (EXIT_SUCCESS);
}

