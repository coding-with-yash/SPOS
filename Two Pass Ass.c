#include<stdio.h>
#include<string.h>

struct mnttab   		
{
	char mnemonic[10];
}m[20];

struct symtab
{
	char symbol[20];
	int addr;
}sym[20];

struct littab
{
	char literal[20];
	int addr;
}lit[20];

struct pooltab
{
	int srno;
	int index;
}pool[20];

 void main()
{
FILE *fp,*fp1;
char str[20];
char str1[20],str2[20],str3[20];
int temp1,temp2,temp3,temp5,idx;
int i,lc=0,sptr=1,lptr=1,poolptr=1,symflag,dlflag1,litflag,n,j,k,data;
int lcflag;
int n0,n1,n2,n3,n4,f=0,f1=0,f2=0,f3=0,f4=0,f5=0,p;
strcpy(m[0].mnemonic,"STOP");
strcpy(m[1].mnemonic,"ADD");
strcpy(m[2].mnemonic,"SUB");
strcpy(m[3].mnemonic,"MULT");
strcpy(m[4].mnemonic,"MOVER");
strcpy(m[5].mnemonic,"MOVEM");
strcpy(m[6].mnemonic,"COMP");
strcpy(m[7].mnemonic,"BC");
strcpy(m[8].mnemonic,"DIV");
strcpy(m[9].mnemonic,"READ");
strcpy(m[10].mnemonic,"PRINT");
fp=fopen("alp1.txt","r");
fp1=fopen("ic.txt","w");
pool[1].index=0;
while(fscanf(fp,"%s",str)!=EOF)
{
	dlflag1=0;
	 
	if(strcmp(str,"START")==0)
	{
		dlflag1=1;
		fprintf(fp1,"AD 01");
		fscanf(fp,"%s",str);
		n=atoi(str);
		lc=n;
		fprintf(fp1," C %d",n);
		 
	}
	if(strcmp(str,"END")==0)
	{
		dlflag1=1;
		fprintf(fp1,"\nAD 02");
		poolptr++;
		pool[poolptr].index=lptr;
		for(j=pool[poolptr-1].index;j<lptr;j++)
		{
			
			lit[j].addr=lc;
			
			fprintf(fp1,"\n%d\t",lc);
			fprintf(fp1,"literal %s is processed",lit[++poolptr].literal);
			lc++;
		}
		
	}
	if(strcmp(str,"LTORG")==0)
	{
		poolptr++;
		pool[poolptr].index=lptr;
		//lit[j].addr=lc-1;
		for(j=pool[poolptr-1].index;j<lptr;j++)
		{
			
			lit[j].addr=lc;
			fprintf(fp1,"\n%d\t",lc);
			//fprintf(fp1,"%s",lit[poolptr].literal);
			fprintf(fp1,"literal %s is processed",lit[poolptr].literal);
			//lit[poolptr].literal++;
			lc++;
			
		}
		//fprintf(fp1,"%d\t",lc);
		
		
	}
	for(i=0;i<=10;i++)
	{
		if(strcmp(str,m[i].mnemonic)==0)
		{
			fprintf(fp1,"\n%d IS 0%d",lc,i);
			dlflag1=1;
			lc++;
			fscanf(fp,"%s",str);
			if(strcmp(str,"AREG")==0)
			fprintf(fp1," R 1");
			if(strcmp(str,"BREG")==0)
			fprintf(fp1," R 2");
			if(strcmp(str,"CREG")==0)
			fprintf(fp1," R 3");
			if(strcmp(str,"DREG")==0)
			fprintf(fp1," R 4");
			fscanf(fp,"%s",str);

			if(str[0]!='=')
			{
				symflag=0;
				for(j=1;j<=sptr;j++)
				{
					if(strcmp(str,sym[j].symbol)==0)
					{
						symflag=1;
						break;
					}
				}
				if(symflag==1)
				{
					fprintf(fp1," S %d",j);
					symflag=0;
				}
				else
				{
					strcpy(sym[sptr].symbol,str);
				 
					fprintf(fp1," S %d",sptr);
					sptr++;
				}
			}
			//pool[poolptr].index=1;
			if(str[0]=='=')
			{
				litflag=0;
				
				for(j=pool[poolptr].index;j<=lptr;j++)
				{
					if(strcmp(str,lit[j].literal)==0)
					{
						litflag=1;
						break;
					}
				}
				if(litflag==1)
				{
					fprintf(fp1,"L %d",j);
					litflag=0;
				}
				else
				{
					if(pool[1].index==0)
					pool[1].index=1;
					strcpy(lit[lptr].literal,str);				 
					fprintf(fp1," L %d",lptr);
					lptr++;
				}
			}				
		}
	}
	if(dlflag1==0)
	{
		for(j=0;j<sptr;j++)
		{
			if(strcmp(str,sym[j].symbol)==0)
			{
				sym[j].addr=lc;
				fscanf(fp,"%s",str);
				if(strcmp(str,"DC")==0)
				{
					fprintf(fp1,"\n%d DL 01",lc);
					fscanf(fp,"%s",str);
					n=atoi(str);
					fprintf(fp1," C %d",n);
					lc++;
				}
				if(strcmp(str,"DS")==0)
				{
					fprintf(fp1,"\n%d DL 02",lc);
					fscanf(fp,"%s",str);
					n=atoi(str);
					lc=lc+n;
					fprintf(fp1," C %d",n);
				}
			}

		}
	}
}
  fclose(fp1);
 fclose(fp);
 printf("\n\n-------Symbol Table--------");
 printf("\n------------------------------");
 printf("\nIndex\tSymbol\tAddr");
 for(i=1;i<=sptr;i++)
 {
     printf("\n%d\t%s\t%d",i,sym[i].symbol,sym[i].addr);
 }
printf("\n ST PIT=%d",sptr);
printf("\n\n-------pool Table--------");
 printf("\n------------------------------");
 printf("\nsrno\tindex");
 for(i=1;i<=poolptr;i++)
 {
     printf("\n%d\t%d",i,pool[i].index);
 }
printf("\n\n-------litearl Table--------");
 printf("\n------------------------------");
 printf("\nIndex\tliteral\tAddr");
 for(i=1;i<=lptr;i++)
 {
     printf("\n%d\t%s\t%d",i,lit[i].literal,lit[i].addr);
 }

// pass2:machine code--------------------------------------

fp=fopen("ic.txt","r");
fp1=fopen("mcode.txt","w");
int ind=0;
		while(fscanf(fp,"%s",str)!=EOF)
		{
			f=0;
			f1=0;
			f2=0;
			f3=0;
			f4=0;
			f5=0;
			if(strcmp("AD",str)==0)
			{
				fscanf(fp,"%s",str);
				fscanf(fp,"%s",str);
				fscanf(fp,"%s",str);
				//fprintf(fp1,"%s ",str);
				f=1;
			}
			
			
	
			if(strcmp("IS",str)==0)
			{
				fscanf(fp,"%s",str);
				n1=atoi(str);
				fprintf(fp1," +0%d ",n1);
				f1=1;
			}
			if(strcmp("R",str)==0)
			{
				fscanf(fp,"%s",str);
				n2=atoi(str);
				fprintf(fp1," 0%d ",n2);
				f2=1;
			}
			/*if(strcmp("S",str)==0)
			{
				fscanf(fp,"%s",str);
				n3=atoi(str);
				fprintf(fp1,"%d",sym[n3-1].addr);
				f3=1;
			}*/
			if(strcmp("L",str)==0)
			{
				/*fscanf(fp,"%s",str);
				n4=atoi(str);
				fprintf(fp1," %d ",lit[n4+1].addr);*/
				fscanf(fp,"%s",str);
				i=atoi(str);
				fprintf(fp1," %d \n",lit[i].addr);
				//fprintf(fp1,"+00 00 0%s",lit[i].literal);
				f4=1;
			}
			
			
			if(strcmp("DL",str)==0)
			{
				f4=1;
				fscanf(fp,"%s",str);
				n=atoi(str);
				if(n==2)
				{
					fprintf(fp1,"0 00 000");
					fscanf(fp,"%s",str);
					fscanf(fp,"%d",&k);
					fprintf(fp1,"%d",k);
				}
				else
				{
					fprintf(fp1,"0 00 000");
					fscanf(fp,"%s",str);
					fscanf(fp,"%d",&k);

				}
			}
			
			if(f!=1&&f1!=1&&f2!=1&&f3!=1&&f4!=1&&f5!=1)
			{
				//fprintf(fp1,"0 00 000");
				//fprintf(fp1,"%d",n0);
				fprintf(fp1,"%s ",str);
				
			}
			
		}
		fclose(fp);
		fclose(fp1);
}









-------Symbol Table--------
------------------------------
Index   Symbol  Addr
1               0
 ST PIT=1

-------pool Table--------
------------------------------
srno    index
1       0

-------litearl Table--------
------------------------------
Index   literal Addr
1               0
--------------------------------
