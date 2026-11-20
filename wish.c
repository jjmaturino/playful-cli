#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int write_error_message(void){
    char error_message[30] = "An error has occurred\n";
    write(STDERR_FILENO, error_message, strlen(error_message)); 

    return 0;
}


static int run_shell(FILE *input, int display_prompt){
    char *line = NULL;
    size_t capacity = 0;

    while (1){
        if (display_prompt != 0){
            printf("wish> ");
            fflush(stdout);
        }
        if (getline(&line, &capacity, input) == -1){ break;}
        char *cursor = line;
        while (cursor != NULL){
            char *token = strsep(&cursor, " \t\n");
            if (token[0] == '\0'){ continue;}
            printf("%s\n", token);
        }

    }

    free(line);
    if (ferror(input)){ return 1;}

    return 0;
}


int main(int argc, char *argv[]) {
    int display_prompt = 1;
    FILE *input = stdin;

    if (argc > 2) {
        write_error_message();
        return 1;
    }

    if (argc == 2) { 
        display_prompt = 0;
        input = fopen(argv[1], "r");

        if (input == NULL){ 
            write_error_message(); 
            return 1;
        }
    }

    int code = run_shell(input, display_prompt);
    if (argc == 2 && fclose(input) == EOF) code = 1;

    if (code != 0){
        write_error_message();
        return 1; 
    }

    return 0;
}


