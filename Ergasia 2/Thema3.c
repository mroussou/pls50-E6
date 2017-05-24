//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 3                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define TEST  => Briskei ek twn proterwn ta SETS gia na dokimasoume an leitoyrgei kala to paixnidi.
// if not defined TEST -> Normal Game
//#define MYTEST   // UNCOMMENT gia na emfanisi oles tis triades me ta SET
#define MYCARDS 81
#define PAIKTES 3

/* Oi 4 idiothtes pou exei h kathe karta */
typedef struct {
    char    xrwma,sxhma,arithmos,yfh;
} SetCards;

/* Oi syntetagmenes  gia na kathorisei mia korta */
typedef struct {
    int x,y;    /*(grammi 0 ews 2) - (stili 0 ews 3) */
} Points;

/* H dom;h pou apothikevob=ntai ta stoixeia kaathe paikth */
typedef struct {
    char    id;     /* To id tou kathe Paikth */
    int     score;  /* Edv apothikeuetai to skor tou kathe paikth */
    char    name[17];   /* kai edw apothikeuetai to onoma */
} SetPaiktes;

void print_full_array(SetCards *myCard);
void swap (SetCards *a, SetCards *b);
void randomize ( SetCards *arr, int CARDS );
void epilexe(int *pinakas);
int getNextCard(int *pinakas,int epilexthikan);
void emfanisePlegma(SetCards *arr, int *p);
int einaiSet(SetCards *mySet,int *p, Points *sel);
int choose_Paikth(SetPaiktes *Paikths);
void diabase_3_cards(Points *my3Choices);

int main()
{
SetPaiktes setPaikths[PAIKTES]; // Gia na apothikeuthoun ta stoixeia twn paiktwn
Points myPoints[3];             // gia na apothikeutoun ta x,y twn triwn kartwn
                                // pou manteuei o paikths gia SET

SetCards    myCards[3][3][3][3];    // oi 81 kartes me 4 idiothtes oi kathe mia
// arxikopoihseis idiothtwn gia na dhmiourgisoume tis 81 kartes.
char xrwma[3]   ={'r','g','b'};     // xrwma[0]=red, xrwma[1] = green kai xrwma[2]=blue
char sxhma[3]   ={'c','t','r'};     // antistoixa gia to sxhma
char arithmos[3]={'1','2','3'};     // touw arithmous
char yfh[3]     ={'b','h','e'};     // kai h idiothta tis yfhs

int  i,j,k, i1,i2,i3,i4; // Boiyhitikes metablites

int  energos;   // O energos paikths. pithanes times einai oi 0 1 kai 2 gia tous 3 paiktes antistoixa
char x;             // boithitiki matbliti gia na diabazoume stoixeia
int  maxBathmoi, indexOfMax;
int  dwdekada[12];  // edw apothikevo tous 12 deiktes (times 0 - 80) pou epilegontai gia na brethoun SETs

    setPaikths[0].id = 'a';     // arxikopoihseis 1hs paiktrias Marinas Andreou
    setPaikths[0].score = 0;
    sprintf(setPaikths[0].name,"Marina Andreou");

    setPaikths[1].id = 'g';     // arxikopoihseis 2ou paikth
    setPaikths[1].score = 0;
    sprintf(setPaikths[1].name,"Kostas Grammenos");

    setPaikths[2].id = 'p';     // arxikopoihseis 3hs paiktrias Marias Perdika
    setPaikths[2].score = 0;
    sprintf(setPaikths[2].name,"Maria Perdika");

    // Arxikopoihseis kartwn
    for (i1=0;i1<3;i1++)    // H prwti diastasi (i1) afora to xrwma kai dinoume tis 3 idiothtes (0,1,2)
        for (i2=0;i2<3;i2++) {  // H deuteri diastasi (i2) afora to sxhma
            for (i3=0;i3<3;i3++) {  // H 3h diastasi (metavliti i3) afora ton arithmo 1 2 & 3 antistoixa.
                for (i4=0;i4<3;i4++) {  // H 4h diastasi afora tin yfh (me to i4)
                    myCards[i1][i2][i3][i4].xrwma = xrwma[i1];
                    myCards[i1][i2][i3][i4].sxhma = sxhma[i2];
                    myCards[i1][i2][i3][i4].arithmos = arithmos[i3];
                    myCards[i1][i2][i3][i4].yfh = yfh[i4];
                }
            }
        }
//    print_full_array(&myCards[0][0][0][0]); // emfanisi stin othoni gia debbuging ...

    randomize(&myCards[0][0][0][0], MYCARDS); // randomize gia na anakatepsoume tis 81 kartes
//        print_full_array(&myCards[0][0][0][0]);   // emfanise tis anakatemenes kartes
    epilexe(&dwdekada[0]);  // Tyxaia epilegoume 12 kartes apo tis 81 kai tis apothetoume ston pinaka dwdekada


    // Dialexe paikti gia arxh.
    energos = choose_Paikth( &setPaikths[0]);   // synartisi pou epistrefei 0,1 kai 2 afou diavasei to id tou paikth
    maxBathmoi = 0;

    // MAIN LOOP
    while (energos >= 0 && maxBathmoi < 10) {
    printf("paizei o paikths: %d %c %s\n",energos,setPaikths[energos].id,setPaikths[energos].name);

        emfanisePlegma(&myCards[0][0][0][0],&dwdekada[0]);   // emfanise tis 12 kartes se morfi plegmatos  stin othoni
#ifdef MYTEST                         // edw dokimazw oles tis triades gia na brw ola ta SETs
        printf("\nSET Triplets - 3 CARDS [0-81] and their (x-y) coordinates\n");
        for (i=0;i<10; i++)          // H prwth karta mporei na einai h 0 mexri kai h 10
            for (j=i+1; j<11; j++)      // H deyterh mporei na einai h i+1 mexri kai h 11
                for (k=j+1;k<12; k++) { // H 3h karta mporei na einai h epomenh ths prohgoumenhs mexri kai thn teleytaia
                        myPoints[0].x = i / 4;      // ypologise ta x,y kathe kartas:
                        myPoints[0].y = i % 4;      // To x einai to akeraio meros tou i / 4. Kathe grammi exei 4 kartes
                        myPoints[1].x = j / 4;      // Yo y einai to ypoloipo thw akeraias diaireshs i /4, dhladh i% 4
                        myPoints[1].y = j % 4;      // Omoiws gia tis alles 2 epiloges kartwn
                        myPoints[2].x = k / 4;
                        myPoints[2].y = k % 4;
                        x = einaiSet(&myCards[0][0][0][0],&dwdekada[0], &myPoints[0]);
                        if (x == 1) { // To Help - cheat - test
                            printf("*** SET: {(%d,%d),(%d,%d),(%d,%d)}\n",myPoints[0].x,myPoints[0].y,myPoints[1].x,myPoints[1].y,myPoints[2].x,myPoints[2].y);
                        }
               }
#endif // MYTEST
        diabase_3_cards(&myPoints[0]);      // diabase 3 kartes me x,y ton kathena. Dhladi 6 arithmous.
        // elenxe ean h triada tou paikth-xrhsth einai SET sta 12 epilegmena xartia
        x = einaiSet(&myCards[0][0][0][0],&dwdekada[0], &myPoints[0]);
        if (x == 1) {   // Ean einai SET (x==1) tote :
            setPaikths[energos].score += 2;   // EINAI SET. +2 monades.
            randomize(&myCards[0][0][0][0], MYCARDS); // randomize gia na anakatepsoume tis 81 kartes
//          print_full_array(&myCards[0][0][0][0]);   // emfanise tis anakatemenes kartes
            epilexe(&dwdekada[0]);  // Tyxaia epilegoume 12 kartes giati vrethike ena SET.
            printf("Sygxaritiria %s. Kerdizete 2 pontous. Epilegontai 12 nees kartes\n",setPaikths[energos].name);
            // megisti vathmologia tha exw mono meta apo epityxia. Tha elegxo gia megisto mono meta apo SET. Einai adynato diaforetika
            if (maxBathmoi < setPaikths[energos].score) {
                maxBathmoi = setPaikths[energos].score;
                indexOfMax = energos;
            }
        } else if (x == -1) {
            if (setPaikths[energos].score > 0) // To skor na meiothei mono ean einai panw apo MHDEN
                setPaikths[energos].score --;       //Den einai SET. -1 monada.
            printf("Dystyxws Den einai SET.\nSynexizetai me tis idies kartes\n");
        }   // else { brikame kapoio lathos - error code?}
        printf("Gia %c - %s\t\ttrexousa vathologia = %d\n",setPaikths[energos].id,setPaikths[energos].name,setPaikths[energos].score);
        if (maxBathmoi < 10)
            energos = choose_Paikth( &setPaikths[0]);
    }
    printf("Teliki Bathmologia :\n");
    for (i=0; i<PAIKTES; i++)     // emfanise TELIKH VATHMOLOGIA
        printf("%c - %s\t\t%d\n",setPaikths[i].id,setPaikths[i].name,setPaikths[i].score);

    if (setPaikths[energos].score>=10) {    // EAN EFTASE KAPOIOS TOUS 10 VATHMOUS NIKHSE. Mono enas mporei na o katafere.
        printf("O nikhths einai o [%s]\n",setPaikths[indexOfMax].name);
    }

    return 0;   /* to main einai integer, epistrefei oti ola EGINAN KALA = 1 */
}
/*********************************************************************************************/
// Print 81 kartes - for debugging and testing...
void print_full_array(SetCards *myCard)
{
int  i;
SetCards    *pCards;

        pCards = myCard;
        for (i=0;i<MYCARDS;i++)  // Emfanise oles tis kartes
            printf("%c%c%c%c\n",pCards[i].xrwma,pCards[i].sxhma,pCards[i].arithmos,pCards[i].yfh);
}
/*********************************************************************************************/
// Antimetathesi 2 kartwn
void swap (SetCards *a, SetCards *b)
{
    SetCards temp = *a;
    *a = *b;
    *b = temp;
}

/*********************************************************************************************/
// Dhmiourgia anadiataxis twn 81 kartwn
void randomize ( SetCards *arr, int CARDS )
{
int i,k,j;

    // Gia na mhn exoume kathe fora to idio paixnidi,  otan trexoume to programma
    srand ( time(NULL) );


    for (k=0; k<3; k++)     // Anakatepse ta 3 fores ... Dhladh:
        for (i = MYCARDS-1; i > 0; i--) {      // Xekina apo to teleutaio stoixeio kai antalaxe to me kapoio tyxaio mexri kai to 1o.
            // Dialexe ena tyxaio metaxy 0 kai i
            j = rand() % (i+1);
            // Antalaxe to i stoixeio me kapoio tyxaio (j)...
            swap(&arr[i], &arr[j]);
        }
}
/*********************************************************************************************/
// Dialexe 12 stoixeia apo ta 81 gia na emfanistoun stin othoni, wste o paikths na anazhthsei SET.
void epilexe(int *pinakas)  // Dinetai o pinakas gia na epistrafei gematos me 12 nees kartes
{
int i;
int epilexthikan;    // posoi arithmoi exoun epilexthei mexri twra

    srand ( time(NULL) );   // Neous tyxaious arithmous.

    pinakas[0] = rand() % MYCARDS;   // Dialexe mia tyxaia karta apo tis 81.
    epilexthikan = 1;           // plithos epilegmenwn = 1. Molis epilexame ton proto

    for (i=1; i<12; i++) {      // epilexe tous ypoloipous 11 arithmous ( 1 ews 11)
        pinakas[i] = getNextCard(&pinakas[0],epilexthikan);     // edw tha erthei o elegxos tou programmatos otan o x einai diaforetikos apo tous idi epilegmenous.
        epilexthikan ++;    // metra kai auton. H anazhthsh ginetai sto diasthma apo 1 mexri tous epilegmenous - oxi anamesa stous 12.
    }
}

/*********************************************************************************************/
// Synarthsh pou efmfanizei tous 12 arithmous se plegma 3 x 4
int getNextCard(int *pinakas,int epilexthikan) {
int j,x;    /* Bohthitikes */
int Brethike;       /* Flag: TRUE ean o arithmos pou epilexthike yparxei stous idi epilegmenous. */
    do {
        x = rand() % MYCARDS;    // dialegoume mia akoma karta.
        Brethike = 0;       // kai thn anazhtoume stous epilegmenous elegxontas gia diplotypa.
        j=0;
        while ((j < epilexthikan) && (Brethike == 0)) { // oso den exei brethei anamesa stous epilegmenous paxne
            if (x == pinakas[j]) {  // ean berthike tote
                Brethike = 1;       // shmeiwse to gia na dialexoume neo arithmo-karta.
            }
            j ++;                   // Synexise na elegxeis kai to epomeno stoixeio tou pinaka
        }
    } while (Brethike == 1);        // OSO epilegete arithmos pou yparxei psaxne gia kainourgio... mexri na mhn einai idios
    return x;
}

/*********************************************************************************************/
// Synarthsh pou efmfanizei tous 12 arithmous se plegma 3 x 4
void emfanisePlegma(SetCards *arr, int *p)
{
int i,j;   // i grammes , j sthles

    for (i=0; i<3; i++) {   // se kathe mia grammi apo tis 3
        for (j=0; j<4; j++) {   // emfanise 4 stoixeia-sthles me tis 12 epilegmenes kartes.
            printf("[%c,%c,%c,%c]  ",arr[p[3*i+j]].xrwma,arr[p[3*i+j]].sxhma,arr[p[3*i+j]].arithmos,arr[p[3*i+j]].yfh);
        }
        printf("\n");
    } // plegma kartwn:
    // 0  1  2  3
    // 4  5  6  7
    // 8  9 10 11
}
/*********************************************************************************************/
//************ elegxos gia na diapistosoume ena h epilogh 3 kartwn apotelei SET.
int einaiSet(SetCards *mySet,int *p, Points *sel)
{
int i1,i2,i3;
int xrwma,sxhma,arithmos,yfh;

// metatrepoume ta 3 zeygh x,y pou epelexe o xrhsths se deiktes apo 0 ews 11 (12 kartwn) gia na elegxoume gia ean yparxei SET.
    i1 = 4*sel[0].x + sel[0].y; // kathe grammi (apo tis 3) exei 4 kartes....
    i2 = 4*sel[1].x + sel[1].y;
    i3 = 4*sel[2].x + sel[2].y;

    if (i1<0 || i1 >11 || i2<0 || i2 >11 || i3<0 || i3 >11)
            return -1;   // Lathos. Epestrepse -1. Mhpws na epistrepso kapoio error code p.x.  -2

    xrwma = -1;     // arxikh timh -1.
    if (mySet[p[i1]].xrwma == mySet[p[i2]].xrwma && mySet[p[i1]].xrwma == mySet[p[i3]].xrwma)
        xrwma = 3;  // tria idia xrwmata.
    if (mySet[p[i1]].xrwma != mySet[p[i2]].xrwma && mySet[p[i1]].xrwma != mySet[p[i3]].xrwma && mySet[p[i2]].xrwma != mySet[p[i3]].xrwma)
        xrwma = 0;  // tria diaforetika xrwmata
    if (xrwma == -1)    // Ean den exei tria idia h tria diaforetika exase. Na epistrepsei OXISET.
        return -1;

    // Synexizoume mono ean pame kala.
    sxhma = -1;     // arxikh timh -1.
    if (mySet[p[i1]].sxhma == mySet[p[i2]].sxhma && mySet[p[i1]].sxhma == mySet[p[i3]].sxhma)
        sxhma = 3;  // Tria idia sxhmata
    if (mySet[p[i1]].sxhma != mySet[p[i2]].sxhma && mySet[p[i1]].sxhma != mySet[p[i3]].sxhma && mySet[p[i2]].sxhma != mySet[p[i3]].sxhma)
        sxhma = 0;  // Tria diaforetika sxhmata.
    if (sxhma == -1) // Ean den pame kala epistrefoume -1, oti XASAME
        return -1;

    arithmos = -1;  // Ean mexri edw pame kala akoma synexizoume
    if (mySet[p[i1]].arithmos == mySet[p[i2]].arithmos && mySet[p[i1]].arithmos == mySet[p[i3]].arithmos)
        arithmos = 3;   // kai 3 arithmous idious ....
    if (mySet[p[i1]].arithmos != mySet[p[i2]].arithmos && mySet[p[i1]].arithmos != mySet[p[i3]].arithmos && mySet[p[i2]].arithmos != mySet[p[i3]].arithmos)
        arithmos = 0;   // 3 diaforetikoi aritmoi
    if (arithmos == -1) // Ean den exoume 3 h 0 tote xasame.
        return -1;      // epistrofh -1 ean phgame kala sta xrwmata kai sto sxhma kai xasame stoyw arithmous.
    // Ean phgame kala se xrwmata, sxhma kai arithmous tote elegxoume kai thn yfh.
    yfh = -1;   // arxika thewrw oti den brhka tipota
    if (mySet[p[i1]].yfh == mySet[p[i2]].yfh && mySet[p[i1]].yfh == mySet[p[i3]].yfh)
        yfh = 3;    // Ean brhka 3 idia tote ftanoume sto SET
    if (mySet[p[i1]].yfh != mySet[p[i2]].yfh && mySet[p[i1]].yfh != mySet[p[i3]].yfh && mySet[p[i2]].yfh != mySet[p[i3]].yfh)
        yfh = 0;    // Ean brhka 3 diaforetika tote exoume SET.
    if (yfh == -1)  // edw exoume xasei
        return -1;
#ifdef MYTEST
    printf("[%c,%c,%c,%c]  ",mySet[p[i1]].xrwma,mySet[p[i1]].sxhma,mySet[p[i1]].arithmos,mySet[p[i1]].yfh);
    printf("[%c,%c,%c,%c]  ",mySet[p[i2]].xrwma,mySet[p[i2]].sxhma,mySet[p[i2]].arithmos,mySet[p[i2]].yfh);
    printf("[%c,%c,%c,%c]\n",mySet[p[i3]].xrwma,mySet[p[i3]].sxhma,mySet[p[i3]].arithmos,mySet[p[i3]].yfh);
#endif
return 1;   // SET. giati perasame apo olous tous elegxous gia 3 diaforetika h tria idia.
}

/*********************************************************************************************/
int choose_Paikth(SetPaiktes *Paikths) {
char x; // o xarakthras gia to id tou paikth
short i;
    // Odhgies kai plhrofories
    printf("\n");
    for (i=0; i<PAIKTES; i++)
        printf("%c ",Paikths[i].id);
    printf("\n");
    printf("Parakalw Pliktrologhste to id sas gia na synexisete...\n");
    do {
        scanf("%c",&x); // diavase id  (char) paikth
        if (x == '0')   // Ean einai 0, tote epistrofh gia termatismo paixnidiou.
            return -1;  // RETURN -1 gia TERMATISMO
        for (i=0; i<PAIKTES; i++) // Anazhthse poios apo tous 3 paiktes plhktrologhse to 'id' tou
            if (x == Paikths[i].id) // Ean brw to id, tote episterfw ton atistoixo dikti (0 1 h 2).
                return i;       // epestrepse to index tou id.
    } while (1);        // gia panta mexri na epilegei pextis h na stamathsei to paixnidi.
}

/*********************************************************************************************/
void diabase_3_cards(Points *my3Choices) {
int i,j, xval, yval,ok;
//char x,y;

    printf("Pliktrologhse 6 arithmous (=3 zeugh me x(0-1-2) ,y(0-1-2-3):\nkathe fora apo ena arithmo:\n");
    for (i=0; i<3; i++) {   // DIAVASE 3 ZEYGH (x,y)
      do {
        do {    // Diavase To x, me elegxo gia swsth grammh : 0 1 2
            scanf("%d",&xval);  // xrhsimopoihse thn scanf h thn getc ...
//            x = getc(stdin); xval = x - '0';
        } while (xval != 0 && xval != 1 && xval != 2);
        do {    // Diavase to y me elegxo gia swsth sthlh 0 1 2 3
            scanf("%d",&yval);
//            y = getc(stdin); yval = y - '0';
        } while (yval != 0 && yval != 1 && yval != 2 && yval != 3);
//        xval = x - '0';
//        yval = y - '0';
        ok = 1; // YPOTHETW OTI DEN EINAI DIPLOTYPO KAI EPEITA PSAXNW...
        for (j=0; j<i; j++) // Psaxe kathe zeugos pou diavazeis na vevaiothoume oti den yparxei pali.
            if (xval == my3Choices[j].x && yval == my3Choices[j].y) {   // Ean to zeygos yparxei tote
                ok = 0;     // akyrwse to gia na xanadiavaseis allo, diaforetiko.
                break;      // Ean vrethike idio tote stamata thn anazhthsh.
            }
        if (ok==1) {    // ean den vrethike idio tote apothikeyse to zeygos san katalili epilogh tou xrhsth
            my3Choices[i].x = xval; // apothikeyse to x kai
            my3Choices[i].y = yval; // to y
        }
      } while (ok == 0);    // mexri na apothikeyseis katallilo zeugos (OXI DIPLOTYPA)
      printf("epilegthike h karta [%d, %d]\n",my3Choices[i].x,my3Choices[i].y);
    } // diabase 3 zeygh.
    printf("\n");
}
