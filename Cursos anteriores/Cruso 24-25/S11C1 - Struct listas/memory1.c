/* memory1.c

es treballa amb 2 tipus estructurats: 
   triangle: 3 vèrtexs
   recta: 1 punt i 1 vector director

es vol comprovar, per a qualsevol triangle no degenerat:
   les 3 rectes bisectrius són concurrents: incentre 
   les 3 rectes mitjanes són concurrents: baricentre
   les 3 rectes mediatrius són concurrents: circumcentre
   les 3 rectes altures són concurrents: ortocentre
   el baricentre, el circumcentre i l'ortocentre estan alineats: recta d'Euler
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define tol 1e-4     /* tolerància per a considerar que un valor és 0 */

/* tipus estructurats */
typedef struct{
    float x;
    float y;
} punto;

typedef struct {
   punto a;
   punto b;
   punto c;
} triangle;

typedef struct{
   punto p;
   float v[2];
} recta;

struct recta_{
  float p[2];
  char v[30]; 
};

/* prototipus de funcions */
recta bisectriu(punto , punto , punto);
void mitjanes3(triangle, recta *, recta *, recta *);
recta mediatriu(punto, punto);
recta * altures3(triangle);
int intersec2rectes(recta, recta, punto *);
void escriure1recta(char *, recta);
void escriure1punt(char *, punto);

/* funció main */
int main(void) {
   int res;
   float aux, bar[2], cir[2], ort[2];
   punto p;
   triangle t, *pointer;
   recta ra, rb, rc, re, *rr;

   struct recta_ e1;

   /* definició d'un triangle */
   t.a.x= 0.0;
   t.a.y= 0.0;
   t.b.x= 0.0;
   t.b.y= 1.0;
   t.c.x= 1.0;
   t.c.y= 0.0;

   /* test de memoria */
   printf("\n");
   printf("memoria de t.a: %llu\n", sizeof(t.a));
   printf("memoria de t.a.x: %llu\n", sizeof(t.a.x));
   printf("memoria de t: %llu\n", sizeof(t));
   printf("memoria de recta: %llu\n", sizeof(ra));
         
   printf("memoria de e1.p: %llu\n", sizeof(e1.p));
   printf("memoria de e1.v: %llu\n", sizeof(e1.v));
   printf("memoria de e1: %llu\n",sizeof(e1));

   pointer  = (triangle *) calloc(1,sizeof(triangle));
   printf("memoria del puntero a triangulo: %llu\n", sizeof(pointer));
   printf("%lf %lf %lf %lf %lf %lf\n", pointer->a.x,pointer->a.y,pointer->b.x,pointer->b.y,pointer->c.x,pointer->c.y);

   /* comprovació que no és degenerat 
      àrea = (1/2) | det ( TA, 1 \\ TB, 1 \\ TC, 1 ) |  */
   printf("\ncomprovació de si el triangle és degenerat \n");
   aux =       t.a.x * (t.b.y - t.c.y);
   aux = aux + t.b.x * (t.c.y - t.a.y);
   aux = aux + t.c.x * (t.a.y - t.b.y);
   printf("area = %+.4f \n", 0.5*fabs(aux));
   if (fabs(aux)<tol)
      exit(1);
  
   /* comprovació que les 3 bisectrius es tallen en un punt: incentre */
   printf("\ncomprovacio que les 3 bisectrius son concurrents: incentre \n");

   ra = bisectriu(t.a, t.b, t.c);
   escriure1recta("bisectriu 1", ra);

   rb = bisectriu(t.b, t.c, t.a);
   escriure1recta("bisectriu 2", rb);

   rc = bisectriu(t.c, t.a, t.b);
   escriure1recta("bisectriu 3", rc);

   res = intersec2rectes(ra, rb, &p);
   if (res != 0) {
      printf("les dos rectes bisectius ra, rb no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de bisectrius 1-2", p);

   res = intersec2rectes(rb, rc, &p);
   if (res != 0) {
      printf("les dos rectes bisectius rb, rc no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de bisectrius 2-3", p);

   res = intersec2rectes(rc, ra, &p);
   if (res != 0) {
      printf("les dos rectes bisectius rc, ra no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de bisectrius 3-1", p);


   /* comprovació que les 3 mitjanes es tallen en un punt: baricentre */
   printf("\ncomprovacio que les 3 mitjanes son concurrents: baricentre \n");

   mitjanes3(t, &ra, &rb, &rc);

   escriure1recta("mitjana 1", ra);
   escriure1recta("mitjana 2", rb);
   escriure1recta("mitjana 3", rc);

   res = intersec2rectes(ra, rb, &p);
   if (res != 0) {
      printf("les dos rectes mitjanes ra, rb no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mitjanes 1-2", p);

   res = intersec2rectes(rb, rc, &p);
   if (res != 0) {
      printf("les dos rectes mitjanes rb, rc no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mitjanes 2-3", p);

   res = intersec2rectes(rc, ra, &p);
   if (res != 0) {
      printf("les dos rectes mitjanes rc, ra no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mitjanes 3-1", p);

   bar[0] = p.x;
   bar[1] = p.y;

   /* comprovació que les 3 mediatrius es tallen en un punt: circumcentre */
   printf("\ncomprovacio que les 3 mediatrius son concurrents: circumcentre \n");

   ra = mediatriu(t.b, t.c);
   escriure1recta("mediatriu 1", ra);

   rb = mediatriu(t.c, t.a);
   escriure1recta("mediatriu 2", rb);

   rc = mediatriu(t.a, t.b);
   escriure1recta("mediatriu 3", rc);

   res = intersec2rectes(ra, rb, &p);
   if (res != 0) {
      printf("les dos rectes mediatrius ra, rb no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mediatrius 1-2", p);

   res = intersec2rectes(rb, rc, &p);
   if (res != 0) {
      printf("les dos rectes mediatrius rb, rc no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mediatrius 2-3", p);

   res = intersec2rectes(rc, ra, &p);
   if (res != 0) {
      printf("les dos rectes mediatrius rc, ra no tenen interseccio unica \n");
      exit(1);
   }
   escriure1punt("interseccio de mediatrius 3-1", p);

   cir[0] = p.x;
   cir[1] = p.y;
  
   /* comprovació que les 3 altures es tallen en un punt: ortocentre */
   printf("\ncomprovacio que les 3 altures son concurrents: ortocentre \n");

   rr = altures3(t);
   if (rr == NULL) {
      printf("problemes en rr, no es calculen les altures, acabem \n");
      return 0;
   }
   escriure1recta("altura 1", rr[0]);
   escriure1recta("altura 2", rr[1]);
   escriure1recta("altura 3", rr[2]);

   res = intersec2rectes(rr[0], rr[1], &p);
   if (res != 0) {
      printf("les dos rectes altures r0, r1 no tenen interseccio unica \n");
      free(rr);
      exit(1);
   }
   escriure1punt("interseccio d'altures 1-2", p);

   res = intersec2rectes(rr[1], rr[2], &p);
   if (res != 0) {
      printf("les dos rectes altures r1, r2 no tenen interseccio unica \n");
      free(rr);
      exit(1);
   }
   escriure1punt("interseccio d'altures 2-3", p);

   res = intersec2rectes(rr[2], rr[0], &p);
   if (res != 0) {
      printf("les dos rectes altures r2, r0 no tenen interseccio unica \n");
      free(rr);
      exit(1);
   }
   escriure1punt("interseccio d'altures 3-1", p);

   ort[0] = p.x;
   ort[1] = p.y;
   
   /* comprovació que baricentre, circumcentre i ortocentre estan alineats 
   (b0, b1), (c0, c1) i (o0, o1) estan alineats sii
      sii (c1-b1) / (c0-b0) = (o1-b1) / (o0-b0)
      sii (c1-b1)*(o0-b0) - (c0-b0)*(o1-b1) = 0 
      s'usa a questa última expressió, on no hi ha divisions */
   printf("\ncomprovacio que baric., circum. i ortoc. estan alineats: \n");
   aux = (cir[1]-bar[1])*(ort[0]-bar[0])-(cir[0]-bar[0])*(ort[1]-bar[1]);
   printf("(cir1-bar1)*(ort0-bar0)-(cir0-bar0)*(ort1-bar1) = %+.4f \n", aux);

   /* recta d'Euler
      fem-la passar pel baricentre i l'ortocentre */
   re.p.x = bar[0];
   re.p.y = bar[1];
   re.v[0] = ort[0]-bar[0];
   re.v[1] = ort[1]-bar[1];
   printf("\n");
   escriure1recta("recta d'Euler", re);

   free(rr);


   return 0;
}

/* càlcul d'una recta bisectriu:
   passa per un vèrtex i parteix l'angle en dos meitats iguals 
*/
recta bisectriu (punto p, punto q1, punto q2) {
   float aux, u[2], v[2];
   recta r;

   /* punt de la bisectriu */
   r.p.x = p.x;
   r.p.y = p.y;

   /* vector p->q1 i escalat a norma = 1 */
   u[0] = q1.x-p.x;
   u[1] = q1.y-p.y;
   aux = sqrt(u[0]*u[0]+u[1]*u[1]);
   u[0] = u[0]/aux;
   u[1] = u[1]/aux;

   /* vector p->q2 i escalat a norma = 1 */
   v[0] = q2.x-p.x;
   v[1] = q2.y-p.y;
   aux = sqrt(v[0]*v[0]+v[1]*v[1]);
   v[0] = v[0]/aux;
   v[1] = v[1]/aux;

   /* com que els 2 vectors anteriors tenen la mateixa norma
      la seva suma és vector director de la bisectriu */
   r.v[0] = u[0]+v[0];
   r.v[1] = u[1]+v[1];

   return r;
}

/* càlcul de les 3 rectes mitjanes
   cada mitjana passa per un vèrtex i pel punt mitjà dels altres dos
   vector director = punt mitjà dels altres dos -> vèrtex 
*/
void mitjanes3(triangle t, recta *r1, recta *r2, recta *r3) {

   /* mitjana pel vèrtex a */
   r1->p.x = t.a.x;
   r1->p.y = t.a.y;
   r1->v[0] = (t.b.x+t.c.x)/2.-t.a.x;
   r1->v[1] = (t.b.y+t.c.y)/2.-t.a.y;

   /* mitjana pel vèrtex b */
   r2->p.x = t.b.x;
   r2->p.y = t.b.y;
   r2->v[0] = (t.c.x+t.a.x)/2.-t.b.x;
   r2->v[1] = (t.c.y+t.a.y)/2.-t.b.y;

   /* mitjana pel vèrtex c */
   r3->p.x = t.c.x;
   r3->p.y = t.c.y;
   r3->v[0] = (t.a.x+t.b.x)/2.-t.c.x;
   r3->v[1] = (t.a.y+t.b.y)/2.-t.c.y;

   return;
}

/* càlcul d'una recta mediatriu:
   passa pel punt mitjà d'un costat i és perpendicular a aquest costat
*/
recta mediatriu(punto p, punto q) {
   recta r;

   /* punt */
   r.p.x = 0.5*(p.x+q.x);
   r.p.y = 0.5*(p.y+q.y);

   /* vector director:
      una direcció perpendicular a (v0,v1) és (-v1, v0) */
   r.v[0] = (q.y-p.y);
   r.v[1] = - (q.x-p.x);

   return r;
}

/* càlcul de les 3 rectes altures
   cada altura passa per un vèrtex i és perpendicular al costat oposat
   una direcció perpendicular a (v0, v1) és (-v1, v0)
   com que cal retornar el tipus recta *, cal declarar un vector i retornar-lo
*/
recta * altures3(triangle t) {
   recta *r;

   r = (recta *) malloc (3*sizeof(recta));
   if ( r == NULL ) return NULL;

   /* altura pel vèrtex A */
   r[0].p.x = t.a.x;
   r[0].p.y = t.a.y;
   r[0].v[0] = t.c.y-t.b.y;
   r[0].v[1] = t.b.x-t.c.x;
   /* altura pel vèrtex B */
   r[1].p.x = t.b.x;
   r[1].p.y = t.b.y;
   r[1].v[0] = t.a.y-t.c.y;
   r[1].v[1] = t.c.x-t.a.x;
   /* altura pel vèrtex C */
   r[2].p.x = t.c.x;
   r[2].p.y = t.c.y;
   r[2].v[0] = t.b.y-t.a.y;
   r[2].v[1] = t.a.x-t.b.x;

   return r;
}


/* intersecció de dues rectes en forma paramètrica
      r: x = rp0 + t rv0, y = rp1 + t rv1
      s: x = sp0 + t sv0, y = sp1 + t sv1
eliminant t de r:    (x-rp0) / rv0  =  (y - rp1) / rv1   
eliminant t de s:    (x-sp0) / sv0  =  (y - sp1) / sv1 
cal resoldre, doncs, el sistema lineal 2x2 en les incògnites x, y:
   rv1  -rv0  |  rp0*rv1 - rp1*rv0 
   sv1  -sv0  |  sp0*sv1 - sp1*sv0 
sigui den = rv0*sv1 - rv1*sv0
si den = 0 llavors no hi ha solució única (paral·leles o iguals)
en el cas den != 0, la solució única és
   x = ( rv0*(sp0*sv1 - sp1*sv0) - sv0*(rp0*rv1 - rp1*rv0) ) / den
   y = ( rv1*(sp0*sv1 - sp1*sv0) - sv1*(rp0*rv1 - rp1*rv0) ) / den
*/
int intersec2rectes(recta r, recta s, punto *p) {
   float den, aux1, aux2;

   den = r.v[0]*s.v[1]-r.v[1]*s.v[0];

   if (fabs(den) < tol) {
      printf("rectes paral·leles! \n");
      return 1;

   } else {
      aux1 = s.p.x*s.v[1]- s.p.y*s.v[0];
      aux2 = r.p.x*r.v[1]- r.p.y*r.v[0];
      p->x = (r.v[0]*aux1-s.v[0]*aux2)/den;
      p->y = (r.v[1]*aux1-s.v[1]*aux2)/den;
      return 0;
   }
}

/* escriptura d'una recta en forma paramètrica */
void escriure1recta(char * nom, recta r) {

   printf("%s: (%+.4f, %+.4f) + t(%+.4f, %+.4f) \n",
           nom, r.p.x, r.p.y, r.v[0], r.v[1]);

   return;
}

/* escriptura d'un punt */
void escriure1punt(char * nom, punto p) {

   printf("%s: (%+.4f, %+.4f) \n", nom, p.x, p.y);

   return;
}



