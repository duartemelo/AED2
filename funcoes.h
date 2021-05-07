


#pragma region Parts

extern PartsList *new_parts_list();
extern Part *new_part();
extern void add_part(PartsList *list, Part *item);
extern void change_part_data(Part *part, char *part_num, char *name, char *part_class, int stock);
extern void print_part_data(Part *part);
extern void print_part_list(PartsList *parts);

#pragma endregion

#pragma region PartsSets

extern PartsSetList *new_parts_sets_list();
extern PartsSet *new_parts_set();
extern void add_parts_set(PartsSetList *list, PartsSet *item);
extern void change_parts_set_data(PartsSet *partset, char *set_num, int quantity, char *part_num);
extern void print_parts_set_data(PartsSet *partset);
extern void print_partset_list(PartsSetList *partsset);

#pragma endregion


extern SetList *new_sets_list();