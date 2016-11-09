#include "StudentUpdate.h"
#include "print.h"

void studentUpdate(student *head)			//학생 이름 수정 함수
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);

	printf("수정 할 학생의 이름을 입력하시오 :");
	scanf_s("%s", &name, sizeof(name));	//수정 할 학생 이름 입력

	for (temp = head->next; temp != NULL; temp = temp->next)	//연결리스트 끝까지 반복
	{
		if (strcmp(temp->name, name) == 0)								//연결리스트의 이름과 입력받은 이름 비교
		{
			printf("변경 될 학생의 이름을 입력하시오 :");
			scanf_s("%s", &temp->name, sizeof(temp->name));	//수정 될 학생 이름 입력
			break;
		}
	}

	fflush(stdin);
}