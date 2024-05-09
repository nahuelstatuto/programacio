#include <stdio.h>
#include <math.h>

long int qu = 0;

double rec(double x0, double x1, int n);
double rec_optim(double x0, double x1, int n);

int main(void) {
	int n;
	double x0, x1, qn, xaux;
	printf("n, x0, x1 = ? \n");
	scanf("%d %le %le", &n, &x0, &x1);
	if (n < 0) return 1;
	xaux=rec(x0, x1, n);
	qn = (7+sqrt(7))/12*pow(2-sqrt(7), n) + (7-sqrt(7))/12*pow(2+sqrt(7), n) - 1/6;
	printf("x_n = %+.8le \n", xaux);
	printf("q_n = %+.8le \n", qn);
	printf("qu = %.ld \n", qu);

	qu=0;
	xaux = rec_optim(x0, x1, n);
	/* falta resolver qn para rec_optim (será tipo Fibonacci) */
	printf("x_n = %+.8le \n", xaux);
	/*printf("q_n = %+.8le \n", qn);*/
	printf("qu = %.ld \n", qu);

	return 0;
}

double rec(double x0, double x1, int n) {
	double a;
	qu = qu+1;
	if (n == 0) return x0;
	else if (n == 1) return x1;
	else{
		a = 0.02*rec(x0,x1,n-1)*rec(x0,x1,n-1)+0.01*rec(x0,x1,n-2)*rec(x0,x1,n-2)-0.5*(rec(x0,x1,n-1)+rec(x0,x1,n-2))-n*sin(rec(x0,x1,n-1));
		return a;
	}	
}

double rec_optim(double x0, double x1, int n) {
	double a,a2,a1;
	qu = qu+1;
	if (n == 0) return x0;
	else if (n == 1) return x1;
	else{
		a1 = rec(x0,x1,n-1);
		a2 = rec(x0,x1,n-2);
		a = 0.02*a1*a1+0.01*a2*a2-0.5*(a1+a2)-n*sin(a1);
		return a;
	}	
}