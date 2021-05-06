


#pragma region Parts

extern PartsList *new_parts_list();
extern void add_part(PartsList *list, Part *item);
extern void change_part_data(Part *part, char *part_num, char *name, char *part_class, int stock);
extern void print_part_data(Part *part);
extern void print_part_list(PartsList *parts);

#pragma endregion

#pragma region PartsSets

extern PartsSetList *new_parts_sets_list();
void add_parts_set(PartsSetList *list, PartsSet *item);

#pragma endregion


extern SetList *new_sets_list();