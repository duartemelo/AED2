#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    printf("PARTS TESTS \n\n\n");

    PartsList *parts = new_parts_list();

    Part *part = new_part();
    change_part_data(part, "123num", "test", "123num", 5);    
    add_part(parts, part);
    

    Part *part2 = new_part();
    change_part_data(part2, "123num123", "testname", "testclass", 3);
    add_part(parts, part2);
    
    print_part_list(parts);

    printf("\n\n\n");
    printf("PARTS SETS TESTS \n\n\n");

    PartsSetList *partssetslist = new_parts_sets_list();
    
    PartsSet *partset = new_parts_set();
    change_parts_set_data(partset, "setnumtest", 3, "partnumtest");
    add_parts_set(partssetslist, partset);

    print_partset_list(partssetslist);



    return 0;
}
