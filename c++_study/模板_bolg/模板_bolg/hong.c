
#ifdef DEBUG

#endif // DEBUG

#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体和链表结构体的宏
#define DEFINE_LIST(type) \
typedef struct Node_##type { \
    type data; \
    struct Node_##type* next; \
} Node_##type; \
\
typedef struct List_##type { \
    Node_##type* head; \
} List_##type; \
\
void init_##type##_list(List_##type* list) { \
    list->head = NULL; \
} \
\
void add_##type##_node(List_##type* list, type value) { \
    Node_##type* new_node = (Node_##type*)malloc(sizeof(Node_##type)); \
    new_node->data = value; \
    new_node->next = list->head; \
    list->head = new_node; \
} \
\
void print_##type##_list(List_##type* list, void (*print_func)(type)) { \
    Node_##type* current = list->head; \
    while (current != NULL) { \
        print_func(current->data); \
        current = current->next; \
    } \
}

// 定义打印函数
void print_int(int value) {
    printf("%d ", value);
}

void print_float(float value) {
    printf("%f ", value);
}

// 使用宏定义不同类型的链表
DEFINE_LIST(int)
DEFINE_LIST(float)

int main() {
    // 整型链表示例
    List_int int_list;
    init_int_list(&int_list);
    add_int_node(&int_list, 10);
    add_int_node(&int_list, 20);
    add_int_node(&int_list, 30);
    printf("Integer list: ");
    print_int_list(&int_list, print_int);
    printf("\n");

    // 浮点型链表示例
    List_float float_list;
    init_float_list(&float_list);
    add_float_node(&float_list, 10.5);
    add_float_node(&float_list, 20.5);
    add_float_node(&float_list, 30.5);
    printf("Float list: ");
    print_float_list(&float_list, print_float);
    printf("\n");

    return 0;
}


