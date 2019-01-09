#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define dlugosc 4
#define s 6
#define ilosc 6*6*6*6

static bool DEBUG = true;

typedef struct {
    int kolory[dlugosc];
    bool czyMozliwy;
} Uklad;


Uklad mozliwosci[ilosc];



int ileCzarne(Uklad *wzor, Uklad *strzal){
    int ile=0;
    for(int i=0; i<dlugosc; i++){
        if(wzor->kolory[i] == strzal->kolory[i])
            ile++;
    }
    return ile;
}

int ileBiale(Uklad *wzor, Uklad *strzal){
    int ile=0;
    bool sprawdzone_kolory[s];
    for(int kolor=0; kolor<s; kolor++)
        sprawdzone_kolory[kolor]=false;

    for(int i=0; i<dlugosc; i++)
    {
        if(!sprawdzone_kolory[wzor->kolory[i]]){
            for(int j=0; j<dlugosc; j++){
                if(strzal->kolory[j]==wzor->kolory[i]){
                    ile++;
                    break;
                }
            }

            sprawdzone_kolory[wzor->kolory[i]]=true;
        }
    }

    //TO SAMO ALE INNY KOD
//    for(int kolor=0; kolor<s; kolor++){
//        for(int i=0; i<dlugosc; i++){
//            if(strzal->kolory[i]==kolor){
//                for(int j=0; j<dlugosc; j++){
//                    if(wzor->kolory[j]==kolor){
//                        ile++;
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//    }

// PRAWDZIWE ZASADY Z BIALYMI
//    for(int i=0; i<dlugosc; i++){
//        for(int j=0; j<dlugosc; j++){
//            if(strzal->kolory[i]==wzor->kolory[j]){
//                ile++;
//                break;
//            }
//        }
//    }

    ile -= ileCzarne(wzor, strzal);
    return ile;
}




bool czySpelnia(int czarne, int biale, Uklad *wzor, Uklad *strzal){
    return (ileCzarne(wzor, strzal)==czarne && ileBiale(wzor, strzal)==biale);
}

void redukuj(int biale, int czarne, Uklad *strzal){
    for(int i=0; i<ilosc; i++){
        if(mozliwosci[i].czyMozliwy){
           if(!czySpelnia(czarne, biale, &mozliwosci[i], strzal))
                mozliwosci[i].czyMozliwy = false;
        }
	}
}

int ileMozliwychKodow(){
    int ile = 0;
    for(int i=0; i<ilosc; i++)
        if(mozliwosci[i].czyMozliwy)
            ile++;
    return ile;
}

void MasterMind(){
	int tura = 1;
	bool temp_mozliwosci[ilosc];
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
        int ile_mozliwosci = ileMozliwychKodow(mozliwosci);
        if(ile_mozliwosci==0)
        {
            printf("you are cheating! \n");
            return;
        }
        int lowestIndex = 8;
        int lowestScore = (int)(pow(s,dlugosc))+1;
        if(tura!=1)
        {

            for(int i=0; i<ilosc; i++){
                int highestScore = -1;

                for(int j=0; j<ilosc; j++){
                    if(mozliwosci[j].czyMozliwy){
                        for(int k=0; k<ilosc; k++)
                            temp_mozliwosci[k] = mozliwosci[k].czyMozliwy;
                        int ile_biale = ileBiale(&mozliwosci[j], &mozliwosci[i]);
                        int ile_czarne = ileCzarne(&mozliwosci[j], &mozliwosci[i]);
                        redukuj(ile_biale,ile_czarne, &mozliwosci[i]);
                        int ile_mozliwosci = ileMozliwychKodow(mozliwosci);

                        if(ile_mozliwosci > highestScore){
                            highestScore = ile_mozliwosci;
                        }

                        for(int k=0; k<ilosc; k++)
                            mozliwosci[k].czyMozliwy = temp_mozliwosci[k];
                    }
                }
                if(lowestScore > highestScore){
                    lowestScore = highestScore;
                    lowestIndex = i;
                }
            }
        }

        if(ile_mozliwosci==1){
            for(int i=0; i<ilosc; i++){
                if(mozliwosci[i].czyMozliwy){
                    lowestIndex = i;
                    break;
                }
            }
        }

                for(int j=0; j<dlugosc; j++)
                    printf("[%d] ",mozliwosci[lowestIndex].kolory[j]+1);
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
                redukuj(biale,czarne, &mozliwosci[lowestIndex]);
                tura++;
                if(DEBUG){
                    printf("----------\n");
                    for(int i=0; i<ilosc; i++){
                        if(mozliwosci[i].czyMozliwy){
                            for(int k = 0; k<dlugosc; k++){
                                printf("[%d] ", mozliwosci[i].kolory[k]+1);
                            }
                            printf("\n");
                        }
                    }
                    printf("KONIEC TURY NR %d\n ----------\n",tura-1);
                }
	}
}


int main(void){

    MasterMind();

//  ilosc = (int)pow(s,dlugosc);
//	Uklad mozliwosci[ilosc];
//	bool temp_mozliwosci[ilosc];
//	int biale, czarne;
//	for(int i=0; i<ilosc; i++){
//        int calosc = i;
//        for(int k=0; k<dlugosc; k++){
//            mozliwosci[i].kolory[k]=calosc%s;
//            calosc/=s;
//        }
//        mozliwosci[i].czyMozliwy = true;
//	}
//    int q[] = {0,0,0,0};
//    int w[] = {3,2,1,1};
//    int e[] = {3,2,1,0};
//
//    int r[] = {1,3,2,2};
//    Uklad a = createUklad(q);
//    Uklad b = createUklad(w);
//    Uklad c = createUklad(e);
//    Uklad wzor = createUklad(r);
//    printf("XD %d - %d\n",ileBiale(wzor,c),ileCzarne(wzor,c));
//    redukuj(0,0,mozliwosci, a);
//    redukuj(4,0,mozliwosci, b);
//    printf("ILE 2 : %d\n",ileMozliwychKodow(mozliwosci));
////    for(int i=0; i<ilosc; i++){
////                    if(mozliwosci[i].czyMozliwy)
////                        printf("[%d] [%d] [%d] [%d]\n",mozliwosci[i].kolory[0],mozliwosci[i].kolory[1],mozliwosci[i].kolory[2],mozliwosci[i].kolory[3]);
////    }
//    redukuj(3,0,mozliwosci, c);
//   printf("ILE 3 : %d\n",ileMozliwychKodow(mozliwosci));
////    printf("------------------\n");
////    redukuj(0,0,mozliwosci, strzal);
////    printf("ILE 2 : %d",ileMozliwychKodow(mozliwosci));
////        printf("SPELNIA\n");
//   // printf ("na swoim: %d, nie na swoim: %d\n",ileCzarne(wzor, strzal),ileBiale(wzor, strzal));
//    Uklad a,b;
//
//    a.kolory[0] = 1;
//    a.kolory[1] = 1;
//    a.kolory[2] = 2;
//    a.kolory[3] = 2;
//
//    b.kolory[0] = 1;
//    b.kolory[1] = 2;
//    b.kolory[2] = 3;
//    b.kolory[3] = 3;

   // 1233
   // 1122
//    int biale = ileBiale(&b,&a);
//    int czarne = ileCzarne(&b,&a);
//
//    printf("XD biale-czarne: %d - %d\n",biale,czarne);



}
