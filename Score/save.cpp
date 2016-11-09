#include "save.h"

void save(student *head)
{
	FILE * f_Student;										//FILE�� f_Student���� ����
	fopen_s(&f_Student, "Score.txt", "w+");		//���� ��������� ����

	if (f_Student == NULL)								//����� ���ȴ��� üũ
	{
		puts("���� ����");
		return;
	}

	student *temp = head->next;

	puts("�л� ���� ����");
	while (temp != NULL)								//���Ḯ��Ʈ�� ������ �ݺ�
	{
		fprintf_s(f_Student, "/ \n %s \n %d \n %d \n %d \n %.2f \n %d \n", temp->name, temp->KOR, temp->MATH, temp->total, temp->average, temp->ranking);	//���Ͽ� �л� ������ ���� �������(/ �̸� ����� ���м��� ���� ��� ����)
		fflush(stdin);										//�Է� ���� �ʱ�ȭ
		temp = temp->next;
	}

	if (fclose(f_Student) == EOF)						//����� �������� üũ
		puts("���� �ݱ� ����");
}