#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<windows.h>
#include<time.h>



void doctor(void);
void staff(void);
void menu(void);
void patient(void);
void medicine(void);
void credits(void);
void help(void);


int n=0;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void time()
{
            time_t currentTime = time(0);

            SetConsoleTextAttribute(h,14);
	    	printf("It Is Currently %s\n\n", ctime(&currentTime));
	    	SetConsoleTextAttribute(h,15);
}

/*------------------------------MENU--------------------------------------*/
void menu()
{

                int choice;
                time();
                SetConsoleTextAttribute(h,14);
                printf("\t\t  =======================================\n");
                printf("\t\t  ||             MAIN MENU             ||\n");
                printf("\t\t  =======================================\n\n");
                SetConsoleTextAttribute(h,15);
                printf("\t\t1.DOCTOR SECTION");
                printf("\n\t\t2.PATIENT SECTION");
                printf("\n\t\t3.STAFF SECTION");
                printf("\n\t\t4.MEDICINE SECTION");
                printf("\n\t\t5.HELP");
                printf("\n\t\t6.CREDITS");
                printf("\n\t\t7.EXIT");
                printf("\n\n\tEnter your choice: ");
                fflush(stdin);
                scanf("%d",&choice);

                switch(choice)
                {
                    case 1:
                            doctor();
                            break;
                    case 2:
                            patient();
                            break;
                    case 3:
                            staff();
                            break;
                    case 4:
                            medicine();
                            break;
                    case 5:
                            help();
                            break;
                    case 6:
                            credits();
                            break;
                    case 7:
                            exit(1);
                }
}

/*-----------------------------------------DOCTORS SECTION----------------------------------------------*/

void doctor()
{

    char day1[]="saturday",day2[]="sunday",day3[]="monday",day4[]="tuesday",day5[]="wednesday",day6[]="thursday",day7[]="friday";
    char d1[25],d2[25],d3[25],d4[25],d5[25],d6[25],d7[25];
    int choice;
    system("cls");

    SetConsoleTextAttribute(h,14);
    l:
    {
    time();
    SetConsoleTextAttribute(h,14);
    printf("\t\t  =======================================\n");
    printf("\t\t  ||           DOCTORS SECTION         ||\n");
    printf("\t\t  =======================================\n\n");
    SetConsoleTextAttribute(h,15);

    printf("\n\t\t1.Appointed Doctor's List\t2.Work schedule\n\n\t\t3.Salary of a Doctor\t\t4.Main Menu\n\n\t\t\tEnter Your Choice :");
    scanf("%d",&choice);
    }

    if(choice==1)
    {
        system("cls");
        time();

        char a;
    FILE *fp;
	fp = fopen("doctorslist.txt","r");
	while(fscanf(fp,"%c",&a)!=EOF)
	{
	printf("%c",a);
	}
    getch();
    }

    if(choice==2)
    {
        system("cls");
        time();

    char a;

{
    FILE *fp;
	fp = fopen("wrkngsc.txt","r");
	while(fscanf(fp,"%c",&a)!=EOF)
	{
	printf("%c",a);
	}
    getch();
}



    }
    if(choice==3)
    {
    char a;
    float mnthslry1,mnthslry2,leave,basic,x,month,allownces,hra,expns;
    printf("\n\nEnter his/her basic salary :");
    scanf("%f",&basic);
    printf("\nEnter total working days :");
    scanf("%f",&month);
    printf("\nDid he/she take any leave?<Y=Yes N=No> :");
    a=getch();
    getch();
    if(a=='Y'||a=='y')
    {
        printf("\n\nenter day of leave taken : ");
    scanf("%f",&leave);
    mnthslry1 = ((basic/month)*leave);
    x= basic-mnthslry1;
    printf("Total salary = %f",x);
    }
    if(a=='N'||a=='n')
    {
    printf("\n\nEnter his/her monthly allowances :");
    scanf("%f",&allownces);
    printf("\nEnter his/her monthly HRA :");
    scanf("%f",&hra);
    printf("\nEnter his/her expenses :");
    scanf("%f",&expns);
        mnthslry2 = (basic+allownces+hra+expns);
        printf("\n\nHis/her Salary is = %0.3f",mnthslry2);
    }
    getch();
    }
    if(choice==4)
    {
        system("cls");
        menu();
    }
    system("cls");
    goto l;
}
/*-----------------------------------------DOCTORS SECTION END----------------------------------------------*/

/*-----------------------------------------STAFF SECTION START----------------------------------------------*/

struct record
{
	char name[35];
	int age;
	char phone[15];
	char email[50];


}
employee[50];


void staff()
{


    int choice,l;
    system("cls");
    time();
    l:
    {
    SetConsoleTextAttribute(h,14);
    printf("\t\t  =======================================\n");
    printf("\t\t  ||            STAFF SECTION          ||\n");
    printf("\t\t  =======================================\n\n");
    SetConsoleTextAttribute(h,15);
    printf("\n\t\t\t1.Add new Staff record into archive\n\t\t\t2.List Of Staff\n\t\t\t3.Search Staff record\n\t\t\t4.Delete Staff record\n\t\t\t5.Salary\n\t\t\t6.Main Menu\n\n\t\t\tEnter Your Choice :");
    scanf("%d",&choice);
    }
/* ADD STAFF INFO*/

    if(choice==1)
    {
    system("cls");
    time();
    printf("\t\tADDING STAFF INFORMATION");
    printf("\n\nEnter the name of the Staff: ",n+1);
  // getch();
	scanf("%s",employee[n].name);
	printf("\nEnter the age of the Staff: ",n+1);
	scanf("%d",&employee[n].age);
	printf("\nEnter the phone number of the Staff: ",n+1);
    scanf("%s",employee[n].phone);
	printf("\nEnter the e-mail of the Staff: ",n+1);
	scanf("%s",employee[n].email);
	printf("\nRecord has been added");
	getch();
	n++;

    }
 /* LIST OF STAFF */
    if(choice==2)
    {
        system("cls");
        time();

        	if (n==0)
		printf("Empty");
	else
		for (int i=0;i<n;i++)
            {
            printf("\t\t\tLIST OF STAFFS\n");
            printf("\nName\tAge\tPhone\tEmail");
            printf("\n=======================================");
			printf("\n\n%s\t%d\t%s\t%s\n",employee[i].name,employee[i].age,employee[i].phone,employee[i].email);
			}

	getch();
    }

/* SEARCH STAFF*/
    if(choice==3)
    {
        system("cls");
        time();

        char ph[34];
	int found=0;
	if (n==0) printf("no data");
	else
        {
        printf("\t\tSEARCHING OF STAFF");
		printf("\nEnter the phone number of the Staff you want to search:");
		scanf("%s",ph);
	//gets(ph);
		for (int i=0;i<n;i++){
			if (strcmp(ph,employee[i].phone)==0)
            {
				found=1;
                printf("Name\tAge\tPhone\tEmail");
                printf("\n=======================================");
				printf("\n%s\t%d\t%s\t%s",employee[i].name,employee[i].age,employee[i].phone,employee[i].email);
				break;
			}
		}
		if (found==0)
			printf("not found");
	}
		getch();
    }
/* DELETE STAFF INFO*/
    if(choice==4)
    {
        system("cls");
        time();

        char ph[23];
	 int i,j;
	 int found=0;
	 printf("\t\tDELETATION OF STAFF INFORMATION\n\n");
	 if (n==0)
    {
        printf("no data");
        getch();
     }
	 else
        {
        printf("Enter the phone number of Staff you want to delete:");
        scanf("%s",ph);
        for (i=0; i<n; i++){
		if (strcmp(ph,employee[i].phone)==0)
		{
			found=1;
			printf("\n\nThe Number is Delete successfully\n\n");

			break;
		}
	}
	if (found==0)
		printf("The Staff you want to delete is not found");
	else{
		for(j=i; j<n; j++){
			strcpy(employee[j].name,employee[j+1].name);
			employee[j].age=employee[j+1].age;
			strcpy(employee[j].phone,employee[j+1].phone);
			strcpy(employee[j].email,employee[j+1].email);
		}
		n--;
	}
	 }

    }
    if(choice==5)
    {
    char a;
    float mnthslry1,mnthslry2,leave,basic,x,month,allownces,hra,expns;
    system("cls");
    printf("\t\t\t\tSALARY OF A STAFF");
    printf("\n\nEnter his/her basic salary :");
    scanf("%f",&basic);
    printf("\nEnter total working days :");
    scanf("%f",&month);
    printf("\nDid he/she take any leave?<Y=Yes N=No> :");
    a=getch();
    getch();
    if(a=='Y'||a=='y')
    {
        printf("\n\nenter day of leave taken : ");
    scanf("%f",&leave);
    mnthslry1 = ((basic/month)*leave);
    x= basic-mnthslry1;
    printf("\nTotal salary = %f",x);
    }
    if(a=='N'||a=='n')
    {
    printf("\n\nEnter his/her monthly allowances :");
    scanf("%f",&allownces);
    printf("\nEnter his/her monthly Tiffin Bill :");
    scanf("%f",&hra);
    printf("\nEnter his/her expenses :");
    scanf("%f",&expns);
        mnthslry2 = (basic+allownces+hra+expns);
        printf("\n\nHis/her Salary is = %0.3f",mnthslry2);
    }
    getch();
    }
    if(choice==6)
    {
        system("cls");
        menu();
    }
    system("cls");
    goto l;
}
/*-----------------------------------------STAFF SECTION END----------------------------------------------*/


/*-----------------------------------------PATIENT SECTION START----------------------------------------------*/
struct address
{
                int houseno;
                char streetno[50];
                char area[50];
                char city[50];
                char country[40];
};

struct patient
{
                char name[40];
                char fname[40];
                int age;
                char bg[3];
                char reginum[10];
                struct address a;
                char ph[10];
                char gender;
                char disease[60];
                char doc_name[40];
                char history[200];
                char date[10];
                char treatment[40];
                char medicine[40];
};



void patient()
{

    FILE *fp,*ft;
    char another,ch;
    float cabin,ward,outdoor;
    char ca[]="cabin",wa[]="ward",ou[]="outdoor";
    char b[10];
    char reg[20],pname[40];
    int iF=0;
    long int recsize;
    struct patient p;
    fp=fopen("patient.DAT","ra+");
    if(fp==NULL)
    {
        fp=fopen("patient.DAT","wa+");
        if(fp==NULL)
        {
            puts("\nSorry!! Cannot open file");
            exit(1);
        }
    }
    recsize = sizeof(p);
    while(1)
    {

/* DISPLAY OF OPTIONS */
        system("cls");
        time();
        SetConsoleTextAttribute(h,14);
        printf("\t\t  =======================================\n");
        printf("\t\t  ||           PATIENT SECTION         ||\n");
        printf("\t\t  =======================================\n\n");
        SetConsoleTextAttribute(h,15);
        printf("\n\t\t1.Enter New Patient Entry");
        printf("\n\t\t2.Modify Existing Entry of Patient");
        printf("\n\t\t3.Search an Entry of Admitted Patient");
        printf("\n\t\t4.List of Admitted Patients");
        printf("\n\t\t5.Delete an Entry of Patient");
        printf("\n\t\t6.Bill");
        printf("\n\t\t7.Main Menu");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {
/* ADDITION OF RECORDS */

        case 1:
            fseek(fp,0,SEEK_END);
            another='Y';
            while(another=='Y'||another=='y')
            {
                w:
                system("cls");
                printf("\t\t\tAdding Patient Information\n");
                printf("\n\n\nEnter Serial Number: ");
                scanf("%s",reg);
                rewind(fp);
/* CHECKING FOR Serial NUMBER */
                while(fread(&p,recsize,1,fp)==1)
                {
                    if(strcmp(p.reginum,reg)==0)
                    {
                        iF=1;
                        printf("\n\t\tSERIAL NUMBER EXISTS. ENTER NEW ONE");
                        getch();
                        goto w;
                    }
                }
                if(iF==0||fread(&p,recsize,1,fp)==0)
                {
                    fseek (fp,0,SEEK_END);
                    strcpy(p.reginum,reg);
                    fflush(stdin);
                    printf("\nEnter patient name: ");
                    scanf("%s",p.name);
                    printf("\nEnter Guardian name: ");
                    scanf("%s",p.fname);
                    printf("\nEnter patient Gender(M.male or F.female): ");
                    scanf("%s",&p.gender);
                    printf("\nEnter patient Blood group: ");
                    scanf("%s",p.bg);
                    printf("\nEnter patient age: ");
                    scanf("%d",&p.age);
                    printf("\nEnter patient address:\n");
                    printf("\n\tEnter house number: ");
                    scanf("%d",&p.a.houseno);
                    fflush(stdin);
                    printf("\n\tEnter road no. : ");
                    scanf("%s",p.a.streetno);
                    printf("\n\tEnter area : ");
                    scanf("%s",p.a.area);
                    printf("\n\tEnter city: ");
                    scanf("%s",p.a.city);
                    printf("\n\tEnter country: ");
                    scanf("%s",p.a.country);
                    printf("\nEnter Guardians phone number: ");
                    scanf("%s",p.ph);
                    fflush(stdin);
                    printf("\nEnter the Disease for which he/she wants treatment: ");
                    scanf("%s",p.disease);
                    printf("\nEnter Doctor name which he/she is referred: ");
                    scanf("%s",p.doc_name);
                    printf("\nenter date of treatment given: ");
                    scanf("%s",p.date);
                    printf("\nEnter detail of treatment given: ");
                    scanf("%s",p.treatment);
                    printf("\nEnter prescribed medicines: ");
                    scanf("%s",p.medicine);
                    printf("\nEnter history,if any,related to treatment of the patient(otherwise write NOT AVAILABLE): ");
                    scanf("%s",p.history);
                    fwrite(&p,recsize,1,fp);
                    printf("\n\nThe Record has been added to Library");
                    printf("\n----------------------------------------------------");
                    printf("\nWant to add entry of another Patient(Y/N): ");
                    fflush(stdin);
                    another=getche();
                }
            }
            break;

/* MODIFICATION OF EXISTING RECORDS */
        case 2:
            another='Y';
            while(another=='Y'||another=='y')
            {
                system("cls");
                printf("\t\tModification of Admitted Patients\n");
                printf("\nEnter desired Serial number of patient to modify: ");
                scanf("%s",reg);
                rewind(fp);
                while(fread(&p,recsize,1,fp)==1)
                {
                    if(strcmp(p.reginum,reg)==0)
                    {
                        fflush(stdin);
                        printf("\nEnter new Patient name : ");
                        scanf("%s",p.name);
                        printf("\nEnter Guardian name: ");
                        scanf("%s",p.fname);
                        printf("\nEnter patient new Blood group: ");
                        scanf("%s",p.bg);
                        printf("\nEnter patient new age: ");
                        scanf("%d",&p.age);
                        printf("\nEnter the new address of the patient:\n");
                        printf("\n\tEnter the house number: ");
                        scanf("%d",&p.a.houseno);
                        fflush(stdin);
                        printf("\n\tEnter road no. : ");
                        scanf("%s",p.a.streetno);
                        printf("\n\tEnter area : ");
                        scanf("%s",p.a.area);
                        printf("\n\tEnter city: ");
                        scanf("%s",p.a.city);
                        printf("\n\tEnter country: ");
                        scanf("%s",p.a.country);
                        printf("\nEnter guardian's new phone number: ");
                        scanf("%s",p.ph);
                        fflush(stdin);
                        printf("\nenter new date of treatment given: ");
                        scanf("%s",p.date);
                        printf("\nEnter detail of treatment given: ");
                        scanf("%s",p.treatment);
                        printf("\nEnter new medicines prescribed: ");
                        scanf("%s",p.medicine);
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&p,recsize,1,fp);
                        break;
                    }
                }
                printf("\nNo entry is saved by this Serial number\n");
                printf("\n----------------------------------------------------");
                printf("\nModify another Record(Y/N): ");
                fflush(stdin);
                another=getche();
            }
            break;

/*SEARCHING A PARTICULAR ENTRY (BY NAME) */

        case 3:
            another='Y';
            while(another=='Y'||another=='y')
            {
                system("cls");
                printf("\t\t\tSearching of Admitted Patients\n");
                printf("\nEnter Serial number to search: ");
                scanf("%s",reg);
                rewind(fp);
                while(fread(&p,recsize,1,fp)==1)
                {
                    if(strcmp(p.reginum,reg)==0)
                    {

                        printf("\nName of Patient : ");
                        printf("%s",p.name);
                        printf("\nName of Guardian : ");
                        printf("%s",p.fname);
                        printf("\nAge : %d",p.age);
                        printf("\nGender : %c",p.gender);
                        printf("\nBlood group: %s",p.bg);
                        printf("\nAddress  : House no-%d,Road no-%s,Area-%s,City-%s,Country-%s",p.a.houseno,p.a.streetno,p.a.area,p.a.city,p.a.country);
                        printf("\nphone number : +88%s",p.ph);
                        printf("\nDisease : %s",p.disease);
                        printf("\nEarlier History : ");
                        printf("%s",p.history);
                        printf("\nDetails of treatment given and medicine prescribed:");
                        printf("\nDATE\t\tTREATMENT GIVEN\t\tMEDICINE PRESCRIBED\n");
                        printf("%s\t\t\t %s\t\t %s\n",p.date,p.treatment,p.medicine);
                        printf("\nName of Doctor : ");
                        printf("%s",p.doc_name);
                    }
                }

                printf("\n----------------------------------------------------");
                printf("\nSearch another Entry(Y/N): ");
                fflush(stdin);
                another=getche();
            }
                break;

/* LISTING OF ALL RECORDS */
        case 4:
            rewind(fp);
            while(fread(&p,recsize,1,fp)==1)
            {
                system("cls");
                printf("\t\t\tList of Admitted Patients\n");
                printf("\nSerial Number of Patient : ");
                printf("%s",p.reginum);
                printf("\nName of Patient : ");
                printf("%s",p.name);
                printf("\nName of Guardian : ");
                printf("%s",p.fname);
                printf("\nAge : %d",p.age);
                printf("\nGender : %c",p.gender);
                printf("\nBlood group: %s",p.bg);
                printf("\nAddress  : House no-%d,Road no-%s,Area-%s,city-%s,country-%s",p.a.houseno,p.a.streetno,p.a.area,p.a.city,p.a.country);
                printf("\nphone number : +88%s",p.ph);
                printf("\nDisease : %s",p.disease);
                printf("\nEarlier History : ");
                printf("%s",p.history);
                printf("\nDetails of treatment given and medicine prescribed:");
                printf("\nDATE\t\t TREATMENT GIVEN\t\t\t MEDICINE PRESCRIBED\n");
                printf("%s\t\t %s\t\t\t %s\n",p.date,p.treatment,p.medicine);
                printf("\nName of Doctor : ");
                printf("%s",p.doc_name);
                printf("\n----------------------------------------------------\n");
            }
            getch();
            break;

/* DELETION OF RECORD */

        case 5:
            another='Y';
            while(another=='Y'||another=='y')
            {
                printf("\nEnter desired patient's Serial number to delete : ");
                scanf("%s",reg);
                ft=fopen("temp.DAT","wa+");
                rewind(fp);
                while(fread(&p,recsize,1,fp)==1)
                {
                    if(strcmp(p.reginum,reg)!=0)
                        fwrite(&p,recsize,1,ft);
                    else
                        printf("\nThe Record has been Deleted Successfully.");
                }
                fclose(fp);
                fclose(ft);
                remove("patient.DAT");
                rename("temp.DAT","patient.DAT");
                fp=fopen("patient.DAT","ra+");
                printf("\nDelete another record?(Y/N): ");
                fflush(stdin);
                another=getche();
            }
            break;

        case 6:
            {
                int v;
                float f;
                system("cls");
                printf("\t\t\t\tBILLING");
                printf("\n\nEnter section of patient's living :");
                scanf("%s",b);
                if(strcmp(ca,b)==0)
                {
                    printf("\nEnter amount of staying in this section per night <in BDT> : ");
                    scanf("%f",&cabin);
                    printf("\nHow much day patient being in hospital :");
                    scanf("%d",&v);
                    f=v*cabin;
                    printf("\nPatienet's Bill is : %0.4fBDT",f);
                    getch();
                }
                if(strcmp(wa,b)==0)
                {
                    printf("\nEnter amount of staying in this section per night <in BDT> : ");
                    scanf("%f",&ward);
                    printf("\nHow much day patient being in hospital :");
                    scanf("%d",&v);
                    f=v*ward;
                    printf("\nPatienet's Bill is : %0.4fBDT",f);
                    getch();
                }
                if(strcmp(ou,b)==0)
                {
                    printf("\nEnter amount of staying in this section per night <in BDT> : ");
                    scanf("%f",&outdoor);
                    printf("\nHow much day patient being in hospital :");
                    scanf("%d",&v);
                    f=v*outdoor;
                    printf("\nPatienet's Bill is : %0.4fBDT",f);
                    getch();
                }
            }
            break;

        case 7:
        {
            fclose(fp);
            system("cls");
            menu();
        }
        break;
        }
    }
}
/*-----------------------------------------PATIENT SECTION END----------------------------------------------*/

/*-----------------------------------------MEDICINE SECTION START----------------------------------------------*/

struct medicine
{
                int serialno;
                char name[30];
                char dop[20];
                int quantity;
                float price;
                float amount;
};

void medicine()
{
    FILE *fi,*fy;
    char a;
    int m;
    char i_name[40];
    int iF=0,j=1;
    long int recordsize2;
    struct medicine v;
    fi=fopen("medicine.DAT","rb+");
    if(fi==NULL)
    {
        fi=fopen("medicine.DAT","wb+");
        if(fi==NULL)
        {
            puts("\nSorry!! Cannot open file");
            exit(1);
        }
    }
    recordsize2=sizeof(v);
    while(1)
    {
/* DISPLAY OF OPTIONS */
        system("cls");
        time();
        SetConsoleTextAttribute(h,14);
        printf("\t\t  =======================================\n");
        printf("\t\t  ||          MEDICINE SECTION         ||\n");
        printf("\t\t  =======================================\n\n");
        SetConsoleTextAttribute(h,15);
        printf("\n\t\t1.Add an Item");
        printf("\n\t\t2.Modify Existing Item");
        printf("\n\t\t3.Search an Item");
        printf("\n\t\t4.List of all Items");
        printf("\n\t\t5.Delete an Item");
        printf("\n\t\t6.Main Menu");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d",&m);
        switch(m)

        {
/* ADDITION OF RECORDS */
            case 1:
                fseek(fi,0,SEEK_END);
                a='Y';
                while(a=='Y'||a=='y')
                {
                    x:
                    system("cls");
                    printf("\t\t\tADDING AN ITEM\n");
                    printf("\n\n\nEnter Item name: ");
                    scanf("%s",i_name);
                    rewind(fi);
/* CHECKING FOR EXISTANCE OF NAME */
                    while(fread(&v,recordsize2,1,fi)==1)
                    {
                        if(strcmp(v.name,i_name)==0)
                        {
                            iF=1;
                            SetConsoleTextAttribute(h,10);
                            printf("\n\t\tITEM ALREADY IN HOSPITAL.");
                            SetConsoleTextAttribute(h,15);
                            goto x;
                        }
                    }
                    if(iF==0||fread(&v,recordsize2,1,fi)==0)
                    {
                        fseek (fi,0,SEEK_END);
                        strcpy(v.name,i_name);
                        fflush(stdin);
                        printf("\nEnter Date of purchase: ");
                        scanf("%s",v.dop);
                        fflush(stdin);
                        printf("\nEnter Quantity of Item: ");
                        scanf("%d",&v.quantity);
                        printf("\nEnter price of One Item: ");
                        scanf("%f",&v.price);
                        v.amount=v.quantity*v.price;
                        printf("\nThe amount of %d piece %s is = %0.3f BDT",v.quantity,v.name,v.amount);
                        fwrite(&v,recordsize2,1,fi);
                        printf("\n\n----------------------------------------------------");
                        printf("\nWant to add entry of the another Item(Y/N): ");
                        fflush(stdin);
                        a=getche();
                    }
                }
                break;

/* MODIFICATION OF EXISTING RECORDS */

        case 2:
            a='Y';
            while(a=='Y'||a=='y')
            {
                system("cls");
                printf("\t\tMODIFYING AN ITEM\n");
                printf("\nEnter the name of the item to modify: ");
                scanf("%s",i_name);
                rewind(fi);
                while(fread(&v,recordsize2,1,fi)==1)
                {
                    if(strcmp(v.name,i_name)==0)
                    {
                        fflush(stdin);
                        printf("\nEnter new name of Item: ");
                        scanf("%s",v.name);
                        printf("\nEnter new Date of purchase: ");
                        scanf("%s",v.dop);
                        printf("\nEnter new Quantity of Item: ");
                        scanf("%d",&v.quantity);
                        printf("\nEnter new price of One Item: ");
                        scanf("%f",&v.price);
                        v.amount=v.quantity*v.price;
                        printf("\nThe amount of %d piece %s is = %0.3f BDT",v.quantity,v.name,v.amount);
                        fseek(fi,-recordsize2,SEEK_CUR);
                        fwrite(&v,recordsize2,1,fi);
                        break;
                    }
                }
                printf("\nNo Item is saved by this name\n");
                printf("\n----------------------------------------------------");
                printf("\nModify another Item(Y/N): ");
                fflush(stdin);
                a=getche();
            }
            break;
/*SEARCHING A PARTICULAR ENTRY BY NAME*/
            case 3:
                a='Y';
                while(a=='Y'||a=='y')
                {
                    system("cls");
                    printf("\t\tSEARCHING AN ITEM\n");
                    printf("\nEnter item name to search: ");
                    scanf("%s",&i_name);
                    rewind(fi);
                    while(fread(&v,recordsize2,1,fi)==1)
                    {
                        if(strcmp(v.name,i_name)==0)
                        {
                            printf("ITEM\t DOP\t    QUANTITY\t PRICE\t\t AMOUNT\n");
                            printf("%s\t %s   %d piece\t BDT.%0.3f\t BDT.%0.3f\n",v.name,v.dop,v.quantity,v.price,v.amount);
                        }
                    }

                    printf("\n----------------------------------------------------");
                    printf("\nSearch another Item(Y/N): ");
                    fflush(stdin);
                    a=getche();
                }
                break;
/* LISTING OF ALL RECORDS */

        case 4:
            system("cls");
            printf("S.No.\t ITEM\t DOP\t    QUANTITY\t PRICE\t\t AMOUNT\n");
            printf("-----------------------------------------------------------------------------\n");
            rewind(fi);
            while(fread(&v,recordsize2,1,fi)==1)
            {
                printf("%d\t %s\t %s   %d piece\t BDT.%0.3f\t BDT.%0.3f\n",j,v.name,v.dop,v.quantity,v.price,v.amount);
                j++;
            }
            getch();
            break;

/* DELETION OF RECORD */

        case 5:
            a='Y';
            while(a=='Y'||a=='y')
            {
                system("cls");
                printf("\t\tDELETATION OF ITEM\n");
                printf("\nEnter Item name to deleted: ");
                scanf("%s",i_name);
                fy=fopen("temporary.DAT","wb+");
                rewind(fi);
                while(fread(&v,recordsize2,1,fi)==1)
                {
                    if(strcmp(v.name,i_name)!=0)
                    fwrite(&v,recordsize2,1,fy);
                    else
                    printf("\nThe item has been Deleted Successfully.");
                }
                fclose(fi);
                fclose(fy);
                remove("medicine.DAT");
                rename("temporary.DAT","medicine.DAT");
                fi=fopen("medicine.DAT","rb+");
                printf("\nDelete another record?(Y/N): ");
                fflush(stdin);
                a=getche();
            }

        case 6:
            {
                fclose(fi);
                system("cls");
                menu();
            }
            break;
        }
    }
}
/*-----------------------------------------MEDICINE SECTION END----------------------------------------------*/

/*-----------------------------------------HELP MENU----------------------------------------------*/

void help()
{
    system("cls");
    time();
    SetConsoleTextAttribute(h,14);
    printf("\t\t=======================================\n");
    printf("\t\t||               HELP                ||\n");
    printf("\t\t=======================================\n\n");
    SetConsoleTextAttribute(h,15);
    char a;
    FILE *fp;
	fp = fopen("help.txt","r");
	while(fscanf(fp,"%c",&a)!=EOF)
	{
	printf("%c",a);
	}
    SetConsoleTextAttribute(h,4);
    printf("\n\n\n \t\t\t\t\t\tPress any key to continue ....");
    SetConsoleTextAttribute(h,15);
    getch();
    system("cls");
    menu();

}
/*-----------------------------------------HELP MENU----------------------------------------------*/

/*-----------------------------------------CREDITS----------------------------------------------*/

void credits()
{
    system("cls");
    time();
    SetConsoleTextAttribute(h,14);
    printf("\t\t=======================================\n");
    printf("\t\t||              CREDITS              ||\n");
    printf("\t\t=======================================\n\n");
    SetConsoleTextAttribute(h,15);
    char b;
    FILE *sp;
	sp = fopen("aboutus.txt","r");
	while(fscanf(sp,"%c",&b)!=EOF)
	{
	printf("%c",b);
	}
	SetConsoleTextAttribute(h,4);
    printf("\n\n\n \t\t\t\t\t\tPress any key to continue ....");
    SetConsoleTextAttribute(h,15);
    getch();
    system("cls");
    menu();

}
/*-----------------------------------------CREDITS----------------------------------------------*/

/*-----------------------------------------MAIN FUNCTION----------------------------------------------*/

int main()
{
    int choice;
	char pwrd[]="*";
	char temp1[25] , temp2[25] , uname[]="mh" , ch;
	int i=0;
    p:
    {
    system("cls");
    time();

    SetConsoleTextAttribute(h,13);

    printf("\t    ===================================================\n");
    printf("\t    ||            Please Log in to continue          ||\n");
    printf("\t    ===================================================\n\n");
    SetConsoleTextAttribute(h,15);
	printf("\n                           Enter username: ");
	scanf("%s",temp1);                                          /*ask for user name*/
	printf("\n\n                           Enter password: ");
	scanf("%s",temp2);                      /*ask for password*/

	if(!strcmp(uname,temp1)&&!strcmp(temp2,pwrd)) //6
    {

    system("COLOR 2");
	printf("\n\n                           User Access Granted\n\n\n");
    printf("\n\n                          ******* Welcome ******\n\n\n");
    SetConsoleTextAttribute(h,14);
    printf("\n\t\t\tplease press ENTER to continue");
    getch();
    system("cls");
    menu();

    }

    else
    {
        system("COLOR 4 ");
		printf("\n\n\n\n                   Given Username/Password didn't match");
		system("COLOR 4 ");
		printf("\n\n                   Enter Correct One Please\n\n\n");
		getch();
        goto p;
    }

    getch();
    return 0;
}
}

/*-----------------------------------------END OF PROGRAM----------------------------------------------*/
