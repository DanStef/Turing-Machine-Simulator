typedef struct {
	char stareCurenta[150];
	char simbol1Citit;
	char simbol2Citit;
	char stareUrmatoare[150];
	char simbol1Scris;
	char simbol2Scris;
	char directieBanda1;
	char directieBanda2;
}TTranzitie;


typedef struct {
	int nrStari;
	char stariTot[1050][150];
	int nrStariFinale;
	char stariFin[1050][150];
	char stareInit[150];
	int nrTranzitii;
	char banda1[1050];
	char banda2[1050];
	TTranzitie tranzitii[10050];
}TMT;

