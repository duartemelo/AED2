/**
 * @file structure.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * @brief 
 * set_num: Identificação do set.
 * name: Nome do set.
 * year: Ano em que o set foi colocado no mercado.
 * theme: Tema do set.
 */
typedef struct _setsQueueList{
    int set_num;
    char *name;
    int year;
    char *theme;
    struct _setsQueue *next, *prev;
} SetsQueueList;

/**
 * @brief Apontadores para início e fim da lista dos sets.
 * 
 */
typedef struct _setsQueue{
    SetsQueueList *first;
    SetsQueueList *last;
} SetsQueue;