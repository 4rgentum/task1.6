#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node {
    char letter;
    struct Node *next;
}Node;

typedef struct {
    Node *head;
    Node *tail;
}Stack;

typedef struct {
    Node *begin_word;
    Node *end_word;
}Coordinate;

Stack* read_str(void);
void delete_spaces(Stack *list);
void print_list(Stack *list);
void delete_list(Stack *list);
int words_counter(Stack *list);
void *array_of_words_coordinates(Stack *list, Coordinate **array);
int comparator(const void *val1, const void *val2);
void sorted_list(Stack *list);

#endif
