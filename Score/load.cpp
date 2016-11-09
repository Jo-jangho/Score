#include "load.h"

void load(student *head)							//�л� ������ �ҷ�����
{
	FILE * f_Student;									//FILE������ f_Student���� ����
	fopen_s(&f_Student, "Score.txt", "r+");	//������ �б������ ����

	if (f_Student == NULL)							//����� ���ȴ��� üũ
	{
		puts("���� ����");
		return;
	}

	student *temp = head;
	char c;
	float a;

	puts("�л� ���� �ҷ�����");


	while ((c = fgetc(f_Student)) != EOF)		//������ ������ �ݺ�
	{
		if (c == '/')										// '/' ���ڸ� ������ ����
		{
			student *New = (student *)malloc(sizeof(student));							//���Ḯ��Ʈ�� ���� �����ϱ� ���� ���� �Ҵ�
			fscanf_s(f_Student, "%s", New->name, sizeof(New->name));			//�̸� �ҷ�����
			fscanf_s(f_Student, "%d", &New->KOR, sizeof(New->KOR));			//���� ���� �ҷ�����
			fscanf_s(f_Student, "%d", &New->MATH, sizeof(New->MATH));		//���� ���� �ҷ�����
			fscanf_s(f_Student, "%d", &New->total, sizeof(New->total));			//���� �ҷ�����
			fscanf_s(f_Student, "%f", &a, sizeof(a));										//����� ���� a�� ����
			New->average = a;																		//��� �� ����
			fscanf_s(f_Student, "%d", &New->ranking, sizeof(New->ranking));	//���� �ҷ�����
			New->next = NULL;																		//���Ḯ��Ʈ�� �� ����
			temp->next = New;																		//�Ӹ��� ����
			temp = temp->next;																		//��� �̵�
		}
	}
	if (fclose(f_Student) == EOF)																	//����� �������� üũ
		puts("���� �ݱ� ����");
}