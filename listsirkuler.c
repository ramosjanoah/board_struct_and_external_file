#include "listsirkuler.h"
#include "mesinkata.h"

Infotype CreateEmpty ()
{
	Infotype X;
	
	return X;
}

Address Last(List L)
{
	Address p;

	p=First(L);
	
	if(p!=Nil)
	{
		while (Next(p)!=First(L))
		{
			p=Next(p);
		}
	}

	return p;
}
 
boolean IsListEmpty (List L)
{
	boolean isEmpty;

	isEmpty = (First(L)==Nil);
	return isEmpty;
}

void CreateList (List *L)
{
	First(*L) = Nil;
}

Address Alokasi (Infotype X)
{
	Address p;

	p = (ElmtList*) (malloc(sizeof(ElmtList)));

	if (p!=Nil)
	{
		Info(p)=X;
		Next(p)=Nil;
	}
	return p;
}

void Dealokasi (Address *P)
{
	free(*P);
}

Address Search (List L, Infotype X)
{
	if (IsListEmpty(L))
	{
		return Nil;
	}
	else
	{
		Address p;
		boolean found;

		found=false;
		p=First(L);
		/*if (Info(p)==X)
		{
			found=true;
		}*/

		while ((!found) && (Next(p)!=First(L)))
		{
			p=Next(p);
			/*if (Info(p)==X)
			{
				found=true;
			}*/
		}

		if (found)
		{
			return p;
		}
		else
		{
			return Nil;
		}
	}
}

boolean FSearch (List L, Address P)
{
	/*if (IsListEmpty(L))
	{
		return false;
	}
	else
	{
		Address px;
		boolean found;

		found=false;
		px=First(L);
		if (px==P)
		{
			found=true;
		}

		while ((!found) && (Next(px)!=First(L)))
		{
			px=Next(px);
			if (px==P)
			{
				found=true;
			}
		}
		return found;
	}*/
		//Slide
		Address ptrav;
	 	
		if (IsListEmpty(L)) 
		{ 
			return false;
		} 
		else 
		{ 	
			ptrav = First(L); 

			while ((Next(ptrav) != First(L)) && (ptrav != P)) 
			{ 
				ptrav = Next(ptrav); 
			} 
			
			if (ptrav == P) 
			{ 
				return true; 
			} 
			else 
			{ 
				return false; 
			}
		}
}

Address SearchPrec (List L, Infotype X)
{
	if (IsListEmpty(L))
	{
		return Nil;
	}
	else
	{
		Address p,prec;
		boolean found;

		found=false;
		p=First(L);
		prec=Nil;
		/*if (Info(p)==X)
		{
			found=true;
		}*/

		while ((!found) && (Next(p)!=First(L)))
		{
			prec=p;
			p=Next(p);
			/*if (Info(p)==X)
			{
				found=true;
			}*/
		}

		if (found)
		{
			return prec;
		}
		else
		{
			return Nil;
		}
	}
}

void InsVFirst (List *L, Infotype X)
{
	Address p;

	p=Alokasi(X);

	if (p!=Nil)
	{
		InsertFirst(L,p);
	}
}

void InsVLast (List *L, Infotype X)
{
	Address p;

	p=Alokasi(X);

	if (p!=Nil)
	{
		InsertLast(L,p);
	}
}

void DelVFirst (List *L, Infotype *X)
{
	Address p;

	*X=Info(First(*L));
	DeleteFirst(L,&p);
	Dealokasi(&p);
}

void DelVLast (List *L, Infotype *X)
{
	Address p;
	
	DeleteLast(L,&p);
	*X=Info(p);
	Dealokasi(&p);
}

void InsertFirst (List *L, Address P)
{
	if (IsListEmpty(*L))
	{
		First(*L)=P;	
		Next(First(*L))=First(*L);
	}
	else
	{
		Next(Last(*L))=P;
		Next(P)=First(*L);
		First(*L)=P;		
	}

	//Slide
	/*Address last;

	if (IsListEmpty(*L)) 
	{ 
		Next(P) = P;
	} 
	else 
	{ 
		last = First(*L); 

		while (Next(last) != First(*L)) 
		{
			last = Next(last); 
		} 
		Next(P) = First(*L); 
		Next(last) = P;
	}
	First(*L) = P;*/
}


void InsertAfter (List *L, Address P, Address Prec)
{
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

void InsertLast (List *L, Address P)
{
	if (IsListEmpty(*L)) 
	{
		InsertFirst(L,P);
	}
	else
	{
		Address plast;

		plast=Last(*L);
		InsertAfter(L,P,plast);
	}

	//Slide
	/*Address last;

	if (IsListEmpty(*L)) 
	{ 
		InsertFirst(L,P);
	} 
	else 
	{
		last = First(*L);
		while (Next(last) != First(*L)) 
		{
			last = Next(last);
		} 
		InsertAfter(L,P,last);
	}*/
}


void DeleteFirst (List *L, Address *P)
{
	*P=First(*L);
	if (NbElmt(*L)==1)
	{
		First(*L) = Nil;
	}
	else
	{
		Address plast;

		plast=Last(*L);
		Next(plast)=Next(First(*L));
		First(*L)=Next(First(*L));
	}

	//Slide
	/*Address last;

	*P = First(*L);
	if (Next(First(*L)) == First(*L)) 
	{ 
		First(*L) = Nil;
	} 
	else 
	{
		last = First(*L); 

		while (Next(last) != First(*L)) 
		{ 
			last = Next(last); 
		}  
		First(*L) = Next(First(*L)); 
		Next(last) = First(*L);
	}
	Next(*P) = Nil;*/
}

void DeleteP (List *L, Infotype X)
{	
	if (!IsListEmpty(*L))
	{
		Address p,pdel;
		Address prec;
		
		p=First(*L);
		prec=SearchPrec(*L,X);

		if (prec!=Nil)
		{
			DeleteAfter(L,&pdel,prec);
		}
		/*else if (Info(p)==X)
		{
			DeleteFirst(L,&pdel);
		}*/
		Dealokasi(&pdel);
	}
}

void DeleteLast (List *L, Address *P)
{
	*P=Last(*L);

	if(NbElmt(*L)==1)
	{
		DeleteFirst(L,P);
	}
	else
	{
		Address prec;

		prec=First(*L);
		while (Next(prec)!=Last(*L))
		{
			prec = Next(prec);
		}

		Next(prec)=First(*L);
	}

	//Slide
	/*Address Last, PrecLast;

	Last = First(*L);
	PrecLast = Nil;
	while (Next(Last) != First(*L)) 
	{
		PrecLast = Last; Last = Next(Last);
	}
	*P = Last;
	if (PrecLast == Nil) 
	{ 
		First(*L) = Nil;
	} 
	else 
	{ 
		Next(PrecLast) = First(*L);
	}
	Next(*P) = Nil;*/
}

void DeleteAfter (List *L, Address *Pdel, Address Prec)
{
	*Pdel=(Next(Prec));
	Next(Prec)=Next(Next(Prec));
}

void PrintInfo (List L)
{
	if (IsListEmpty(L))
	{
		printf("[]\n");
	}
	/*else
	{
		Address p;

		p=First(L);
		if ((p==First(L)) && (Next(p)==First(L)))
		{
			printf("[%d]",Info(p));
		}
		else if ((p==First(L)) && (Next(p)!=First(L)))
		{
			printf("[%d,",Info(p));
		}
		else if ((p!=First(L)) && (Next(p)==First(L)))
		{
			printf(" %d]",Info(p));	
		}
		else
		{
			printf(" %d,",Info(p));
		}

		while (Next(p)!=First(L))
		{
			p=Next(p);
			if ((p==First(L)) && (Next(p)==First(L)))
			{
				printf("[%d]",Info(p));
			}
			else if ((p==First(L)) && (Next(p)!=First(L)))
			{
				printf("[%d,",Info(p));
			}
			else if ((p!=First(L)) && (Next(p)==First(L)))
			{
				printf(" %d]",Info(p));	
			}
			else
			{
				printf(" %d,",Info(p));
			}
		}
		printf("\n");
	}*/
}

int NbElmt (List L)
{
	int count=0;

	if (!IsListEmpty(L))
	{
		Address p;
		p=First(L);
		count++;

		while (Next(p)!=First(L))
		{
			p=Next(p);
			count++;
		}
	}
	return count;
}

Infotype Max (List L)
{
	Infotype maksimum;
	Address p;

	maksimum=Info(First(L));
	p=Next(First(L));

	/*while (p!=First(L))
	{
		if (Info(p)>maksimum)
		{
			maksimum=Info(p);
		}
		p=Next(p);
	}*/
	return maksimum;
}

Address AdrMax (List L)
{
	return Search(L,Max(L));
}

Infotype Min (List L)
{
	Infotype minimum;
	Address p;

	minimum=Info(First(L));
	p=Next(First(L));

	/*while (p!=First(L))
	{
		if (Info(p)<minimum)
		{
			minimum=Info(p);
		}
		p=Next(p);
	}*/
	return minimum;
}

Address AdrMin (List L)
{
	return Search(L,Min(L));
}

double Average (List L)
{
	double sum=0.0;

	if (!IsListEmpty(L))
	{
		Address p;
		int jumlah = NbElmt(L);

		p=First(L);
		/*sum+= (double) Info(p);

		while (Next(p)!=First(L))
		{
			p=Next(p);
			sum+= (double) Info(p);
		}*/
		sum /= (double) jumlah;
	}
	return sum;
}

void DeleteAll (List *L)
{
	if (!IsListEmpty(*L))
	{
		Address p;

		p=First(*L);
		while (NbElmt(*L)>0)
		{
			DeleteFirst(L,&p);
			Dealokasi(&p);
			p=First(*L);
		}
	}
}

void InversList (List *L)
{
	Address ptrav, pdel;
	int jumlahel,i;

	jumlahel=NbElmt(*L);
	ptrav=Nil;
	for (i=1; i<=jumlahel; i++)
	{
		DeleteLast(L,&pdel);
		if (ptrav==Nil)
		{
			InsertFirst(L,pdel);
			ptrav=First(*L);
		}
		else
		{
			InsertAfter(L,pdel,ptrav);
			ptrav=Next(ptrav);
		}
	}
}

List FInversList (List L)
{
	List Ltemp;
	Address p, temp;

	p=First(L);
	CreateList(&Ltemp);

	if (!IsListEmpty(L))
	{
		First(Ltemp) = Alokasi (Info(p));
		Next(First(Ltemp)) = First(Ltemp);
		p=Next(p);

		while (p!=First(L))
		{
			temp = Alokasi(Info(p));
			if (temp==Nil)
			{
				DeleteAll(&Ltemp);
				p=First(L);
			}
			else
			{
				InsertFirst(&Ltemp,temp);
				p=Next(p);
			}
		}
	}
	return Ltemp;
}

void CopyList (List L1, List *L2)
{
	First(*L2) = First(L1);
}

List FCopyList (List L)
{
	List temp;
	Address p, prec;

	p=First(L);
	CreateList(&temp);

	if (!IsListEmpty(L))
	{
		First(temp) = Alokasi (Info(p));
		prec=First(temp);
		p=Next(p);

		if(p==First(L))
		{
			Next(First(temp))=First(temp);
		}

		while (p!=First(L))
		{
			Next(prec) = Alokasi(Info(p));
			if (Next(prec)==Nil)
			{
				DeleteAll(&temp);
				p=First(L);
			}
			else
			{
				p=Next(p);
				prec=Next(prec);
				if (p==First(L))
				{
					Next(prec)=First(temp);
				}
			}
		}
	}
	return temp;
}

void CpAlokList (List Lin, List *Lout)
{
	*Lout = FCopyList(Lin);
}

void Concat (List L1, List L2, List *L3)
{
	CreateList(L3);
	if ((!IsListEmpty(L1)) && (IsListEmpty(L2)))
	{
		*L3 = FCopyList (L1);
	}
	else if ((IsListEmpty(L1)) && (!IsListEmpty(L2)))
	{
		*L3 = FCopyList (L2);
	}
	else if ((!IsListEmpty(L1)) && (!IsListEmpty(L2)))
	{
		List Ltemp;

		CreateList(&Ltemp);

		*L3=FCopyList(L1);
		Ltemp=FCopyList(L2);

		Next(Last(Ltemp))=First(*L3);
		Next(Last(*L3))=First(Ltemp);	
	}
}

void Concat1 (List *L1,  List *L2, List *L3)
{
	CreateList(L3);
	if ((!IsListEmpty(*L1)) && (IsListEmpty(*L2)))
	{
		CopyList(*L1,L3);
		CreateList(L1);
	}
	else if ((IsListEmpty(*L1)) && (!IsListEmpty(*L2)))
	{
		CopyList(*L2,L3);
		CreateList(L2);
	}
	else if ((!IsListEmpty(*L1)) && (!IsListEmpty(*L2)))
	{
		List Ltemp;

		CreateList(&Ltemp);

		CopyList(*L1,L3);
		CopyList(*L2,&Ltemp);

		Next(Last(Ltemp))=First(*L3);
		Next(Last(*L3))=First(Ltemp);	

		CreateList(L1);
		CreateList(L2);
	}
}

void PecahList (List *L1, List *L2, List L)
{
	Address p,temp;
	int i, jumlahel1, jumlahel2;

	CreateList(L1);
	CreateList(L2);

	jumlahel1 = NbElmt(L)/2;
	jumlahel2 = NbElmt(L)-jumlahel1;

	for (i=1; i<=jumlahel1; i++)
	{
		if (i==1)
		{
			p=First(L);
		}

		temp = Alokasi (Info(p));
		if (temp==Nil)
		{
			DeleteAll(L1);
		}
		else
		{
			InsertLast(L1,temp);
		}
		p=Next(p);
	}	

	for (i=1; i<=jumlahel2; i++)
	{
		temp = Alokasi (Info(p));
		if (temp==Nil)
		{
			DeleteAll(L1);
			DeleteAll(L2);
		}
		else
		{
			InsertLast(L2,temp);
		}
		p=Next(p);
	}	
}



