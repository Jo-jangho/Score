#include "Score.h"
#include "Insert.h"
#include "allSerch.h"
#include "print.h"
#include "StudentDel.h"
#include "StudentUpdate.h"
#include "save.h"
#include "load.h"

int main(void)	
{
	int num = 0;																	//�޴� ������ ���� ����(0���� �ʱ�ȭ)

	student * head = (student *)malloc(sizeof(student));			//���Ḯ��Ʈ�� �Ӹ� �κ� ���� �Ҵ�(������ ������ ����)

	head->next = NULL;														//���Ḯ��Ʈ�� ���κ��� NULL�� �ʱ�ȭ

	
	do{																				//�������� ���α׷��� ���� �κ�(�޴� ��� �� �Լ� ȣ�� ���)
		puts("\n================================================================================");
		puts("1. �л� �߰�");
		puts("2. �л� ���� ��ȸ");
		puts("3. �л� ����");
		puts("4. �л� �̸� ����");
		puts("5. �л� ���� ����");
		puts("6. �л� ���� �ҷ�����");

		printf("�޴��� �����ϼ���(���� -1) : ");
		scanf_s("%d", &num, sizeof(num));								//�޴� ����

		if (num == 0)																//�Է��� ����� ���Դ��� üũ
			puts("�ٽ� �Է��ϼ���.");

		switch (num)
		{
		case -1:																	//���α׷� ����
			puts("���α׷��� ����˴ϴ�.");
			break;
		case 1:																		//1.�л� �߰�
			fflush(stdin);															//�Է��Լ� ���� �ʱ�ȭ
			newStudent(head);	
			break;
		case 2:																		//2.�л� ���� ��ȸ
			fflush(stdin);
			printData(head);
			break;
		case 3:																		//3.�л� ����
			fflush(stdin);
			studentDel(head);
			break;
		case 4:																		//4. �л� �̸� ����
			fflush(stdin);
			studentUpdate(head);
			break;
		case 5:																		//5. �л� ���� ����
			fflush(stdin);
			save(head);
			break;
		case 6:																		//6.�л� ���� �ҷ�����
			fflush(stdin);
			load(head);
			break;
		default:																		//�ݺ��� ���� üũ(�޴� �̿��� �ٸ� ���� ��� �Դ��� Ȯ��)
			fflush(stdin);
			continue;
		}
	}while (num != -1);

	return 0;
}