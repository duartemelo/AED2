

#pragma region Parts

extern PartsList *new_parts_list();
extern Part *new_part();
extern void add_part(PartsList *list, Part *item);
extern void change_part_data(Part *part, char *part_num, char *name, char *part_class, int stock);
extern void print_part_data(Part *part);
extern void print_part_list(PartsList *parts);
extern void change_stock(Part *part, int newStock);
extern int total_stock(PartsList *parts);
extern void remove_parts_per_class(PartsList *parts, char *part_class);

#pragma endregion

#pragma region PartsSets

extern PartsSetList *new_parts_sets_list();
extern PartsSet *new_parts_set();
extern void add_parts_set(PartsSetList *list, PartsSet *item);
extern void change_parts_set_data(PartsSet *partset, char *set_num, int quantity, char *part_num);
extern void print_parts_set_data(PartsSet *partset);
extern void print_partset_list(PartsSetList *partsset);
extern void parts_in_partsset_per_class(PartsSetList *list, PartsList *parts, char *part_class, char *set_num);
extern void parts_to_build_set(PartsSetList *list, PartsList *parts, char *set_num);
extern void parts_quantity_to_build_set(PartsSetList *list, char *set_num);
extern void add_stock_from_partsset(PartsSetList *list, char *set_num, PartsList *parts);

#pragma endregion

#pragma region Sets

extern SetList *new_sets_list();
extern Set *new_set();
extern void add_set(SetList *list, Set *item);
extern void change_set_data(Set *set, char *set_num, char *name, int year, char *theme);
extern void print_set_data(Set *set);
extern void print_set_list(SetList *sets);
extern void organize_setsList_per_year(SetList *sets);
extern void print_sets_per_theme_year(SetList *sets, char *theme);
extern void remove_sets_per_theme(SetList *sets, char *theme);

#pragma endregion
