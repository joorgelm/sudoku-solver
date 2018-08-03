// ALUNO: JORGE LUIS MELGAREJO RA:201519050011 - TRABALHO DE PROG2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MAX 16

typedef struct{
	int value;
}cel;

// esse metodo recebe o indice da linha e da coluna que estou buscando o elemento
// caso o mesmo ja exista na linha ou na coluna, retorno 1
// senao retorno 0
// x e y sao os indices de linha e coluna
// n é o elemento
int search_lc(cel tab[MAX][MAX], int y, int x, int n){
  for(int i = 0; i<MAX; i++){

  	if(n == tab[i][y].value || n == tab[x][i].value){
  		return 1;
  	}
  }
  return 0;
}

// funcao recebe um numero e coordenadas iniciais dos quadrantes.
// a partir disso verifica se n já existe no quadrante
// caso retorno 1 n ja existe no quadrante
int search_n_in_quadrant(cel tab[MAX][MAX], int iy, int ix, int n){
	int t = sqrt(MAX);
	for(int y = iy; y<(iy+t); y++){
		for(int x = ix; x<(ix+t); x++){
			if(tab[x][y].value == n) return 1;
		}
	}
	return 0;
}

/*funcao verifica vai receber as coordenadas de uma celula (do zero)
descobrir o quadrante dessa celula
e verificar se n nao existe na linha, na coluna e no quadrante.
retornar 1 se tudo estiver ok;*/
bool isOk(cel tab[MAX][MAX], int y, int x, int n){
	int iy,ix;
	int t = sqrt(MAX);

	iy = (y/t)*t;
	ix = (x/t)*t;

	if(search_n_in_quadrant(tab,iy,ix,n) == 0 && search_lc(tab,y,x,n) == 0){
		return true;
	}
	return false;
}

void show(cel tab[MAX][MAX]){
	int t = sqrt(MAX);
	printf("\n");
		for(int x = 0; x<MAX; x++){
			for(int y = 0; y<MAX; y++){
				if(y == t || y == t*2 || y == t*3){
					printf(" | ");
				}
				if(tab[y][x].value < 10){ // para ficar bonitinho
					printf("  %d ",tab[y][x].value);
				}else{
					printf(" %d ",tab[y][x].value);
				}
			}
			printf("\n");
			if(MAX == 9){
				if(x == (t-1) || x == (t*2)-1 || x == (t*3)-1){
					printf("------------------------------------------ \n");
				}
			}else{
				if(x == (t-1) || x == (t*2)-1 || x == (t*3)-1){
					printf("---------------------------------------------------------------------------- \n");
				}
			}
		}
	printf("\n");
}

int goWork(cel tab[MAX][MAX],int y, int x){
	int f;
	if(y < MAX){
		if(tab[x][y].value == 0)
		{
			for(int i = 1;i<=MAX;i++){ // nada faz o for parar a nao ser outra chamada.
				if(isOk(tab,y,x,i) == true){
					tab[x][y].value = i;

					if((x+1)<MAX)
					{
						f = goWork(tab,y,x+1);
						if(f == 1){
							return 1;
						}else{
							tab[x][y].value = 0;
						}
					}
					else if((y+1)<MAX)
					{
						f = goWork(tab,y+1,0);
						if(f == 1){
							return 1;
						}else{
							tab[x][y].value = 0;
						}
					}else{
						return 1;
					}
				}
			}
			if(tab[0][0].value == 0){
				printf("NAO EXISTE SOLUCAO\n");
				return 0;
			}
		}
		else
		{
			if((x+1)<MAX){
				return goWork(tab,y,x+1);
			}else if((y+1)<MAX){
				return goWork(tab,y+1,0);
			}else{
				return 1;
			}
		}
		return 0;// caso a celula nao for preenchida eu retorno zero;
	}
	else //se y == MAX significa que terminou
	{
		return 1;
	}
}

int main(){

	cel tab[MAX][MAX];

	for(int x = 0; x<MAX; x++){
		for(int y = 0; y<MAX; y++){
			scanf("%d",&tab[y][x].value);
		}
	}

  show(tab);
  
  goWork(tab,0,0);

  show(tab);

  return 0;
}