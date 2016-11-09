#include "Insert.h"

void newStudent(student *head)										//�л� �߰� �Լ�
{
	student *New = (student *)malloc(sizeof(student));				//���Ḯ��Ʈ�� ���� ���� �� ����
	student *temp = head;											//���Ḯ��Ʈ�� ���������� Ž���ϴ� ����

	if (temp->next == NULL)											//���Ḯ��Ʈ�� �Ӹ��� �ְ� ������ ������� �Ӹ��� ����
	{
		New->next = temp->next;												
		temp->next = New;
		printf("�л��� �Է��Ͻÿ� : ");
		scanf_s("%s", &New->name, sizeof(New->name));				//�л��� �̸� �Է�
		fflush(stdin);
		scoreInsert(head, New);										//���� �Է� �Լ� ȣ��(�Ӹ��� �߰��� ��� �Ѱ� ��)
	}
	else															//���Ḯ��Ʈ�� ���� ��� ���Ḯ��Ʈ�� �������� ����
	{
		while (temp->next != NULL)									//���Ḯ��Ʈ�� ������ �̵�
			temp = temp->next;

		New->next = temp->next;
		temp->next = New;
		printf("�л��� �Է��Ͻÿ� : ");
		scanf_s("%s", &New->name, sizeof(New->name));				//�л��� �̸� �Է�
		fflush(stdin);
		scoreInsert(head, New);										//���� �Է� �Լ� ȣ��(�Ӹ��� �߰��� ��� �Ѱ� ��)
	}
}

void resetRanking(student *head)									//�л� ������ ���� 1�� �ʱ�ȭ
{
	student	*temp = head->next;
	while (temp != NULL)
	{
		temp->ranking = 1;
		temp = temp->next;
	}
}
void Ranking(student *head)											//�л� ���� ���� �Լ�
{
	student	*temp = head->next;
	student	*next = NULL;
	student *TopStudent = temp;
	int TopPoint = 1;

	resetRanking(head);												//�л� ������ ���� 1�� �ʱ�ȭ

	if (temp != NULL && temp->next == NULL)							//�л��� 1���� ���
		temp->ranking = 1;

	for (temp = head->next; temp != NULL; temp = temp->next)		//�л� �Ѹ��Ѹ� ��
	{
		for (next = head->next; next != NULL; next = next->next)
		{
			if (next->total < temp->total)							//a�л��� �������� b�л��� ������ ������� ������ 1 ����
				next->ranking++;
		}
	}
}

void scoreInsert(student *head, student *New)						//�л� ���� �Է� �Լ�
{
	while (1)
	{
		printf("%s�л��� ���� ������ �Է��Ͻÿ�(0~100��) : ", New->name);
		scanf_s("%d", &New->KOR, sizeof(New->KOR));					//���� ���� �Է�
	
		if (New->KOR >= 0 && New->KOR <= 100) break;				//0�� �̻� 100�� ���� �ΰ�� �ݺ� ����
		else														//�ƴҰ�� �ݺ��� ó������ ���ư��� �ٽ� �Է�
		{
			printf("������ �ٽ� �Է��ϼ���!\n");
			fflush(stdin);											//�Է� ���� �ʱ�ȭ
		}
	}

	while (1)
	{
		printf("%s�л��� ���� ������ �Է��Ͻÿ�(0~100��) : ", New->name);
		scanf_s("%d", &New->MATH, sizeof(New->MATH));				//���� ���� �Է�
	
		if (New->MATH >= 0 && New->MATH <= 100) break;
		else
		{
			printf("������ �ٽ� �Է��ϼ���!\n");
			fflush(stdin);
		}
	}
	calculation(head);												//����, ���, ���� ����
}

void calculation(student *head)
{
	student *temp = head->next;

	while (temp != NULL)											//���Ḯ��Ʈ ������ �ݺ�
	{
		temp->total = (temp->KOR + temp->MATH);						//���� ����
		temp->average = temp->total / 2;							//��� ����
		Ranking(head);												//���� ����
		temp = temp->next;
	}
}