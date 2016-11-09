#include "StudentDel.h"

void studentDel(student *head)							//학생 데이터 삭제 함수
{
	char name[8];
	student *temp = head->next;
	student *Del;

	allPrintNAME(head);									//학생 이름 전체 출력

	printf("삭제 할 학생의 이름을 입력하시오 :");
	scanf_s("%s", &name, sizeof(name));			//삭제 할 학생 이름 입력

	temp = head->next;
	if ((temp->next == NULL) && (strcmp(temp->name, name)) == 0)		//연결리스트의 데이터가 1개밖에 없고 이름이 일치할 경우
	{
		head->next = NULL;
		free(temp);
	}
	else
	{
		for (temp = head, Del = temp->next; temp != NULL; temp = temp->next, Del = Del->next)			//연결리스트의 끝까지 반복
		{
			if (strcmp(temp->next->name, name) == 0)								//연결리스트의 이름과 입력받은 이름 비교
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