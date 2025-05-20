#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DT 0.01
#define T_MAX 10.0
#define K 1.0

typedef struct {
    /* ... */
} Cos;

void forca_central(double x, double y, double m, double* fx, double* fy);
void pas_euler(Cos* estat, double dt);
void pas_rk4(Cos* estat, double dt);
double energia_total(Cos estat);
void escriure_trajectoria(const char* nom_base, Cos* trajectoria, int n);

int main() {
    return 0;
}

void pas_rk4(Cos* estat, double dt) {
    double fx1, fy1, fx2, fy2, fx3, fy3, fx4, fy4;
    double x, y, vx, vy, massa;
    double x2, y2, vx2, vy2;
    double x3, y3, vx3, vy3;
    double x4, y4, vx4, vy4;

    x = estat->x;
    y = estat->y;
    vx = estat->vx;
    vy = estat->vy;
    massa = estat->massa;

    forca_central(x, y, massa, &fx1, &fy1);

    vx2 = vx + fx1 / massa * dt / 2;
    vy2 = vy + fy1 / massa * dt / 2;
    x2 = x + vx * dt / 2;
    y2 = y + vy * dt / 2;
    forca_central(x2, y2, massa, &fx2, &fy2);

    vx3 = vx + fx2 / massa * dt / 2;
    vy3 = vy + fy2 / massa * dt / 2;
    x3 = x + vx2 * dt / 2;
    y3 = y + vy2 * dt / 2;
    forca_central(x3, y3, massa, &fx3, &fy3);

    vx4 = vx + fx3 / massa * dt;
    vy4 = vy + fy3 / massa * dt;
    x4 = x + vx3 * dt;
    y4 = y + vy3 * dt;
    forca_central(x4, y4, massa, &fx4, &fy4);

    estat->x += dt * (vx + 2*vx2 + 2*vx3 + vx4) / 6;
    estat->y += dt * (vy + 2*vy2 + 2*vy3 + vy4) / 6;
    estat->vx += dt * (fx1 + 2*fx2 + 2*fx3 + fx4) / (6 * massa);
    estat->vy += dt * (fy1 + 2*fy2 + 2*fy3 + fy4) / (6 * massa);
}