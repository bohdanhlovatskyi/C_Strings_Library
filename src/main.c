// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../c_str_lib/c_string.h"

void show_default_funcion(my_str_t *str);
void show_get_put_char(my_str_t *str);
void show_inserts(my_str_t *str, my_str_t *str2);
void show_appends(my_str_t *str, my_str_t *str2);
void show_find(my_str_t *str);
void show_read_files();

int pred(int sym);

int main() {
    int err = 0;
    my_str_t str = {0};
    char *test_str = "Hello there!";
    
    my_str_create(&str, 0); 
    // NOTE: strlen only here as out implementation is static one in lib
    my_str_from_cstr(&str, test_str, strlen(test_str));

    show_default_funcion(&str);
    show_get_put_char(&str);

    my_str_t str2 = {0};
    my_str_create(&str2, 0);

    my_str_copy(&str, &str2, 1);
    printf("Second string after copying first string: %s\n", my_str_get_cstr(&str2));
    my_str_clear(&str2);
    printf("Second string after clear: %s\n", my_str_get_cstr(&str2));
    
    show_inserts(&str, &str2);
    show_appends(&str, &str2);
    show_find(&str);
    show_read_files();

    my_str_free(&str);
}

void show_default_funcion(my_str_t *str) {
    printf("--------------- Show default funcs -------------------\n");
    printf("String from cstr: %s\n", my_str_get_cstr(str));
    printf("Size: %zu\n", my_str_size(str));
    printf("Capacity: %zu\n", my_str_capacity(str));
    printf("My str empty: %s\n\n", my_str_empty(str) ? "true" : "false");
}

void show_get_put_char(my_str_t *str) {
    printf("-------------- Show get and put chars ----------------\n");
    printf("Getc: %c\n", my_str_getc(str, 0));
    printf("String before puts: %s\n", my_str_get_cstr(str));
    my_str_putc(str, 0, 'f');
    printf("String after puts: %s\n\n", my_str_get_cstr(str));
}

void show_inserts(my_str_t *str, my_str_t *str2) {
    printf("-------------- Show inserts ----------------\n");
    my_str_append_cstr(str2, "String that was appended");
    printf("Second string after append cstr: %s\n", my_str_get_cstr(str2));
    my_str_insert_c(str2, 'f', 3);
    printf("Second string after inserting f at third position: %s\n\n", my_str_get_cstr(str2));
    
    my_str_insert_cstr(str2, "ffff", 3);
    printf("Second string after inserting ffff at third position: %s\n", my_str_get_cstr(str2));
    my_str_insert(str2, str, 3);
    printf("Second string after inserting first string at third position: %s\n\n", my_str_get_cstr(str2));
}

void show_appends(my_str_t *str, my_str_t *str2) {
    printf("------------- Show appends ----------------\n");
    printf("First string: %s\n", my_str_get_cstr(str));
    my_str_append_c(str, 'f');
    printf("First string after f has been appended: %s\n", my_str_get_cstr(str));
    my_str_append_cstr(str, "ffff");
    printf("First string after ffff has been appended: %s\n", my_str_get_cstr(str));
    my_str_append(str, str2);
    printf("Second string appended to the first one: %s\n\n", my_str_get_cstr(str));
    my_str_clear(str2);
}

void show_find(my_str_t *str) {
    printf("------------ Show find ---------------------\n");
    printf("First string: %s\n", my_str_get_cstr(str));
    printf("Index of l: %d\n", my_str_find_c(str, 'l', 0));
    my_str_t find_str = {0};
    my_str_create(&find_str, 0);
    // here 0 denotes that the buffer should be set with the length of the find_str
    my_str_from_cstr(&find_str, "there", 0);
    printf("Index of there starting from 7-th character: %zu\n", my_str_find(str, &find_str, 0));

    printf("Index of l (find if): %d\n\n", my_str_find_if(str, 0, pred));

    my_str_free(&find_str);
}

int pred(int sym) {
    if ((char) sym == 'l') {
        return 1;
    }

    return 0;
}

void show_read_files() {
    my_str_t test_file = {0};
    my_str_create(&test_file, 0);

    FILE *file_to_read = fopen("test.txt", "r");
    int err = my_str_read_file(&test_file, file_to_read);
    printf("%d\n", err);
    printf("Read test file: %s\n", my_str_get_cstr(&test_file));
}
