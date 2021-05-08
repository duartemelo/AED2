/**
 * @file funcoes.c
 * @author Duarte Ribeiro de Melo (a21149@alunos.ipca.pt)
 * @brief Funções relativas ao trabalho prático de AED2
 * @version 0.1
 * @date 2021-05-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include "structs.h"

#pragma region Parts

/**
 * @brief Criação de uma lista de parts.
 * 
 * @return PartsList* 
 */
PartsList *new_parts_list()
{
    PartsList *new = (PartsList *)malloc(sizeof(PartsList));
    assert(new);
    new->first = new->last = NULL;
    return new;
}

/**
 * @brief Criação de um nodo "Part"
 * 
 * @return Part* 
 */
Part *new_part()
{
    Part *new = (Part *)malloc(sizeof(Part));
    assert(new);
    new->stock = 0;
    return new;
}

/**
 * @brief Adicionar uma part a uma lista PartsList
 * 
 * @param list 
 * @param item 
 */
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

/**
 * @brief Alterar os dados de uma part
 * 
 * @param part 
 * @param part_num 
 * @param name 
 * @param part_class 
 * @param stock 
 */
void change_part_data(Part *part, char *part_num, char *name, char *part_class, int stock)
{
    part->part_num = part_num;
    part->name = name;
    part->part_class = part_class;
    part->stock = stock;
}

/**
 * @brief Imprimir os dados de uma part
 * 
 * @param part 
 */
void print_part_data(Part *part)
{
    printf("Part_num: %s\nPart_name: %s\nPart_class: %s\nPart_stock: %d\n", part->part_num, part->name, part->part_class, part->stock);
}

/**
 * @brief Imprimir uma lista de parts, reutiliza função print_part_data
 * 
 * @param parts 
 */
void print_part_list(PartsList *parts)
{
    Part *lst = parts->first;
    while (lst)
    {
        print_part_data(lst);
        printf("\n");
        lst = lst->next;
    }
}

/**
 * @brief Alterar o stock de uma part, reutiliza função change_part_data
 * 
 * @param part 
 * @param newStock 
 */
void change_stock(Part *part, int newStock)
{
    change_part_data(part, part->part_num, part->name, part->part_class, newStock);
}

Part *find_part_in_list(char *part_num, PartsList *parts)
{
    Part *lst = parts->first;
    int find = 0;
    while (lst || find != 0)
    {
        if (strcmp(lst->part_num, part_num) == 0)
        {
            return lst;
        }
        lst = lst->next;
    }
    return NULL;
}

/**
 * @brief Devolve o stock total
 * 
 * @param parts 
 * @return int 
 */
int total_stock(PartsList *parts)
{
    int stock = 0;
    Part *lst = parts->first;
    while (lst)
    {
        stock = stock + lst->stock;
        lst = lst->next;
    }
    return stock;
}

/**
 * @brief Remove parts a partir da classe, alteração dos apontadores e free do nodo
 * 
 * @param parts 
 * @param part_class 
 */
void remove_parts_per_class(PartsList *parts, char *part_class)
{

    Part *part = malloc(sizeof(Part));

    for (part = parts->first; part; part = part->next)
    {
        if (strcmp(part->part_class, part_class) == 0)
        {
            if (part->next)
            {
                part->next->prev = part->prev;
            }
            else
            {
                parts->last = part->prev;
            }
            if (part->prev)
            {
                part->prev->next = part->next;
            }
            else
            {
                parts->first = part->next;
            }
            free(part);
        }
    }
}

/**
 * @brief Peça mais usada nos partssets, devolve a mesma
 * 
 * @param parts 
 * @param partssetslist 
 * @return Part 
 */
Part *most_used_part(PartsList *parts, PartsSetList *partssetslist)
{
    Part *part = malloc(sizeof(Part));
    PartsSet *partset = malloc(sizeof(PartsSet));
    int contadorMaisUsada = 0;
    int contadorCompara;
    Part *partMaisUsada = malloc(sizeof(Part));
    for (part = parts->first; part; part = part->next)
    {
        contadorCompara = 0;
        for (partset = partssetslist->first; partset; partset = partset->next)
        {
            if (strcmp(partset->part_num, part->part_num) == 0)
            {
                contadorCompara++;
            }
        }
        if (contadorCompara > contadorMaisUsada)
        {
            contadorMaisUsada = contadorCompara;

            change_part_data(partMaisUsada, part->part_num, part->name, part->part_class, part->stock);
        }
    }
    return partMaisUsada;
}

#pragma endregion

#pragma region Parts Sets

/**
 * @brief Nova lista de partsSets
 * 
 * @return PartsSetList* 
 */
PartsSetList *new_parts_sets_list()
{
    PartsSetList *new = (PartsSetList *)malloc(sizeof(PartsSetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

/**
 * @brief Novo nodo parts_set
 * 
 * @return PartsSet* 
 */
PartsSet *new_parts_set()
{
    PartsSet *new = (PartsSet *)malloc(sizeof(PartsSet));
    assert(new);
    return new;
}

/**
 * @brief Alterar data dum part_set
 * 
 * @param partset 
 * @param set_num 
 * @param quantity 
 * @param part_num 
 */
void change_parts_set_data(PartsSet *partset, char *set_num, int quantity, char *part_num)
{
    partset->set_num = set_num;
    partset->quantity = quantity;
    partset->part_num = part_num;
}

/**
 * @brief Adicionar nodo parts_set à lista partsSetList
 * 
 * @param list 
 * @param item 
 */
void add_parts_set(PartsSetList *list, PartsSet *item)
{
    PartsSet *new = malloc(sizeof(PartsSet));
    change_parts_set_data(new, item->set_num, item->quantity, item->part_num);
    //se ainda não existir nenhum elemento na lista
    if (list->first == NULL)
    {
        list->first = new;
        new->next = NULL;
        new->prev = NULL;
    }
    else
    {
        list->last->next = new;
        new->prev = list->last;
        new->next = NULL;
    }
    list->last = new;
}

/**
 * @brief Imprimir dados de um part_set
 * 
 * @param partset 
 */
void print_parts_set_data(PartsSet *partset)
{
    printf("Set_num: %s\nQuantity: %d\nPart_num:%s\n", partset->set_num, partset->quantity, partset->part_num);
}
/**
 * @brief Imprimir lista parts_set, reutiliza função print_parts_set_data
 * 
 * @param partsset 
 */
void print_partset_list(PartsSetList *partsset)
{
    PartsSet *lst = partsset->first;
    while (lst)
    {
        print_parts_set_data(lst);
        printf("\n");
        lst = lst->next;
    }
}

/**
 * @brief Imprime as parts num partset que correspondem a uma determinada classe
 * 
 * @param list 
 * @param parts 
 * @param part_class 
 * @param set_num 
 */
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

/**
 * @brief Imprime as partes necessárias para construir um set (conjunto)
 * 
 * @param list 
 * @param parts 
 * @param set_num 
 */
void parts_to_build_set(PartsSetList *list, PartsList *parts, char *set_num)
{

    PartsSet *lst = list->first;
    while (lst)
    {
        if (strcmp(lst->set_num, set_num) == 0)
        {

            Part *part = parts->first;
            while (part)
            {
                if (strcmp(part->part_num, lst->part_num) == 0)
                {
                    print_part_data(part);
                }
                part = part->next;
            }
        }
        lst = lst->next;
    }
}

/**
 * @brief Imprime as quantidades de peças para construir um set
 * 
 * @param list 
 * @param set_num 
 */
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

        lst = lst->next;
    }
    printf("Total quantity of parts: %d\n", totalAmount);
}

/**
 * @brief Adicionar stock de peças a partir de um partset
 * 
 * @param list 
 * @param set_num 
 * @param parts 
 */
void add_stock_from_partsset(PartsSetList *list, char *set_num, PartsList *parts)
{
    PartsSet *lst = list->first;
    while (lst)
    {
        if (strcmp(lst->set_num, set_num) == 0)
        {
            char *part_num = lst->part_num;
            Part *part = parts->first;
            while (part)
            {
                if (strcmp(part->part_num, part_num) == 0)
                {
                    part->stock = part->stock + lst->quantity;
                }
                part = part->next;
            }
        }
        lst = lst->next;
    }
}

#pragma endregion

#pragma region Sets List

/**
 * @brief Nova lista de sets
 * 
 * @return SetList* 
 */
SetList *new_sets_list()
{
    SetList *new = (SetList *)malloc(sizeof(SetList));
    assert(new);

    new->first = new->last = NULL;
    return new;
}

/**
 * @brief Novo nodo set
 * 
 * @return Set* 
 */
Set *new_set()
{
    Set *new = (Set *)malloc(sizeof(Set));
    assert(new);
    return new;
}

/**
 * @brief Adicionar nodo set à lista SetList
 * 
 * @param list 
 * @param item 
 */
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

/**
 * @brief Alterar dados de um set
 * 
 * @param set 
 * @param set_num 
 * @param name 
 * @param year 
 * @param theme 
 */
void change_set_data(Set *set, char *set_num, char *name, int year, char *theme)
{
    set->set_num = set_num;
    set->name = name;
    set->year = year;
    set->theme = theme;
}

/**
 * @brief Imprimir dados de um set
 * 
 * @param set 
 */
void print_set_data(Set *set)
{
    printf("Set_num: %s\nSet_name: %s\nSet_year: %d\nSet_theme: %s\n", set->set_num, set->name, set->year, set->theme);
}

/**
 * @brief Imprimir dados da lista SetList, reutiliza função print_set_data
 * 
 * @param sets 
 */
void print_set_list(SetList *sets)
{
    Set *lst = sets->first;
    while (lst)
    {
        print_set_data(lst);
        lst = lst->next;
    }
}

/**
 * @brief Organiza setList pelo ano, apontadores mantêm-se, alteram os dados
 * (na altura, alterar os apontadores deu-me problemas então optei por esta forma, considero esta abordagem menos boa (caso mude a struct dos sets, terei de mudar a função também))
 * 
 * @param sets 
 */
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

/**
 * @brief Print sets de um determinado tema pelo ano, utiliza funções organize_setsList_per_year e print_set_list
 * 
 * @param sets 
 * @param theme 
 */
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

/**
 * @brief Remove sets de um determinado tema
 * 
 * @param sets 
 * @param theme 
 */
void remove_sets_per_theme(SetList *sets, char *theme)
{
    Set *set = malloc(sizeof(Set));

    for (set = sets->first; set; set = set->next)
    {
        if (strcmp(set->theme, theme) == 0)
        {
            if (set->next)
            {
                set->next->prev = set->prev;
            }
            else
            {
                sets->last = set->prev;
            }
            if (set->prev)
            {
                set->prev->next = set->next;
            }
            else
            {
                sets->first = set->next;
            }
            free(set);
        }
    }
}

#pragma endregion

#pragma region Data Reading

/**
 * @brief Procedimento para ler o ficheiro parts e passar os dados para a lista correspondente
 * 
 * @param list 
 */
void readParts(PartsList *list)
{
    FILE *partsFile = fopen("data/parts.tsv", "r");

    char readingBuffer[60];
    //int contador = 0;

    fscanf(partsFile, "%[^\n]", readingBuffer);
    while (!feof(partsFile))
    {
        //printf("%d\n", contador);
        //contador++;
        Part *aux = new_part();

        char *part_num = malloc(300);
        char *name = malloc(300);
        char *part_class = malloc(300);
        int stock;

        fscanf(partsFile, "\n%[^\t]\t%[^\t]\t%[^\t]\t%d", part_num, name, part_class, &stock);
        change_part_data(aux, part_num, name, part_class, stock);
        add_part(list, aux);
    }
}

/**
 * @brief Procedimento para ler o ficheiro parts_sets e passar os dados para a lista correspondente
 * 
 * @param list 
 */
void readPartsSets(PartsSetList *list)
{
    FILE *partsSetsFile = fopen("data/parts_sets.tsv", "r");

    char readingBuffer[60];
    //int contador = 0;

    fscanf(partsSetsFile, "%[^\n]", readingBuffer);

    while (!feof(partsSetsFile))
    {
        //printf("%d\n", contador);
        //contador++;
        PartsSet *aux = new_parts_set();
        char *set_num = malloc(300);
        int quantity;
        char *part_num = malloc(300);
        fscanf(partsSetsFile, "\n%[^\t]\t%d\t%[^\n]", set_num, &quantity, part_num);
        change_parts_set_data(aux, set_num, quantity, part_num);
        add_parts_set(list, aux);
    }
}

/**
 * @brief Procedimento para ler o ficheiro sets e passar os dados para a lista correspondente
 * 
 * @param list 
 */
void readSets(SetList *list)
{
    FILE *setsFile = fopen("data/sets.tsv", "r");

    char readingBuffer[60];
    //int contador = 0;
    fscanf(setsFile, "%[^\n]", readingBuffer);
    while (!feof(setsFile))
    {
        //printf("%d\n", contador);
        //contador++;
        Set *aux = new_set();
        char *set_num = malloc(300);
        char *name = malloc(300);
        int year;
        char *theme = malloc(300);

        fscanf(setsFile, "\n%[^\t]\t%[^\t]\t%d\t%[^\n]", set_num, name, &year, theme);
        change_set_data(aux, set_num, name, year, theme);
        add_set(list, aux);
    }
}

#pragma endregion

#pragma region Menu

void textoMenu()
{
    system("cls");
    printf("Escreva a sua opcao: \n1 - Conjuntos de determinado tema (ord por ano).\n2 - Pecas de determinado tipo em determinado conjunto\n3 - Pecas necessárias para construir um conjunto\n4 - Total pecas em stock\n5 - Total de pecas num conjunto\n6 - Peca utilizada em mais conjuntos diferentes\n7 - Alterar num de pecas em stock\n8 - Adicao de stock pelo identificador do conjunto\n9 - Remover todas as pecas de uma classe\n10 - Remover todos os sets de um tema\n0 - Sair\n");
}

void menu(PartsList *partsList, PartsSetList *partsSetList, SetList *setList)
{
    int opcao;
    textoMenu();
    scanf("%d", &opcao);
    getchar();
    printf("\n");
    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            printf("Theme: ");
            char *input = malloc(150);

            fgets(input, 150, stdin);
            input[strlen(input) - 1] = '\0';
            printf("\n");
            print_sets_per_theme_year(setList, input);
            free(input);
            break;
        case 2:
            printf("Part class: ");
            char *input2 = malloc(150);
            fgets(input2, 150, stdin);
            input2[strlen(input2) - 1] = '\0';
            printf("\n");

            printf("Set_num: ");
            char *input3 = malloc(150);
            fgets(input3, 150, stdin);
            input3[strlen(input3) - 1] = '\0';
            printf("\n");

            parts_in_partsset_per_class(partsSetList, partsList, input2, input3);
            free(input2);
            free(input3);
            break;
        case 3:
            printf("Set num: ");
            char *set_num = malloc(150);
            fgets(set_num, 150, stdin);
            set_num[strlen(set_num) - 1] = '\0';
            printf("\n");
            parts_to_build_set(partsSetList, partsList, set_num);
            free(set_num);
            break;
        case 4:
            printf("Stock total: %d\n", total_stock(partsList));
            break;
        case 5:
            printf("Set num: ");
            fgets(set_num, 150, stdin);
            set_num[strlen(set_num) - 1] = '\0';
            printf("\n");
            parts_quantity_to_build_set(partsSetList, set_num);
            free(set_num);
            break;
        case 6:
            print_part_data(most_used_part(partsList, partsSetList));
            break;
        case 7:
            printf("Part num: ");
            char *part_num = malloc(150);
            fgets(part_num, 150, stdin);
            part_num[strlen(part_num) - 1] = '\0';
            printf("\n");
            printf("New stock: ");
            int newStock;
            scanf("%d", &newStock);
            change_stock(find_part_in_list(part_num, partsList), newStock);
            free(part_num);
            break;
        case 8:
            printf("Set_num: ");
            fgets(set_num, 150, stdin);
            set_num[strlen(set_num) - 1] = '\0';
            printf("\n");
            add_stock_from_partsset(partsSetList, set_num, partsList);
            break;
        case 9:
            printf("Part class: ");
            char *part_class = malloc(150);
            fgets(part_class, 150, stdin);
            part_class[strlen(part_class) - 1] = '\0';
            printf("\n");
            remove_parts_per_class(partsList, part_class);
            free(part_class);
            break;
        case 10:
            printf("Theme: ");
            char *set_theme = malloc(150);
            fgets(set_theme, 150, stdin);
            set_theme[strlen(set_theme) - 1] = '\0';
            printf("\n");
            remove_sets_per_theme(setList, set_theme);
            free(set_theme);
            break;
        }
        
        

        sleep(5);
        textoMenu();
        scanf("%d", &opcao);
        getchar();
        printf("\n");
    }
}

#pragma endregion