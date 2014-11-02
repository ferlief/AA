

/***** Declaracoes exportadas pelo modulo *****/

typedef struct tagVerGraph GRA_ttVerGraph;


/* Tipo referencia para um grafo */

typedef struct GRA_tagGraph GRA_ttGraph ;



/************  Codigo das funcoes exportadas no modulo  *************/



int GRA_CreateGraph ( GRA_ttGraph ** pGraph, int pNumVer );


int GRA_FillGraph ( GRA_ttGraph ** pGraph, char pVer, char * pAdjVec );


int GRA_FindVerGraph ( GRA_ttGraph ** pGraph, char pVertex, int * pInd);

int GRA_RetTotalVer ( GRA_ttGraph ** pGraph, int pRet );

int GRA_RetTamVecAdj ( GRA_ttGraph ** pGraph, int pInd, int * pRet );

int GRA_RetVerInd ( GRA_ttGraph ** pGraph, int pInd, char * pRet );

int GRA_RetEleAdj ( GRA_ttGraph ** pGraph, int pIndNo, int pIndAdj, char * pRet );