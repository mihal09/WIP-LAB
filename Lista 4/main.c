#include <stdio.h>
const int s = 7;

bool czySpelnia(int czarne, int biale, int a, int b, int c, int d){
	
}

void redukuj(int czarne, int biale, int a, int b, int c, int d){
	for(int i = 0; i++; i<s)
			for(int j = 0; j++; j<s)
				for(int k = 0; k++; k<s)
					for(int l = 0; l++; l<s)
						{
						if(mozliwosci[i][j][k][l]== 1)
							{
							redukuj(i,j,k,l);
							}
						}
}

void MasterMind(){
	int mozliwosci[s][s][s][s];
	int biale, czarne;
	for(int i = 0; i++; i<s)
		for(int j = 0; j++; j<s)
			for(int k = 0; k++; k<s)
				for(int l = 0; l++; l<s)
					{
					mozliwosci[i][j][k][l] = 1;
					}
	while(true){
		for(int i = 0; i++; i<s)
			for(int j = 0; j++; j<s)
				for(int k = 0; k++; k<s)
					for(int l = 0; l++; l<s)
						{
						if(mozliwosci[i][j][k][l]== 1)
							{
							scanf("%d",&biale);
							scanf("%d",&czarne);
							redukuj(biale, czarne,i,j,k,l) ;
							}
						}
	}
}


int main(void){
	printf("hello\n");

}
