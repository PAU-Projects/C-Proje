/* S���nmac� Takip Sistemi
*  No: 11253804
*  Mehemmed �xiyev
* */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
//Global tanimlamalar
#define MAX 150
//Fonksiyon Protipler.
int d_control();
void Siginmaci_Kayit();
bool d_sayi_control(char* x);
bool d_harf_control(char* x);
void Bubble_sort(struct User siginmaci[], int num);
int d_count(char dizi[]);
void menu_Giris();
void menu_Admin();
void menu_Memur();
void Memur_Kayit();
void dosya_S_Ekle(int); //Siginmaci dosya kayit
void dosya_M_Ekle(int); //Memur dosya kayit

//Grup uye tanimlamalari
struct User{
	int  no;
	char ad[15];
	char soyad[15];
	char dogum_tarihi[15];
	char dogum_yeri[15];
	char cinsiyet[5];
	char uyruk[10];
	char meslek[10];
	char egitim_durumu[10];
	char telefon[10];
	char geldigi_sehir[10];
	char gelis_tarihi[11];
	char eposta[20];
	char tc[11];
	char kullanici_adi[10];
	char sifre[15];
	char yetki_turu[10];
	char adres[20];
}siginmaci[150], Memur[50];


//Main fonksiyon
int main() {
	printf("==================================================================\n");
	printf("\t\t\tSiginmaci Takip SisTemi\n");
	printf("==================================================================\n");
	Memur_Kayit();
	menu_Giris();
	return 0;
}
//Giris menusu sifre kontrolu
void menu_Giris() {
	char secim[10], k_ad[50], k_sifre[50];
	int i = 0, indis;
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
	}
	printf("\tGiris Yapiniz (1/2)\n\t'\n");
	printf("\t'--> Admin : 1 \n");
	printf("\t'--> Memur : 2 \n");

	do {
		printf("Seciminiz: ");
		gets_s(secim);
		if (secim[i] == '1' ) {
			printf("\nAdminseniz Lutfen Giris Yapiniz...!\n");
			do {
			
				printf("\tKullanici adi: ");
				gets_s(k_ad);
				printf("\tSifre Giriniz: ");
				gets_s(k_sifre); 
				if (strcmp(k_ad, "root") || strcmp(k_sifre, "toor")) {
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			} while(strcmp(k_ad, "root") || strcmp(k_sifre, "toor"));	
			menu_Admin();
		}
		else if	(!(strcmp(secim, "q")) || !(strcmp(secim, "Q"))){
			exit(EXIT_SUCCESS);
		}
		else if (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1') {
			printf("\tHatali Giris...!\nCikis icin q giriniz...!\n");
		}
		if (secim[i] == '2') {
			printf("\nSiginmaci Memuru iseniz Giris yapiniz...!\n");
			do {
				printf("\tKullanici adi: ");
				scanf("%s", Memur[indis].kullanici_adi);
				printf("\tSifre Giriniz: ");
				gets(Memur[indis].sifre);
				if (strcmp(Memur[indis].kullanici_adi, "root") || strcmp(Memur[indis].sifre, "toor")) { //Kay�tl� kullan�c�lar ile kar��la�t�r�lacak t�r
					printf("\n\nKullanici adi ve ya Sifre Yalnis...!\n");
				}
			} while (strcmp(Memur[indis].kullanici_adi, "root") || strcmp(Memur[indis].sifre, "toor"));
			menu_Memur();
		} 
	} while (!d_sayi_control(secim) || secim[i] != '2' || secim[i] != '1');

}
//Siginmaci Kayit fonksiyonu
void Siginmaci_Kayit() {
int i=0; int indis=0;
	char secim[10];
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
		return; 
	} else {
		printf("\t\tSiginmaci Kayit Sistemi...\n");
		do {	
			printf("\n============{ Yeni Siginmaci icin bilgileri giriniz }============\n\n");
			do {
				printf("Siginmaci Ad              : ");
				scanf("%15s", siginmaci[indis].ad);
			} while (!d_harf_control(siginmaci[indis].ad));
			do {
				printf("Siginmaci Soyad           : ");
				scanf("%15s",siginmaci[indis].soyad);
			} while (!d_harf_control(siginmaci[indis].soyad));
			do {
				printf("Dogum tarihi.(gun.ay.yil) : ");

				gets(siginmaci[indis].dogum_tarihi);
			} while (!d_sayi_control(siginmaci[indis].dogum_tarihi) && !strpbrk(siginmaci[indis].dogum_tarihi, "."));
			do {
				printf("Siginmaci Dogum Yeri       : ");
				gets( siginmaci[indis].dogum_yeri);
			} while (!d_harf_control(siginmaci[indis].dogum_yeri));
			do
			{
				printf("Siginmaci Cinsiyyet        : ");
				gets(siginmaci[indis].cinsiyet);
			} while (!d_harf_control(siginmaci[indis].cinsiyet));
			do
			{
				printf("Siginmaci Uyruk            : ");
				gets(siginmaci[indis].uyruk);
			} while (!d_harf_control(siginmaci[indis].uyruk));
			do
			{
				printf("Siginmaci Meslegini        : ");
				scanf("%10s",siginmaci[indis].meslek);
			} while (!d_harf_control(siginmaci[indis].meslek));
			do
			{
				printf("Siginmaci Egitim Durumu    : ");
				scanf("%10s",siginmaci[indis].egitim_durumu);
			} while (!d_harf_control(siginmaci[indis].egitim_durumu));
			do
			{
				printf("Siginmaci Yerlesdigi Yer   : ");
				gets(siginmaci[indis].adres);
			} while (!d_harf_control(siginmaci[indis].adres));
			do
			{
				printf("Siginmaci Geldigi Sehir    : ");
				scanf("%20s",siginmaci[indis].geldigi_sehir);
			} while (!d_harf_control(siginmaci[indis].geldigi_sehir));
			do { //tarih formatinda oldugunu kontrol ediyoruz
				getch();
				printf("S.Gelis Tarihi (gun.ay.yil): ");
				gets(siginmaci[indis].gelis_tarihi);
			} while (!d_sayi_control(siginmaci[indis].gelis_tarihi) && !strpbrk(siginmaci[indis].gelis_tarihi, "."));
			do {
				printf("Siginmaci email adress    : ");
				gets(siginmaci[indis].eposta);
			} while (!strpbrk(siginmaci[indis].eposta, "@") || !strpbrk(siginmaci[indis].eposta, ".") || !strpbrk(siginmaci[indis].eposta, "\n"));
			do {
				printf("Siginmaci Telefon(10 Hane!): ");
				gets(siginmaci[indis].telefon);
				if (! (d_sayi_control(siginmaci[indis].telefon) && sizeof(siginmaci[indis].telefon) == d_count(siginmaci[indis].telefon))) {
					printf("\t\tHatali Giris...!\n\tLutfen 10 Haneli Rakam Girdiniz...!\n");
				}
			} while (!d_sayi_control(siginmaci[indis].telefon) || d_count(siginmaci[indis].telefon) != sizeof(siginmaci[indis].telefon));
		
			printf("\n============\nToplam : %d\n============\n",indis+1);
			do {
				printf("\nDiske Kayd etmek icin < k > --->{ Baska Kayit Yapilacak mi(E/h) ?: ");
				secim[i] = getch();
				/*if (secim[i] != 'E' && secim[i] != 'e') {
				printf("\tHatali Giris...!\nSeciminiz: ");
			}*/
				if (secim[i] ==  'h' || secim[i] == 'H') {
					exit(false);
				}
				if (secim[i] == 'k' ||secim[i] == 'K') {
					dosya_S_Ekle(indis);
				}
			} while (secim[i] != 'E' && secim[i] != 'e');
			indis++;
			system("cls");
		} while (secim[i] == 'E' || secim[i] == 'e' || secim[i] != 'h' || secim[i] != 'H');
	}
}
//
void Memur_Kayit() {
	int  indis,i=0;
	char secim[10];
	indis = d_control();
	if (indis < 0) {
		printf("\tListe Dolu!\n");
		return; 
	} else {
		printf("\t...Kullanici Kayit Sistemi...\n");
		/*do {
			printf("\n============{ Yeni Kullanici icin bilgileri giriniz }============\n\n");
			do
			{
				printf("Kullanici Ad              : ");
				scanf("%s",Memur[indis].ad);
			} while (!d_harf_control(Memur[indis].ad));
			do
			{
				printf("Kullanici Soyad           : ");
				scanf("%s", Memur[indis].soyad);
			} while (!d_harf_control(Memur[indis].soyad));
			do
			{
				printf("Kullanici Adress          : ");
				scanf("%s",Memur[indis].adres);
			} while (!d_harf_control(Memur[indis].adres));
			do {
				printf("Kullanici TC (11 Hane)    : ");
				scanf("%s", Memur[indis].tc);
				if (d_count(Memur[indis].tc) != sizeof(Memur[indis].tc) || ! d_sayi_control(Memur[indis].tc)) {
					printf("\t\tHatali Giris...!\n\tLutfen 11 Haneli Rakam Girdiniz...!\n");
				}
			} while (!d_sayi_control(Memur[indis].tc) || d_count(Memur[indis].tc) != sizeof(Memur[indis].tc));
			printf("Kullanici kullanici adi   : ");
			scanf("%s",Memur[indis].kullanici_adi);
			printf("Kullanici sifre           : ");
			scanf("%s",Memur[indis].sifre);*/
			do 
			{
				printf("Kullanici Yetki Turu      : ");
				//scanf("%10s",Memur[indis].yetki_turu);
				gets(Memur[indis].yetki_turu);
				if ( (strcmp(Memur[indis].yetki_turu,"admin")) || (strcmp(Memur[indis].yetki_turu,"memur"))) {
					printf("Hatali ...! { admin ve ya memur }\n");
				}
			} while( Memur[indis].yetki_turu !="admin" && Memur[indis].yetki_turu !="memur");
			do 
			{
				printf("Kullanici Telefon(10 Hane): ");
				scanf("%12s",Memur[indis].telefon);
				if (d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon) || !d_sayi_control(Memur[indis].telefon)) {
					printf("\t\tHatali Giris...!\n\tLutfen 10 Haneli Rakam Girdiniz...!\n");
				}
			} while (!d_sayi_control(Memur[indis].telefon) || d_count(Memur[indis].telefon) != sizeof(Memur[indis].telefon));
			do 
			{ //tarih format�n� do�rulu�unu kontrol ediyoruz
				printf("S.Gelis Tarihi(gun.ay.yil): ");
				scanf("%10s",Memur[indis].gelis_tarihi);
			} while (!strpbrk(siginmaci[indis].gelis_tarihi, ".") && !d_sayi_control(Memur[indis].gelis_tarihi));
			do {
				printf("Kullanici email adress    : ");
				scanf("%s",Memur[indis].eposta);
			} while (!strpbrk(Memur[indis].eposta, "@") || !strpbrk(Memur[indis].eposta, ".")); //@ karakterinin dizi icinde kontrol
			printf("\n============\nToplam: %d\n============\n",indis+1);
			do {
				printf("\nDiske Kayd etmek icin < k > --->{ Baska Kayit Yapilacak mi (E/h) ?: ");
				secim[i] = getch();
				//if (secim[i] != 'E' && secim[i] != 'e') {
				//	printf("\tHatali Giris...!\nSeciminiz: ");
				//}
				if (secim[i] ==  'h' || secim[i] == 'H') {
					exit(false);}
				if (secim[i] == 'k' ||secim[i] == 'K') {
					dosya_M_Ekle(indis);
				}
			} while (secim[i] != 'E' && secim[i] != 'e');
			indis++;
			system("cls");
		} while (secim[i] == 'E' || secim[i] == 'e' || secim[i] != 'h' || secim[i] != 'H');
	}
}
//
void Bubble_sort(struct User siginmaci[], int num) {
	int i, j;
	struct User temp;
	for (i = 1; i < num; i++) {
		for (j = 0; j < num - 1; j++) {
			if (siginmaci[j].gelis_tarihi > siginmaci[j + 1].gelis_tarihi) {
				temp = siginmaci[j];
				siginmaci[j]= siginmaci[j + 1];
				siginmaci[j + 1] = temp;
			}
		}
	}
}
//Dizi kontrol

int d_control() {
	int bos;
	for (bos = 0; siginmaci[bos].no && Memur[bos].no && bos < MAX; bos++);
	if (bos < MAX) {
		return bos;
	}
	else {
		return - 1;
	}
}
//Dizi eleman sayimi
int d_count(char dizi[]) {
	int count = 0,i=0;
	while (dizi[i] != '\0') {
		count += 1;
		i ++;
	}
	return count;
}
//Girilenin sayi olup olmad���n� kontrol eder.
bool d_sayi_control(char* x) {
	bool Checked = true;
	int i = 0;
	do
	{   //girilen sayi mi?
		if (isdigit(x[i])) {
			i++;
			Checked = true;
		}
		else {
			i++;
			Checked = false;
			break;
		}
	} while (x[i] != '\0');
	return Checked;
}
//Girilenin Harf olup olmad���n� kontrol eder.
bool d_harf_control(char* x) {
	bool Checked = true;
	int i = 0;
	for (i = 0; i < sizeof(x); i++) {
		do {	  //girilen harf mi?
			if (isalpha(x[i])) {
				i++;
				Checked = true;
			}
			else {
				i++;
				Checked = false;
				break;
			}
		} while (x[i] != '\0');
	}
	return Checked;
}
//
void menu_Admin( ){
	char secim[15]; int i = 0;
	system("cls");
	printf("==================================================================\n");
	printf("\t\t\t\tADMIN\n");
	printf("==================================================================\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("|    Kullanici Islemleri       |   Siginmaci Islemleri         |\n");
	printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
	printf("  '                                  ' \n");
	printf("  '-->Kullanici Islemleri (k)        '--> Siginmaci Islemleri (s)\n");
	printf("\t\t'-->  1. Ekle.                '-->  1. Ekle.\n");
	printf("\t\t'-->  2. Silme.               '-->  2. Silme.\n");
	printf("\t\t'-->  3. Guncelle.            '-->  3. Guncelleme.\n");
	printf("\t\t'-->  4. Listele.             '-->  4. Listeleme.\n");
	printf("\t\t'-->  5. Arama.               '-->  5. Arama.\n\n");
	printf("\n---------------------------------------------------------------\n");
	printf("Kullanici I. icin < k >, Siginmaci I. icin <s>, Cikis icin <q>\n");
	printf("\n---------------------------------------------------------------\n");
	do {
		printf("Seciminiz: ");
		gets(secim);
		if (secim[i] == 'k') {
			do {
				printf("Kullanici Islemleri icin Seciminiz: ");
				gets(secim);
				switch (secim[i]) {
				case '1':
					system("cls");
					Memur_Kayit();
					break;
				default:
					break;
				}
			} while (secim[i] != 'k');
		}//if 1
		//Siginmaci islemleri menu secimi
		if (secim[i] == 's') {
		do {
			printf("Siginmaci Islemleri icin Seciminiz: ");
			gets_s(secim);
			switch (secim[i]) {
			case '1':
				system("cls");
				Siginmaci_Kayit();
				break;
			default:
				printf("Hatali secim\n");
				break;
			}//switch
		} while (secim[i] != 'k');
	} // if 2
		
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' );
}
//
void menu_Memur() {
	char secim[15]; int i = 0;
	system("clear");
	printf("==================================================================\n");
	printf("\t\t\tSiginmaci MEMUR\n");
	printf("==================================================================\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("|    Siginmaci Islemleri          |\n");
	printf("- - - - - - - - - - - - - - - - - -\n");
	printf("\t'  \n");
	printf("\t'-->  1. Yeni Kayit.\n");
	printf("\t'-->  2. Silme.\n");
	printf("\t'-->  3. Guncelle.\n");
	printf("\t'-->  4. Listele.\n");
	printf("\t'-->  5. Arama.\n");
	printf("\t'-->  6. Bilgilerimi goster, Sifre degis.\n\n");

	do {
		printf("Seciminiz: ");
		scanf_s("%s", secim);
		switch (secim[i]) {
			case '1':
				system("cls");
				Siginmaci_Kayit();
		        break;
			case '2':
				system("cls");

		        break;
			case '3':
				system("cls");

		        break;
			case '4':
				system("cls");

		        break;
			case '5':
				system("cls");

		        break;
			case '6':
				system("cls");

			default:
				printf("\tHatali Secim...!\n");
		}
	} while (!d_sayi_control(secim) ||secim[i] != '1' || secim[i] != '2' || secim[i] != '3' || secim[i] != '4' || secim[i] != '5' || secim[i] != '6');

}
//
void dosya_S_Ekle(int Sayi) {
	FILE *di;
	int i =0, count = 1; siginmaci[i].no = 1;
	if((di = fopen("Siginmaci.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	}
	fprintf(di,"\t\t\t\t\t\t...Siginmaci Kayitlari...\n________________________________________________________________________________________________________________________________________\n");
	fprintf(di," No |\tAd\t\t|\tSoyad\t\t|\t\t\t|\t\t\t|\t\t\t|\n");
	fprintf(di,"________________________________________________________________________________________________________________________________________\n");
	printf("\n\n----------------------------------------------------\n\t--{ %d Siginmaci Kayd edildi...!}--\n----------------------------------------------------\n", Sayi+1);
	for (i = 0; i <= Sayi; i++){
		if (siginmaci[i].ad[0])
			fprintf(di, "%3.d |%15s |%15s|\n", count, siginmaci[i].ad, siginmaci[i].soyad);
			count++;
			siginmaci[i].no = count;
			//printf(" Count: %d - NO: %d\n",count,siginmaci[i].no);
	}	
	fclose(di);
}
//Memur yeni kayit islemi
void dosya_M_Ekle(int Sayi) {
	FILE *di;
	int i =0, count = 1; Memur[i].no = 1;
	if((di = fopen("Kullanici.txt", "a")) == NULL){
		printf("Dosya acilamadi...!!!!!!\n");	
		return;
	}
	printf("\n\n----------------------------------------------------\n\t--{ %d Kullanici Kayd edildi...!}--\n----------------------------------------------------\n", Sayi+1);
	fprintf(di,"\t\t\t\t\t\t...Kullanici Kayitlari...\n________________________________________________________________________________________________________________________________________\n");
	fprintf(di," No |\tAd    \t|\tSoyad\t|\t\t\t|\t\t\t|\t\t\t|\n");
	fprintf(di,"________________________________________________________________________________________________________________________________________\n");
	for (i = 0; i <= Sayi; i++){
		if (Memur[i].ad[0])
			fprintf(di,"%3.d |%15s |%15s|\n", count, Memur[i].ad, Memur[i].soyad);
			count++;
			Memur[i].no = count;
			//printf(" Count: %d - NO: %d\n",count,Memur[i].no);
	}
	fclose(di);
}