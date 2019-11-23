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
    one.message[10] = (char)"Hello";
    
    data_struct two;
    two.id = 1;
    two.message[10] = (char)"There";
    
    data_struct three;
    three.id = 2;
    three.message[10] = (char)"This is";    

    Head->data = one;
    Head->pNext = Second;
    Second->data = two;
    Second->pNext = Third;
    Third->data = three;   
    
    
    printf("Hello world");
    
    //printNodes(Head);
    
    
    printf(Head->data.id);
    printf(Head->data.message);
    printf("\n");

    
    return (EXIT_SUCCESS);
}

