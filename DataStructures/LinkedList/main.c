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
    node_t *Head = NULL;
    node_t *Second = NULL;
    node_t *Third = NULL;    
    
    data_struct one;
    one.id = 0;
    strcpy(one.message,"Zero");
    
    data_struct two;
    two.id = 1;
    strcpy(two.message,"One");
    
    data_struct three;
    three.id = 2;
    strcpy(three.message,"Two");
    
    Head = addNode(one);
    Second = addNode(two);
    Third = addNode(three);
    linkLists(Head, Second);
    linkLists(Second,Third);
    
    
    printNodes(Head);
 
    return (EXIT_SUCCESS);
}

