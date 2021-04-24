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
#include "queueStructures/parts/structure.h"

PartsQueue *new_parts_queue()
{
    PartsQueue *new = (PartsQueue *)malloc(sizeof(PartsQueue));
    assert(new);

    new->first = new->last = NULL;
    return new;
}
