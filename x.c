#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
enum simbG{
S,C,B,L,E,T,F,M,N,v,i,a,f,p,e,w,d,o,c,m,t,n,s,q
};
struct {
char terminalOrigem[21];
int terminal;
} tabNomeTerm[12] = {
{"if",i},{"(",a},{")",f},{";",p},
{"else",e},{"while",w},{"do",d},{"{",o},{"}",c},
{"+",m},{"*",t},{"=",s}};
char cadeia [21];
char * aptCadeia = &cadeia[0];


/*
esse main vai ser substituido pelo compilador
ele somente testa se os tokens vem sendo sendo gerados corretamente
*/
main () {
int tok191;
int k, l;
while (1) {
	tok191 = yylex();
	if (tok191 == q){
		printf ("\nfim normal do programa \n");
		exit(0);
	}; // fim do fonte
	if (tok191 == v)
		printf("\nfoi lida a variavel: %s", aptCadeia);
	else
		if (tok191 == n)
			printf("\nfoi lida a constante numerica : %s",aptCadeia);
		else { //vai ser tentada a busca porreservadas/delimitadores/operadores
			for(k = 0; k < 12; k++)
				if (tok191 == tabNomeTerm [k].terminal){
				printf("\nfoi lido o terminal: %s",tabNomeTerm[k].terminalOrigem);
				break; //encontrou um terminal e vai continuar o while
			}; // sucesso na busca por reservadas/delimitadores/operadores
		if (k == 12) // terminou for e busca fracassada? assim mesmo continua busca no loop do while
				printf("%s\n",cadeia);
		}; // else de tentativa de encontrar reservada/delimitador/operador
			//fim do if (tok191 == v) para continuar a ler o fonte
	};// while (1);
} // main
