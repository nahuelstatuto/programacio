#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void quicksort_while(double*, int, int);
void quicksort_while_ahorro(double*, int, int);
void quicksort_pdf(double*, int, int);

void calcular_media_std(double*, int, double*, double*);

int main() {
    double *base, *v, *u, *w;
    double *temps_while, *temps_pdf, *temps_ahorro;
    double mean_while, mean_pdf, mean_ahorro;
    double std_while, std_pdf, std_ahorro;

    int j, r, idx, n;
    clock_t t0, t1;

    int valors_n[] = {5000, 10000, 20000, 100000, 400000, 1000000, 1200000, 1400000, 2000000};
    int num_valors = 9;

    int repeticions = 10;

    FILE *fout;

    fout = fopen("temps_quicksort.dat", "w");
    if (fout == NULL) {
        printf("Error obrint el fitxer de sortida.\n");
        exit(1);
    }

    fprintf(fout, "# n mean_while std_while mean_pdf std_pdf mean_ahorro std_ahorro\n");

    srand(time(NULL));

    for (idx = 0; idx < num_valors; idx++) {

        n = valors_n[idx];

        base = (double *) malloc(n * sizeof(double));
        v    = (double *) malloc(n * sizeof(double));
        u    = (double *) malloc(n * sizeof(double));
        w    = (double *) malloc(n * sizeof(double));

        temps_while  = (double *) malloc(repeticions * sizeof(double));
        temps_pdf    = (double *) malloc(repeticions * sizeof(double));
        temps_ahorro = (double *) malloc(repeticions * sizeof(double));

        if (base == NULL || v == NULL || u == NULL || w == NULL ||
            temps_while == NULL || temps_pdf == NULL || temps_ahorro == NULL) {
            printf("Error al malloc per n = %d\n", n);
            exit(2);
        }

        for (r = 0; r < repeticions; r++) {

            /*
               Generamos un vector aleatorio base.
               Después copiamos ese mismo vector en v, u y w para que
               los tres algoritmos ordenen exactamente los mismos datos.
            */
            for (j = 0; j < n; j++) {
                base[j] = (double) rand() / RAND_MAX;
            }

            memcpy(v, base, n * sizeof(double));
            memcpy(u, base, n * sizeof(double));
            memcpy(w, base, n * sizeof(double));

            t0 = clock();
            quicksort_while(v, 0, n - 1);
            t1 = clock();
            temps_while[r] = (double)(t1 - t0) / CLOCKS_PER_SEC;

            t0 = clock();
            quicksort_pdf(u, 0, n - 1);
            t1 = clock();
            temps_pdf[r] = (double)(t1 - t0) / CLOCKS_PER_SEC;

            t0 = clock();
            quicksort_while_ahorro(w, 0, n - 1);
            t1 = clock();
            temps_ahorro[r] = (double)(t1 - t0) / CLOCKS_PER_SEC;
        }

        calcular_media_std(temps_while, repeticions, &mean_while, &std_while);
        calcular_media_std(temps_pdf, repeticions, &mean_pdf, &std_pdf);
        calcular_media_std(temps_ahorro, repeticions, &mean_ahorro, &std_ahorro);

        printf("n = %d\n", n);
        printf("  quicksort_while:        mean = %.6e s, std = %.6e s\n", mean_while, std_while);
        printf("  quicksort_pdf:          mean = %.6e s, std = %.6e s\n", mean_pdf, std_pdf);
        printf("  quicksort_while_ahorro: mean = %.6e s, std = %.6e s\n", mean_ahorro, std_ahorro);
        printf("\n");

        fprintf(fout, "%d %.10e %.10e %.10e %.10e %.10e %.10e\n",
                n,
                mean_while, std_while,
                mean_pdf, std_pdf,
                mean_ahorro, std_ahorro);

        free(base);
        free(v);
        free(u);
        free(w);

        free(temps_while);
        free(temps_pdf);
        free(temps_ahorro);
    }

    fclose(fout);

    printf("Fitxer 'temps_quicksort.dat' creat correctament.\n");

    return 0;
}


void calcular_media_std(double *temps, int n, double *media, double *std) {
    double suma = 0.0;
    double suma2 = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        suma += temps[i];
    }

    *media = suma / n;

    if (n > 1) {
        for (i = 0; i < n; i++) {
            suma2 += (temps[i] - *media) * (temps[i] - *media);
        }

        *std = sqrt(suma2 / (n - 1));
    } else {
        *std = 0.0;
    }
}


void quicksort_while_ahorro(double *v, int esq, int drt) {
    double aux;
    int i, k;

    while (esq < drt) {

        /* pivot: element central; es mou a l'esquerra */
        i = esq + (drt - esq) / 2;
        aux = v[esq];
        v[esq] = v[i];
        v[i] = aux;

        /* tots els petits cap a la part davantera */
        k = esq;
        for (i = esq + 1; i <= drt; ++i) {
            if (v[i] < v[esq]) {
                ++k;
                aux = v[k];
                v[k] = v[i];
                v[i] = aux;
            }
        }

        /* el pivot al seu lloc */
        aux = v[esq];
        v[esq] = v[k];
        v[k] = aux;

        /*
           Estalvi de memòria:
           es fa la crida recursiva només sobre la zona més petita.

           La zona més gran es continua ordenant amb el bucle while.
        */
        if (k - esq <= drt - k) {

            quicksort_while_ahorro(v, esq, k - 1);

            esq = k + 1;

        } else {

            quicksort_while_ahorro(v, k + 1, drt);

            drt = k - 1;
        }
    }
}


void quicksort_while(double *v, int esq, int drt) {
    double aux;
    int i, k;

    while (esq < drt) {

        /* pivot: element central; es mou a l'esquerra */
        i = esq + (drt - esq) / 2;
        aux = v[esq];
        v[esq] = v[i];
        v[i] = aux;

        /* tots els petits cap a la part davantera */
        k = esq;
        for (i = esq + 1; i <= drt; ++i) {
            if (v[i] < v[esq]) {
                ++k;
                aux = v[k];
                v[k] = v[i];
                v[i] = aux;
            }
        }

        /* el pivot al seu lloc */
        aux = v[esq];
        v[esq] = v[k];
        v[k] = aux;

        /*
           Versió amb while:
           es fa una crida recursiva a l'esquerra i es continua
           amb la dreta modificant esq.
        */
        quicksort_while(v, esq, k - 1);

        esq = k + 1;
    }
}


void quicksort_pdf(double *v, int esq, int drt) {
    double aux;
    int i, k;

    if (esq >= drt) return;

    /* pivot: element central; es mou a l'esquerra */
    i = esq + (drt - esq) / 2;
    aux = v[esq];
    v[esq] = v[i];
    v[i] = aux;

    /* tots els petits cap a la part davantera */
    k = esq;
    for (i = esq + 1; i <= drt; ++i) {
        if (v[i] < v[esq]) {
            ++k;
            aux = v[k];
            v[k] = v[i];
            v[i] = aux;
        }
    }

    /* el pivot al seu lloc */
    aux = v[esq];
    v[esq] = v[k];
    v[k] = aux;

    /*
       Versió recursiva original:
       es fan dues crides recursives.
    */
    if (k - esq <= drt - k) {
        quicksort_pdf(v, esq, k - 1);
        quicksort_pdf(v, k + 1, drt);
    } else {
        quicksort_pdf(v, k + 1, drt);
        quicksort_pdf(v, esq, k - 1);
    }
}