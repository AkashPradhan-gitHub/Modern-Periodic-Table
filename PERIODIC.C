#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct element
{
	char name[10];
	char sy[5];
	int atm;
	float atms;
	char block[10];
	char atc[20];
	char prop[250];	
}p,q;

FILE *fp;
void add();
void explore();
void print();
void mainmenu();

int main()
{
	int ch;

	clrscr();
	mainmenu();
	while(1)
	{
	printf("\n\n\t\tEnter the corresponding no\n");
	printf("\n\n\t\t1.Explore Element\n");
	printf("\t\t2.Add new Element Information\n");

	printf("\t\t3.Quit");
	printf("\n\n\t\tEnter choice(1-3):");
	scanf("%d",&ch);
	switch(ch)
	{
		case 2:
			add();
			clrscr();
			printf("\nPRESS ANY KEY TO GO TO MAIN MANU\n");
			getch();
			mainmenu();
			break;
		case 1:
			explore();
			clrscr();
			mainmenu();
			getch();
			break;

		case 3:
			printf("Thank you ...BYE");
			getch();
			exit(0);
			break;
		default:
			printf("\nWrong choice\n");
			getch();
			clrscr();
			mainmenu();
			break;
	}
      }

}

void add()
{
	int ch,c;
	clrscr();


	mainmenu();
	printf("Are you sure to enter new elememt(y/n)");
	c=getch();
	if(c=='n')
	{
	   main();
	}
	label1:
	printf("\n\t\tEnter the Information of Elements:");

	printf("\n\n\tName:");
	scanf("%s",&p.name);

	printf("\n\tSymbol:");
	scanf("%s",&p.sy);

	printf("\n\tAtomic No: ");
	scanf("%d",&p.atm);

	printf("\n\tAtomic Wt: ");
	scanf("%f",&p.atms);


	printf("\n\tBlock:");
	scanf("%s",&p.block);

	printf("\n\tProperties:");
	scanf("%s",&p.prop);


	 fp=fopen("akash","ab+");
	if(fp==NULL)
	{
		printf("Empty file");
		exit(0);
	}
	fwrite(&p,sizeof(p),1,fp);
   fclose(fp);
   printf("\n\n\t\tDo you want to enter more element(y/n)");
   c=getch();
   if(c=='y')
   {	clrscr();
       goto label1;
   }
   else
	main();
}

void  explore()
{
	char ch,c;
	FILE *fp;
	int atm_no;
	float atm_mass;
	int flag;
	char string[20],str[10];
	clrscr();
	mainmenu();
	//clrscr();
	while(1)
	{
	label2:
	printf("\n\n\t\tEnter the corresponding no\n");
	printf("\n\n\t\t1.Search by 'NAME'");
	printf("\n\t\t2.Search by SYMBOL");
	printf("\n\t\t3.Search by ATOMIC NUMBER");
	printf("\n\t\t4.Search by ATOMIC WEIGHT");
	printf("\n\t\t5.Elements of Diff. Blocks");
	printf("\n\t\t6.Return to main menu");
	scanf("%d",&ch);
	switch(ch)
       {
		case 1:
		{
			clrscr();
			mainmenu();
			printf("\n\n\n\t\tEnter the Name of Element:");
			scanf("%s",string);

			if((fp=fopen("akash","ab+"))==NULL)                  //file open
			{
			//clrscr();
			printf("\n Empty file file");
			getch();
			exit(1);
			}
			flag=1;

			while(fread(&p,sizeof(p),1,fp))
			{

				 if(strcmp(p.name,string)==0)
				{
					print();

					//printf("in if");
					flag=0;

					break;
				 }

			}
			if(flag==1)
			{
			      clrscr();
			      mainmenu();

				printf("\n::No Element Available::");

			}

			fclose(fp);
			getch();
			clrscr();
			mainmenu();
		     //	goto label2;
			break;
		}


		case 2:
		  {
		     clrscr();
		      mainmenu();
		      printf("\n\n\n\t\tEnter the symbol:");
		      scanf("%s",&string);

		      if((fp=fopen("akash","rb+"))==NULL)
			{
			//clrscr();

				printf("\n cannot open the record file 1");
				getch();
				exit(1);
			}
			flag=1;

			while(fread(&p,sizeof(p),1,fp))
			{

				 if(strcmp(p.sy,string)==0)
				{
					print();
					flag=0;
					break;
				 }

			}
			if(flag==1)
			{
				printf("\n::No Element Available::");
			}

			fclose(fp);
			getch();
			clrscr();
			mainmenu();
		      //	goto label2;
			break;

		   }


		case 3:
		   {
			clrscr();
			mainmenu();
			printf("\n\n\n\t\tEnter the Atomic No. Element:");
			scanf("%d",&atm_no);

			if((fp=fopen("akash","rb+"))==NULL)
			{
			//clrscr();

			printf("\n cannot open the record file");
			getch();
			exit(1);
			}
			flag=1;

			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atm==atm_no)
				{
					print();
					flag=0;
					break;
				 }
			}

			if(flag==1)
			{
				printf("\n::No Element Available::");
			}
			fclose(fp);
			getch();
			clrscr();
			mainmenu();
			break;
		   }

		case 4:
		   {
			clrscr();
			mainmenu();
			printf("\n\n\n\t\tEnter the Atomic MASS of element");
			scanf("%f",&atm_mass);

			if((fp=fopen("akash","rb+"))==NULL)
			{
			//clrscr();

			printf("\n cannot open the record file");
			getch();
			exit(1);
			}
			flag=1;

			while(fread(&p,sizeof(p),1,fp))
			{
				 if(p.atms==atm_mass)
				{
					print();
					flag=0;
					break;
				 }
			}

			if(flag==1)
			{
				printf("\n::No Element Available::");
			}
			fclose(fp);
			getch();
			clrscr();
			mainmenu();
			break;
		   }

		case 5:
		   {
			clrscr();
			mainmenu();
			printf("\n\n\n\t\tEnter the block::");
			scanf("%s",&str);

			if((fp=fopen("akash","rb+"))==NULL)
			{
			//clrscr();

			printf("\n cannot open the record file 1");
			getch();
			exit(1);
			}
			flag=1;

			while(fread(&p,sizeof(p),1,fp))
			{

				 if(strcmp(p.block,str)==0)
				{
					print();

					flag=0;
					break;
				 }

			}
			if(flag==1)
			{
				printf("\n::No Element Available::");
			}

			fclose(fp);
			getch();
			clrscr();
			mainmenu();
			break;

		   }
		 case 6:
		   {
			clrscr();
			mainmenu();
			main();
		   }
		 default:
			clrscr();
			mainmenu();
			printf("\n\t\tWrong choice!!!");
			printf("\n\t\tEnter again");
			getch();
			clrscr();
			mainmenu();



	   }
     }
}


void print()
{
	clrscr();
	mainmenu();

	printf("\n\n\n\tName:");
	printf("%s",p.name);

	fflush(stdin);
	printf("\n\tSymbol:");
	printf("%s",p.sy);


	printf("\n\tAtomic No: ");
	printf("%d",p.atm);

	printf("\n\tAtomic Wt: ");
	printf("%.2f",p.atms);



	printf("\n\tBlock:");
	printf("%s",p.block);

	printf("\n\tProperties:");
	printf("%s",p.prop);
	getch();

}
void mainmenu()
{
	printf("================================================================================\n");
	printf("\t\t\t  MORDERN PERIODIC TABLE\n");
	printf("\n================================================================================\n\n");
}
