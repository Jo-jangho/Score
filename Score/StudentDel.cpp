#include "StudentDel.h"

void studentDel(student *head)							//�л� ������ ���� �Լ�
{
	char name[8];
	student *temp = head->next;
	student *Del;

	allPrintNAME(head);									//�л� �̸� ��ü ���

	printf("���� �� �л��� �̸��� �Է��Ͻÿ� :");
	scanf_s("%s", &name, sizeof(name));			//���� �� �л� �̸� �Է�

	temp = head->next;
	if ((temp->next == NULL) && (strcmp(temp->name, name)) == 0)		//���Ḯ��Ʈ�� �����Ͱ� 1���ۿ� ���� �̸��� ��ġ�� ���
	{
		head->next = NULL;
		free(temp);
	}
	else
	{
		for (temp = head, Del = temp->next; temp != NULL; temp = temp->next, Del = Del->next)			//���Ḯ��Ʈ�� ������ �ݺ�
		{
			if (strcmp(temp->next->name, name) == 0)								//���Ḯ��Ʈ�� �̸��� �Է¹��� �̸� ��
			{
				temp->next = Del->next;
				Del->next = NULL;
				free(Del);
				break;
			}
		}
	}

	fflush(stdin);
}