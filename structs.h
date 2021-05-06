/**
 * @brief 
 * part_num: Identificação da peça.
 * name: Nome da peça.
 * part_class: Classe da peça.
 * Stock: stock da peça existente.
 */
typedef struct _part{
    char *part_num;
    char *name;
    char *part_class;
    int stock;
    struct _part *next, *prev;
} Part;

/**
 * @brief Apontadores para início e fim da lista das parts.
 * 
 */
typedef struct _partsList{
    Part *first;
    Part *last;
} PartsList;

/**
 * @brief 
 * set_num: Conjunto ao qual pertence a peça.
 * quantity: Unidades desta peça necessárias para a construção deste set.
 * part_num: Identificação da peça.
 */
typedef struct _partsSet{
    char *set_num;
    int quantity;
    int part_num;
    struct _partsSet *next, *prev;
} PartsSet;

/**
 * @brief Apontadores para início e fim da lista dos parts sets.
 * 
 */
typedef struct _partsSetList{
    PartsSet *first;
    PartsSet *last;
} PartsSetList;

/**
 * @brief 
 * set_num: Identificação do set.
 * name: Nome do set.
 * year: Ano em que o set foi colocado no mercado.
 * theme: Tema do set.
 */
typedef struct _set{
    char *set_num;
    char *name;
    int year;
    char *theme;
    struct _set *next, *prev;
} Set;

/**
 * @brief Apontadores para início e fim da lista dos sets.
 * 
 */
typedef struct _setList{
    Set *first;
    Set *last;
} SetList;