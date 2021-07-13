#include<stdio.h>
#include<time.h>
#include<string.h>
void main()
{
    struct details
    {
        char name[20];
        int price;
        int qty;
        int amount;
    };
    char coupon[7],c1[7];
    struct details item[50];
    int i=0,n=0,total=0,cp=0,totalamount=0;
	char ch;
	FILE *fp,*te;
    ch='y';
    time_t t;
    time(&t);
    fflush(stdin);
    fp=fopen("coupon.txt","r");
    while(ch=='y')
    {
        fflush(stdin);
        printf("Enter Product Name :");
        scanf("%s",item[i].name);
        fflush(stdin);
        printf("Enter Qty and Price:");
        scanf("%d %d",&item[i].qty,&item[i].price);
        fflush(stdin);
		printf("Add More Items [y/n]:");
		scanf("%c",&ch);
		n++;
		i++;
    }
    printf("\nEnter coupon no:");
    fflush(stdin);
    gets(c1);
    te=fopen("Temp.txt","w");
    while(fgets(coupon,7,fp)){
    	if(strcmp(coupon,c1)==0){
    		cp=1;
    	printf("Coupon Applied Successfully");
		}
		else if(strcmp(coupon,c1)!=0){
			fputs(coupon,te);
		}
	}
	fclose(fp);
	fclose(te);
	remove("coupon.txt");
	rename("Temp.txt","coupon.txt");
	if(!cp){
		printf("\nNo Such Coupon Found");
	}
    printf("\n====================================================================================================\n");
    printf("                                  ***** SUPER MARKET ***** \n");
    printf("====================================================================================================\n");
    printf("Item                             Qty                          Price                         Amount  \n");
    printf("----------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++){
     item[i].amount=item[i].qty*item[i].price;
      printf("%-15s                  %-5d                        %-5d                         %-5d\n", item[i].name,item[i].qty,item[i].price,item[i].amount);
      total+=item[i].amount;
    }
    if(cp==1){
    	totalamount=total-((total*(0.08)));
	}
	else{
		totalamount=total;
	}
    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Total Amount:      \t\t\t\t\t\t\t\t            %d",total);
    printf("\n----------------------------------------------------------------------------------------------------\n");
    printf("\nAfter coupon Total Amount:    \t\t\t\t\t\t\t\t    %d",totalamount);
    printf("\nBilling Date And Time:%s",ctime(&t));
 }
