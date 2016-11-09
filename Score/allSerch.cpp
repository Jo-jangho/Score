#include "allSerch.h"
#include "print.h"
#include "PrintKor.h"
#include "PrintMath.h"
#include "PrintTotal.h"
#include "PrintAvg.h"
#include "PrintRank.h"

void printData(student *head)									//�л� ���� ��ȸ �޴�
{
	int num = 0;														
	
	do{																	
		puts("\n================================================================================");
		puts("1. �л� ��ü ��ȸ");
		puts("2. ���� ���� ��ȸ");
		puts("3. ���� ���� ��ȸ");
		puts("4. �л� ���� ��ȸ");
		puts("5. �л� ��� ��ȸ");
		puts("6. �л� ���� ��ȸ");
		puts("�޴��� �����ϼ���(���� : -1) : ");

		scanf_s("%d", &num, sizeof(num));					

		if (num == 0)												
			puts("�ٽ� �Է��ϼ���.");

		switch (num)
		{
		case -1:														//���� �޴�(�Լ� ����)
			break;
		case 1:															//1.�л� ��ü ��ȸ
			fflush(stdin);												//�Է��Լ� ���� �ʱ�ȭ
			allPrint(head);
			break;
		case 2:															//2.���� ���� ��ȸ
			fflush(stdin);
			printKor(head);
			break;
		case 3:															//3.���� ���� ��ȸ
			fflush(stdin);
			printMath(head);
			break;
		case 4:															//4.�л� ���� ��ȸ
			fflush(stdin);
			printTotal(head);
			break;
		case 5:															//5.�л� ��� ��ȸ
			fflush(stdin);
			printAvg(head);
			break;
		case 6:															//6.�л� ���� ��ȸ
			fflush(stdin);
			printRank(head);
			break;
		default:															//�ݺ��� ���� üũ(�޴� �̿��� �ٸ� ���� ��� �Դ��� Ȯ��)
			fflush(stdin);
			continue;
		}
	}while (num != -1);
}

void allPrint(student *head)										//�л��� ��� ������ ���
{
	student *temp = head->next;									//���Ḯ��Ʈ�� ���������� Ž���ϴ� ����
	printf("�̸� : ");
	while (temp != NULL)											//���Ḯ��Ʈ�� ���������� �ݺ�
	{
		printName(temp);												//�л� �̸� ���
		temp = temp->next;											//���Ḯ��Ʈ�� ���� ���� �̵�
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		printKOR(temp);												//�л� ���� ���� ���
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		printMATH(temp);											//�л� ���� ���� ���
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		printTOTAL(temp);											//�л� ���� ���
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("��� : ");
	while (temp != NULL)
	{
		printAVG(temp);												//�л� ��� ���
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		printRANKING(temp);										//�л� ���� ���
		temp = temp->next;
	}
	puts("");
}


