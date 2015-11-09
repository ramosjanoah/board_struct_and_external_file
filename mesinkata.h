#ifndef MESINKATA_H
#define MESINKATA_H
#define blank ' '
#define NMax 50
#include "mesinkarakter.h"
#include <stdio.h>
#define blank ' '

typedef struct {
	char TabKata[NMax];
	int	 Length;
} Kata;

boolean EndKata;
Kata	CKata;

void Ignore_Blank(char filename[]);

void Ignore_Separator(char filename[]);

void STARTKATA(char filename[]);

void ADVKATA(char filename[]);

void SalinKata(char filename[]);

Kata CopyKata(Kata K1);

boolean IsBilangan(Kata CKata);

int ConvertToBilangan (Kata CKata);

void TulisKata(Kata K1);

boolean IsKataSama(Kata K1, Kata K2);

#endif
