#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

/* Funcions */
void escriure_fitxer(char *filename);
void llegir_getc(char *filename);
void llegir_fgets(char *filename);
void llegir_fscanf(char *filename);
void afegir_text(char *filename);

int main() {
    char filename[] = "dades.txt";

    /* Escriure dades al fitxer */
    escriure_fitxer(filename);

    /* Llegir el fitxer caràcter a caràcter amb getc */
    llegir_getc(filename);

    /* Llegir línia a línia amb fgets */
    llegir_fgets(filename);

    /* Llegir dades formatades amb fscanf */
    llegir_fscanf(filename);

    /* Afegir una línia nova amb fputs */
    afegir_text(filename);

    return 0;
}

/* Escriure dades al fitxer amb fprintf i fputs */
void escriure_fitxer(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error obrint el fitxer per escriure");
        exit(1);
    }

    fprintf(file, "Nom: %s\n", "Joan");
    fprintf(file, "Edat: %d\n", 25);
    fputs("Hola, aquest és un exemple de fitxer de text.\n", file);
    fputs("Segona línia del fitxer de text.\n", file);

    fclose(file);
}

/* Llegir caràcter a caràcter amb getc */
void llegir_getc(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error obrint el fitxer per llegir");
        exit(1);
    }

    printf("Contingut llegit amb getc():\n");
    int c;
    while ((c = getc(file)) != EOF) {
        putchar(c);
    }
    putchar('\n');

    fclose(file);
}

/* Llegir una línia completa amb fgets */
void llegir_fgets(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error obrint el fitxer per llegir");
        exit(1);
    }

    char buffer[MAX_LEN];

    printf("\nContingut llegit amb fgets():\n");
    while (fgets(buffer, MAX_LEN, file) != NULL) {
        printf("%s", buffer);
    }
    putchar('\n');

    fclose(file);
}

/* Llegir dades formatades amb fscanf */
void llegir_fscanf(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error obrint el fitxer per llegir");
        exit(1);
    }

    char nom[MAX_LEN];
    int edat;

    printf("\nLectura de dades formatades amb fscanf():\n");
    fscanf(file, "Nom: %s\n", nom);
    fscanf(file, "Edat: %d\n", &edat);
    printf("Nom: %s, Edat: %d\n\n", nom, edat);

    fclose(file);
}

/* Afegir una línia amb fputs */
void afegir_text(char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error obrint el fitxer per afegir text");
        exit(1);
    }

    fputs("Aquesta és una nova línia afegida amb fputs.\n", file);
    fclose(file);

    printf("S'ha afegit una nova línia al fitxer.\n");
}
