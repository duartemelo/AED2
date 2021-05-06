#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"

#pragma region Parts

PartsList *new_parts_list()
{
    PartsList *new = (PartsList *)malloc(sizeof(PartsList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

Part add_part(PartsList *list, Part *part){
    //se ainda não existir nenhum elemento na lista
    if(list->first == NULL){
        list->first = part;
        part->next = NULL;
        part->prev = NULL;
    } else {
        Part *partAux = list->first;
        while (partAux->next){
            partAux = partAux->next;
        }
        //neste momento partAux será o ultimo elemento da lista
        part->prev = partAux;
        partAux->next = part;
        list->last = part;
    }
    return *part;
}

#pragma endregion

#pragma region Parts Sets

PartsSetList *new_parts_sets_list()
{
    PartsSetList *new = (PartsSetList *)malloc(sizeof(PartsSetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

#pragma endregion

#pragma region Sets List

SetList *new_sets_list()
{
    SetList *new = (SetList *)malloc(sizeof(SetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

#pragma endregion