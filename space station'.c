
//This is the part 1 of the space craft management system.
#include<stdio.h>
#include<time.h>
#include<windows.h>  //gotoxy()
#include<conio.h>    //Use of delay() and getch()
#include<ctype.h>    //Use of toupper() and tolower()
#include<string.h>   //Use of strcmp() , strcpy() , strlen() etc.
#include<stdlib.h>


//Declaring some golbal variables.
char ans=0 ;
int a , OK , valid=0;

// Function decleration

void WelcomeScreen(void);
void Title(void);
void LoginScreen(void);
void MainMenu(void);
void shuffle(int *array, int n, int num_shuffles);
void Add(void);
void list(void);
void search(void);
void edit(void);
void del(void);
void ex(void);

void gotoxy(short x , short y)
{
    COORD pos = {x,y}; // Sets Co-ordinates in X and Y.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

struct astronaut
{
    int no_astronaut[1];
    char Full_Name[40];
    char Gender[10];
    char Product[25];
    int cost[25];

};
struct astronaut p, temp_c;

int main(void)
{
    WelcomeScreen();
    Title();
    LoginScreen();
}

void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\t\t\t\t ******************** ");
    printf("\n\n\t\t\t\t ####\t WELCOME TO INTERNATIONAL SPACE STATION \t ####");
    printf("\n\n\t\t\t\t I AM JARVIS YOUR MANAGEMENT VIRTUAL ASSISTANT ");
    printf("\n\n\t\t\t\t ******************** ");
    printf("\n\n\n\n\t\t\t\t Please Press Any key to Continue to Login Page");
    getch();
    system("cls"); //Clean the Screen
}

void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t\t 1. ADD REQUIREMENTS. \n");
    printf("\n\t\t\t\t 2. VIEW THE LIST OF REQUIRNMENTS. \n");
    printf("\n\t\t\t\t 3. SEARCH FOR THE PARTICULAR MATERIAL. \n");
    printf("\n\t\t\t\t 4. EDIT THE LIST OF REQUIRMENTS. \n");
    printf("\n\t\t\t\t 5. DELETE AN ITEM. \n");
    printf("\n\t\t\t\t 6. EXIT \n");
    scanf("%i",&choose);
    switch(choose) //Add function is called
    {
        case 1:
            Add();
            break;
        case 2:
            list();
            break;
        case 3:
            search();
            break;
        case 4:
            edit();
            break;
        case 5:
            del();
            break;
        case 6:
            ex();
            break;
        default :
          printf("\t\t\t INVALID ENTRY !!! PLEASE ENTER RIGHT OPTION :");
          getch();
    }
}

void Title(void)
{
   printf("\n\n\t\t\t\t -------------------------------------- \t");
   printf("\n\n\t\t WELCOME TO LOGIN PAGE \t\t ");
   printf("\n\n\t\t PLEASE LOGIN TO CONFIRM ID");
   printf("\n\n\t\t\t\t -------------------------------------- \t");
}
   #define ROWS 20
    #define COL 21
    #define RND_NAMES 2

void shuffle(int *array, int n, int num_shuffles)
{
    srand((unsigned)time(NULL));
    for (int j = 0; j < num_shuffles; j++) {
        for (int i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void LoginScreen(void)
{

 int e=0;
    char user_name[25];
    char Password[15];

      int i;
    char name[ROWS][COL] = {"Neil_Armstrong",  "Christa_McAuliffe",  "Kalpana_Chawla",
                            "Mae_C._Jemison",  "Guion_Bluford",  "Scott_Kelly",
                            "Alexei_Leonov",  "Pete_Conrad",  "Chris_Hadfield",
                            "John_Glenn", "Sally_Ride", "Alan_Shepard",
                            "Buzz_Aldrin","Valentina_Tereshkova","Yuri_Gagarin",
                            "Jim_Lovell", "Svetlana_Savitskaya",
                            "Peggy_Whitson","Gus_Grissom","Andriyan_Nikolayev"};
    int positions[ROWS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    shuffle(positions, ROWS , 100);

    printf("\n\n\n\n\t\t\t\t %s AND %s ARE THE ONLY CREW MEMBERS TO ACCESS THE SYSTEM\n", name[positions[1]],name[positions[2]]);

    char pass[20]="2021";
    do
    {
        printf("\n\n\n\n\t\t\t\t ENTRE YOUR USER NAME AND PASSWORD ");
        printf("\n\n\n\t\t\t\t USER NAME :");
        scanf("%s",&user_name);
        printf("\n\n\t\t\t\t PASSWORD :");
        scanf("%s",&Password);
         if(strcmp(user_name,name[positions[1]])==0 || strcmp(user_name,name[positions[2]])==0 && strcmp(Password,pass)==0)
            {
                printf("\n\n\n\n\t\t\t\t .......LOGIN SUCCESSFULL.......");
                    getch();
                    MainMenu();// call the main-menue function....
                    break;
            }
            else
            {
                printf("\n\n\t\t\t\t ....USER ID OR PASSWORD INCORRECT :(PLEASE TRY AGAIN) ");
                e++;
                getch();
            }
    } while (e<=2);
    if(e>2)
    {
        printf("THE LIMIT TO ACCESS THIS SYSTEM EXCEED !!!!");
        getch();
        ex();
    }
    system("cls");
}

void Add(void)
{
    system("cls");
    Title();

    char ans;
    FILE*ek;
    ek = fopen("Record1.dat","a");// open file in write mode
    printf("\n\n\t\t\t ################# PLEASE ADD THE REQUIRMENTS LIST ################# \n");

    A:
    printf("\n\t\t ENTRE YOUR FULL NAME !! : ");
    scanf("%s",p.Full_Name);
    p.Full_Name[0]=toupper(p.Full_Name[0]);
    if(strlen(p.Full_Name)>40 || strlen(p.Full_Name)<2)
    {
       printf(" \n\t INVALID USER NAME LENGTH : ");
       goto A;
    }
    else
    {
        for(int b=0 ;b<strlen(p.Full_Name);b++)
        {
           if(isalpha(p.Full_Name[b]))
           {
               valid=1;
           }
           else
           {
               valid=0;
               break;
           }
        }
        if(!valid)
        {
            printf("\n\n\t\t  NAME CONTAINED INVALID CHARACTOR : (TRY AGAIN)");
            goto A;
        }
    }

     B:
     printf("\n\n\t\t\t\t PLEASE MENTION YOUR GENDER !!! ");
     scanf("%s",&p.Gender);
     p.Gender[0]=toupper(p.Gender[0]);
     if(strcmp(p.Gender,"MALE")==0 || strcmp(p.Gender,"FEMALE")==0)
     {
       for(int b=0 ;b<strlen(p.Gender);b++)
        {
           if(isalpha(p.Gender[b]))
           {
               valid=1;
           }
           else
           {
               valid=0;
               break;
           }
        }
          if(!valid)
        {
            printf("\n\n\t\t  NAME CONTAINED INVALID CHARACTOR : (TRY AGAIN)");
            goto B;
        }
     }
     else
     {
       printf(" \n\t INVALID GENDER INPUT : ");
       goto B;
     }

    C:
    printf("\n\n\t\t\t PLEASE ENTRE THE NUMBER OF ASTRONAUT !!!");
    scanf("%i",&p.no_astronaut);
    if(strcmp(p.no_astronaut,'4')==0 || strcmp(p.no_astronaut,'6')==0)
    {
        for(int b=0 ;b<strlen(p.Gender);b++)
        {
           if(isalpha(p.Gender[b]))
           {
               valid=1;
           }
           else
           {
               valid=0;
               break;
           }
        }
          if(!valid)
        {
            printf("\n\n\t\t  INVALID INPUT OF THE NUMBER OF ASTRONAUTS : (TRY AGAIN)");
            goto C;
        }
    }
     else
     {
       printf(" \n\t INVALID NUMBER ASTRONAUTS IN THE SPACE STATION PLEASE CHECK : ");
       goto C;
     }

     D: ;
     int n;
     printf("\n\n\t\t PLEASE ENTRE THE NUMBER OF PRODUCTS YOU WANT TO ENTRE !!");
     scanf("%i",&n);
     printf("\n\n\t\t\t\t PLEASE ENTRE THE LIST OF REQUIREMETNS !!! \n\n\t");
     if(n<25)
     for(int i=0;i<n;i++)
     {
        {
            scanf("%s",&p.Product[i]);
        }
     }
     else
     {
         printf("\n\n\t\t\t THE INPUT CAPACITY IS 25 AT MAX !!!");
         goto D;
     }

     printf(" \n\n\t\t PLEASE INPUT THE COST OF THE EACH ITEM \n\n");
       for(int i=0;i<n;i++)
     {
        {
            scanf("%i",&p.cost[i]);
        }
     }
     fprintf(ek,"%i %s %s %s %i",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
     printf("\n\n\t\t\t\t <<<<<<INFORMATION RECORD SUCCESSFULL >>>>>>> ");
     fclose(ek);
     sd:
     getch();
     printf("\n\t\t ......DO YOU WISH TO ADD MORE[Y/M]....... ");
     scanf("%c",&ans);
     if(toupper(ans)=='Y')
     {
         Add();
     }
     else if(toupper(ans)=='N')
     {
         printf("\n\n\t\t THANK YOU ");
         getch();
         MainMenu();
     }
     else
     {
         printf("\n\t\t INVALID INPUT !!!");
         goto sd;
     }

}

void list()
{
    int row;
    system("cls");
    Title();
    FILE*ek;
    ek=fopen("Record1.dat","r");
    printf("\n\n\n\t\t\t\t !!!!!!!!!!!! LIST OF PRODUCTS !!!!!!!!!!!!!!\n");
    gotoxy(1,15);
    printf("NO OF ASTRONAUTS");
    gotoxy(20,15);
    printf("FULL NAME");
    gotoxy(35,15);
    printf("GENDER");
    gotoxy(49,15);
    printf("LIST");
    gotoxy(64,15);
    printf("COST");
    printf("====================================================================================================================================================================================================================");
    row = 15;
    while(fscanf(ek,"%i %s %s %s %i",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost) != EOF)
    {
      gotoxy(1,row);
      printf("%i",p.no_astronaut);
      gotoxy(20,row);
      printf("%s",p.Full_Name);
      gotoxy(35,row);
      printf("%s",p.Gender);
      gotoxy(49,row);
      printf("%s",p.Product);
      gotoxy(64,row);
      printf("%i",p.cost);
      row++;
    }
      fclose(ek);
      getch();
      MainMenu();
}

void search(void)
{
    char pname[20];
    system("cls");
    Title();
    FILE*ek;
    ek=fopen("Record1.dat","r");
    printf("\n\n\t\t\t\t !!!!!!!!! SEARCH FOR A PRODUCT !!!!!!!!!! \n");
    gotoxy(12,8);
    printf("\n ENTRE PRODUCT NAME TO BE VIEWED: ");
    scanf("%s",pname);
    fflush(stdin);
    pname[0]=toupper(pname[0]);
    while(fscanf(ek,"%i %s %s %s %i",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost) != EOF)
    {
        if(strcmp(p.Product,pname)==0)
        {
         gotoxy(1,15);
         printf("NO OF ASTRONAUTS");
         gotoxy(20,15);
         printf("FULL NAME");
         gotoxy(35,15);
         printf("GENDER");
         gotoxy(49,15);
         printf("LIST");
         gotoxy(64,15);
         printf("COST");
         printf("====================================================================================================================================================================================================================");
         gotoxy(1,18);
         printf("%i",p.no_astronaut);
         gotoxy(20,18);
         printf("%s",p.Full_Name);
         gotoxy(35,18);
         printf("%s",p.Gender);
         gotoxy(49,18);
         printf("%s",p.Product);
         gotoxy(64,18);
         printf("%i",p.cost);
         printf("\n");
         break;
        }
    }
    if(strcmp(p.Full_Name,pname) != 0)
    {
        gotoxy(5,10);
        printf("\n RECORD NOT FOUND !!!");
        getch();
    }
    fclose(ek);

    L:
    getch();
    printf("\n\n\t\t\t DO YOU WANT TO VIEW MORE ITEMS[Y/N] !!!");
    scanf("%c",&ans);
    if(toupper(ans)=='Y')
    {
        search();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t THANK YOU !!");
        getch();
    }
    else
    {
        printf("\n\t INVALID INPUT . \n");
        goto L;
    }
}

void edit(void)
{
    FILE *ek,*ft;
    int i,b, valid=0;
    char ch;
    char name[25];
    system("cls");
    ft=fopen("temp2.dat","wt");
    ek=fopen("Record1.dat","r");
    if(ek==NULL)
    {
        printf("\n\t\t CANT OPEN THE FILE !!!");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t\t <<<<<<<<<EDIT THE LIST >>>>>>>>>>\n");
    gotoxy(12,13);
    printf("ENTRE THE NAME OF THE PRODUCT :");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);
    if(ft==NULL)
    {
        printf("\n CAN NOT OPNE THE FILE !!!");
        getch();
        MainMenu();
    }
    while(fscanf(ek,"%i %s %s %s %i",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost) != EOF)
    {
        if(strcmp(p.Product,name)==0)
        {
            valid = 1;
            gotoxy(25,17);
            printf("*** EXISTING RECORDS ***");
            gotoxy(10,19);
            printf("%i \t%s \t%s \t%s \t%i \n",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
            gotoxy(12,22);
            printf("NO OF ASTRONAUTS");
            scanf("%i",p.no_astronaut);
            gotoxy(12,24);
            printf("FULL NAME");
            scanf("%s",p.Full_Name);
            p.Full_Name[0]=toupper(p.Full_Name[0]);
            gotoxy(12,26);
            printf("GENDER");
            scanf("%s",p.Gender);
            p.Gender[0]=toupper(p.Gender[0]);
            gotoxy(12,28);
            printf("LIST");
            scanf("%s",p.Product);
            p.Product[0]=toupper(p.Product[0]);
            gotoxy(12,30);
            printf("COST");
            scanf("%i",p.cost);
            printf("\n PRESS K CHARECTER TO UPDATE THE FILE :");
            ch=getche();
            if(ch =='k'|| ch=='K')
            {
                fprintf(ft,"%i %s %s %s %i \n",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
                printf("\n\n\n\t\t\t <<<<<<< PRODUCT RECORD UPDATED SUCCESSFULLY >>>>>>> ");
            }
        }
        else
        {
           fprintf(ft,"%i %s %s %s %i \n",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
        }
    }
    if(!valid)
    {
        printf("\n\t\t NO SUCH RECORD FOUND !!");
    }
    fclose(ft);
    fclose(ek);
    remove("Record1.dat");
    rename("temp2.dat","Record1.dat");
    getch();
    MainMenu();
}

void del()
{
    char name[25];
    int found = 0;
    system("cls");
    Title();
    FILE *ek,*ft;
    ft=fopen("temp_file2.dat","w+");
    ek=fopen("Record1.dat","r");
    printf("\n\n\t\t\t !!!!!!!!!!! DELETE THE PRODUCT RECORDS !!!!!!!!!!");
    gotoxy(12,8);
    printf("\n ENTRE THE PRODUCT NAME TO BE DELETED :");
    fflush(stdin);
    getw (name);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%i %s %s %s %i",p.no_astronaut,p.Full_Name,p.Gender,&p.Product,&p.cost) != EOF)
    {
        if(strcmp(p.Product,name)!=0){
         fprintf(ft,"%i %s %s %s %i\n",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
        }
        else
        {
            printf("%i %s %s %s %i\n",p.no_astronaut,p.Full_Name,p.Gender,p.Product,p.cost);
            found=1;
        }
    }
   if(found ==0)
   {
       printf("\n\n\n\n\t\t RECORD NOT FOUND !!!!");
       getch();
       MainMenu();
   }
   else
   {
       fclose(ek);
       fclose(ft);
       remove("Record1.dat");
       rename("temp_file2.dat","Record1.dat");
       printf("\n\t DATA ERASED SUCCESFULLY !");
       getch();
       MainMenu();
   }

}

void ex(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\t\t\t THANKS FOR VISITING !!!");
    getch();
}

