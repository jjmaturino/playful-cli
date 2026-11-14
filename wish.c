#include <stdio.h>
#include <stdlib.h>

int interactive_mode(){
    char *line = NULL;
    size_t capacity = 0;
    while (1){
        printf("wish> ");
        fflush(stdout);
        if (getline(&line, &capacity, stdin) == -1) break;
        printf("%s \n", line);
    }


    return 0;
}

int batch_mode(){

    printf("batch mode!!!!\n");
    return 0;
}


int main(int argc, char *argv[]) {

    if (argc == 1){ interactive_mode();}
    else { batch_mode();}


    return 0;
}
