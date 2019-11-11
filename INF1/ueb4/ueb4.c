#include <stdio.h>
#include <math.h>

int main()
{ double p,q;
  double x1,x2; 

printf("|---------------------------------------------------------------------------|\n");
printf("| Dieses Programm loest eine quadratische Gleichung zweiten Grades:         |\n");
printf("| x^2 + p*x + q = 0                                                         |\n");
printf("|                                                                           |\n");
printf("|Geben Sie die Faktoren p und q ein:                                        |\n");
printf("|---------------------------------------------------------------------------|\n");
printf("p=  "); scanf("%lf",&p);
printf("q=  "); scanf("%lf",&q);
printf("|---------------------------------------------------------------------------|\n");
printf("|Es wird nun die quadratische Gleichung zweiten Grades                      |\n");
printf("| x^2 +%8.2lf * x +%8.2lf = 0                                           |\n",p,q);
printf("|geloest.                                                                   |\n");
printf("|                                        ________________________________   |\n");
printf("|                  1            +       /          %8.2lf^2            \\  |\n",p);
printf("|x      =      - ----- *%8.2lf-   \\  /  ------------------- - %8.2lf    |\n",p,q);
printf("| 1,2              2                 \\/            4                        |\n");
printf("|                                                                           |\n");

double dx=((pow(p,2)/4.0))-q;
x1= -(1.0/2.0)*p+sqrt(dx);
x2= -(1.0/2.0)*p-sqrt(dx);

printf("| x1=%8.2lf                                                               |\n",x1);
printf("| x2=%8.2lf                                                               |\n",x2);
printf("|---------------------------------------------------------------------------|\n");

return 0;
}
