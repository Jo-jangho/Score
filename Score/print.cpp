#include "print.h"

void printName(student *temp)		//학생 이름 출력
{
	printf(" %5s ", temp->name);
}

void printKOR(student *temp)		//국어 성적 출력
{
	printf(" %5d ", temp->KOR);
}

void printMATH(student *temp)		//수학 성적 출력
{
	printf(" %5d ", temp->MATH);
}

void printTOTAL(student *temp)	//총점 출력
{
	printf(" %5d ", temp->total);
}

void printAVG(student *temp)		//평균 출력
{
	printf(" %5.1f ", temp->average);
}

void printRANKING(student *temp)		//석차 출력
{
	printf(" %5d ", temp->ranking);
}

void allPrintNAME(student *head)		//학생 이름 전체 출력
{
	student *temp = head->next;
	printf("이름 : ");
	while (temp != NULL)
	{
		printName(temp);
		temp = temp->next;
	}
	puts("\n================================================================================");
}