/* Author : @Noah - 13514089
*
*  INTERFACE ~
*  File ini dibuat dengan tujuan menyelesaikan tugas besar mata kuliah
*  Algoritma dan Struktur Data, IF2110.
*/


#ifndef INTERFACE_H
#define INTERFACE_H
#include "boolean.h"
#include "mesinkata.h"
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>


void TulisKata11Char(Kata K1); 
/* 	I.S : Sembarang
 * 	F.S : K1 tertulis dengan pasti 11 karakter. Bila kata panjangnya 
 * 		adalah x, maka akan dicetak spasi sebesar (11-x).
 * 
 * 	Untuk pembaharuan berikutnya, prosedur ini akan melakukan pencetakan
 * 	di tengah.
 */



void PrintBoard(List L);
/*
    I.S : Sembarang
    F.S : Board tercetak di layar, dengan posisi masing-masing pemain A, B, C, D (atau kurang),
          beserta blok-blok yang sudah dibeli.
*/


Address Petak_Idx(int Idx, List L);



#endif
