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

void change_stock(Part *part, int newStock)
{
    change_part_data(part, part->part_num, part->name, part->part_class, newStock);
}

int total_stock(PartsList *parts)
{
    int stock = 0;
    Part *lst = parts->first;
    while (lst)
    {
        stock = stock + lst->stock;
    }
    return stock;
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

void parts_in_partsset_per_class(PartsSetList *list, PartsList *parts, char *part_class, char *set_num)
{
    PartsSet *lst = list->first;
    Part *part = parts->first;
    while (lst)
    {
        if (strcmp(lst->set_num, set_num) == 0)
        {
            while (part)
            {
                if (strcmp(part->part_class, part_class) == 0)
                {
                    print_part_data(part);
                }
                part = part->next;
            }
        }
        lst = lst->next;
    }
}

void parts_to_build_set(PartsSetList *list, PartsList *parts, char *set_num)
{
    int found;
    PartsSet *lst = list->first;
    while (lst)
    {
        if (strcmp(lst->set_num, set_num) == 0)
        {
            found = 0;
            char *part_num = lst->part_num;
            Part *part = parts->first;
            while (part && found != 0)
            {
                if (strcmp(part->part_num, part_num) == 0)
                {
                    print_part_data(part);
                    found = 1;
                }
                part = part->next;
            }
        }
        lst = lst->next;
    }
}

void parts_quantity_to_build_set(PartsSetList *list, char *set_num)
{
    int totalAmount = 0;
    PartsSet *lst = list->first;
    while (lst)
    {

        if (strcmp(lst->set_num, set_num) == 0)
        {
            printf("%s\n", lst->part_num);
            printf("%d\n", lst->quantity);
            totalAmount += lst->quantity;
        }

        lst->next;
    }
    printf("Total quantity of parts: %d\n", &totalAmount);
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

Set *new_set()
{
    Set *new = (Set *)malloc(sizeof(Set));
    assert(new);
    return new;
}

void add_set(SetList *list, Set *item)
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

void change_set_data(Set *set, char *set_num, char *name, int year, char *theme)
{
    set->set_num = set_num;
    set->name = name;
    set->year = year;
    set->theme = theme;
}

void print_set_data(Set *set)
{
    printf("Set_num: %s\n", set->set_num);
    printf("Set_name: %s\n", set->name);
    printf("Set_year: %d\n", set->year);
    printf("Set_theme: %s\n", set->theme);
}

void print_set_list(SetList *sets)
{
    Set *lst = sets->first;
    while (lst)
    {
        print_set_data(lst);
        lst = lst->next;
    }
}

void organize_setsList_per_year(SetList *sets)
{

    Set *lst = sets->first;
    Set *lst2 = sets->first->next;

    while (lst)
    {
        lst2 = lst->next;
        while (lst2)
        {
            if (lst2->year < lst->year)
            {
                char *set_num = lst->set_num;
                char *name = lst->name;
                int year = lst->year;
                char *theme = lst->theme;
                change_set_data(lst, lst2->set_num, lst2->name, lst2->year, lst2->theme);
                change_set_data(lst2, set_num, name, year, theme);
            }
            lst2 = lst2->next;
        }
        lst = lst->next;
    }
}

void print_sets_per_theme_year(SetList *sets, char *theme)
{
    SetList *organizedSetList = new_sets_list();
    Set *lst = sets->first;
    while (lst)
    {
        if (strcmp(theme, lst->theme) == 0)
        {
            Set *lstCopy = new_set();
            change_set_data(lstCopy, lst->set_num, lst->name, lst->year, lst->theme);
            add_set(organizedSetList, lstCopy);
        }
        lst = lst->next;
    }
    organize_setsList_per_year(organizedSetList);
    print_set_list(organizedSetList);
}

#pragma endregion