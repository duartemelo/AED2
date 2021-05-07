#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    //printf("PARTS TESTS \n\n\n");

    PartsList *parts = new_parts_list();

    Part *part = new_part();
    change_part_data(part, "123num", "test", "123num", 5);    
    add_part(parts, part);
    change_stock(part, part->stock+5);
    

    Part *part2 = new_part();
    change_part_data(part2, "123num123", "testname", "testclass", 3);
    add_part(parts, part2);
    
    print_part_list(parts);

    printf("\n\n\n");

    remove_parts_per_class(parts, "testclass");
    
    print_part_list(parts);
    

    //printf("PARTS SETS TESTS \n\n\n");

    PartsSetList *partssetslist = new_parts_sets_list();
    
    PartsSet *partset = new_parts_set();
    change_parts_set_data(partset, "setnumtest", 3, "partnumtest");
    add_parts_set(partssetslist, partset);

    //print_partset_list(partssetslist);

    //printf("\n\n\n");
    //printf("SETS TESTS \n\n\n");

    SetList *setList = new_sets_list();
    Set *set1 = new_set();
    change_set_data(set1, "setnumtest1", "name1", 2004, "theme1");
    add_set(setList, set1);

    Set *set2 = new_set();
    change_set_data(set2, "setnumtest2", "name2", 2000, "theme1");
    add_set(setList, set2);

    Set *set3 = new_set();
    change_set_data(set3, "setnumtest3", "name3", 2000, "theme1");
    add_set(setList, set3);

    Set *set4 = new_set();
    change_set_data(set4, "setnumtest4", "name4", 2003, "theme1");
    add_set(setList, set4);

    Set *set5 = new_set();
    change_set_data(set5, "setnumtest4", "name4", 2003, "theme1");
    add_set(setList, set5);

    Set *set6 = new_set();
    change_set_data(set6, "setnumtest4", "name4", 1900, "theme1");
    add_set(setList, set6);

    //print_sets_per_theme_year(setList, "theme1");



    return 0;
}
