/**
 * @file functions.c
 * @author Duarte Ribeiro de Melo (a21149@alunos.ipca.pt)
 * @brief Funções relacionadas com a manipulação de dados nas estruturas parts
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queueStructures/sets/structure.h"

SetsQueue *new_sets_queue()
{
    SetsQueue *new = (SetsQueue *)malloc(sizeof(SetsQueue));
    assert(new);

    new->first = new->last = NULL;
    return new;
}






