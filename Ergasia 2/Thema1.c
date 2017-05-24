//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 1                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>  /* logw printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* logw exit() */
#include <string.h>

/* H domh dedomenwn Gia kathe epiati */
   typedef struct {
       unsigned char *name;
       unsigned short *tel;
       unsigned int seatNo;
   } aBus;

/* Voithitikes metavlites gia proswrinh apothikeush plhroforias kai elegxou gia pereterw xrhsh */
/* Oi parakatw metablhtest tha mporousan na dhlothoun topika se kathe synarthsh opou xreiazontan */
/* alla gia genikh xrhsh mporoun na dhlwthoun kai edw. */
unsigned char * nameTemp1;
unsigned char * nameTemp2;
unsigned char * nameTemp;
unsigned short * telTemp;
unsigned int seatNoTemp;

int main()
{
   aBus *myBus;     /* O kyriws pinakas gia tous epivates tou leofwreiou. Edw einai monon o pointer */

    int     x,charsRead;        /* Voithikes. Xrhsimopoiountai sthn scanf gia diavasma xarakthrwn */
    int     theseis, reserved;  /* plithos synolikwn thesewn leoforeiou kai Krathmenes theseis (reserved) */


   FILE* f_in, *f_out;        /* metablites-deiktes se arxeio */
   char license[8];           /* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
   int seats;                 /* plithos thesewn */
   int i,j, choice, myCount;      /* boithitikes metablites */

    theseis = 53;   /* Arxikopoihsh stis 53 theseis */
    reserved = 0;   /* Arxikopoihsh stis 0 kathlimenes theseis */
    myBus = (aBus *)malloc(theseis*sizeof(aBus));    /* Allocate memory gia toys ypopsifious epibates leoforeiou */
    if (myBus == (aBus *)NULL) {    /* Ean den egine h desmefsi tis mnimis prepei na stamatisoume... */
        printf("Memory can not be allocated. Exiting...");
        exit(1);    /* kai na bgoume apo to programma me mymhma Lathous. */
    }
    for (i=0; i<53; i++) {  /* Gia kathe thesi desmeuse mnhmh gia ta stoixeia ywn epivatwn */
        myBus[i].name = (unsigned char *)malloc(41*sizeof(unsigned char));  /* 41 aprosimous chars gia kathe onomatepwnymo */
        myBus[i].tel  = (unsigned short *)malloc(11*sizeof(unsigned short));    /* 11 u-char gia kathe tlefwno )mazi me EOS */
        if ((myBus[i].name == (unsigned char *)NULL) || (myBus[i].tel  == (unsigned short *)NULL)) { /* Ean den egine h desmeush mnhmhs ..*/
            printf("No memory allocated. Exiting..."); /* Den mporoume na synexisoume. Eidopoioume kai kleinoume */
            exit(1);
        }
        myBus[i].seatNo = 0;  // Adeia Thesi
    }

/* Desmeush Mnhmhs gia tis proswrines metabltes. */
    nameTemp1 = (unsigned char *)malloc(41*sizeof(unsigned char));
    nameTemp2 = (unsigned char *)malloc(41*sizeof(unsigned char));
    nameTemp = (unsigned char *)malloc(41*sizeof(unsigned char));
    telTemp =(unsigned short *)malloc(11*sizeof(unsigned short));
    if (nameTemp1 == NULL || nameTemp2 == NULL || nameTemp == NULL || telTemp == NULL) { /* Ean den egine h desmeush mnhmhs ..*/
        printf("No memory allocated. Exiting..."); /* Den mporoume na synexisoume. Eidopoioume kai kleinoume */
        exit(1);
    }

    readfromFileOldData(&myBus[0], &theseis, license, &reserved); /* diavazei ta stoixeia tou file "bus.txt" */
    seats = theseis;    /* Oi theseis pithanon na mhn exoun thn megisth timh LEOFOREIWN pou einai 53 */
    printf("%s %d\n", license, seats); /* ektypwsi pinakidas kai plithous thesewn */

    choice = 1; /* arxiki timi gia eisodo sto loop */
    while (choice != 0) { /* mexri na epilegei termatismos */
      printf("1. emfanish synolikoy plhthous kenwn thesewn kai taxinomhmenhs listas twn arithmwn  tous\n");
      printf("2. krathsh theshs me sygkekrimeno arithmo\n");
      printf("3. anazhthsh gia to an einai krathmenh thesh me sygkekrimeno onomatepwnymo h thlefwno\n");
      printf("4. akyrwsh krathshs theshs me sygkekrimeno arithmo\n");
      printf("5. emfanish listas krathmenwn thesewn taxinomhmenhs kata arithmo theshs\n");
      printf("0. termatismos\n");
      scanf("%d", &choice); printf("Epilogi: %d\n",choice);
      switch(choice) {  /* Gia kathe epilogh kaleitai katalili synarthsh gia na oloklhrwsh thn antistoixh diadikasia */
        case 1: /* pername deikti twn stoixeiwn tou leoforeiou gia epexergasia tous. Epishs pername kai to plhthos thesewn
            kathws kai tp p;hthos twn thesewn pou exoun kraththei.*/
            emfanishKenwn(&myBus[0], theseis, reserved);
            break;
        case 2:     /* Ean epilegxthike to 2 gia krathsh me arithmo thesis... */
            krathshArithmhmenhsTheshs(&myBus[0], theseis, reserved);
           break;
        case 3:     /* Anazhthsh me bash to onomatepwnymo h to thlefwno ston pinaka thesewn */
            Search(&myBus[0],theseis,reserved);
           break;
        case 4: /* Diabase ariyhmo thesis gia akyrwsh krathshs */
            printf("dwse arithmo thesis gia akyrwsh\n");
            scanf("%d", &i);
            AkyrwshKrathshs(&myBus[0],theseis, i);
           break;
        case 5: /* Emfanise katastash me theseis pou exoun kraththei. */
            emfanishListasThesewn(&myBus[0],theseis);
        break;
        case 0:  /* min kaneis tipote */
           break;
        default:
           printf("akatallili epilogi\n");
      }
    }
    /* Store updated data to File "bus.txt" */
    updateFileWithNewData(&myBus[0], theseis,&license);

    /* free allocated memory, Gia kathe thesi tou leoforiou */
    for (i=0; i<53; i++) {
        free(myBus[i].name);
        free(myBus[i].tel);
    }
    /* Eleutherwse kai tous pointers twn 53 thesewn  */
    free(myBus);

    /* Eleutherwse kai thn mnhmh twn proswrinwn metablhtwn */
    free(nameTemp2);
    free(nameTemp1);
    free(nameTemp);
    free(telTemp);
}
/******************************************************************************/
/*              FUNCTIONS                                                     */
/******************************************************************************/

void emfanishKenwn(aBus *myBus,int theseis,int reserved){
int i;

    printf("\nPlithos kenwn Thesewn: %d\n",theseis - reserved);
    printf("Lista Kenwn Thesewn : ");
    for (i=0; i<theseis; i++)   /* Gia kathe thesitou leoforeiou ... */
        if (myBus[i].seatNo == 0)   /* Ean einai kenh */
                printf(" %d", i+1); /* emfanise ton arithmo ths */
        printf("\n\n");
}

/******************************************************************************/
void krathshArithmhmenhsTheshs (aBus *myBus,int theseis,int reserved){
short x;

    printf("dwse arithmo thesis\n");
    scanf("%d", &x);        /* diabase ena arithmo pou antistoixei se arithmo thesis. */
    if (x<1 || x>theseis) // elegxos oti arithmos thesis entos oriwn
        printf("arithmos thesis ektos oriwn\n");
    else if (myBus[x-1].seatNo == 0) {// an einai eleutheri
        printf("Dwste epwnymo: ");
        scanf("%s",nameTemp1);  /* Diabase epwnymo */
        printf("Dwste onoma: ");
        scanf("%s",nameTemp2);  /* Diavase onoma */
        printf("Dwste Thlefwno: ");
        scanf("%s",telTemp);    /* Diavase thlefwno */
        if (strlen(nameTemp1) + strlen(nameTemp2) <= 40  && sizeof(telTemp)<=10) {  /* Mexri 40 xarakthres epitrepete */
            sprintf(myBus[x-1].name,"%s %s",nameTemp1,nameTemp2); /* metefere onoma kai epwnymo sto domh dedomenwn tou leoforeiou */
            myBus[x-1].seatNo = x;  /* ekxwrhse to x sth hesi mnhhs tou */
            strcpy(myBus[x-1].tel,telTemp); /*  */
        } else { /* Ean einai panw apo 40 xarakthres den xwraei, mhn kaneis tipotw */
            printf("Lanthasmena stoixeia. Den egine Kratisi. Ean epithimeite prospatheiste pali.\n");
        }
    } else
    printf("thesi idi kateilhmmeni\n");
}

/******************************************************************************/
void Search(aBus *myBus,int theseis,int reserved) {
short i,x, choice;

    printf("1. gia eisagwgi epwnymou kai onomatos\n");
    printf("2. gia eisagwgi thlefwnou\n");
    printf("Me allo arithmo epistrofi sto kentriko menu.\n");
    scanf("%d", &choice); printf("Epilogi: %d\n",choice);   /* epilexe anazhthsh me onomatepwnymo h thlefwno */
    if (choice == 1) {
        printf("Dwste epwnymo: ");
        scanf("%s",nameTemp1);  /* Diavase epwnymo */
        printf("Dwste onoma: ");
        scanf("%s",nameTemp2);  /* diabase kai onoma */
        sprintf(nameTemp,"%s %s",nameTemp1,nameTemp2);  /* kai dhmiourghse ena alfarithimiko (me ena keno) gia anazhthsh */
        printf("Searching ...\n");
        x = 0;      /* x= 0 => Den vrethike to zhtoumeno onoma */
        for (i=0; i<theseis;i++) {      /* elegxe kathe thesi tou leofwreiou ... */
            if (myBus[i].seatNo > 0 ) { /* pou den einai adeia */
                if (strcmp(myBus[i].name,nameTemp)==0) {    /* Ean brisketai to zhtoumeno onoma ekei tote ... */
                    x = 1;                                  /* shmeiwse oti vrethike kai */
                    printf("Brethike stin thesi %d\n",myBus[i].seatNo); /* deixto sthn othoni */
                    break;
                }
            }
        }
        if (x == 0)     /* Ean den brethike tote anafere sthn othoni to apotelesma */
            printf("Den yparxei Epivaths me to onoma <%s>",nameTemp);
    } else if (choice == 2) {
        /* anazhthsh me bash to thlefwno */
        printf("Dwste Thlefwno: ");
        scanf("%s",telTemp);
        x = 0;      /* Den Vrethike */
        for (i=0; i<theseis;i++) {      /* gia kathe thesi tou leoforeiou */
            if (myBus[i].seatNo > 0 ) { /* pou den einai adeia */
                if (strcmp(myBus[i].tel,telTemp)==0) {  /* Ean yparxei to thlefwno se kapoia thesi */
                    printf("Brethike stin thesi %d\n",myBus[i].seatNo); /* anafere oiti Brethike */
                    x = 1; /* kai shmeiwse oti Vrethike */
                    break;
                }
            }
        if (x == 0)
            printf("Den yparxei Epivaths me to Thlefwno <%s>",telTemp);
        }
    } else {    /* ean the epilegxthike anazhthsh me onoma (1) h thlefwno (2) epestrepse sto kyriws menou */
        printf("H diadikasia anazhthshs akyrwnetai. Epistrofh sto kyrio menu.\n");
    }
}

/******************************************************************************/
void AkyrwshKrathshs(aBus *myBus,int theseis, int giaAkyrwsh) {
    if (giaAkyrwsh<1 || giaAkyrwsh>theseis)   /* elegxos oti arithmos thesis entos oriwn */
        printf("arithmos thesis ektos oriwn\n");
    else if (myBus[giaAkyrwsh-1].seatNo != 0) { /* an thesi kratimeni */
        myBus[giaAkyrwsh-1].seatNo = 0;    /* apodesmeuse tin */
        printf("thesi apodesmeutike\n");
    } else
        printf("thesi idi eleutheri\n");
}

/******************************************************************************/
void emfanishListasThesewn(aBus *myBus,int theseis){
short   i;

    for(i=0; i<theseis; i++)
        if (myBus[i].seatNo > 0 )
            printf("Thesi %d - %s %s\n",myBus[i].seatNo,myBus[i].name,myBus[i].tel);
}

/******************************************************************************/
void readfromFileOldData(aBus *myBus, int *theseis, char *license, int *reserved) {
FILE *f_in;        /* metablith-deikths se arxeio */
short   i, plhthos, x, charsRead;

   f_in = fopen("bus.txt", "r"); /* Anoigei to arxeio eisodou*/
   if(f_in == NULL) /* se periptwsi problimatos kata to anoigma */
   {
      printf("To arxeio bus.txt de mporese na anoixthei gia anagnwsh.\n");
      exit(1);      /* ejodos apo to programma */
   }
   fscanf(f_in,"%s %u", license, &plhthos); /* Diabase ton Arithmo kykloforias kai to plhyhos Thesewn tou Leoforeiou */

   if (plhthos >= 5 && plhthos <= 53) /* Theoroume oti leoforeia me ligoteres apo 5 theseis H >= 53 Den ypaxoun.*/
        *theseis = plhthos;    /* Aytos einai o arithmos pou xrhsimopoume telika. */
   do {                                                                 /* Diabaze grammh grammh to arxeio */
        charsRead = fscanf(f_in,"%s %s %u %s\n",nameTemp1,nameTemp2,&x,telTemp);    /* diabase ta stoixeia enos epibath */
        if (charsRead > 0 && x > 0 && x <= *theseis) {      /* Ean den einai EOF kai h thesi einai apodektos arithmos ... */
            sprintf(myBus[x-1].name,"%s %s",nameTemp1,nameTemp2); /* krathse to onomatepwnymo */
            for (i=0; i<10; i++)                                    /* apothikeuse ta 10 psifia tou thlefwnou */
                myBus[x-1].tel[i] = telTemp[i];                     /* psifio - psifio */
            myBus[x-1].seatNo = x;                                  /* apothikeuse kai ton arithmo */
            (*reserved) ++;                                            /* kai auxise ton arithmo twn krathsewn */
        }
   } while ((charsRead > 0) && ((*reserved) < 52));        /* synexise oso yparxoun ki alles grammes sto arxeio kai adeies theseis
                                                            sto lwoforeio */
   fclose(f_in);    /* kleisimo arxeiou eisodou */
}

/******************************************************************************/
void updateFileWithNewData(aBus *myBus, int theseis, int license) {
FILE *f_out;        /* metablith-deikths se arxeio */
short   i;

    f_out = fopen("bus.txt", "w"); /* Anoigei to arxeio ejodou*/
    if(f_out == NULL) /* se periptwsi problimatos kata to anoigma - p.x. den mporo na grapso arxeio - Free everything and return */
    {
        printf("To arxeio bus.txt den mporese na anoixtei gia eggrafi.\n");
        for (i=0; i<theseis; i++) {
            free(myBus[i].name);        /* free to string onoma */
            free(myBus[i].tel);         /* free to string thlefwno */
        }
        free(myBus);                    /* free kai ton pinaka deiktwn ths data structure */
        exit(1);                    /* exit to the system otan den mporeis na anoixeis arxeio gia eggrafi. */
    }
    /* afou anoixei epityxws to arxeio ...*/
    fprintf(f_out,"%s %d\n",license, theseis);  /* grapse ton arithmo kykloforias kai to plhthos thesewn ... */
    for (i=0;i<theseis;i++) {       /* kai gia kathe thesi tou leoforeiou ... */
        if (myBus[i].seatNo > 0)    /* ean exei krathsh ... */
            fprintf(f_out,"%s %u %u\n",myBus[i].name,myBus[i].seatNo,myBus[i].tel);    /* apothikeuse ta stoixeia tou epibath */
    }
    fprintf(f_out,"\n");
    fclose(f_out); /* kleise to arxeio ejodou */
}
