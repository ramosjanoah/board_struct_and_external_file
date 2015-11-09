#include "mesinkata.h"

void Ignore_Blank(char filename[])
{
	while ((CC==blank) && (!EOP()))
	{
		ADV(filename);
	}	
}

void Ignore_Separator(char filename[])
{
	while ((CC=='|') && (!EOP()))
	{
		ADV(filename);
	}	
}

void STARTKATA(char filename[])
{
	START(filename);
	Ignore_Separator(filename);
	
	if (EOP(filename))
	{
		EndKata=true;
	}
	else
	{
		EndKata=false;
		SalinKata(filename);
	}
}

void ADVKATA(char filename[])
{
	Ignore_Separator(filename);
	
	if (EOP())
	{
		EndKata=true;
	}
	else
	{
		SalinKata(filename);
	}
}

void SalinKata(char filename[])
{
	int i=0;
	
	EndKata=false;
	CKata.Length=0;

	for (;;)	
	{
		CKata.TabKata[i]=CC;
		ADV(filename);
		
		if ((EOP()) || (CC=='|'))
		{
			break;
		}
		else
		{
			i++;
		}
	}
	CKata.Length=i+1;		

	if (CKata.Length>NMax)
	{
		for (i=NMax; i<=CKata.Length-1; i++)
		{
			CKata.TabKata[i]='\0';
		}
		CKata.Length=NMax;
	}
	
	if (EOP())
	{
		EndKata=true;
	}
	else
	{
		EndKata=false;
	}
}

Kata CopyKata(Kata K1)
{
	int i;
	Kata K2;
	
	K2.Length = K1.Length;
	
	for (i=0; i<=K1.Length-1; i++)
	{
		K2.TabKata[i] = K1.TabKata[i];
	}
	return K2;
}

void TulisKata(Kata K1)
{
	int i;
	
	for (i=0; i<=K1.Length-1; i++)
	{
		printf("%c",K1.TabKata[i]);
	}
	printf("\n");
}

boolean IsBilangan(Kata CKata) 
{
	boolean isbil;
	
	if (CKata.Length==0)
	{
		isbil = false;
	}
	else if (CKata.Length>=1) 
	{
		if (CKata.TabKata[0]=='1' || CKata.TabKata[0]=='2' || CKata.TabKata[0]=='3' || CKata.TabKata[0]=='4' || CKata.TabKata[0]=='5'
		 || CKata.TabKata[0]=='6' || CKata.TabKata[0]=='7' || CKata.TabKata[0]=='8' || CKata.TabKata[0]=='9' || CKata.TabKata[0]=='0')
			{
				isbil = true;
			}
		else 
			{
				isbil = false;
			}
	}
	return isbil;
}

int ConvertToBilangan(Kata CKata) 
{
	int i;
	int total = 0;
	if (IsBilangan(CKata))
	{
		for (i=0; i<CKata.Length; i++)
		{
			if (i>0)
			{
				total *= 10;
			}
			total = total + (CKata.TabKata[i]-'0');
		}
	}
	return total;
}

boolean IsKataSama(Kata K1, Kata K2)
{
	boolean sama;
	
	if (K1.Length!=K2.Length)
	{
		sama=false;
	}
	else
	{
		int i=0;
		
		sama=true;
		
		while ((sama) && (i<=K1.Length-1))
		{
			if (K1.TabKata[i]!=K2.TabKata[i])
			{
				sama=false;
			}
			else
			{
				i++;
			}
		}
	}
	
	return sama;
}

