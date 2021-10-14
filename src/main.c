// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../c_str_lib/c_string.h"

void show_default_funcion(my_str_t *str);
void show_get_put_char(my_str_t *str);
void show_inserts(my_str_t *str, my_str_t *str2);
void show_appends(my_str_t *str, my_str_t *str2);
void show_find(my_str_t *str);
void show_read_write_files();
void show_substr(my_str_t* str);
void show_cmp(my_str_t* str);
void show_other(my_str_t* str);

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

    // the same works with read from stdin, though it is not showed here
    // as there is the requirement not to have anything that requires user
    // input
    show_read_write_files();

    show_substr(&str);
    show_cmp(&str);
    show_other(&str);

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


void show_read_write_files() {
    printf("------------ show read write to file ----------------\n");
    // create a string to write to file
    my_str_t test_file = {0};
    my_str_create(&test_file, 0);
    my_str_from_cstr(&test_file, "Hello there, this shows the write file func", 0);

    // opens the file and writes to it
    FILE *file_to_read = fopen("../test_files/test2.txt", "w");
    my_str_write_file(&test_file, file_to_read);
    printf("String: \"%s\" was written to the file", my_str_get_cstr(&test_file));

    // closes it so open it for reading later on
    fclose(file_to_read);

    // reads from the file and outputs it to the stdout
    my_str_t test_file2 = {0};
    my_str_create(&test_file2, 0);
    file_to_read = fopen("../test_files/test2.txt", "r");
    my_str_read_file(&test_file2, file_to_read);
    printf("Read test file that was written to: %s\n", my_str_get_cstr(&test_file2));

    // read file delimi example
    my_str_t test_file3 = {0};
    my_str_create(&test_file3, 0);
    my_str_read_file_delim(&test_file3, file_to_read, 'i');
    printf("Read the file up to delim, that is in this case 'i': %s\n", my_str_get_cstr(&test_file3));

    fclose(file_to_read);

    printf("The next message is the example of write to the stdout\n");
    my_str_write(&test_file2);
    printf("\n\n");
}

void show_substr(my_str_t* str){
    printf("------------ Show substr ---------------------\n");
    my_str_t str_test;
    my_str_create(&str_test, 0);

    printf("Initiali string: %s\n", my_str_get_cstr(str));
    my_str_substr(str, &str_test, 0, 2);
    printf("Substr of str (from 0 to 2, my_str_substr is used): %s\n", my_str_get_cstr(&str_test));
    char to[3];
    my_str_substr_cstr(&str_test, to, 0, 2);
    to[2] = '\0';
    printf("Cstr substr of str: %s\n\n", to);
    my_str_free(&str_test);
}

void show_cmp(my_str_t* str){
    printf("------------ Show cmp ---------------------\n");
    my_str_t str_test;
    my_str_create(&str_test, 0);
    my_str_from_cstr(&str_test, "sdhfdsannjdhv", 0);
    printf("Cmp with my_str: %d\n", my_str_cmp(str, &str_test));
    printf("String: %s; my_str: %s\n", my_str_get_cstr(str), my_str_get_cstr(&str_test));
    printf("Cmp with cstr: %d\n", my_str_cmp_cstr(str, "dksbhgslsajdhj"));
    printf("String: %s; my_str: %s\n", my_str_get_cstr(str), "dksbhgslsajdhj");
    printf("Cmp with another cstr: %d\n\n", my_str_cmp_cstr(str, "omg"));
    printf("String: %s; my_str: %s\n", my_str_get_cstr(str), "omg");
    my_str_free(&str_test);
}

void show_other(my_str_t* str){
    printf("------------ Show other ---------------------\n");
    printf("String before popback: %s\n", my_str_get_cstr(str));
    my_str_popback(str);
    printf("String after popback: %s\n", my_str_get_cstr(str));
    printf("Capacity before reserve: %zu\n", str->capacity_m);
    my_str_reserve(str, 2*str->capacity_m);
    printf("Capacity after reserve: %zu\n", str->capacity_m);
    printf("My str before resize: %s\n", my_str_get_cstr(str));
    my_str_resize(str, 80, '0');
    printf("My str after resize: %s\n", my_str_get_cstr(str));
    printf("Capacity before shrink to fit: %zu\n", str->capacity_m);
    my_str_shrink_to_fit(str);
    printf("Capacity after shrink to fit: %zu\n", str->capacity_m);

    printf("\nNote here that string is filled with zeroes after the resize");
    printf("My str before erase: %s\n", my_str_get_cstr(str));
    my_str_erase(str, 10, 70);
    printf("My str after erase: %s\n\n", my_str_get_cstr(str));
}
