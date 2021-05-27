#include<stdio.h>
#include<string.h>
int amountdata;
char place[100][50], province[100][20], category[100][20] ;
char baseprovince[10][20] = {"BANGKOK", "CHIANG_MAI", "AYUTHAYA", "PHUKET", "KRABI", "SURAT_THANI", "KHON_KAEN", "CHIANG_RAI", "KANCHANABURI", "CHONBURI"};
char basecategory[10][20] ={"MOUNTAIN", "TEMPLE", "MARKET", "BEACH", "ISLAND", "WALKING_STREET", "HISTORICAL_PARK", "SHOPPING_MALL", "COFFEE_SHOP", "WATERFALL"};
char strinput[30];
void loaddata(){
	int i;
	FILE *fp;
    fp = fopen("Amountdata.txt","r");
    fscanf(fp,"%d",&amountdata);
    fclose(fp);
	fp = fopen("travel.txt","r");
	for(i = 0; i < amountdata ; i++){
		fscanf(fp,"%s %s %s",&province[i], &place[i], &category[i] );
	}
	fclose(fp);
}
void patternstr(){
	int i = 0;
	while(strinput[i] != '\0'){
		if(strinput[i]>='a'&&strinput[i]<='z'){
			strinput[i] = strinput[i]-32;
		}
		if(strinput[i]==' '){
			strinput[i] = '_';
		}
		i++;
	} 
}
void Searchbyprovince(){
	int i,j,k,input;
	
	do{
		system("cls");
		for(i = 0; i<10 ; i++){
			printf(" %2d : %s \n",i+1,baseprovince[i]);
		}
		printf("\n Back Enter (MENU) \n\n");
		printf("Enter Province name : ");
		scanf(" %[^\n]", strinput);
		patternstr();
		if(strcmp(strinput,"MENU") != 0){
			do{
			k=1;
			system("cls");
			for(i = 0; i<10 ;i++){
				if(strcmp(strinput,baseprovince[i])==0){
					break;
				}
			}
			for(j = 0; j < amountdata ; j++){
				if(strcmp(province[j],baseprovince[i])==0){
					printf(" [ %2d ] : %-20s %-50s %-20s \n",k++,province[j], place[j], category[j]);
				}
			}
			printf("\nEnter [0] Back: ");
			scanf("%d", &input);	
			}
			while(input != 0);
			
		}	
	}
	while(strcmp(strinput,"MENU")!=0);
		
}
void Searchbycategory(){
	int i,j,k,input;
	do{
		system("cls");
		for(i = 0; i<10 ; i++){
			printf(" %2d : %s \n",i+1, basecategory[i]);
		}
		printf("\n Back Enter (MENU) \n\n");
		printf("Enter category : ");
		scanf(" %[^\n]", &strinput);
		patternstr();
		if(strcmp(strinput,"MENU")!=0){
			do{
			k = 1;
			system("cls");
			for(i = 0; i<10 ;i++){
				if(strcmp(strinput,basecategory[i])==0){
					break;
				}
			}
			for(j = 0; j < amountdata ; j++){
				if(strcmp(category[j],basecategory[i])==0){
					printf(" [ %2d ] : %-20s %-50s %-20s \n",k++,province[j], place[j], category[j]);
				}
			}	
			printf("\nEnter [0] Back: ");
			scanf("%d", &input);	
			}
			while(input != 0);	
		}
			
	}
	while(strcmp(strinput,"MENU")!=0);
	
}
void Addplace(){
	system("cls");
	int i;
	for(i = 0; i<10 ; i++){
		printf(" %2d : Province : %-50s  Tegory : %s\n",i+1,baseprovince[i],basecategory[i]);
	}
	while(1){
		printf("\nEnter Province name : ");
		scanf(" %[^\n]", &strinput);
		patternstr();
		for(i = 0; i<10 ;i++){
				if(strcmp(strinput,baseprovince[i])==0){
					break;
				}
		}
		if(i != 10){
			break;
		}
		printf("No name in the list\nAgain");	
	}
	
	strcpy(province[amountdata], strinput);
	printf("Enter Place name : ");
	scanf(" %[^\n]", &strinput);
	patternstr();
	strcpy(place[amountdata], strinput);
	
	while(1){
		printf("Enter Category : ");
		scanf(" %[^\n]", &strinput);
		patternstr();
		for(i = 0; i<10 ;i++){
				if(strcmp(strinput,basecategory[i])==0){
					break;
				}
		}
		if(i != 10){
			break;
		}
		printf("No Category in the list\nAgain\n");	
	}
	
	strcpy(category[amountdata], strinput);
	FILE *fp;
    fp = fopen("travel.txt","a");
    fprintf(fp,"\n%s %s %s",province[amountdata], &place[amountdata], &category[amountdata]);
	fclose(fp);
	amountdata++;
	fp = fopen("Amountdata.txt","w");
    fprintf(fp,"%d",amountdata);
	fclose(fp);
}

int main() 
{
	loaddata();
	int i;
	int intput;
	while(1){
		system("cls");
		printf("Search by province Enter : 1\n");
		printf("Search by category Enter : 2 \n");
		printf("Add a place Enter : 3 \n");
		printf("\nEnter number : ");
		scanf("%d", &intput);
		if(intput == 1){
			Searchbyprovince();
		}
		else if(intput == 2){
			Searchbycategory();
		}
		else if(intput == 3){
			Addplace();
		}
	}
	
	
}
