/* TEMA 1 TASK 1  DAN STEFANESCU 325 CB -- AA */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header1.h"

TMT* citesteMasina() {
	FILE *f = fopen("task1.in","rt");
	TMT *m=malloc(sizeof(TMT));
	int i;
	char s[100];

	(void)fscanf(f,"%d",&(m->nrStari));

//Citeste toate starile
	for(i=0;i<m->nrStari;i++) {
		(void)fscanf(f,"%s",m->stariTot[i]);
	}

//Citeste starile finale
	(void)fscanf(f,"%d",&(m->nrStariFinale));

		for(i=0;i<m->nrStariFinale;i++) {
		(void)fscanf(f,"%s",m->stariFin[i]);
	}

//Citeste stare initiala
	(void)fscanf(f,"%s",m->stareInit);

//Citeste tranzitii
	(void)fscanf(f,"%d",&(m->nrTranzitii));

	for(i=0;i<m->nrTranzitii;i++) {
		(void)fscanf(f,"%s ",m->tranzitii[i].stareCurenta);
		(void)fscanf(f,"%c ",&(m->tranzitii[i].simbol1Citit));
		(void)fscanf(f,"%c ",&(m->tranzitii[i].simbol2Citit));
		(void)fscanf(f,"%s ",m->tranzitii[i].stareUrmatoare);
		(void)fscanf(f,"%c ",&(m->tranzitii[i].simbol1Scris));
		(void)fscanf(f,"%c ",&(m->tranzitii[i].directieBanda1));
		(void)fscanf(f,"%c ",&(m->tranzitii[i].simbol2Scris));
		(void)fscanf(f,"%c ",&(m->tranzitii[i].directieBanda2));
	}

//Citeste benzi
	(void)fscanf(f,"%s",m->banda1);
	(void)fscanf(f,"%s",m->banda2);

	fclose(f);
	return m;
}
int main() {


	TMT *m=citesteMasina();
	FILE *f = fopen("task1.out","wt");


	int i;
	char stareCurenta[100];
	strcpy(stareCurenta,m->stareInit);
	int cursor1 = 1;
	int cursor2 = 1;
	int check;
	int Loop = 1;

	while(Loop) {
		check = 0;
		for(i=0;i<m->nrTranzitii;i++) {
			if(strcmp(m->tranzitii[i].stareCurenta,stareCurenta)==0) {

				if(m->banda1[cursor1]=='\0') {
					m->banda1[cursor1]='#';
				}

				if(m->banda1[cursor1]==m->tranzitii[i].simbol1Citit) {

					if(m->banda2[cursor2]=='\0') {
						m->banda2[cursor2]='#';
					}

					if(m->banda2[cursor2]==m->tranzitii[i].simbol2Citit) {
						check = 1;
						strcpy(stareCurenta,m->tranzitii[i].stareUrmatoare);
						m->banda1[cursor1] = m->tranzitii[i].simbol1Scris;
						m->banda2[cursor2] = m->tranzitii[i].simbol2Scris;

						if(m->tranzitii[i].directieBanda1=='R') {
							cursor1 = cursor1 + 1;
						}
						if(m->tranzitii[i].directieBanda1=='L') {
							cursor1 = cursor1 - 1;
						}
						if(m->tranzitii[i].directieBanda2=='R') {
							cursor2 = cursor2 + 1;
						}
						if(m->tranzitii[i].directieBanda2=='L') {
							cursor2 = cursor2 - 1;
						}

					}
				}
			}
		}


		if(check==0) {
			fprintf(f,"The machine has blocked!\n");
			fclose(f);
			free(m);
			return 0;
		}

		for(i=0;i<m->nrStariFinale;i++) {
			if(strcmp(m->stariFin[i],stareCurenta)==0) {
				Loop = 0;			
			}
		}

	}

	fprintf(f,"%s\n",m->banda1);
	fprintf(f,"%s\n",m->banda2);
	fclose(f);
	free(m);

	return 0;

}
