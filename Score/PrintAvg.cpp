#include "PrintAvg.h"
#include "print.h"

void printAvg(student *head)		//�л� ��� ��ȸ �޴�
{
	int num = 0;
	
	do{
		puts("\n================================================================================");
		puts("1. ��� ��ü ��ȸ");
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
		case 1:									//1.��� ��ü ��ȸ
			fflush(stdin);						//�Է��Լ� ���� �ʱ�ȭ
			allPrintAvg(head);
			break;
		case 2:									//2.X�� �̻� ��ȸ
			fflush(stdin);
			overAVG(head);
			break;
		case 3:									//3.X�� ���� ��ȸ
			fflush(stdin);
			underAVG(head);
			break;
		case 4:									//4.�л� ���� ��ȸ
			fflush(stdin);
			nameAVG(head);
			break;
		default:
			fflush(stdin);						//�ݺ��� ���� üũ(�޴� �̿��� �ٸ� ���� ��� �Դ��� Ȯ��)
			continue;
		}
	}while (num != -1);
}

void nameAVG(student *head)			//�л� ���� ��ȸ �Լ�
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);					//�л� �̸� ��ü ���

	printf("��ȸ �� �л��� �̸��� �Է��Ͻÿ� :");
	scanf_s("%s", &name, sizeof(name));		//��ȸ �� �л� �̸� �Է�

	printf("�̸� : ");

	for (temp = head->next; temp != NULL; temp = temp->next)	//���Ḯ��Ʈ ������ Ž��
	{
		if (strcmp(temp->name, name) == 0)								//���Ḯ��Ʈ�� �̸��� �Է¹��� �̸� ��
		{
			printName(temp);														//�л� �̸� ���
			puts("\n================================================================================");
			printf("��� : ");
			printAVG(temp);														//�л� ��� ���
			break;
		}
	}

	fflush(stdin);
}

void allPrintAvg(student *head)												//�л� ��� ��ü ���
{
	student *temp = head->next;
	printf("�̸� : ");

	allPrintNAME(head);														//�л� �̸� ��ü ���

	temp = head->next;
	printf("��� : ");
	while (temp != NULL)														//�л� ��� ��ü ���
	{
		printAVG(temp);
		temp = temp->next;
	}
	puts("");
}

void overAVG(student *head)												//X�� �̻� ��� ���
{
	int num;
	student *temp = head->next;

	printf("\n ���� �̻��� ��ȸ �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &num, sizeof(num));


	printf("�̸� : ");
	while (temp != NULL)														//����� X�� �̻��� �л� �̸� ���
	{
		if (temp->average >= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("��� : ");
	while (temp != NULL)														//����� X�� �̻��� �л� ��� ���
	{
		if (temp->average >= num)
		{
			printAVG(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}

void underAVG(student *head)												//X�� ���� ��� ���
{
	int num;
	student *temp = head->next;

	printf("\n ���� ������ ��ȸ �Ͻðڽ��ϱ�? : ");
	scanf_s("%d", &num, sizeof(num));


	printf("�̸� : ");
	while (temp != NULL)														//����� X�� ������ �л� ��� ���
	{
		if (temp->average <= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("��� : ");
	while (temp != NULL)														//����� X�� ������ �л� ��� ���
	{
		if (temp->average <= num)
		{
			printAVG(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}
