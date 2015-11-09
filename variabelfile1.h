#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "mesinkata.h"

#define CharMax 50
#define LvlMax 4
#define NumberOfBoards 32
#define travstart 3
#define travkota 12
#define travpariwisata 10
#define travbonus 3
#define travchance 3
#define travpenjara 3
#define travworldcup 3
#define travworldtravel 3
#define travtax 3

typedef struct
{
	int sewa;
	int beli;
	int belipaksa;
	int listoffered;
	int biayaupgrade[LvlMax];
} tipeharga;

/*typedef struct
{
	tipeharga harga;
	int lvlbangunan;
	char kepemilikan;
	boolean isoffered;
} tipekota;

typedef struct
{
	tipeharga harga;
	char kepemilikan;
	boolean isoffered;
} tipepariwisata;*/

typedef struct
{
	Kata kepemilikan;
	int lvlbangunan;
	tipeharga harga;
} tipekotapariwisata;
	

typedef struct
{
	int id;
	Kata nama;
	Kata tipe;
	Kata currentplayer;
	tipekotapariwisata kotapariwisata;
} Petak;


