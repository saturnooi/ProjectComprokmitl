#include <stdio.h>

int price[20];
char foodName[20][40];
int total=0;
int totalnummenu = 20;
int bill[20];

void rData();
void printPatternMenu();
void Calculatefood();
void printPatternbill();
void Calculatechange();
void setbill();
int main(){
	rData();
	while(1){
	setbill();
	system("cls");
	printPatternMenu();
	Calculatefood();
	printPatternbill();
	Calculatechange();	
	}
}

void rData(){
    FILE *fp;
    fp = fopen("menu.txt","r");
	int i;
    for (i = 0 ; i < totalnummenu ; i++){
        fscanf(fp,"%s %d", foodName[i],&price[i]); 
    }
    fclose(fp);
}
void printPatternMenu(){
	int i =0;
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+                                                   WELCOME                                                      +\n");
	printf("+                                                                                                                +\n");
	printf("+                                                    KMITL                                                       +\n");
	printf("+                                                                                                                +\n");
	printf("+                                                PAPAYA SALAD                                                    +\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
	printf("#################################################################################################################\n");
	printf("#                                                       |                                                       #\n");
	printf("#                                                       |                                                       #\n");
	while (i < totalnummenu ){
        printf("#  [%2d] %-40s %4d B\t", i+1, foodName[i], price[i]);
        i++;
        printf("| [%2d] %-40s %4d B  #\n", i+1, foodName[i], price[i]);
        i++;
    }
    printf("#                                                       |                                                       #\n");
    printf("#                                                       |                                                       #\n");
    printf("#################################################################################################################\n\n");
    
}
void Calculatefood(){
	int totalnumber,i=0,indexfood,amount;
	while(1){
		printf("Enter Total number of menu : ");
		scanf("%d",&totalnumber);	
		if(totalnumber > 0 ){
			break;
		}
		printf("---Out of range!!!---\nTry again ");
	}
	
	while(i<totalnumber){
		while(1){
			printf("Enter the food number(1-%d) : ",totalnummenu);
			scanf("%d",&indexfood);
			if(indexfood>=1 && indexfood<=totalnummenu)	{
				break;
			}
			printf("---Out of range!!!---\nTry again ");
		}
		indexfood-=1;
		printf("%s --> Enter Amount of food : ",foodName[indexfood]);
		scanf(" %d",&amount);
		bill[indexfood]+=amount;
		total += price[indexfood]*amount;
		i++;
	}
}
void setbill(){
	int i;
	for(i = 0 ; i<totalnummenu ; i++){
		bill[i]=0;
	}
}
void printPatternbill(){
	system("cls");
	int i = 0 ,j=1;
    while (i < totalnummenu){
    	if(bill[i]>0){
    	printf("%2d : %-40s %4d B\n",j++, foodName[i], price[i]*bill[i]);	
		}
		i++;
    }
    printf("total = %5d B\n",total);
}
void Calculatechange(){
	int money,summoney=0,i,j=0;
	while(1){
		printf("Enter money : ");
		scanf(" %d",&money);		
		summoney += money;
		if(summoney>=total){
			break;
		}
		printf("Money is less than the total price. Please pay extra.\n");
	}
	printf("Change = %d B\n",summoney-total);
	do{
		printf("Enter [0] = exit : ");
		scanf("%d",&i);
	}while(i != 0);
	total = 0;
}
