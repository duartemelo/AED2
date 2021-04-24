/**
 * @file functions.h
 * @author Duarte Ribeiro de Melo (a21149@alunos.ipca.pt)
 * @brief Assinaturas das funções relacionadas com a manipulação de dados nas estruturas
 * @version 0.1
 * @date 2021-04-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "./queueStructures/parts/structure.h"
#include "./queueStructures/sets/structure.h"
#include "./queueStructures/parts_sets/structure.h"

extern PartsQueue *new_parts_queue();
extern SetsQueue *new_sets_queue();
extern PartsSetsQueue *new_parts_sets_queue();
