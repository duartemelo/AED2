#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "funcoes.h"

int main()
{
    PartsList *parts = new_parts_list();

    Part *part = malloc(sizeof(Part));
    part->name = "test";
    part->part_num = "123num";
    part->stock = 5;
    add_part(parts, part);
    

    Part *part2 = malloc(sizeof(Part));
    part2->name = "test2";
    add_part(parts, part2);
    change_part_data(part2, part2->part_num, "test3", part2->part_class, part2->stock);
    
    print_part_list(parts);



    return 0;
}
