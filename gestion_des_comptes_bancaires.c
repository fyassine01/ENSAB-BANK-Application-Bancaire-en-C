#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
 
#define MAX1 40 
#define MAX2 100 
 
void creation(void); 
void se_connecter(void); 
void compte(char*,char*); 
void information(void); 
void afficher(char*,char*); 
void ajouter(char*,char*); 
void reclamation(char*,char*); 
void virement(char*,char*); 
 
 struct compte_bancaire 
 { 
    char NOM[MAX1]; 
    char PRENOM[MAX1]; 
    char CIN[8]; 
    int AGE; 
    char ADRESSE[MAX2]; 
    char TELE[10]; 
    float MONTANT; 
    char EMAIL[MAX2]; 
    char PASSWORD[MAX1]; 
 }; 
 
 int main(){ 
    char choix; 
    int n; 
    FILE* basededonnees; 
  FILE* supp; 
     
    basededonnees = fopen("basededonnees.txt","ab"); 
    supp = fopen("supp.txt","a"); 
    if(basededonnees == NULL || supp == NULL){ 
      printf("erreur\n"); 
      exit(1);  
     } 
     fclose(basededonnees); 
     fclose(supp); 
    system("cls"); 

     
      back : 
        system("cls"); 
         
      printf("\t\t\t   ENSAB BANK \n\n\n"); 
      printf("\t _____________________MENU_____________________\n\n"); 
      printf("\t|\t1. creer un compte bancaire            |\n"); 
      printf("\t|\t2. acceder a votre compte bancaire     |\n"); 
      printf("\t|\t3. des infomations sur bank ensab      |\n"); 
      printf("\t|\t4. quitter                             |\n"); 
      printf("\t________________________________________________\n"); 
      printf("\n\tEntrer votre choix :"); 
       
     choix = getch(); 
     switch(choix){ 
      case '1': 
        system("cls"); 
        creation(); 
        break; 
      case '2' : 
         se_connecter(); 
         break; 
      case '3' : 
        system("cls"); 
        information(); 
        break; 
      case '4' : 
        system("cls"); 
        exit(1); 
      default : 
        goto back; 
      } 
   
    return 0; 
 } 
 
  void creation(void){ 
   char choix; 
   struct compte_bancaire nv ; 
   char tempCIN[8],NOM[MAX1],PRENOM[MAX1]; 
   int test = 0; 
   FILE *basededonnees; 
    
   basededonnees = fopen("basededonnees.txt","rb+"); 
     if(basededonnees == NULL ){ 
      printf("erreur\n"); 
      exit(1);  
     } 

      
     system("cls"); 
      
   printf("**************creation**************\n"); 
   printf("\n\n\n\tNOM ="); 
   scanf("%s",&nv.NOM); 
    
   printf("\n\tPrenom ="); 
   scanf("%s",&nv.PRENOM); 
    
   strcpy(NOM,nv.NOM); 
   strcpy(PRENOM,nv.PRENOM); 
    
   cin : 
     
   printf("\n\tCIN ="); 
   scanf("%s",&nv.CIN); 
    
   strcpy(tempCIN,nv.CIN); 
   while (fread(&nv, sizeof(nv),1, basededonnees)) { 
    if(strcmp(nv.CIN,tempCIN) == 0){ 
     test++; 
     break; 
     } 
     } 
    if(test != 0){ 
      printf("\nvous avez un compte deja\n"); 
      test = 0; 
      goto cin; 
  } 
   
  fclose(basededonnees); 
  basededonnees = fopen("basededonnees.txt","ab"); 
   
   printf("\n\ttelephone ="); 
   scanf("%s",&nv.TELE); 
    
   printf("\n\tAdresse ="); 
   scanf("%s",&nv.ADRESSE); 
    
   do{ 
     
    printf("\n\tAge ="); 
    scanf(" %d",&nv.AGE); 
     
    if(nv.AGE < 18){ 
      printf("\n\n\t??????????invalide age??????????\n\n\tsi votre age est 
inferieur a 18 entrer 1 sinon entrer\n\n"); 

 
      printf("\n\tEntrer votre choix :"); 
    choix = getch(); 
    printf("\n"); 
    switch (choix) 
   { 
    case '\n' : 
     continue; 
    case '1' : 
      exit(1); 
   } 
  } 
   }while(nv.AGE<18); 
   printf("\n\tEmail ="); 
   scanf("%s",&nv.EMAIL); 
    
   printf("\n\tPASSWORD ="); 
   scanf("%s",&nv.PASSWORD); 
    
   printf("\n\tmontant ="); 
   scanf("%f",&nv.MONTANT); 
    
   strcpy(nv.CIN,tempCIN); 
   strcpy(nv.NOM,NOM); 
   strcpy(nv.PRENOM,PRENOM); 
    
   fwrite(&nv,sizeof(nv),1,basededonnees); 
    
   fclose(basededonnees); 
    se_connecter(); 
} 
void se_connecter(void){ 
  char mail[MAX2],pass[MAX1],choix; 
  FILE* basededonnees; 
  struct compte_bancaire nv; 
   
  log : 
     
  system("cls"); 
   
  basededonnees = fopen("basededonnees.txt","rb"); 
     if(basededonnees == NULL){ 
      printf("erreur\n"); 
      exit(1);  
     } 
  system("cls"); 
  printf("**************se connecter**************\n"); 
  printf("\t\n\n\nEmail ="); 
  scanf("%s",&mail); 

  printf("\t\n\n\npassword ="); 
  scanf("%s",&pass); 
   
    while(fread(&nv,sizeof(nv),1,basededonnees)){ 
      if((strcmp(mail,nv.EMAIL) == 0) && (strcmp(pass,nv.PASSWORD) == 0)){ 
    compte(mail,pass); 
    fclose(basededonnees);   
    break;   
   }  
 
    } 
     
  printf("\n\t info incorrecte \n"); 
  printf("\npour reconnecter entrer 1 pour quitter entrer 2\n"); 
  printf("\n\tEntrer votre choix :");   
   
  choix = getch(); 
   
  switch(choix){ 
    case '1' : 
      fclose(basededonnees); 
      goto log; 
      break; 
    case '2' : 
      break; 
       
  } 
} 
     
     
void information(void){ 
  char choix; 
   
  system("cls"); 
   
  printf("**************information**************\n"); 
  printf("Grace au Mobile Banking, tu peux aujourd'hui" 
  " te connecter a ta banque n'importe quand et realiser " 
  "toutes tes operations \nfinancieres de facon simple et "  
  "flexible depuis ton smartphone & pc , ou que tu te " 
  "trouves. Nous souhaitons te presenter les avantages du " 
  "Mobile Banking afin de t'aider a garder a tout moment" 
  " le controle de tes finances. \n" 
  "Le Mobile Banking te permet d executer tres facilement " 
  " des operations bancaires via ton smartphone. " 
  "Tu peux gerer tes \nfinances a tout moment et depuis" 
  " n'importe ou au moyen d'une application dediee.  \n"); 
  printf("\n\t1.menu\n\n\t2.quitter\n"); 

 
  printf("\n\t\tEntrer votre choix :");   
   
  choix = getch(); 
   
  switch (choix){ 
    case '1' : 
      main(); 
      break; 
    case '2' : 
      exit(1); 
   } 
} 
 
  void compte(char mail[],char pass[]){ 
    char choix; 
    ch : 
    system("cls"); 
     
    printf("\n\n=================bievenue=================\n"); 
    printf("1..affichage d'information\n"); 
    printf("2..ajouter un montant\n"); 
    printf("3..virement bancaire\n"); 
    printf("4..reclamation\n"); 
    printf("5..deconnecter\n"); 
    printf("==========================================\n"); 
    printf("\n\tEntrer votre choix :"); 
     
    choix = getch(); 
     
    switch(choix){ 
      case '1' : 
        afficher(mail,pass); 
        break; 
      case '2' : 
        ajouter(mail,pass); 
        break; 
      case '3' : 
        virement(mail,pass); 
          break; 
      case '4' : 
        reclamation(mail,pass); 
        break; 
      case '5' : 
        main(); 
          break; 
      default : 
          goto ch; 
    } 

     
} 
 
void afficher(char mail[],char pass[]){ 
  FILE* basededonnees; 
  FILE* supp; 
  char  choix; 
  struct compte_bancaire nv; 
  char tempCIN[8]; 
  float tempmontant,montant = 0; 
  int test = 0; 
   
  system("cls"); 
   
    basededonnees = fopen("basededonnees.txt","rb"); 
    supp = fopen("supp.txt","r+"); 
    if(basededonnees == NULL && supp == NULL){ 
      printf("erreur\n"); 
      exit(1);  
     } 
      
    while (fread(&nv, sizeof(nv),1, basededonnees)) { 
      if((strcmp(mail,nv.EMAIL) == 0) && (strcmp(pass,nv.PASSWORD) == 0)) { 
         
         montant = nv.MONTANT; 
          
    while(!feof(supp)){ 
      fscanf(supp,"%s %f\n",tempCIN,&tempmontant); 
     
          if(strcmp(tempCIN,nv.CIN) == 0){ 
            test++; 
      //  printf("\n\t %s %f\n",tempCIN,tempmontant); 
                     montant = montant + tempmontant; 
          } 
    } 
     
         printf("==================== bonjour %s %s 
====================\n",nv.NOM,nv.PRENOM); 
         printf("\n\n\tEMAIL : %s",nv.EMAIL); 
         printf("\n\n\tAGE : %d" ,nv.AGE); 
         printf("\n\n\tTELEPHONE  : %s",nv.TELE); 
         printf("\n\n\tADRESSE : %s",nv.ADRESSE); 
         printf("\n\n\tCIN : %s",nv.CIN); 
      
       break; 
       } 
    } 
      if(test == 0){   

 
        printf("\n\n\n=======================%.3f 
DH=======================",nv.MONTANT); 
      } 
      else{ 
        printf("\n\n\n=======================%.3f 
DH=======================",montant); 
     
       } 
    printf("\ntaper 1 pour routeur et 2 pour deconnecter "); 
       
    choix = getch(); 
     
    switch(choix){ 
      case '1' : 
        compte(mail,pass); 
        break; 
      case '2' : 
        main(); 
        break; 
  } 
 
    fclose(basededonnees); 
    fclose(supp); 
} 
void ajouter(char mail[],char pass[]){ 
    float montant; 
    FILE* basededonnees; 
    FILE* supp; 
    struct compte_bancaire nv; 
     
    system("cls"); 
     
    basededonnees = fopen("basededonnees.txt", "rb"); 
     
    supp = fopen("supp.txt","a"); 
    if(basededonnees == NULL || supp == NULL){ 
      printf("erreur\n"); 
      exit(1);  
     } 
     printf("\t\t*******ajouter*******\n"); 
     printf("\n\n\n\tAJOUTER en DH :"); 
     scanf("%f",&montant); 
      
      while (fread(&nv, sizeof(nv),1, basededonnees)) { 
      if((strcmp(mail,nv.EMAIL) == 0) && (strcmp(pass,nv.PASSWORD) == 0)) { 
       
        fprintf(supp,"%s %f\n",nv.CIN,montant); 
         

 
        } 
    } 
    fclose(basededonnees); 
    fclose(supp); 
    compte(mail,pass); 
} 
  void reclamation(char mail[],char pass[]){ 
    char*txt =  malloc(200); 
     
    system("cls");  
     
    printf("\n\n============================RECLAMATION=======================
 =====\n"); 
    fgets(txt, sizeof(txt),stdin); 
     
    free(txt); 
    compte(mail,pass); 
  } 
  void virement(char mail[],char pass[]){ 
    struct compte_bancaire nv; 
    FILE* supp; 
    FILE* basededonnees; 
    float vir,som = 0,tempmontant; 
    char CINtemp[8],tempCIN[8],mainC[8],choix; 
    int test = 0; 
     
    system("cls"); 
    supp = fopen("supp.txt","a+"); 
    basededonnees = fopen("basededonnees.txt","rb"); 
    if(supp == NULL || basededonnees == NULL){ 
      printf("erreur\n"); 
      exit(1);  
    } 
     
    while (fread(&nv, sizeof(nv),1, basededonnees)) { 
      if((strcmp(mail,nv.EMAIL) == 0) && (strcmp(pass,nv.PASSWORD) == 0)) { 
        strcpy(mainC,nv.CIN); 
        som = nv.MONTANT; 
        break; 
      } 
  } 
   rtr : 
     
   fclose(basededonnees); 
   basededonnees = fopen("basededonnees.txt","rb"); 
     
    printf("\n\n=================================================\n"); 
    printf("=====================virment=====================");   

    printf("\n=================================================\n"); 
     
    printf("\n\n\n\tCIN du beneficiaire : "); 
    scanf("%s",&CINtemp); 
     
    while(fread(&nv, sizeof(nv),1, basededonnees)){ 
      if(strcmp(nv.CIN,CINtemp) == 0){ 
    test++; 
    }             
    } 
    if(test == 0){ 
      printf("\ncette CIN n'existe pas entrer 1 pour continue 2 pour 
quitter  "); 
      test = 0; 
       
      choix = getch(); 
       
      switch(choix){ 
        case '1' :         
          goto rtr; 
          break; 
        case '2' : 
          compte(mail,pass); 
          break; 
    } 
  } 
     else{ 
    bck : 
       
    printf("\n\n\n\tentrer un montant :"); 
    scanf("%f",&vir); 
     
    while(!feof(supp)){ 
      fscanf(supp,"%s %f\n",tempCIN,&tempmontant); 
      if(strcmp(tempCIN,mainC) == 0){ 
        som = tempmontant + som; 
      } 
    } 
     
    if(vir > som){ 
      printf("solde insuffisant entrer un caractere pour essayer \n"); 
      getch(); 
      goto bck; 
    } 
    else{ 
      fprintf(supp,"%s %f\n",mainC,-vir); 
      fprintf(supp,"%s %f\n",CINtemp,vir); 
    } 
} 
fclose(basededonnees); 
fclose(supp); 
compte(mail,pass); 
}

