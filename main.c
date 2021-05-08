/**
 * @file main.c
 * @author Duarte Ribeiro de Melo (a21149@alunos.ipca.pt)
 * @brief Ficheiro principal, que chama funções do ficheiro funcoes.c, do trabalho prático de AED2.
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "funcoes.h"

int main()
{

    PartsList *parts = new_parts_list();
    readParts(parts);
   
    

    PartsSetList *partssetlist = new_parts_sets_list();
    readPartsSets(partssetlist);
    
    SetList *setList = new_sets_list();
    readSets(setList);


    menu(parts, partssetlist, setList);


    free(parts);
    free(partssetlist);
    free(setList);
    


    return 0;
}
