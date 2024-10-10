#include <stdio.h>
#include <string.h>

int fatura_id =1, furnizimi_id=100;
int nr_art, nr_klient, nr_sh, nr_f;
	
char fn_a[500]="Artikuj.dat";
char fn_k[500]="Kliente.dat";
char fn_s[500]="Shitje.dat";
	
struct artikulli{
	char id[8];
	char kategoria[100];
	char emertimi[200];
	int cmimi;
	int sasia;
}art[200];

struct klienti{
	char id_klienti[10];
	char emri[50];
	char mbiemri[50];
	char nr_tel[13];
}k[200];

struct shitje{
	char id_klienti[10];
	int id_fature;
	char data[15];
	int vlera;
	
	struct shitje_detaje{
		char id_art[8];
		int sasia;
		int cmimi;
		int vlera;
	}sd[10];
	
}s[200];

struct furnizim{
	int id_furnizimi;
	char data_furnizimit[15];
	int vlera_f;
	char kodi[50];
	int sasia[50];
	int cmimi[50];
}f[200];


void lexim_te_dhenash(){
	
	FILE *f1;
	char tmp[50];
	f1= fopen(fn_a, "rb");
	
	if (f1==NULL){
		printf("Gabim ne hapjen e file.");
		return;
	}
	
	nr_art=0;
	
	while(fread(&art[nr_art],sizeof(struct artikulli),1,f1))
	{nr_art++;}
	
	fclose(f1);
	
	
	
	FILE *f2;
	
	f1= fopen(fn_k, "rb");
	
	if (f2==NULL){
		printf("Gabim ne hapjen e file.");
		return;
	}
	
	nr_klient=0;
	
	while(fread(&k[nr_klient],sizeof(struct klienti),1,f2))
	{nr_klient++;}
	
	fclose(f2);
	
	
	
	FILE *f3;

	f3= fopen(fn_s, "rb");
	
	if (f3==NULL){
		printf("Gabim ne hapjen e file.");
		return;
	}
	
	nr_sh=0;
	
	while(fread(&s[nr_sh],sizeof(struct shitje),1,f3))
	{nr_sh++;}
	
	fclose(f3);
	
}


void save(){
	
	FILE *f1;
	f1=fopen(fn_a, "wb");
	
	if(f1==NULL){
		printf("\nGabim ne hapjen e file.");
		return;
	}
	
	nr_art=0;
	
	for(int i=0; i<nr_art;i++){
		fwrite(&art[i], sizeof(struct artikulli),1,f1);
		nr_art++;
	}
	
	fclose(f1);
	
	FILE *f2;
	f2=fopen(fn_k, "wb");
	
	if(f2==NULL){
		printf("\nGabim ne hapjen e file.");
		return;
	}
	
	nr_klient=0;
	
	for(int i=0; i<nr_klient;i++){
		fwrite(&k[i], sizeof(struct klienti),1,f2);
		nr_klient++;
	}
	
	fclose(f2);
	
	FILE *f3;
	f3=fopen(fn_s, "wb");
	
	if(f3==NULL){
		printf("\nGabim ne hapjen e file.");
		return;
	}
	
	nr_sh=0;
	
	for(int i=0; i<nr_sh;i++){
		fwrite(&s[i], sizeof(struct shitje),1,f3);
		nr_sh++;
	}
	
	fclose(f3);
}


//Regjistrim Artikulli
void f1(){
	
	char tmp[8];
	
    printf("\n Shtim Artikulli. ");
    
	printf("\nJepni ID :  ");
	scanf("%s",tmp);
	
	for(int i=0; i<nr_art;i++){
		if (strcmp(art[i].id,tmp)==0){
			printf("\nKjo ID eshte regjistruar me pare.");
			return;
		}
	}
	
	strcpy(art[nr_art].id,tmp);
	fflush(stdin);
	
	printf("\nJepni Kategorine : ");
	gets(art[nr_art].kategoria);
	
	printf("\nJepni Emertimin : ");
	gets(art[nr_art].emertimi);
	
	printf("\nJepni Cmimin : ");
	scanf("%d", &art[nr_art].cmimi);
			
	art[nr_art].sasia=0;
	nr_art++;
}


//Regjistrim Klienti
void f2(){
	
	char tmp[30];
	
	printf("\n Shtim Klienti. ");
	
	printf("\nJepni ID : ");
	scanf("%s",tmp);
	
	int kushti= 0;
	
	for(int i=0; i<nr_klient;i++){
		if (strcmp(k[i].id_klienti,tmp)==0){
			kushti=1;
			break;
		}
	}
	
	if(kushti==1){
 	printf("\nKjo ID eshte regjistruar me pare.");
	return;	}
	
	
	strcpy(k[nr_klient].id_klienti,tmp);
	fflush(stdin);
	
	printf("\nJepni Emrin : ");
	gets(k[nr_klient].emri);
	
	printf("\nJepni Mbiemrin : ");
	gets(k[nr_klient].mbiemri);
		
	printf("\nJepni nr Tel : ");
	gets(k[nr_klient].nr_tel);
		
	nr_klient++;
}


//Furnizim
void f3(){
	char tmp[30];
	int tmp1,tmp2;
	
	printf("\nFurnizim. ");
	
	f[nr_f].id_furnizimi=furnizimi_id;
	furnizimi_id++;
	
	strcpy(f[nr_f].data_furnizimit,"09.06.2022");
	
	int vlera=0;
	
	printf("\nJepni ID e artikullit: ");
	scanf("%s",tmp);
	fflush(stdin);
	
	printf("\nJepni sasine e artikullit: ");
	scanf("%d",&tmp1);
	
	printf("\nJepni cmimin e artikullit: ");
	scanf("%d",&tmp2);
	
		for(int i=0; i<nr_art;i++)
	{
		if (strcmp(art[i].id,tmp)==0)
		{
			art[i].sasia+=tmp1;
			art[i].cmimi=tmp2;
			break;
		}
		else {
		printf("Ky produkt nuk gjendet ne magazine.");
		return;	}
	}
	
	vlera=(tmp1*tmp2);
	f[nr_f].vlera_f=vlera;
	
	nr_f++;
}


//Shitje
void f4(){
	char tmp[30];
	
	printf("\nShitje. ");
	
	printf("\nJepni ID e Klientit : ");
	scanf("%s",tmp);
	fflush(stdin);

	int kushti=0;
	
	for(int i=0; i<nr_klient;i++){
		if (strcmp(k[i].id_klienti,tmp)==0){
			kushti=1;
			break;
		}
	}
		
	if (kushti==0){
		printf("\nKy Klient nuk gjendet ne program.");
		return;
	}
	

	strcpy(s[nr_sh].id_klienti,tmp);
	
	int vlera =0;
	strcpy(s[nr_sh].data,"09.06.2022");
	
	s[nr_sh].id_fature = fatura_id;
	fatura_id++;
	
	char c;
	int d=0;
	do{
		printf("\nJepni Kodin e artikullit : ");
		scanf("%s",tmp);
		
		for(int i=0;i<nr_art; i++)
			if(strcmp(tmp, art[i].id)==0){
				printf ("Jepni sasine %s: ",art[i].emertimi);
				scanf("%d", &s[nr_sh].sd[d].sasia);
				
				if(s[nr_sh].sd[d].sasia>art[i].sasia){
					printf("\n Nuk ka sasi te mjaftueshme.");
					break;
				}
				
				s[nr_sh].sd[d].cmimi=art[i].cmimi;
				strcpy(s[nr_sh].sd[d].id_art,tmp);
				
				s[nr_sh].sd[d].vlera=s[nr_sh].sd[d].cmimi * s[nr_sh].sd[d].sasia;
				art[i].sasia -=s[nr_sh].sd[d].sasia;
				vlera+=s[nr_sh].sd[d].vlera;
				d++;
			}
		
		fflush(stdin);
		printf("\n Deshironi te shtoni artikull tjeter (P/J):");
		scanf("%c", &c);
		if (c=='J')
			break;
	}while(1);
	
	nr_sh++;
}


//Gjendja e Magazines
void f5(){

	printf("\nGjendje ne Magazine: \n");
	
	FILE *f2;
	
	f2= fopen(fn_a, "r");
	
	if (f2==NULL){
		return;
	}
	
	char t[30];	
	while(fscanf(f2,"%s",&t)==1){
		printf("%s ",t);
	}
	
	fclose(f2);

}


//10 klientet qe blejne me shume ne vlere
void f6(){

	int v=0,vek[100],k=0;
	
	for (int i=0; i<nr_klient; i++);
	{
	v=0;
		for(int j=0; j<nr_sh; j++){
		if(strcmp(k[i].id_klienti,s[j].id_klienti)==0)
		v+=s[j].vlera;
		}
		vek[k]=v;
		k++;
	}
	
	int tmp;
	
	for(int i=0; i<k-1; i++)
		for(int j=i+1; j<k; j++)
		if(vek[i]>vek[j]){
			tmp=vek[i];
			vek[i]=vek[j];
			vek[j]=tmp;
		}
	
	printf("\n 10 Klientet qe blejne me shume jane: ");
	
	for(int k=0; k<10; k++);
		for (int i=0; i<nr_klient; i++);
		{
		v=0;
			for(int j=0; j<nr_sh; j++)
			if(strcmp(k[i].id_klienti,s[j].id_klienti)==0)
				v+=s[j].vlera;
				
		if(vek[k]==v) printf("%d - %s/n",k+1, k[i].id_klienti);
		}


}


//20 klientet qe blejne me shpesh
void f7(){

	int v=0,vek[100],k=0;
	
	for (int i=0; i<nr_klient; i++);
	{
	v=0;
		for(int j=0; j<nr_sh; j++){
		if(strcmp(k[i].id_klienti,s[j].id_klienti)==0)
		v++;
		}
		vek[k]=v;
		k++;
	}
	
	
	int tmp;
	
	for(int i=0; i<k-1; i++)
		for(int j=i+1; j<k; j++)
		if(vek[i]>vek[j]){
			tmp=vek[i];
			vek[i]=vek[j];
			vek[j]=tmp;
		}
		
	
	printf("\n 20 Klientet qe blejne me shpesh jane: ");

	for(int k=0; k<20; k++);
		for (int i=0; i<nr_klient; i++);
		{
		v=0;
			for(int j=0; j<nr_sh; j++)
			if(strcmp(k[i].id_klienti,s[j].id_klienti)==0)
				v++;
		if(vek[k]==v) printf("%d - %s/n",k+1, k[i].id_klienti);
		}

}


//Kerkim Artikulli
void f8(){
	
	char tmp[15];
	
	printf("\nJepni ID e artikullit: ");
	scanf("%s", tmp);
	
	for(int i=0; i<nr_art; i++){
		if(strcmp(art[i].id, tmp)==0)
			{
				printf("\n\nArtikulli gjendet ne magazine.");
				printf("\n%s    ", art[i].kategoria);
				printf("%s    ", art[i].emertimi);
				printf("%d", art[i].cmimi);
			}
		else { printf("Produkti nuk gjendet ne magazine.");
		return;}
	}
	
}


void menu()
{
  printf("\n=====================================\n");
  printf("\n           Detyre Kursi");
  printf("\n\n 1 - Regjistrim Artikulli ");
  printf("\n 2 - Regjistrim Klienti");
  printf("\n 3 - Furnizim");
  printf("\n 4 - Shitje ");
  printf("\n 5 - Gjendje ne magazine ");
  printf("\n 6 - Klientet qe blejne me shume ");
  printf("\n 7 - Klientet qe blejne me shpesh ");
  printf("\n 8 - Kerkim artikulli ");
  printf("\n s - Save ");
  printf("\n d - Dalja \n");
  printf("\n=====================================");
  printf("\n Zgjedhja : ");
}


main()
{
	lexim_te_dhenash();
	
	menu();
	
	char z;
	do{
		z=getchar();
		
		if(z=='1') f1();
		else if(z=='2') f2();
		else if(z=='3') f3();
		else if(z=='4') f4();
		else if(z=='5') f5();
		else if(z=='6') f6();
		else if(z=='7') f7();
		else if(z=='8') f8();
		else if(z=='s') save();
		
		printf("\n shtypni nje karakter per te vazhduar...   ");
   		getchar();
   		
	}
	while(z!='d' && z!='D' && z!=27);
}
