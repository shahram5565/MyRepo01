#include <stdio.h>
#include <string.h>
#include<time.h>

unsigned short int f1(char PhPar[][11], int Ind1Par,int Ind2Par){
    int LnIndCopy=0;
    int PhoneIndexCopy1 =0;
    int PhoneIndexCopy2 =0;
    int ln1 =0;
    int ln2 = 0 ;
    char dest[11] ;
    int consistSt = 1 ;
    char PhTemp1[11];
    char PhTemp2[11];


    if (Ind2Par <=0)
        {
           // printf("Ind2Par : %d  consistSt is : %d \n",Ind2Par-1,consistSt);
            return 1;
        }
    else{
       //  printf("ELSE   Ind2Par : %d  consistSt is : %d \n",Ind2Par-1,consistSt);
          consistSt = consistSt*f1(PhPar,Ind1Par,Ind2Par-1);
          if ( consistSt ==0 ) return 0;
                ln1 = strlen(PhPar[Ind1Par]);
                ln2=strlen(PhPar[Ind2Par-1])  ;

                if (ln1 <= ln2)
                {
                    LnIndCopy = ln1;
                }
                else {LnIndCopy = ln2;}

                 strncpy(PhTemp1,PhPar[Ind1Par],LnIndCopy);
                 PhTemp1[LnIndCopy]='\0';
                 strncpy(PhTemp2,PhPar[Ind2Par-1],LnIndCopy);
                  PhTemp2[LnIndCopy]='\0';
                if (Ind1Par !=  (Ind2Par-1)) consistSt = (strcmp(PhTemp1,PhTemp2)==0) ? 0:consistSt;
                return consistSt;
      }
return consistSt;
}



int main(void) {
       int TestCaseNo=0;
       int CntOfPhoneNo=0;
       int PhoneNoIndex;
       int PhoneNoIndex1;
       int PhoneNoIndex2;
       int TestCasInd=0;
       int  returnScanf;
       char g[10];
int consistStatusPhonList ;
       int phonIndRecursive =0;



       returnScanf = scanf("%2d",(int*)&TestCaseNo);
       if (TestCaseNo > 40) fprintf(stderr, "Enter Number Of Case Number Between 1 - 40  :%d\n", 0);
       while ((getchar()) != '\n');

       unsigned short int consistStatus[TestCaseNo][1];

       for (TestCasInd=0;TestCasInd < TestCaseNo;++TestCasInd)
        {
         consistStatus[TestCasInd][0]=1;
         CntOfPhoneNo = 0 ;
         returnScanf = scanf("%6d",(int*)&CntOfPhoneNo);
         while ((getchar()) != '\n');

      //   if (CntOfPhoneNo > 10000) fprintf(stderr, "Enter Number Of Phone again (between 1 to 10000 :%d\n", 0);

        char Ph[CntOfPhoneNo+1][11];
        for(PhoneNoIndex = 0; PhoneNoIndex <= CntOfPhoneNo-1 ; ++PhoneNoIndex )
            {
                returnScanf = scanf("%10s",(char*)&g);
                strncpy(Ph[PhoneNoIndex],g,strlen(g));
                 Ph[PhoneNoIndex][strlen(g)]='\0';
            }
         //  PhoneNoIndex1 = 0 ;
                    //  clock_t begin = clock();
      //  printf("consist status befor loop for : %d\n",consistStatusPhonList);
                    for (phonIndRecursive =0; phonIndRecursive<CntOfPhoneNo ; phonIndRecursive++ )
                      {
                          consistStatusPhonList =  f1(Ph,phonIndRecursive,CntOfPhoneNo);
                        //  printf("consist status inside for : %d\n",consistStatusPhonList);
                      if (consistStatusPhonList == 0) break;
                     // Ph[0][0]='\0';
                      }
                      consistStatus[TestCasInd][0] = consistStatusPhonList;
                           consistStatusPhonList = 0 ;
        }
     //     free(Ph);
   int  i;

   for (i=0 ; i <  TestCaseNo ; ++i) {
       if (consistStatus[i][0] == 0)
    printf("NO\n");
    else
        printf("YES\n");
   }


return 0;
}
