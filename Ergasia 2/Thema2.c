//*************************************************************
//*** ΠΛΣ50 "Βασικές Εξειδικεύσεις σε Θεωρία και Λογισμικό" ***
//***                   Εργασία Ε02 - Θέμα 2                ***
//***                                                       ***
//***                   Ακ.έτος 2016-17                     ***
//***                                                       ***
//*************************************************************
#include <stdio.h>  /* logw printf(), fscanf(), fopen(), fclose() */
#include <stdlib.h> /* logw exit() */
#include <string.h>

/* GLOBAL types and var */  /* Linked List structure gia na desmeuoume mnhmh mono gia tis krethmenes theseis */
struct node {
       unsigned char *name; /* pointer gia ewpwnymo kai onoma 40 thesewn. Tha ginete memory allocation otan xreiastei */
       unsigned short *tel; /* pointer gia to thlefwno. Tha ginetai desmeush mnhmhs, epishs me malloc */
       unsigned int seatNo; /* O arithmos thesis pou exei desmeuthei gia ton pelati  */
       struct node * next;  /* pointer gia ton epomeno komvo (node) ths linked list. */
   };
typedef struct  node dynamicBus;    /* onomasia ths domhs me neo onoma dynamicBus */

unsigned char * nameTemp1;      /* Oi epomenes metablhtes dhlonontai global gia na einai diathesimes gia syntomi */
unsigned char * nameTemp2;      /* xrisi se kathe synartisi. Desmeuetai mhnhmh stin arxh kai apodesmeuetai sto telos */
unsigned char * nameTemp;       /* tou nain.  */
unsigned short * telTemp;
unsigned int seatNoTemp;

/* dhlwsi synarthsewn. Tha analithoun katallhla parakatw ...*/
void initTempVar();
void readFromFileNonReacurs(dynamicBus *head,dynamicBus *tail,char *license,short *seats,short *theseis, short *dReserved);
void kenesTheseis(dynamicBus *head,short *seats);
void krathshTheshs(dynamicBus *head,dynamicBus *tail,short *seats, short *dReserved);
void anazhthsh(dynamicBus *head,dynamicBus *tail);
void akyrwshKrathshs(dynamicBus *head,dynamicBus *tail,short *seats, short *dReserved);
void emfanisiTaxinomhmenhsListas(dynamicBus *head,dynamicBus *tail,short *dReserved);
void printListRecurs(dynamicBus *node,int what);
void selectionSort(dynamicBus * head);
void selectionSortByName(dynamicBus * head);
void swapValues(dynamicBus * a, dynamicBus *b);
void swapBySeat(dynamicBus *a, dynamicBus *b);
dynamicBus * copyList(dynamicBus *node);
void saveToFileANDdeleteList(FILE *f_out,dynamicBus* node);

/* To kyrios programma - main (Den xrisimopoiountai argc, argv) */
int main()
{

    dynamicBus *head;   /* the head node of the linked list of my dynamic Bus structure */
    dynamicBus *tail;   /* the tail node  tiw kyrias domis dedomenwn tou leoforeiou mas (linked list *) */
    dynamicBus *p;      /* bohthitikh metabliti */
    dynamicBus *temp;   /* --//--               */
    dynamicBus *list2;  /* head (start) node ths deyterhs listas pou tha xrisimopoihthei gia thn aggrafi se arxeio */

    head = (dynamicBus *)malloc(sizeof(dynamicBus));    /* arxikopoihsh tis listas */
    head->next = (void *)NULL;                          /* O komvos aytos einai kai o teleutaios - pros to paron */
    tail = head;                    /* head kai tail dixoun ton idio teleutaio komvo */

    int     x,charsRead;  /* Boithikes metablites gia to diavasma (scanf) dedomenwn apo to pliktrologio h arxeio*/
    int     theseis;    /* Plithos diadesimwn thesewn (arxika 53) */
    int     dReserved;  /* plithos krathmenwn thesewn */
    int     deiktis;    /* FLAG se anazhthsh. times 0 kai 1 */


    FILE* f_in, *f_out;        /* metablites-deiktes se arxeio */
    char license[8];           /* pinakida kykloforias, 7 grammata-arithmoi kai to '\0' */
    int seats;                 /* plithos thesewn */
    int i,j, choice, myCount;      /* boithitikes metablites */

    theseis = 53;       /* megisth kai default timh 53 */
    dReserved = 0;      /* arxikopoihsh. Oles oi theseis einai akoma adeies. */

    initTempVar();  /* arxikopoihsh (malloc) voithitikwn metablhtwn */
    /* diabase ta dedomena apo to bus.txt - NON recursive - me while loop */
    readFromFileNonReacurs(head,tail,license,&seats,&theseis,&dReserved);
    selectionSort(head);    /* TAXINOMHSE. OI LEITOYRGIES PROYPOTHETOYN TAXINOMHMENH LISTA */

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
      switch(choice) {
        case 1: /* menu option 1 */
            printf("Plithos kenwn Thesewn: %d\n",theseis - dReserved);
            printf("%d Dynamikes Theseis\n",dReserved);
            printListRecurs(head,0);    /* emfanise mono tis katilimenes theseis */
            printf("\nKenes Theseis\n");
            kenesTheseis(head,&seats);
            printf("\n\n");
            break;
        case 2: /* menu option 2 */
            krathshTheshs(head,tail,&seats,&dReserved); /* Diavazei arithm. thesis kai thn desmeuei ean einai eleutheri */
           break;
        case 3: /* menu option 3 */
            anazhthsh(head,tail);   /* search me onomatepwnymo h thlefono */
            break;
        case 4: /* diavazei arithmo thesis kai ean einai kathlhmenh thn apodesmeuei kai kanei free ton komvo */
            akyrwshKrathshs(head,tail,&seats,&dReserved);
           break;
        case 5: /* taxinomei ws pros onoma, emfanizei kai XANA-taxinomei ws pros thesi */
            emfanisiTaxinomhmenhsListas(head,tail,&dReserved);
            break;
        case 0:  /* min kaneis tipote */
            break;
        default:
            printf("akatallili epilogi\n");
      }
    }

    selectionSortByName(head);  /* taxinomei ws pros onoma me SELECTION SORT */
    printf("Creating ... New List\n");
    list2 = (dynamicBus *)malloc(sizeof(dynamicBus)); /* arxikopoihsh antigrafou listas me onoma lista2 */
    list2->next = copyList(head); /* ANTIGRAFH me ANADROMH */
    printf("List has been copied ... \n");
    printListRecurs(list2,1);   /* emfanise thn NEA lista me andromh */

    f_out = fopen("bus.txt", "w"); // Anoigei to arxeio ejodou
    if(f_out == NULL) {// se periptwsi problimatos kata to anoigma
        printf("To arxeio bus.txt den mporese na anoixtei gia eggrafi.\n");
        exit(1);
    }
    /* To arxeio einai anoixto gia eggrafi */
    fprintf(f_out,"%s %d\n",license, theseis); /* STORE ArithmoKykloforias kai plithos thesewn leoforeiou */
    saveToFileANDdeleteList(f_out,list2->next);
    printf("Done saveToFileANDdeleteList\nprintfing empty list ...\n");
    fclose(f_out);  /* kleise to arxeio */

    free(nameTemp2);        /* free tis bohthikes metablites pou dimiourghse i initVars */
    free(nameTemp1);
    free(nameTemp);
    free(telTemp);

    while(head != NULL) {   /* free thn kyria linked list me ta dedomena tou leoforeiou */
        p = head;       /* pare antigrafo tou head */
        head = head->next;  /* DEIXE TON EPOMENO KOMBO GIATI O TREXWN THA DIAGRAFEI */
        free(p->name);      /* free ta 41 bytes tou onomatepwnymou */
        free(p->tel);       /* free ta 10 bytes toy thlefonou */
        free(p);            /* free kai ton kombo */
        dReserved --;       /* meiwse kata ena ton metriti */
    }
}
/********************************************************************/
/* arxikopoiei (memory allocation) 4 global metablhtes, bohthitikes
/* se olo to programma. Gia tis : nameTemp1, nameTemp2, nameTemp kai telTemp
/********************************************************************/
void initTempVar() {    /* memory allocation 41 chars gia onoma */
    nameTemp1 = (unsigned char *)malloc(41*sizeof(unsigned char));
    if (nameTemp1 == (unsigned char *)NULL) {
        printf("Memory can not be allocated. Exiting...");
        exit(1);
    }
    nameTemp2 = (unsigned char *)malloc(41*sizeof(unsigned char));
    if (nameTemp2 == (unsigned char *)NULL) {
        printf("Memory can not be allocated. Exiting...");
        exit(1);
    }
    nameTemp  = (unsigned char *)malloc(41*sizeof(unsigned char));
    if (nameTemp == (unsigned char *)NULL) {
        printf("Memory can not be allocated. Exiting...");
        exit(1);
    }
    /* memory allcation 11 bytes gia to thlefono - bohthitikh metablhth */
    telTemp =(unsigned short *)malloc(11*sizeof(unsigned short));
    if (telTemp == (unsigned char *)NULL) {
        printf("Memory can not be allocated. Exiting...");
        exit(1);
    }
}

/**************************************************************/
/**** Diavase ta stoixeia apo to bus.txt - NON Recursive  *****/
/**************************************************************/
void readFromFileNonReacurs(dynamicBus *head,dynamicBus *tail,char *license,short *seats,short *theseis, short *dReserved)
{
FILE *f_in;
dynamicBus *p;
short     i,x,charsRead;

    f_in = fopen("bus.txt", "r"); /* Anoigei to arxeio eisodou*/
    if(f_in == NULL) /* se periptwsi problimatos kata to anoigma */
    {
      printf("To arxeio bus.txt de mporese na anoixthei gia anagnwsh.\n");
      exit(1);      /* ejodos apo to programma */
    }

    *dReserved = 0;     /* arxikopoihsh = 0 onomata. Adeio leoforeio akoma */
    fscanf(f_in,"%s %d", license, seats);   /* diavase Arithmo kykloforias kai pragmatikes theseis */

    if (*seats >= 5 && *seats <= 53) /* theoroume elaxisto arithmo thesewn leoforeiou to 5 kai megisto to 53 */
        *theseis = *seats;      /* tote mono these *theseis = oti diabastike apo to arxeio bus.txt */

    do {
        charsRead = fscanf(f_in,"%s %s %u %s\n",nameTemp1,nameTemp2,&x,telTemp);    /* oso yparxoun DATA */
      if (charsRead > 0 && x > 0 && x <= 53) {  /* kai exei diabasei arithmo theseis YPARKTO */
            p = (dynamicBus *)malloc(sizeof(dynamicBus));   /* DHMIOURGIA KOMBOU */
            p->name = (unsigned char *)malloc(41*sizeof(unsigned char));    /* DHMIOURGIA XWROU GIA ONOMATEPWNYMO */
            sprintf(p->name,"%s %s",nameTemp1,nameTemp2);   /* antegrapse onoma & epwnymo ston NOMBO */
            p->tel = (unsigned short *)malloc(11*sizeof(unsigned short));    /* DHMIOURGIA XWROU GIA THLEFWNO */
            for (i=0; i<10; i++)    /* 11 psifia (me to EOS) */
                p->tel[i] = telTemp[i]; /* antegrapse ta ston kombo */
            p->seatNo = x;  /* antegrapse ton arithmo thesis ston KOMBO ths listas */
            p->next = NULL; /* Tha ginei o telautaios, prepei na deixnei to keno */
            tail->next=p; /* insert thenode at the end */
            tail = p;     /* O tail prpei na deixnei ton neo teleutaio node */
            (*dReserved) ++;    /* ki alli mia thesi kataxwrithike swsta */
        }
    } while ((charsRead > 0) && ((*dReserved) < 53));   /* synexise oso diabazontai theseis mexri kai 53 */

    fclose(f_in);    /* kleisimo arxeiou eisodou */
}
/********************************************************************/
/**** epilogh menu 1 - emfanise taxinomhmenes tis eleytheres thesis */
/********************************************************************/
void kenesTheseis(dynamicBus *head, short *seats){
dynamicBus *p;
short i;
/* Tha xekinisw na metraw apo to 1 mexri to telos twn thesewn (53) kai oso yparxoun theseis parallhla
    sthn lista to agnow giati einai kathllhmenes. Taxoxrona ayxanw tous metrhtes kata 1.
    Ean omos den pane parallhla Ayxanw to i kai emfanizw adeies theseis mexri na xanasinantisw
    kapoia thesi tis listas */

    i = 1;  /* apo ton thesi 1 */
    p = head->next; /* apo tin arxh tis listas xekina */
    while (i <= *seats) {   /* mexri kai thn teleytaia thesi */
//        printf("{%d-%d} ",i,p->seatNo);
        if (p->seatNo == i) {   /* Ean einai idies tote einai katillimenh */
            i ++;               /* epomenh thesi sto kathisma gia elegxo */
            if (p->next != NULL)
                p = p->next;    /* Me thn epomenh Thesi stis katillimenes GIA ELEGXO */
        } else {    /* Euxise to i. Ean einai megalytero tou Thesis, */
                    /* Tote den yparxei alli Katilimenh */
                    /* Ean einai mikrotero, tote einai adeies kai */
                    /* kapoia stigmh tha xanasynantisi katillimenh */
            printf("%d  ",i);   /* emfanise KENH THESI */
            i++;
        }
    }
}
/****************************************************************/
/**** epilogh menu 2 - krathsh thesis, ne epithimito arithmo ****/
/****************************************************************/
void krathshTheshs(dynamicBus *head,dynamicBus *tail,short *seats, short *dReserved){
dynamicBus *p, *temp;
short i, x, deiktis;

    printf("dwse arithmo thesis\n");
    scanf("%d", &x);    /* diabase arithmo theshs. Tha mporouse na ginei kai me getc */
    if (x<1 || x>*seats) // elegxos oti arithmos thesis entos oriwn
        printf("arithmos thesis ektos oriwn\n");
    else {
        deiktis = 0; /* FLAG = FALSE, Den Brethike */
        p = head;   /* arxise apo thn arxh */
        while (p->next != NULL) {   /* oso o epomenos kombos den einai KENOS synexise thn ANAZHTHSH */
//            printf("Dyn: x=%d, seatNo=%d - \n",x,p->next->seatNo);
            if (p->next->seatNo == x) { /* Ean h ahtoumenh thesi einai sto node-kathisma auto TOTE */
                deiktis = 1;            /* Flag - TRUE */
                printf("Dynamic Brethike stin thesi %d\n",deiktis); /* MHNYMA */
                break;  /* STAMATA thn ANAZHTHSH */
            } else if (p->next->seatNo > x) {   /* ean xeperasame thn Thesi TOTE STAMATA KAI ... */
                deiktis = 2;    /* FLAG = XEPERASAME THN THESI KAI DEN BRETHIKE = 2 */
                temp = p;  /* o neos epibaths prepei na eisxthei anamesa apo p kai p->next */
                break;  /* STOP searching */
            }
            p = p->next;    /* synexise me ton epomeno node */
        }
        if (deiktis == 0)   /* EAN DEN BRETHIKE TOTE ZHTHTHIKE THESI STO TELOS THS LISTAS */
            temp = p;       /* EDW tha eisaxthei o NEOS EPIBATHS */

        printf("Search result = %d\n",deiktis);
        if (deiktis != 1 ) {    /* KANE KRATHSH - DHMIOURGHSE NODE GIA EISAGWGH STOIXEIWN */
            printf("thesi idi eleutheri. Tha kratithei...\n");
            printf("Dwste epwnymo: ");
            scanf("%s",nameTemp1);
            printf("Dwste onoma: ");
            scanf("%s",nameTemp2);
            printf("Dwste Thlefwno: ");
            scanf("%s",telTemp);

            /* EAN TO ONOMA KAI TO EPWNYMO XWRANE STO ALFARITHMITIKO 40 XARAKTHRWN */
            if (strlen(nameTemp1) + strlen(nameTemp2) <= 40  && sizeof(telTemp)<=10) {
                p = (dynamicBus *)malloc(sizeof(dynamicBus));   /* NEW NODE */
                p->name = (unsigned char *)malloc(41*sizeof(unsigned char));    /* 41 BYTES for NAME */
                sprintf(p->name,"%s %s",nameTemp1,nameTemp2);   /* copy name to NODE */
                p->tel = (unsigned short *)malloc(11*sizeof(unsigned short));   /* NEW 11 BYTES FOR TELEPHONE */
                for (i=0; i<10; i++)    /* TELEPHONE COPY */
                    p->tel[i] = telTemp[i];
                p->seatNo = x;      /* SHMEIWSE KAI THN THESI POU EPILEXTHIKE */
                if (deiktis == 0) {  /* ean h eisagvgh einai sto telos */
                    printf("temp = %d\n",temp->seatNo);
                    p->next = NULL; /* Einai o teleytaios - NA DEIXNEI NULL */
                    temp->next = p; /* PROSTHIKI STO TELOS */
                    tail = p;       /* O TAIL DEIXNEI TON TELEYTAIO KOMBO */
                } else if (deiktis = 2) { //(temp->next != NULL) { // ean h eisagvgh den einai sto telos
                    p->next = temp->next;    /* EISAGWGH STH MESH THS LISTAS */
                    temp->next = p;          /* O NODE POU BRETHIKE NA DEIXNEI TON NEO */
                }
                dReserved ++;           /* ALLOS ENAS */
//                printListRecurs(head,1);
            } else {      /* ypervolika megalo onomatepwnymo */
                printf("Lanthasmena stoixeia. Den egine Kratisi. Ean epithimeite prospatheiste pali.\n");
            }
        } else
            printf("thesi idi kateilhmmeni\n");     /* O THESI DEN EINAI DIATHESIMH */
    }
}
/****************************************************************/
/**** epilogh menu 3 - anazhthsh me onomatepwnymo h telefono ****/
/****************************************************************/
void anazhthsh(dynamicBus *head,dynamicBus *tail) {
short choice;
dynamicBus *p;
                        /* NEO MENU ME 2 PEILOGES */
    printf("1. gia eisagwgi epwnymou kai onomatos\n");
    printf("2. gia eisagwgi thlefwnou\n");
    printf("Me allo arithmo epistrofi sto kentriko menu.\n");
    scanf("%d", &choice); printf("Epilogi: %d\n",choice);
    if (choice == 1) {
        printf("Dwste epwnymo: ");
        scanf("%s",nameTemp1);
        printf("Dwste onoma: ");
        scanf("%s",nameTemp2);
        sprintf(nameTemp,"%s %s",nameTemp1,nameTemp2);
        printf("%d\n",strlen(nameTemp));
        printf("Dynamic ...\n");
        p = head->next;
        while (p != NULL) { /* ANAZHTHSH */
            if (strcmp(p->name,nameTemp)==0)
                break;
            p = p->next;
        }
        if (p == NULL)
            printf("Den yparxei eisithrio krathmeno sto onomatepwnymo: %s\n",nameTemp);
    } else if (choice == 2) {
        printf("Dwste Thlefwno: ");
        scanf("%s",telTemp);    /* YPOTHETO OTI EINAI 10 PSIFIA - DEN TO ELEGXO */

        p = head->next; /* arxise NEA ANAZHTHSH */
        while (p != NULL) {     /* MEXRI TO TELOS THS LISTAS */
            if (strcmp(p->tel,telTemp)==0)
                break;
            p = p->next;
        }
        if (p == NULL)
            printf("Den yparxei eisithrio krathmeno sto onomatepwnymo: %s\n",nameTemp);
    } else {
        printf("H diadikasia anazhthshs akyrwnetai. Epistrofh sto kyrio menu.\n");
    }
}

/****************************************************************/
/**** epilogh menu 4 - akyrwsh Krathshs sygkekrimenhs thesis ****/
/****************************************************************/
void akyrwshKrathshs(dynamicBus *head,dynamicBus *tail,short *seats, short *dReserved) {
short i, deiktis;
dynamicBus *p, *temp;   /* Boithitikes */

    printf("dwse arithmo thesis\n");
    scanf("%d", &i);
    if (i<1 || i>*seats)   /* elegxos oti arithmos thesis entos oriwn */
        printf("arithmos thesis ektos oriwn\n");
    else {
        deiktis = 0; // Den Vrethike - FLAG
        p = head;
        while (p->next != NULL) {   /* ANAZHTHSH */
            if (p->next->seatNo == i) { /* EAN YPARXEI H THESI ... */
                deiktis =1;
                printf("Dynamic Brethike stin thesi %d\n",deiktis);
                temp = p->next;
                p->next = p->next->next;
                free(temp->name);       /* DIAGRAFH ONOMATEPWNYMOU */
                free(temp->tel);        /* DIAGRAFH THLEFONOU */
                free(temp);             /* DIAGRAFH OLOU TOU KOMBOU */
                printf("thesi apodesmeutike\n");
                break;
            }
            p = p->next;    /* synexise me ton EPOMENO NODE THN ANAZHTHSH */
        }
        if (deiktis == 0)
            printf("thesi idi eleutheri\n");
    }
}

/****************************************************************/
void emfanisiTaxinomhmenhsListas(dynamicBus *head,dynamicBus *tail,short *dReserved) {
short choice;

    printf("1. Emfanisi listas taxinomhmenis kata arithmo thesis\n");
    printf("2. Emfanisi listas taxinomhmenis kata epwnymo kai onoma\n");
    printf("Me allo arithmo epistrofi sto kentriko menu.\n");
    scanf("%d", &choice);
    printf("Epilogi: %d\n",choice);
    if (choice == 1) {
        printf("%d Dynamikes Theseis\n",*dReserved);
        printListRecurs(head,1);    /* ANADROMIKA EMFANISE THN LISTA */
    } else if (choice == 2) {
        // 2 sorted by name
        printf("%d [by Name] Dynamikes Theseis\n",*dReserved);
        selectionSortByName(head);  /* SELECTION SORT BY NAME */
        printListRecurs(head,1);    /* SHOW LIST */
        selectionSort(head);        /* SORT BY SEATNO */
    }
}

/**************************************************************************/
/* Synarthsh na emfanizei ANADROMIKA ta dedomena apo mia linked lsit      */
/* EAN H metabliti what den einai  1 tha emfanisi mono arithmo thesis,    */
/* EAN EINAI 1 Tha emfanisei kai ta ypoloipa stoixeia ths KRATHSHS        */
/**************************************************************************/
void printListRecurs(dynamicBus *node,int what)
{
    if (node->next!=NULL){  /* EAN O EPOMENOS DEN EINAI NULL */
        printf("%d ", node->next->seatNo);  /* EMFANISE arithmo thesis */
        if (what == 1)                      /* emfanise ta ypoloipa stoixeia , opws zhththike */
            printf("%s %s \n",node->next->name, node->next->tel);
        printListRecurs(node->next,what);   /* EMFANISE THN YPOLOIH LISTA ANADROMIKA */
    }
}

/************************************************************************/
/* Selection Sort by seatNo                                             */
/************************************************************************/
void selectionSort(dynamicBus * head) {
dynamicBus *i, *j, *min;

    if (head->next == NULL) /* An einai adeia h lista den apaiteitai taxinomhsh */
        return;
    if (head->next->next == NULL)   /* H Lista me ena mono stoixeio den xreiazetai taxinomhsh */
        return;
/* ARXIZONTAS APO TON PRWTO NODE MEXRI TON TELEYTAIO (NULL), KAI PERNWNTAS APO KATHE NODE*/
    for (i = head->next; i->next != NULL; i = i->next) {
        min = NULL;     /* ARXIKOPOIHSE TON ELAXISTO */
        /*  BRES minimum apo tn trexousa thesi (i->next) MEXRI THN TELAYTAIA */
        for (j = i->next; j != NULL; j = j->next) {
            if (min == NULL || j->seatNo < min->seatNo)
            min = j;
        }
        /* SWAP Thn i thesi me thn Thesi tou minimum */
        if (min->seatNo < i->seatNo) {  /* ean h minimum einai PRAGMATI < tis thesis i */
            swapValues(min, i); /*SWAP them ... */
        }    }
}

/************************************************************************/
/* Selection Sort by name                                               */
/* omoiws, alla sygkrine ta alfarithmitika me strcpy (-1,0,1) an einai  */
/* to aristero mikrotero tou dexiou str                                 */
/************************************************************************/
void selectionSortByName(dynamicBus * head) {
dynamicBus *i, *j, *min;
int compare;

    if (head->next == NULL) /* An einai adeia h lista den apaiteitai taxinomhsh */
        return;
    if (head->next->next == NULL)   /* H Lista me ena mono stoixeio den xreiazetai taxinomhsh */
        return;

    for (i = head->next; i->next != NULL; i = i->next) {
        min = NULL;
        // first find minimum
        for (j = i->next; j != NULL; j = j->next) {
            if (min == NULL || strcmp(j->name,min->name) < 0)   /*string compare */
                min = j;
        }
        // THEN swap
        if (strcmp(i->name,min->name) > 0) {    /* string compare */
            swapValues(min, i);
        }    }
    printf("End of Selection Sort by Name\n");
}
/* swap values for SORTING ALGORITHM */
void swapValues(dynamicBus * a, dynamicBus *b) {
dynamicBus *temp = (dynamicBus *)malloc(sizeof(dynamicBus));    /* bohthitikh metablhth */
char sTemp[40];
short xTemp;
            /* ANTALAGH TWN STOIXWN ME TEMP METABLHTES */
    memcpy(&sTemp[0],a->name,40);
    memcpy(a->name,b->name,40);
    memcpy(b->name,&sTemp[0],40);

    memcpy(&sTemp[0],a->tel,11);
    memcpy(a->tel,b->tel,11);
    memcpy(b->tel,&sTemp[0],11);

    temp->seatNo = a->seatNo;
    a->seatNo = b->seatNo;
    b->seatNo = temp->seatNo;
    free(temp); /* free thn bohthitikh metabliti */
}
/* function to swap 2 nodes a and b by pointer*/
void swapBySeat(dynamicBus *a, dynamicBus *b) {
dynamicBus *temp1;
dynamicBus *temp2;

    temp1 = a->next;
    a->next = b->next;
    temp2 = b->next->next;
    b->next->next = temp1;
    b->next = temp2;
}
/****************************************************************
/* Insert a node At End of the list                             */
dynamicBus * copyList(dynamicBus *node) {
    /* EAN EMPTY LIST, RETURN*/
    if (node->next == NULL)
        return NULL;

    dynamicBus *temp;
    /* NEOS NODE O OPOIOS THA PAREI ANTIGRAFO APO THN ARXIKH LISTA KAI THA EPISTRAFEI */
    temp = (dynamicBus *)malloc(sizeof(dynamicBus));
    temp->name = (unsigned char *)malloc(41*sizeof(unsigned char));
    temp->tel = (unsigned short *)malloc(11*sizeof(unsigned short));
    temp->seatNo = node->next->seatNo;

    memcpy(temp->name,node->next->name,strlen(node->next->name));
    memcpy(temp->tel,node->next->tel,10);

    /* ADD THE NODE TO THE END, KAI SYNEXISE ME TOUS YPOLOIPOUS NODEs */
    temp->next = copyList(node->next);
    return temp;
}
/****************************************************************/
/* ANADROMIKH DIAGRAFH linked list                              */
/*  PARAMETROI: File Id kai linkedList                          */
/****************************************************************/
void saveToFileANDdeleteList(FILE *f_out,dynamicBus* node)
{
dynamicBus *temp;
    if (node!=NULL){    /* ANADROMIKA MEXRI TO TELOS */
        temp = node;    /* ANTIGRAFO POINTER TOU KOMBOU */
        fprintf(f_out,"%s %d %s\n",node->name,temp->seatNo,temp->tel); /* GRAPSE STO ARXEIO MIA GRAMMH */
        node = node->next;  /* DEIXE TON EPOMENO */

        /* DELETE node, Which has been WRITTEN giati den xreiazetai pleon, KAI PREPEI NA DIAGRAFEI KAI H LISTA */
        free(temp->name);   /* free to onomatepwnymo */
        free(temp->tel);    /* free to allocated thlefono */
        free(temp);         /* free ton node */
        saveToFileANDdeleteList(f_out,node);    /* CONTINUE WITH THE REST OF THE LINKED LIST */
    }
}
