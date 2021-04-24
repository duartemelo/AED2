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
 * part_num: Identificação da peça.
 * name: Nome da peça.
 * part_class: Classe da peça.
 * Stock: stock da peça existente.
 */
typedef struct _partsQueueList{
    int part_num;
    char *name;
    char *part_class;
    int stock;
    struct _partsQueue *next, *prev;
} PartsQueueList;

/**
 * @brief Apontadores para início e fim da lista das parts.
 * 
 */
typedef struct _partsQueue{
    PartsQueueList *first;
    PartsQueueList *last;
} PartsQueue;