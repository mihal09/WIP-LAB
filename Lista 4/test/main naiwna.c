#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define dlugosc 4
const int s = 6;



int ilosc;
typedef struct {
    int kolory[dlugosc];
    bool czyMozliwy;
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
            if(strzal.kolory[i]==wzor.kolory[j]){
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

void redukuj(int biale, int czarne,  Uklad mozliwosci[], Uklad wzor){
    for(int i=0; i<ilosc; i++){
        if(mozliwosci[i].czyMozliwy){
//            int noweBiale = ileBiale(wzor, mozliwosci[i]);
//            int noweCzarne = ileCzarne(wzor, mozliwosci[i]);
//            printf("[%d] [%d] [%d] cz:%d b:%d\n",mozliwosci[i].kolory[0],mozliwosci[i].kolory[1],mozliwosci[i].kolory[2], noweCzarne, noweBiale);
            if(!czySpelnia(czarne, biale, mozliwosci[i], wzor))
                mozliwosci[i].czyMozliwy = false;
        }
	}
}

void MasterMind(){
	//int mozliwosci[s][s][s][s];
    ilosc = (int)pow(s,dlugosc);
	Uklad mozliwosci[ilosc];
	Uklad temp_mozliwosci[ilosc];
	int biale, czarne;
	for(int i=0; i<ilosc; i++){
        int calosc = i;
        for(int k=0; k<dlugosc; k++){
            mozliwosci[i].kolory[k]=calosc%s;
            calosc/=s;
        }
        mozliwosci[i].czyMozliwy = true;
	}

	while(true){
        bool czyOszukuje =true;
		for(int i=0; i<ilosc; i++){
            if(mozliwosci[i].czyMozliwy){
                for(int j=0; j<dlugosc; j++)
                    printf("[%d]",mozliwosci[i].kolory[j]);
                printf("?\n");
                printf("white: ");
                scanf("%d",&biale);
                printf("black: ");
                scanf("%d",&czarne);
                if(czarne==dlugosc)
                {
                    printf("I win\n");
                    return;
                }
                redukuj(biale,czarne,mozliwosci, mozliwosci[i]);
                printf("----------\n");
                for(int i=0; i<ilosc; i++){
                    if(mozliwosci[i].czyMozliwy)
                        printf("[%d] [%d] [%d] [%d]\n",mozliwosci[i].kolory[0],mozliwosci[i].kolory[1],mozliwosci[i].kolory[2],mozliwosci[i].kolory[3]);
                }
                printf("----------\n");
                czyOszukuje = false;
                break;
            }
        }

        if(czyOszukuje){
            printf("you are cheating! \n");
            return;
        }

	}
}


int main(void){

//    int a[] = {0,2,1};
//    int b[] = {0,0,0};
//    Uklad wzor = createUklad(a);
//    //printf("%d\n",wzor.kolory[2]);
//    Uklad strzal = createUklad(b);
//    printf ("na swoim: %d, nie na swoim: %d\n",ileCzarne(wzor, strzal),ileBiale(wzor, strzal));
    MasterMind();

}
