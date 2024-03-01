#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {
	    Stack *list;
    while ((list = read_str())->head != NULL) {
        printf("======\n");
        sorted_list(list);
        print_list(list);
        delete_list(list);
	printf("======\n");
    }
    free(list);
    return 0;
}
