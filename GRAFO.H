

/***** Declaracoes exportadas pelo modulo *****/

/* Tipo referencia para um grafo */

typedef struct GRA_tagGraph GRA_ttGraph ;



/************  Codigo das funcoes exportadas no modulo  *************/



int GRA_CreateGraph ( GRA_ttGraph ** pGraph, int pNumVer );




int GRA_FillGraph ( GRA_ttGraph ** pGraph, char pVer, char * pAdjVec );
