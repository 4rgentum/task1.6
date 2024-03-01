#include <stdio.h>
#include <stdlib.h>

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

Stack* read_str(void) {
    Stack *list = (Stack *) calloc(1, sizeof(Stack));
    list->head = list->tail = NULL;
    char input_element = 0;
    while ((input_element = getchar()) != EOF) {
	if (input_element == '\n') {
		return list;
	}
        Node *node = (Node *) calloc(1, sizeof(Node));
        node->letter = input_element;
	node->next = NULL;
        if (list->head == NULL) {
            list->head = node;
            list->tail = node;
        } else {
            list->tail->next = node;
            list->tail = node;
        }
    }
    free(list);
    return NULL;
}

void delete_spaces(Stack *list) {
	Node **tmp = &list->head;
	while (*tmp) {
		if ((*tmp)->letter == '\t') {
			(*tmp)->letter = ' ';
		}
		if ((*tmp)->letter == ' ' && ((*tmp) == list->head || (*tmp)->next == NULL || (*tmp)->next->letter == ' ' || (*tmp)->next->letter == '\t')) {
			Node *p = *tmp;
			*tmp = (*tmp)->next;
			free(p);
		} else {
			tmp = &(*tmp)->next;
		}
	}
}

void print_list(Stack *list) {
    Node *temporary_node = list->head;
    printf("\"");
    while (temporary_node != NULL) {
        printf("%c", temporary_node->letter);
        temporary_node = temporary_node->next;
    }
    printf("\"\n");
}

void delete_list(Stack *list) {
    Node *temporary_node = list->head;
    while (temporary_node != NULL) {
        Node *pointer_previous = temporary_node;
        temporary_node = temporary_node->next;
        free(pointer_previous);
    }
    free(temporary_node);
    free(list);
}

int words_counter(Stack *list) {
    Node *temporary_list_node = list->head;
    Node *temporary_word_node = NULL;
    int words_counter = 0;
    while (temporary_list_node != NULL) {
        if (temporary_list_node->letter != ' ' && temporary_list_node->letter != '\t' && temporary_list_node->next != NULL) {
            temporary_word_node = temporary_list_node;
            while ((temporary_word_node->letter != ' ' && temporary_word_node->letter != '\t') && temporary_word_node->next != NULL) {
                temporary_word_node = temporary_word_node->next;
            }
            words_counter++;
            temporary_list_node = temporary_word_node;
        } else if (temporary_list_node->letter != ' ' && temporary_list_node->letter != '\t' && temporary_list_node->next == NULL) {
            words_counter++;
        }
        temporary_list_node = temporary_list_node->next;
    }
    free(temporary_list_node);
    return  words_counter;
}

void *array_of_words_coordinates(Stack *list, Coordinate **array) {
    Node *temporary_list_node = list->head;
    Node *temporary_word_node = NULL;
    Node *previous_word_node = NULL;
    int index = 0;
    while (temporary_list_node != NULL) {
        if (temporary_list_node->letter != ' ' && temporary_list_node->letter != '\t' && temporary_list_node->next != NULL) {
            temporary_word_node = temporary_list_node;
            (*array)[index].begin_word = temporary_list_node;
            while (temporary_word_node->letter != ' ' && temporary_word_node->letter != '\t' && temporary_word_node->next != NULL) {
                previous_word_node = temporary_word_node;
                temporary_word_node = temporary_word_node->next;
            }
	    temporary_list_node = temporary_word_node;
	    if (temporary_list_node->letter == ' ' || temporary_list_node->letter == '\t') {
                (*array)[index].end_word = previous_word_node;
            } else if (temporary_list_node->letter != ' ' && temporary_list_node->letter != '\t') {
                (*array)[index].end_word = temporary_list_node;
            }
            index++;
        } else if (temporary_list_node->letter != ' ' && temporary_list_node->letter != '\t' && temporary_list_node->next == NULL) {
            (*array)[index].begin_word = temporary_list_node;
            (*array)[index].end_word = temporary_list_node;
            index++;
        }
        temporary_list_node = temporary_list_node->next;
    }
    free(temporary_list_node);
}

int comparator(const void *val1, const void *val2 ) {
    Coordinate *a, *b;
    a = (Coordinate*) val1;
    b = (Coordinate*) val2;
    Node *first = a->begin_word;
    Node *second = b->begin_word;
    while (first && second && first->letter != ' ' && first->letter != '\t' && second->letter != ' ' && second->letter != '\t') {
        if (first->letter > second->letter) {
            return 1;
        }
        if (first->letter < second->letter) {
            return -1;
        }
        first = first->next;
        second = second->next;
    }
    if ((!first || first->letter == ' ' || first->letter == '\t') && (second || second->letter != ' ' && second->letter != '\t')) {
        return 1;
    }
    else if ((first || first->letter != ' ' && first->letter != '\t') && (!second || second->letter == ' ' || second->letter == '\t')) {
        return -1;
    }
    else {
        return 0;
    }
}

void sorted_list(Stack *list) {
    int k = words_counter(list);
    Coordinate *array = (Coordinate *) calloc(k, sizeof(Coordinate));
    array_of_words_coordinates(list, &array);
    qsort(array, words_counter(list), sizeof(Coordinate), comparator);
    delete_spaces(list);
    for (int i = 0; i < k - 1; i++) {
        Node *temporary_node = (Node *) calloc(1, sizeof(Node));
        temporary_node->letter = ' ';
	temporary_node->next = NULL;
        array[i].end_word->next = temporary_node;
        temporary_node->next = array[i + 1].begin_word;
    }
    array[k - 1].end_word->next = NULL;
    list->head = array[0].begin_word;
    free(array);
}

int main() {
    Stack *list;
    while ((list = read_str()) != NULL) {
        printf("======\n");
        sorted_list(list);
        print_list(list);
        delete_list(list);
	printf("======\n");
    }
    free(list);
    return 0;
}
