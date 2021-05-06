#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"

PartsList *new_parts_list()
{
    PartsList *new = (PartsList *)malloc(sizeof(PartsList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

PartsSetList *new_parts_sets_queue()
{
    PartsSetList *new = (PartsSetList *)malloc(sizeof(PartsSetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}


SetList *new_sets_queue()
{
    SetList *new = (SetList *)malloc(sizeof(SetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}