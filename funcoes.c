#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "structs.h"

#pragma region Parts

PartsList *new_parts_list()
{
    PartsList *new = (PartsList *)malloc(sizeof(PartsList));
    assert(new);
    new->first = new->last = NULL;
    return new;
}

Part *new_part()
{
    Part *new = (Part *)malloc(sizeof(Part));
    assert(new);
    return new;
}

void add_part(PartsList *list, Part *item)
{

    //se ainda não existir nenhum elemento na lista
    if (list->first == NULL)
    {
        list->first = item;
        item->next = NULL;
        item->prev = NULL;
    }
    else
    {
        list->last->next = item;
        item->prev = list->last;
        item->next = NULL;
    }
    list->last = item;
}

void change_part_data(Part *part, char *part_num, char *name, char *part_class, int stock)
{
    part->part_num = part_num;
    part->name = name;
    part->part_class = part_class;
    part->stock = stock;
}

void print_part_data(Part *part)
{
    printf("Part_num: %s\n", part->part_num);
    printf("Part_name: %s\n", part->name);
    printf("Part_class: %s\n", part->part_class);
    printf("Part_stock: %d\n", part->stock);
}

void print_part_list(PartsList *parts)
{
    Part *lst = parts->first;
    while (lst)
    {
        print_part_data(lst);
        lst = lst->next;
    }
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

PartsSet *new_parts_set()
{
    PartsSet *new = (PartsSet *)malloc(sizeof(PartsSet));
    assert(new);
    return new;
}

void add_parts_set(PartsSetList *list, PartsSet *item)
{
    //se ainda não existir nenhum elemento na lista
    if (list->first == NULL)
    {
        list->first = item;
        item->next = NULL;
        item->prev = NULL;
    }
    else
    {
        list->last->next = item;
        item->prev = list->last;
        item->next = NULL;
    }
    list->last = item;
}

void change_parts_set_data(PartsSet *partset, char *set_num, int quantity, char *part_num)
{
    partset->set_num = set_num;
    partset->quantity = quantity;
    partset->part_num = part_num;
}

void print_parts_set_data(PartsSet *partset)
{
    printf("Set_num: %s\n", partset->set_num);
    printf("Quantity: %d\n", partset->quantity);
    printf("Part_num: %s\n", partset->part_num);
}

void print_partset_list(PartsSetList *partsset)
{
    PartsSet *lst = partsset->first;
    while (lst)
    {
        print_parts_set_data(lst);
        lst = lst->next;
    }
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