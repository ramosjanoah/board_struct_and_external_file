/* Author : @Noah - 13514089
*
*  INTERFACE ~
*  File ini dibuat dengan tujuan menyelesaikan tugas besar mata kuliah
*  Algoritma dan Struktur Data, IF2110.
*/

#include "MonopoliInterface.h"
#include "mesinkata.h"
#include "listsirkuler.h"


void TulisKata11Char(Kata K1) {
	int i;
	
	for (i=0; i<=K1.Length-1; i++)
	{
		printf("%c",K1.TabKata[i]);
	}
	
	int jumlahspace = 11- (K1.Length);
	for (i=1; i<=jumlahspace ; i++) {
		printf(" ");
	}	
} 

void PrintBoard(List L) {
	 /* 			  |12345678901|  -> 11 karakter. Harus ada fungsi yang menyediakan penulisan nama untuk 11 karakter,
	 * 			  |			  |  		yaitu TulisKata11Char().		
	1 =============================================================================================================
	2 |           |  Beijing 2|   Bonus 3 |  Jakarta 4|   Ancol 5 |   Taipei 6| New Delhi7|  Seoul   8|  DESERTED |	
    3 |   START 1 |           |           |           |           |           |           |           |   ISLAND  |
    4 |           |           |           |           |           |           |           |           |           |
    5 |           |           |           |           |           |           |           |           |          9|
    6 |-----------|===================================================================================|-----------|
    7 |  Bangkok  |                                                                                   |   Hawai   |
    8 |           |                                                                                   |           |
    9 |           |                                                                                   |           |
    10|         32|                                                                                   |         10|
    11|-----------|                                                                                   |-----------|
    12|           |                                                                                   |   Tokyo   |
    13|    TAX    |                                                                                   |           |
    14|           |                                                                                   |           |
    15|         31|                                                                                   |         11|
    16|-----------|                                                                                   |-----------|
    17|  New York |                                                                                   |   Sydney  |
    18|           |                                                                                   |           |
    19|           |                                                                                   |           |
    20|         30|                                                                                   |         12|
    21|-----------|                                                                                   |-----------|
    22|           |                                                                                   |           |
    23|  CHANCE   |                                                                                   |  CHANCE   |
    24|           |                                                                                   |           |
    25|         29|                                                                                   |         13|
    26|-----------|                                                                                   |-----------|
    27|   Paris   |                                                                                   | Singapura |
    28|           |                                                                                   |           |
    29|           |                                                                                   |           |
    30|         28|                                                                                   |         14|
    31|-----------|                                                                                   |-----------|
    32|   London  |                                                                                   |  Senggigi |
    33|           |                                                                                   |           |
    34|           |                                                                                   |           |
    35|         27|                                                                                   |         15|
    36|-----------|                                                                                   |-----------|
    37|   Kuta    |                                                                                   | Sao Paulo |
    38|           |                                                                                   |           |
    39|           |                                                                                   |           |
    40|         26|                                                                                   |         16|
    41|-----------|===================================================================================|-----------|
    42|   WORLD   |    Rome   |   Moscow  |   Geneva  |           |   Berlin  |   Bintan  |  Denmark  |   WORLD   |
    43|   TRAVEL  |           |           |           |  CHANCE   |           |           |           |    CUP    |
    44|           |           |           |           |           |           |           |           |           |
    45|         25|         24|         23|        22 |         21|         20|         19|         18|         17|
    46===================================================================================================================
    * 
    * 
    * YANG HARUS DIKERJAKAN BERIKUTNYA :
    * - SHOW LIST OFFERED (no 6)
    * - Leaderboard : di sebelah kanan.
	 */

	//Address Px;

	// Line 1
		printf(" 1");
		printf("=============================================================================================================\n");
	// Line 2
		printf(" 2");
		printf("|           |");
		TulisKata11Char(Info(Petak_Idx(2,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(3,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(4,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(5,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(6,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(7,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(8,L)).ptk.nama);
		printf("|           |");
		printf("\n");
	// Line 3
		printf(" 3|");
		TulisKata11Char(Info(Petak_Idx(1,L)).ptk.nama);
		printf("|           |           |           |           |           |           |           |           |");
		printf("\n");
	// Line 4
		printf(" 4|");
		printf("           |           |           |           |           |           |           |           |           |");
		printf("\n");
	// Line 5
		printf(" 5|");
		printf("           |           |           |           |           |           |           |           |           |");
		printf("\n");
	// Line 6
		printf(" 6|-----------|===================================================================================|-----------|\n");
	// Line 7
	printf(" 7|");
		//TulisKata11Char(Info(Petak_Idx(32,L)).ptk.nama); // NOMOR 32 MASIH ERROR.
		printf("           "); // 11 karakter space.
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(10,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 8
		printf(" 8|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 9
		printf(" 9|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 10
		printf("10|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 11
		printf("11|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");
	// Line 12
		printf("12|");
		TulisKata11Char(Info(Petak_Idx(31,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(11,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 13
		printf("13|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 14
		printf("14|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 15
		printf("15|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 16
		printf("16|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");
	// Line 17
		printf("17|");
		TulisKata11Char(Info(Petak_Idx(30,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(12,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 18
		printf("18|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 19
		printf("19|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 20
		printf("20|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 21
		printf("21|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");
	// Line 22
		printf("22|");
		TulisKata11Char(Info(Petak_Idx(29,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(13,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 23
		printf("23|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 24
		printf("24|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 25
		printf("25|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 26
		printf("26|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");
		
	// Line 27
		printf("27|");
		TulisKata11Char(Info(Petak_Idx(28,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(14,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 28
		printf("28|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 29
		printf("29|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 30
		printf("30|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 31
		printf("31|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");

	// Line 32
		printf("32|");
		TulisKata11Char(Info(Petak_Idx(27,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(15,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 33
		printf("33|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 34
		printf("34|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 35
		printf("35|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 36
		printf("36|");
		printf("-----------|                                                                                   |-----------|");
		printf("\n");

	// Line 37
		printf("37|");
		TulisKata11Char(Info(Petak_Idx(26,L)).ptk.nama);
		printf("|                                                                                   |");
		TulisKata11Char(Info(Petak_Idx(16,L)).ptk.nama);
		printf("|");
		printf("\n");
	// Line 38
		printf("38|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 39
		printf("39|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 40
		printf("40|");
		printf("           |                                                                                   |           |");
		printf("\n");
	// Line 41
		printf("41|-----------|===================================================================================|-----------|");
		printf("\n");
	// Line 42
		printf("42|");
		//TulisKata11Char(Info(Petak_Idx(25,L)).ptk.nama);	<- Lebih dari 11 Karakter
		printf("           ");
		printf("|");
		TulisKata11Char(Info(Petak_Idx(24,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(23,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(22,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(21,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(20,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(19,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(18,L)).ptk.nama);
		printf("|");
		TulisKata11Char(Info(Petak_Idx(17,L)).ptk.nama);
		printf("|\n");
	// Line 43
		printf("43|");
		printf("           |           |           |           |           |           |           |           |           |");
		printf("\n");
	
	// Line 44
		printf("44|");
		printf("           |           |           |           |           |           |           |           |           |");
		printf("\n");
	
	// Line 45 
		printf("45|");
		printf("           |           |           |           |           |           |           |           |           |");
		printf("\n");
	
	// Line 46
		printf("46|");
		printf("=============================================================================================================\n");

	
}

Address Petak_Idx(int Idx, List L) {
	Address P = First(L);
	boolean found = false;
	
	while (P != Last(L) && (!found)) {
		if (Info(P).ptk.id == Idx) {
			found = true;
		} else {
			P = Next(P);
		}
	}
	
	if (found) {
		return P;
	} else {
		return Nil;
	}
}


