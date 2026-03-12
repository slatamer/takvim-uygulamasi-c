#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

// Fonksiyon Prototipleri
int ArtikYil(int girilen_yil);
int AyinGunleri(int girilen_yil, int ay);
int AyinÝlkGunu(int girilen_yil, int ay);
void TakvimiYaz(int girilen_yil, int ay);



int main() {

	int i, j, k, l;
	char tus;
	int girilen_yil = 0;
	int ay;

	do {
		system("cls");
		// Baþlýk Paneli Tasarýmý
		printf("\n\n\n\n\n                             %c", 201);            // sol üst köþe

		for (i = 0; i < 60; i++) {
			printf("%c", 205);                // yatay kenarlar
		}

		printf("%c", 187);                   // sað üst köþe

		for (j = 0; j < 3; j++) {
			printf("\n\t\t             ");
			printf("%c\t\t\t\t\t\t                  %c", 186, 186);         // dikey kenaralar
		}

		printf("\n\t\t\t     %c\t\t            TAKVIM UYGULAMASI                     %c", 186, 186);

		for (k = 0; k < 3; k++) {
			printf("\n\t\t       ");
			printf("      %c        \t\t\t\t\t\t          %c", 186, 186);      // dikey kenarlar
		}

		printf("\n\t\t             %c          Devam etmek icin D veya d tusuna basiniz.         %c", 186, 186);
		printf("\n\t\t             %c                CIKIS icin ESC tusuna basiniz.              %c", 186, 186);

		for (l = 0; l < 7; l++) {
			printf("\n\t\t\t");
			printf("     %c       \t\t\t\t\t\t          %c", 186, 186);          // dikey kenarlar
		}

		printf("\n\t\t             %c", 200);             // sol alt köþe

		for (i = 0; i < 60; i++) {
			printf("%c", 205);
		}

		printf("%c", 188);

		tus = _getch();

		if (tus == 27) {    // ESC Tuþu
			system("cls");

			printf("\nCikmak istediginizden emin misiniz? (E/H)\n");
			tus = _getch();

			if (tus == 69 || tus == 101) {
				return 0;
			}
			else {
				system("cls");
				continue;
			}
		}
		if (tus == 68 || tus == 100) {
			system("cls");

			printf("\n\n\n\n\n                                                     TAKVIM UYGULAMASI");
			printf("\n                                     ------------------------------------------------");
			printf("\n\n\n\n\t                                Takvimini gormek istediginiz yili giriniz.");
			printf("\n\n\t\t\t\t\t\t Yil: ");
			scanf_s("%d", &girilen_yil);

			// Yýl Sýnýrlandýrmasý
			while (girilen_yil < 1910 || girilen_yil > 2090) {
				system("cls");

				printf("\n\n\n\n\n                                                     TAKVIM UYGULAMASI");
				printf("\n                                     ------------------------------------------------");
				printf("\n\n\n\t                                * Gecersiz yil girisi yapildi !");
				printf("\n\n\n\t                                ** Lutfen 1910-2090 arasi bir yil giriniz!");
				printf("\n\n\n\n\t                                Takvimini gormek istediginiz yili giriniz.");
				printf("\n\n\t\t\t\t\t\t Yil: ");
				scanf_s("%d", &girilen_yil);
			}


			system("cls");

			printf("                                 %d YILI TAKVIMI", girilen_yil);

			for (ay = 1; ay <= 12; ay++) {
				TakvimiYaz(girilen_yil, ay);
			}


			printf("\n\n\n       Farkli bir yilin takvimini gormek isterseniz herhangi bir tusa basarak tekrar giris yapabilirsiniz.");
			printf("\n       Cikmak icin ESC tusuna basiniz.\n\n\n");

			tus = _getch();

			if (tus == 27) {
				system("cls");

				printf("\nCikmak istediginizden emin misiniz? (E/H)\n");
				tus = _getch();

				if (tus == 69 || tus == 101) {
					return 0;
				}
				else {
					system("cls");
					continue;
				}
			}
		}
	} while (1);

	return 0;
}


 
// Artik Yil Hesaplama Fonksiyonu
int ArtikYil(int girilen_yil) {
	if ((girilen_yil % 4 == 0 && girilen_yil % 100 != 0) || girilen_yil % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int AyinGunleri(int girilen_yil, int ay) {
	int gunler[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };            // Sýrasýyla aylarýn gün sayýsýný tutar.
	if (ArtikYil(girilen_yil) && ay == 2) {                           // Girilen yýl artýk mý? Yýlýn aylarýný yazdýrýrken sýra Þubat'a mý geldi?
		return 29;
	}
	return gunler[ay - 1];
}

// Zeller Algoritmasý ile Ayýn Ýlk Gününü Hesaplama Fonksiyonu
int AyinÝlkGunu(int girilen_yil, int ay) {

	int i, j;

	if (ay <= 2) {
		ay = ay + 12;
		girilen_yil--;
	}

	i = girilen_yil % 100;
	j = girilen_yil / 100;

	// Zeller formülü.
	int haftaninÝlkGunu = (1 + (13 * (ay + 1)) / 5 + i + i / 4 + j / 4 + 5 * j) % 7;          

	haftaninÝlkGunu = (haftaninÝlkGunu + 5) % 7;                    // Zeller haftanýn ilk gününe cumartesi ile baþlar,biz pazartesiden baþlatmak istiyoruz.
	                                                               // Bu durum þu þekilde düzeltilebilir.
	return haftaninÝlkGunu;             // Cumartesi(0) olan baþlangýç Pazartesiye(0) þeklinde düzeltildi.
}


void TakvimiYaz(int girilen_yil, int ay) {

	// const char; dizinin bir karakterden oluþmayan (5, a, X gibi), çok karakterli elemanlarýný tutar.
	const char* Aylar[] = { "OCAK","SUBAT","MART","NISAN","MAYIS","HAZIRAN","TEMMUZ","AGUSTOS","EYLUL","EKIM","KASIM","ARALIK" };

	printf("\n     |- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|\n");
	printf("\n                                     %-10s\n", Aylar[ay - 1]);

	printf("\n        Pzt       Sal       Car       Per       Cum       Cmt       Pzr\n");


	int ilkGun;
	int ayinGunSayisi;

	ilkGun = AyinÝlkGunu(girilen_yil, ay);

	// Ayýn gün sayýsýný belirleme
	if (ay == 2) {
		ayinGunSayisi = ArtikYil(girilen_yil) ? 29 : 28;           // "?:" koþul saðlanýyorsa ilk deðer,saðlanmýyorsa ikinci deðer döndürülür.
	}
	else if (ay == 4 || ay == 6 || ay == 9 || ay == 11) {
		ayinGunSayisi = 30;
	}
	else {
		ayinGunSayisi = 31;
	}

	// Baþlangýç gününe kadar boþluk býrakma
	for (int i = 0; i < ilkGun; i++) {
		printf("          ");
	}

	// Günleri yazdýrma
	for (int gun = 1; gun <= ayinGunSayisi; gun++) {

		if (ilkGun % 7 == 5 || ilkGun % 7 == 6) {
			printf("        \033[31m%2d\033[0m", gun);
		}
		else {
			printf("        \033[37m%2d\033[0m", gun);
		}

		ilkGun++;

		if (ilkGun % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");

}