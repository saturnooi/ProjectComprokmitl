#include<stdio.h>

char province[10][30], travel[10][5][50], status[20][20];
int provincenumber = 10, numberattractions = 5;

void loaddata(){
	FILE *fp;
    fp = fopen("data.txt","r");
	int i,j;
    for (i = 0 ; i < provincenumber ; i++){
        fscanf(fp,"%s",province[i]); 
    }
    for (i = 0 ; i < provincenumber ; i++){
        for(j = 0 ; j < numberattractions ; j++){
        	fscanf(fp,"%s",travel[i][j]); 
		}
    }
    for (i = 0 ; i < provincenumber ; i++){
        fscanf(fp,"%s",status[i]); 
    }
    fclose(fp);
}
void  Searchbyprovincename(){
	system("cls");
	int i,j,mode;
	for (i = 0 ; i < provincenumber ; i++){
		printf("[ %2d ] : %s\n",i+1,province[i]);
	}
	do{
		printf("\n Enter the province number (1-%d) : ",provincenumber);
		scanf(" %d",&mode);
	}while(mode <1 || mode >provincenumber);
	mode--;
	system("cls");
	printf("%s Attractions :\n",province[mode]);
    for(j = 0 ; j < numberattractions ; j++){
        printf("[ %2d ] : %s \n",j+1,travel[mode][j]);
	}
	do{
		printf("\nBack Enter 0  : ");
		scanf(" %d",&mode);
	}while(mode != 0);
}
void  Searchbylocation(){
	system("cls");
	int i,j,k=1,mode;
	char place[12][20] = {"TEMPLE","MARKET","FELL","GARDEN","ISLAND","BEACH","HISTORICALPARK","LANDMARK","WALKING STREET","CASCADE","JUNGLE","MUSEUM"};
	char place2[12] = {'T','M','F','G','I','B','H','L','W','C','J','m'};
	for (i = 0 ; i < 12 ; i++){
		printf("[ %2d ] : %s\n",i+1,place[i]);
	}
	do{
		printf("\n Enter Place number (1-12) : ");
		scanf(" %d",&mode);
	}while(mode<1 || mode>12);
	mode--;
	system("cls");
	printf("%s : \n",place[mode]);
	for (i = 0 ; i < provincenumber ; i++){
        for(j = 0 ; j < numberattractions ; j++){
        	if(place2[mode]==status[i][j])
        	printf("[ %2d ] Province : %-20s Attraction : %s\n",k++,province[i],travel[i][j]);
		}
    }
	do{
		printf("\nBack Enter 0  : ");
		scanf(" %d",&mode);
	}while(mode != 0);
}
int main() 
{
	loaddata();
	int mode;
	while(1){
		system("cls");
		printf("Enter 1 --> Search by province name\n");
		printf("Enter 2 --> Search by location\n\n");
		do{
			printf("Enter number 1 or 2 : ");
			scanf("%d",&mode);
		}while(mode<1||mode>2);
		if(mode == 1){
			Searchbyprovincename();
		}
		else{
			Searchbylocation();
		}
	}
}
