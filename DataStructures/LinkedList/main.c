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
    data_struct newData;
    newData.id = 0;
    strcpy(newData.message,"Second");
    
    node_t *pHead = createHead(newData);

    data_struct moreData;
    moreData.id = 1;
    strcpy(moreData.message,"Message");
 
    data_struct secodDat;
    secodDat.id = 2;
    strcpy(secodDat.message,"Yeah");
    
    data_struct th;
    th.id = 3;
    strcpy(th.message,"The th");
    
    addNode(pHead,moreData);
    addNode(pHead,secodDat);
    addNode(pHead,th);
    
    printNodes(pHead);
    
    deleteNode(pHead,secodDat);
    
    printNodes(pHead);
    
    //I want to retrieve one of the pointers to 
    //get the information out of it.
    node_t *aPointer = getNode(pHead,moreData);
    strcpy(aPointer->data.message,"Change");   
    
    printNodes(pHead);
 
    return (EXIT_SUCCESS);
}

