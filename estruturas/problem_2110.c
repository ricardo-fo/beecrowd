#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int qtd, l, e;
    while(1) {
        if (scanf("%d %d %d", &qtd, &l, &e) == EOF) break;
        int idx = -1, d = l + e;
        double maesq = 0, madir = 0;
        double * prs = (double*)malloc(sizeof(double));

        for(idx = 0; idx < qtd; idx++) { // popula as alturas e encontra o jardim
            prs = (double*)realloc(prs, (idx + 1) * sizeof(double));
            scanf("%lf", &prs[idx]);
            if (prs[idx] == 0) break;
        }

        for(int i = 0; i < idx; i++) { // começo até o jardim
            double ang = atanf(prs[i] / ((idx - i) * d));

            if (ang >= maesq) maesq = ang;
        }

        free(prs);

        double aux;
        for(int i = idx + 1; i < qtd; i++) { // jardim até o final
            scanf("%lf", &aux);
            double ang = atanf(aux / ((i - idx) * d));

            if (ang >= madir) madir = ang;
        }

        double value = round((960.0 - (960.0 / 3.14159265358979323846) * (maesq + madir)) * 100) / 100;
        printf("%0.2f\n", value);
    }

    return 0;
}