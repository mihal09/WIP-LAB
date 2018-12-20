#include <stdio.h>
#include <stdbool.h>
const int s = 7;
#define dlugosc 4

typedef struct {
    int kolory[dlugosc];
    bool czyMozliwy = false;
} Uklad;

Uklad createUklad(int kolory[]){
    Uklad uklad;
    for(int i=0; i<dlugosc; i++){

        uklad.kolory[i] = kolory[i];
    }
    return uklad;
  }

//Uklad createUklad(int a,b,c,d){
//    Uklad uklad;
//    uklad.kolory[0] = a;
//    uklad.kolory[1] = b;
//    uklad.kolory[2] = c;
//    uklad.kolory[3] = d;
//    return uklad;
//  }

int ileCzarne(Uklad wzor, Uklad strzal){
    int ile=0;
    for(int i=0; i<dlugosc; i++){
        if(wzor.kolory[i] == strzal.kolory[i])
            ile++;
    }
    return ile;
}

int ileBiale(Uklad wzor, Uklad strzal){
    int ile=0;
    for(int i=0; i<dlugosc; i++){
        for(int j=0; j<dlugosc; j++){
            if(i != j && strzal.kolory[i]==wzor.kolory[j]){
                ile++;
                break;
            }
        }
    }
    ile -= ileCzarne(wzor, strzal);
    return ile;
}




bool czySpelnia(int czarne, int biale, Uklad wzor, Uklad strzal){
    return (ileCzarne(wzor, strzal)==czarne && ileBiale(wzor, strzal)==biale);
}

void redukuj(int czarne, int biale, int a, int b, int c, int d){
	for(int i = 0; i++; i<s)
			for(int j = 0; j++; j<s)
				for(int k = 0; k++; k<s)
					for(int l = 0; l++; l<s)
						{
//						if(mozliwosci[i][j][k][l]== 1)
//							{
//							redukuj(i,j,k,l);
//							}
						}
}

void MasterMind(){
	//int mozliwosci[s][s][s][s];
	int ilosc = (int)pow(s,dlugosc);
	Uklad mozliwosci[ilosc];
	int biale, czarne;
	for(int i = 0; i++; i<s)
		for(int j = 0; j++; j<s)
			for(int k = 0; k++; k<s)
				for(int l = 0; l++; l<s)
					{
					mozliwosci[s][s][s][s].kolory[0];
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
							redukuj(biale, czarne,i,j,k,l);
							}
						}
	}
}


int main(void){
	printf("hello\n");
    int a[] = {1,2,3,2};
    int b[] = {4,2,1,3};
    Uklad wzor = createUklad(a);
    //printf("%d\n",wzor.kolory[2]);
    Uklad strzal = createUklad(b);
    printf ("na swoim: %d, nie na swoim: %d\n",ileCzarne(wzor, strzal),ileBiale(wzor, strzal));


}
