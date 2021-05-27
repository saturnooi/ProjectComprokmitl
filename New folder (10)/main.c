#include<stdio.h>
#include<string.h>
void home();
void Searchmovietitle();
void readdata();
void Searchcategory();
void Searchstar();
char category[5][20],star[20][30],moviename[50][50],categorymovie[50][20],starmovie[50][20];
int main(){
	readdata();
	int num;
	while(1){
		home();
		printf("\nEnter number : ");
		scanf("%d",&num);
		if(num==1){
			Searchmovietitle();
		}
		else if(num==2){
			Searchcategory();
		}
		else if(num==3){
			Searchstar();
		}	
	}
}
void home(){
	system("cls");
	printf("++++++++++++++++++++++++++++++++++++++\n");
	printf("+                                    +\n");
	printf("+               CINEMA               +\n");
	printf("+                                    +\n");
	printf("+                KMITL               +\n");
	printf("+                                    +\n");
	printf("++++++++++++++++++++++++++++++++++++++\n\n");
	printf("Search by movie title --> Enter 1 \n");
	printf("Search by movie category --> Enter 2 \n");
	printf("Search by movie star --> Enter 3 \n");

}
void Searchmovietitle(){
	int i,num;
	system("cls");
	for(i = 0; i < 50 ; i++){
		printf("%2d : %-50s ",i+1, moviename[i]);
		i++;
		printf("%2d : %-50s \n",i+1, moviename[i]);
	}
	printf("\n");
	printf("Enter number : ");
	scanf(" %d",&num);
	num--;
	system("cls");
	printf(" Movie Name : %s \n",moviename[num]);
	printf(" Category : %s \n",categorymovie[num]);
	printf(" Star : %s\n",starmovie[num]);
	printf("\nOut --> Enter number : ");
	scanf(" %d",&num);
}

void Searchstar(){
	int i,num,k;
	system("cls");
	for(i = 0 ; i < 20 ; i++){
		printf("%2d : %s\n",i+1, star[i]);
	}
	printf("\nEnter number : ");
	scanf("%d",&num);
	num--;
	k = 1;
	system("cls");
	for(i = 0; i < 50 ;i++){
		if(strcmp(star[num],starmovie[i])==0){
			printf(" %2d : Movie Name : %-45s Category : %-15s Star : %s \n",k++, moviename[i], categorymovie[i], starmovie[i]);
		}
	}
	printf("\nOut --> Enter number : ");
	scanf(" %d",&num);
}
void Searchcategory(){
	int i,num,k;
	system("cls");
	for(i = 0 ; i < 5 ; i++){
		printf("%2d : %s\n",i+1, category[i]);
	}
	printf("\nEnter number : ");
	scanf("%d",&num);
	num--;
	k = 1;
	system("cls");
	for(i = 0; i < 50 ;i++){
		if(strcmp(category[num],categorymovie[i])==0){
			printf(" %2d : Movie Name : %-45s Category : %-15s Star : %s \n",k++, moviename[i], categorymovie[i], starmovie[i]);
		}
	}
	printf("\nOut --> Enter number : ");
	scanf(" %d",&num);
}
void readdata(){
	int i;
	FILE *fp;
	fp = fopen("movie.txt","r");
	for(i = 0; i < 5 ; i++){
		fscanf(fp,"%s",&category[i]);
	}
	for(i = 0; i < 20 ; i++){
		fscanf(fp,"%s",&star[i]);
	}
	for(i = 0; i < 50 ; i++){
		fscanf(fp,"%s %s %s",moviename[i], categorymovie[i], starmovie[i]);
	}
	fclose(fp);
}
