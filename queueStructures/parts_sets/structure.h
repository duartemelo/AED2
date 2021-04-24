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
 * set_num: Conjunto ao qual pertence a peça.
 * quantity: Unidades desta peça necessárias para a construção deste set.
 * part_num: Identificação da peça.
 */
typedef struct _partsSetsQueueList{
    int set_num;
    int quantity;
    int part_num;
    struct _partsSetsQueue *next, *prev;
} PartsSetsQueueList;

/**
 * @brief Apontadores para início e fim da lista dos parts sets.
 * 
 */
typedef struct _partsSetsQueue{
    PartsSetsQueueList *first;
    PartsSetsQueueList *last;
} PartsSetsQueue;