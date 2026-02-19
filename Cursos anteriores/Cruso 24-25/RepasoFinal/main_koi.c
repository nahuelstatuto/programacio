#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXO 1000
#define MAX_LINIA 1024

typedef struct {
    char nom[20];           /* kepoi_name */
    float periode;          /* koi_period */
    float radi;             /* koi_prad */
    float radi_estrella;    /* koi_srad */
    float teq;              /* koi_teq */
    float insolacio;        /* koi_insol */
} Exoplaneta;

/* Comparar per radi planetari */
int cmp_radi(const void *a, const void *b) {
    float ra = ((Exoplaneta*)a)->radi;
    float rb = ((Exoplaneta*)b)->radi;
    return (ra > rb) - (ra < rb);
}

/* Comparar per radi estrella i després radi planeta */
int cmp_radi_estrella_radi_planeta(const void *a, const void *b) {
    Exoplaneta *ea = (Exoplaneta*)a;
    Exoplaneta *eb = (Exoplaneta*)b;

    if (ea->radi_estrella != eb->radi_estrella)
        return (ea->radi_estrella > eb->radi_estrella) - (ea->radi_estrella < eb->radi_estrella);
    return (ea->radi > eb->radi) - (ea->radi < eb->radi);
}

/* Distància a la Terra per a mètrica d'habitabilitat */
float distancia_habitabilitat(Exoplaneta *e) {
    float dr = e->radi - 1.0;
    float di = e->insolacio - 1.0;
    float dt = e->teq - 300.0;
    return dr*dr + di*di + dt*dt;
}

/* Comparar per proximitat a la Terra */
int cmp_habitabilitat(const void *a, const void *b) {
    float da = distancia_habitabilitat((Exoplaneta*)a);
    float db = distancia_habitabilitat((Exoplaneta*)b);
    return (da > db) - (da < db);
}

/* Llegir el CSV i carregar estructures */
int llegir_csv(const char *nom_fitxer, Exoplaneta exos[], int max) {
    FILE *fp = fopen(nom_fitxer, "r");
    if (!fp) {
        perror("Error obrint fitxer");
        return 0;
    }

    char linia[MAX_LINIA];
    fgets(linia, MAX_LINIA, fp); /* Saltar capçalera */

    int i = 0;
    while (fgets(linia, MAX_LINIA, fp) && i < max) {
        sscanf(linia, "%[^,],%f,%f,%f,%f,%f",
               exos[i].nom,
               &exos[i].periode,
               &exos[i].radi,
               &exos[i].radi_estrella,
               &exos[i].teq,
               &exos[i].insolacio);
        i++;
    }

    fclose(fp);
    return i;
}

/* Mostrar exoplanetes. Si quants = -1, mostrar tots */
void mostrar(Exoplaneta exos[], int total, int quants) {
    int i;
    if (quants == -1 || quants > total) quants = total;
    for (i = 0; i < quants; i++) {
        printf("%-10s  P=%.2f  R=%.2f  R_est=%.2f  T_eq=%.1f  Insol=%.2f\n",
               exos[i].nom,
               exos[i].periode,
               exos[i].radi,
               exos[i].radi_estrella,
               exos[i].teq,
               exos[i].insolacio);
    }
}

/* Programa principal */
int main() {
    Exoplaneta exos[MAX_EXO];
    int qmostrar = 10;
    int total = llegir_csv("kepler_1000.csv", exos, MAX_EXO);

    if (total == 0) {
        printf("No s'han pogut llegir dades.\n");
        return 1;
    }

    printf("Ordenats per radi planetari:\n");
    qsort(exos, total, sizeof(Exoplaneta), cmp_radi);
    mostrar(exos, total, qmostrar);

    printf("\nOrdenats per radi estrella (i radi planeta):\n");
    qsort(exos, total, sizeof(Exoplaneta), cmp_radi_estrella_radi_planeta);
    mostrar(exos, total, qmostrar);

    printf("\nOrdenats per habitabilitat (propers a la Terra):\n");
    qsort(exos, total, sizeof(Exoplaneta), cmp_habitabilitat);
    mostrar(exos, total, qmostrar);

    return 0;
}
