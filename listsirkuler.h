#ifndef LISTSIRKULER_H
#define LISTSIRKULER_H

#include "variabelfile1.h"

#define Nil NULL
 
typedef struct 
{
  Petak ptk;
} Infotype;

typedef struct TElmtList *Address;

typedef struct TElmtList {
	Infotype info;
	Address next;
} ElmtList;

typedef struct {
	Address		first;
} List;

/*typedef struct TElmtList *Address;

typedef struct {
	Petak info;
	Address next;
} TElmtList;

typedef struct {
	Address first;
} List;*/
 
#define First(L) (L).first
#define Next(P) (P)->next
#define Info(P) (P)->info

Infotype CreateEmpty ();

Address Last(List L);
 
boolean IsListEmpty (List L);

void CreateList (List *L);

Address Alokasi (Infotype X);

void Dealokasi (Address *P);

Address Search (List L, Infotype X);

boolean FSearch (List L, Address P);

Address SearchPrec (List L, Infotype X);

void InsVFirst (List *L, Infotype X);

void InsVLast (List *L, Infotype X);

void DelVFirst (List *L, Infotype *X);

void DelVLast (List *L, Infotype *X);

void InsertFirst (List *L, Address P);

void InsertAfter (List *L, Address P, Address Prec);

void InsertLast (List *L, Address P);

void DeleteFirst (List *L, Address *P);

void DeleteP (List *L, Infotype X);

void DeleteLast (List *L, Address *P);

void DeleteAfter (List *L, Address *Pdel, Address Prec);

void PrintInfo (List L);

int NbElmt (List L);

Infotype Max (List L);

Address AdrMax (List L);

Infotype Min (List L);

Address AdrMin (List L);

double Average (List L);

void DeleteAll (List *L);

void InversList (List *L);

List FInversList (List L);

void CopyList (List L1, List *L2);

List FCopyList (List L);

void CpAlokList (List Lin, List *Lout);

void Concat (List L1, List L2, List *L3);

void Concat1 (List *L1,  List *L2, List *L3);

void PecahList (List *L1, List *L2, List L);

#endif
