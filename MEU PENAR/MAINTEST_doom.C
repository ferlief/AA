#include <stdio.h>

#include "GRAFO_doom.H"

int main (void)
{
	int i;
	char input;
	char no, adj[100];
	GRA_tpGrafo * graTeste;

	/* lê vértice */
	scanf ("%c", &no);
	scanf ("\n");

	/* lê lista de adjacências do vértice */
	i=0;
	do 
	{
		scanf ("%c", &input);
		adj[i] = input;
		i++;
	

	} while (input!='\n');
	adj[i] = '\0';

	GRA_CriaGrafo ( &graTeste ) ;
	printf("oi");
	GRA_PopulaGrafo ( &graTeste, no, adj ) ;


	//printf ("oi");

	return 0;
}