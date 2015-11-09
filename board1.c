#include <string.h>
#include "boolean.h"
#include "mesinkata.h"
#include "listsirkuler.h"

List Read_Board_File (char filename[]);

int main()
{	
	Address ptrav;
	List BoardL;
	
	BoardL = Read_Board_File("Board1.txt");
	//CONTOH AKSES KE ELEMEN LIST
	
	ptrav = Last(BoardL);
	
	//Untuk elemen bertipe char* :
	TulisKata(Info(ptrav).ptk.nama);
	TulisKata(Info(ptrav).ptk.tipe);
	TulisKata(Info(ptrav).ptk.currentplayer);
	
	//Untuk elemen bertipe integer
	printf("%d\n",Info(ptrav).ptk.id);
	printf("%d\n",Info(ptrav).ptk.kotapariwisata.harga.beli);
	printf("%d\n",Info(ptrav).ptk.kotapariwisata.harga.biayaupgrade[1]);
	return 0;
}

List Read_Board_File (char filename[])
{
	Kata Kota;

	Kota.Length = 4;
	Kota.TabKata[0] = 'k';
	Kota.TabKata[1] = 'o';
	Kota.TabKata[2] = 't';
	Kota.TabKata[3] = 'a';

	Kata Pariwisata;

	Pariwisata.Length = 10;
	Pariwisata.TabKata[0] = 'p';
	Pariwisata.TabKata[1] = 'a';
	Pariwisata.TabKata[2] = 'r';
	Pariwisata.TabKata[3] = 'i';
	Pariwisata.TabKata[4] = 'w';
	Pariwisata.TabKata[5] = 'i';
	Pariwisata.TabKata[6] = 's';
	Pariwisata.TabKata[7] = 'a';
	Pariwisata.TabKata[8] = 't';
	Pariwisata.TabKata[9] = 'a';

	Kata Start;

	Start.Length = 5;
	Start.TabKata[0] = 's';
	Start.TabKata[1] = 't';
	Start.TabKata[2] = 'r';
	Start.TabKata[3] = 'a';
	Start.TabKata[4] = 't';

	Kata Bonus;
	
	Bonus.Length = 5;
	Bonus.TabKata[0] = 'b';
	Bonus.TabKata[1] = 'o';
	Bonus.TabKata[2] = 'n';
	Bonus.TabKata[3] = 'u';
	Bonus.TabKata[4] = 's';
	
	Kata Chance;
	
	Chance.Length = 6;
	Chance.TabKata[0] = 'c';
	Chance.TabKata[1] = 'h';
	Chance.TabKata[2] = 'a';
	Chance.TabKata[3] = 'n';
	Chance.TabKata[4] = 'c';
	Chance.TabKata[5] = 'e';
	
	Kata Penjara;
	
	Penjara.Length = 7;
	Penjara.TabKata[0] = 'p';
	Penjara.TabKata[1] = 'e';
	Penjara.TabKata[2] = 'n';
	Penjara.TabKata[3] = 'j';
	Penjara.TabKata[4] = 'a';
	Penjara.TabKata[5] = 'r';
	Penjara.TabKata[6] = 'a';
	
	Kata Worldcup;
	
	Worldcup.Length = 8;
	Worldcup.TabKata[0] = 'w';
	Worldcup.TabKata[1] = 'o';
	Worldcup.TabKata[2] = 'r';
	Worldcup.TabKata[3] = 'l';
	Worldcup.TabKata[4] = 'd';
	Worldcup.TabKata[5] = 'c';
	Worldcup.TabKata[6] = 'u';
	Worldcup.TabKata[7] = 'p';
	
	Kata Worldtravel;
	
	Worldtravel.Length = 11;
	Worldtravel.TabKata[0]='w';
	Worldtravel.TabKata[1]='o';
	Worldtravel.TabKata[2]='r';
	Worldtravel.TabKata[3]='l';
	Worldtravel.TabKata[4]='d';
	Worldtravel.TabKata[5]='t';
	Worldtravel.TabKata[6]='r';
	Worldtravel.TabKata[7]='a';
	Worldtravel.TabKata[8]='v';
	Worldtravel.TabKata[9]='e';
	Worldtravel.TabKata[10]='l';
	
	Kata Tax;
	
	Tax.Length = 3;
	Tax.TabKata[0]='t';
	Tax.TabKata[1]='a';
	Tax.TabKata[2]='x';
	
	int i,j=0,counter1=0;
	Infotype X;
	List BoardL;
	
	CreateList(&BoardL);
	
	while (!EOP())
	{
		if (counter1==0)
		{
			START(filename);
		}
		
		for (i=1; i<=3; i++)
		{
			ADVKATA(filename);
			if (i==1) 
			{
				X.ptk.nama = CopyKata(CKata);					
			}
			else
			if (i==2) 
			{
				X.ptk.tipe = CopyKata(CKata);
			}
			else
			if (i==3) 
			{
				X.ptk.currentplayer = CopyKata(CKata);
			}			
		}
		
		if (IsKataSama(X.ptk.tipe,Kota))
		{
			for (i=1; i<=travkota-3; i++)
			{
				ADVKATA(filename);
				if (i==1) 
				{
					X.ptk.kotapariwisata.kepemilikan = CopyKata(CKata);
				}
				else if (i==2) 
				{
					X.ptk.kotapariwisata.harga.beli = ConvertToBilangan(CKata);
				}
				else if (i==3) 
				{
					X.ptk.kotapariwisata.harga.sewa = ConvertToBilangan(CKata);
				}
				else if (i==4) 
				{
					X.ptk.kotapariwisata.harga.belipaksa = ConvertToBilangan(CKata);
				}
				else if (i==5) 
				{
					X.ptk.kotapariwisata.harga.listoffered = ConvertToBilangan(CKata);
				}
				else if (i==6) 
				{
					X.ptk.kotapariwisata.lvlbangunan = ConvertToBilangan(CKata);
				}
				else if (i==7) 
				{
					X.ptk.kotapariwisata.harga.biayaupgrade[i-6] = ConvertToBilangan(CKata);
				}
				else if (i==8) 
				{
					X.ptk.kotapariwisata.harga.biayaupgrade[i-6] = ConvertToBilangan(CKata);
				}
				else if (i==9)
				{
					X.ptk.kotapariwisata.harga.biayaupgrade[i-6] = ConvertToBilangan(CKata);
				}
			}
		}
		else if (IsKataSama(X.ptk.tipe,Pariwisata))
		{
			for (i=1; i<=travpariwisata-3; i++)
			{
				ADVKATA(filename);
				if (i==1) 
				{
					X.ptk.kotapariwisata.kepemilikan = CopyKata(CKata);
				}
				else if (i==2) 
				{
					X.ptk.kotapariwisata.harga.beli = ConvertToBilangan(CKata);
				}
				else if (i==3) 
				{
					X.ptk.kotapariwisata.harga.sewa = ConvertToBilangan(CKata);
				}
				else if (i==4) 
				{
					X.ptk.kotapariwisata.harga.belipaksa = ConvertToBilangan(CKata);
				}
				else if (i==5) 
				{
					X.ptk.kotapariwisata.harga.listoffered = ConvertToBilangan(CKata);
				}
				else if (i==6) 
				{
					X.ptk.kotapariwisata.lvlbangunan = ConvertToBilangan(CKata);
				}
				else if (i==7) 
				{
					X.ptk.kotapariwisata.harga.biayaupgrade[i-6] = ConvertToBilangan(CKata);
				}
			}
		}
		else if (IsKataSama(X.ptk.tipe,Start))
		{
	
		}
		else if (IsKataSama(X.ptk.tipe,Bonus))
		{
			
		}
		else if (IsKataSama(X.ptk.tipe,Chance))
		{
			
		}
		else if (IsKataSama(X.ptk.tipe,Penjara))
		{
			
		}
		else if (IsKataSama(X.ptk.tipe,Worldcup))
		{
			
		}
		else if (IsKataSama(X.ptk.tipe,Worldtravel))
		{
			
		}
		else if (IsKataSama(X.ptk.tipe,Tax))
		{
			
		}
		
		if (counter1<1)
		{
			counter1++;
		}
		
		ADVKATA(filename);
		X.ptk.id = ConvertToBilangan(CKata);
			
		j++;	
		if (j>0)
		{
			InsVLast(&BoardL,X);
		}
		
		if(!EOP())
		{
			ADV(filename);
			ADV(filename);
		}		
	}
	return BoardL;
}
