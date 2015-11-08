#include "mesinkarakter.h"
#include "variabelfile2.h"

void START()
{		
	pita = fopen(filename1,"r");
	ADV();
}

void ADV()
{
	fscanf(pita,"%c",&CC);
	if (EOP())
	{
		fclose(pita);
	}
}

void Read_Newline()
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


