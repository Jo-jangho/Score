#include "StudentUpdate.h"
#include "print.h"

void studentUpdate(student *head)			//�л� �̸� ���� �Լ�
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);

	printf("���� �� �л��� �̸��� �Է��Ͻÿ� :");
	scanf_s("%s", &name, sizeof(name));	//���� �� �л� �̸� �Է�

	for (temp = head->next; temp != NULL; temp = temp->next)	//���Ḯ��Ʈ ������ �ݺ�
	{
		if (strcmp(temp->name, name) == 0)								//���Ḯ��Ʈ�� �̸��� �Է¹��� �̸� ��
		{
			printf("���� �� �л��� �̸��� �Է��Ͻÿ� :");
			scanf_s("%s", &temp->name, sizeof(temp->name));	//���� �� �л� �̸� �Է�
			break;
		}
	}

	fflush(stdin);
}