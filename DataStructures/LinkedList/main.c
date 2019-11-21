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
    node_t *pNode = createNode();
    pNode->id=0;    
    pNode->name="b";
    node_t data;
    data.id = 1;
    data.name = "Structure";
    
    addNode(pNode, data);    
    
    printf("Hello world");
    return (EXIT_SUCCESS);
}

