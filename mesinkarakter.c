#include "mesinkarakter.h"
#include "variabelfile2.h"

void START(char filename[])
{		
	pita = fopen(filename,"r");
	ADV(filename);
}

void ADV(char filename[])
{
	fscanf(pita,"%c",&CC);
	if (EOP())
	{
		fclose(pita);
	}
}

void Read_Newline(char filename[])
{
	fscanf(pita,"\n");
}

boolean EOP()
{
	if (CC==mark)
	{
		return true;
	}
	else
	{
		return false;
	}
}


