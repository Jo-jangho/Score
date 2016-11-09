#include "PrintMath.h"
#include "print.h"

void printMath(student *head)	//�л� ���� ���� ��ȸ �޴�
{
	int num = 0;
	
	do{
		puts("\n================================================================================");
		puts("1. ���� ���� ��ü ��ȸ");
		puts("2. X�� �̻� ��ȸ");
		puts("3. X�� ���� ��ȸ");
		puts("4. �л� ���� ��ȸ");
		puts("�޴��� �����ϼ���(���� : -1) : ");

		scanf_s("%d", &num, sizeof(num));

		if (num == 0)
			puts("�ٽ� �Է��Ͻÿ�.");

		switch (num)
		{
		case -1:								//���� �޴�(�Լ� ����)
			break;
		case 1:									//1.���� ��ü ��ȸ
			fflush(stdin);						//�Է��Լ� ���� �ʱ�ȭ
			allPrintMath(head);
			break;
		case 2:									//2.X�� �̻� ��ȸ
			fflush(stdin);
			overMATH(head);
			break;
		case 3:									//3.X�� ���� ��ȸ
			fflush(stdin);
			underMATH(head);
			break;
		case 4:									//4.�л� ���� ��ȸ
			fflush(stdin);
			nameMATH(head);
			break;
		default:									//�ݺ��� ���� üũ(�޴� �̿��� �ٸ� ���� ��� �Դ��� Ȯ��)
			fflush(stdin);
			continue;
		}
	}while (num != -1);
}

void nameMATH(student *head)			//�л� ���� ��ȸ �Լ�
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);

	printf("��ȸ �� �л��� �̸��� �Է��Ͻÿ� :");
	scanf_s("%s", &name, sizeof(name));

	printf("�̸� : ");

	for (temp = head->next; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->name, name) == 0)
		{
			printName(temp);
			puts("\n================================================================================");
			printf("���� : ");
			printMATH(temp);
			break;
		}
	}

	fflush(stdin);
}

void allPrintMath(student *head)				//�л� ���� ���� ��ü ���
{
	student *temp = head->next;

	allPrintNAME(head);

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		printMATH(temp);
		temp = temp->next;
	}
	puts("");
}

void overMATH(student *head)				//X�� �̻� ���� ���� ���
{
	int num;
	student *temp = head->next;

	printf("\n ���� �̻��� ��ȸ �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &num, sizeof(num));

	printf("�̸� : ");
	while (temp != NULL)
	{
		if (temp->MATH >= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		if (temp->MATH >= num)
		{
			printMATH(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}

void underMATH(student *head)					//X�� �̻� ���� ���� ���
{
	int num;
	student *temp = head->next;

	printf("\n ���� ������ ��ȸ �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &num, sizeof(num));

	printf("�̸� : ");
	while (temp != NULL)
	{
		if (temp->MATH <= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("���� : ");
	while (temp != NULL)
	{
		if (temp->MATH <= num)
		{
			printMATH(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}