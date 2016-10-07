#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

// ---------- //
// Constantes //
// ---------- //

#define CARACTERE_VIDE '-'
#define HAUTEUR_MAX 15
#define LARGEUR_MAX 20

void test_argc(int argc);
void test_single_args(char *str1, char *str2);
void test_args_len(char *str);
void test_width(char *str);
void slice_string(char **array_str,char *str);

int main(int argc, char *argv[]) {
    test_argc(argc);
    test_args_len(argv[1]);
    test_args_len(argv[2]);
    test_single_args(argv[1],argv[2]);

    test_width(argv[argc-1]);
    char *array[strlen(argv[argc-1]-1)];
    slice_string(array, argv[argc-1]);

}

void test_argc(int argc){
    if (argc < 4){
        printf("Nombre d'arguments invalides: il en faut 3\n");
        exit(1);
    }
}

void test_single_args(char *str1, char *str2){
    if (strcmp(str1,str2) == 0){
        printf("Les codes doivent etre distincts\n");
        exit(1);
    }
}

void test_args_len(char *str){
    if (strlen(str) != 1){
        printf("Code %s invalide: il doit etre un caractere unique\n",str);
         exit(1);
    }
}

void test_width(char *str){
    if (strlen(str) > LARGEUR_MAX){
        printf("Largeur invalide: le nombre de hauteurs doit etre entre "
                "1 et 20\n");
        exit(1);
    }
}

void slice_string(char **array_str,char *str){
    const char s[2] = ",";
    char *token;
    int index = 0;

    token = strtok(str,s);
    while (token != NULL){
        array_str[index++] = token;
        token = strtok(NULL,s);
    }
}
