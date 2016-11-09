#include "print.h"

void printName(student *temp)		//�л� �̸� ���
{
	printf(" %5s ", temp->name);
}

void printKOR(student *temp)		//���� ���� ���
{
	printf(" %5d ", temp->KOR);
}

void printMATH(student *temp)		//���� ���� ���
{
	printf(" %5d ", temp->MATH);
}

void printTOTAL(student *temp)	//���� ���
{
	printf(" %5d ", temp->total);
}

void printAVG(student *temp)		//��� ���
{
	printf(" %5.1f ", temp->average);
}

void printRANKING(student *temp)		//���� ���
{
	printf(" %5d ", temp->ranking);
}

void allPrintNAME(student *head)		//�л� �̸� ��ü ���
{
	student *temp = head->next;
	printf("�̸� : ");
	while (temp != NULL)
	{
		printName(temp);
		temp = temp->next;
	}
	puts("\n================================================================================");
}