#include "Insert.h"

void newStudent(student *head)										//학생 추가 함수
{
	student *New = (student *)malloc(sizeof(student));				//연결리스트에 새로 삽입 할 변수
	student *temp = head;											//연결리스트를 순차적으로 탐색하는 변수

	if (temp->next == NULL)											//연결리스트의 머리만 있고 시작이 없을경우 머리에 연결
	{
		New->next = temp->next;												
		temp->next = New;
		printf("학생을 입력하시오 : ");
		scanf_s("%s", &New->name, sizeof(New->name));				//학생의 이름 입력
		fflush(stdin);
		scoreInsert(head, New);										//점수 입력 함수 호출(머리와 추가할 노드 넘겨 줌)
	}
	else															//연결리스트가 있을 경우 연결리스트의 마지막에 연결
	{
		while (temp->next != NULL)									//연결리스트의 끝으로 이동
			temp = temp->next;

		New->next = temp->next;
		temp->next = New;
		printf("학생을 입력하시오 : ");
		scanf_s("%s", &New->name, sizeof(New->name));				//학생의 이름 입력
		fflush(stdin);
		scoreInsert(head, New);										//점수 입력 함수 호출(머리와 추가할 노드 넘겨 줌)
	}
}

void resetRanking(student *head)									//학생 석차를 전부 1로 초기화
{
	student	*temp = head->next;
	while (temp != NULL)
	{
		temp->ranking = 1;
		temp = temp->next;
	}
}
void Ranking(student *head)											//학생 석차 산출 함수
{
	student	*temp = head->next;
	student	*next = NULL;
	student *TopStudent = temp;
	int TopPoint = 1;

	resetRanking(head);												//학생 석차를 전부 1로 초기화

	if (temp != NULL && temp->next == NULL)							//학생이 1명일 경우
		temp->ranking = 1;

	for (temp = head->next; temp != NULL; temp = temp->next)		//학생 한명한명 비교
	{
		for (next = head->next; next != NULL; next = next->next)
		{
			if (next->total < temp->total)							//a학생의 총점보다 b학생의 총점이 높을경우 석차를 1 증가
				next->ranking++;
		}
	}
}

void scoreInsert(student *head, student *New)						//학생 성적 입력 함수
{
	while (1)
	{
		printf("%s학생의 국어 성적을 입력하시오(0~100점) : ", New->name);
		scanf_s("%d", &New->KOR, sizeof(New->KOR));					//국어 성적 입력
	
		if (New->KOR >= 0 && New->KOR <= 100) break;				//0점 이상 100점 이하 인경우 반복 종료
		else														//아닐경우 반복문 처음으로 돌아가서 다시 입력
		{
			printf("점수를 다시 입력하세요!\n");
			fflush(stdin);											//입력 버퍼 초기화
		}
	}

	while (1)
	{
		printf("%s학생의 수학 성적을 입력하시오(0~100점) : ", New->name);
		scanf_s("%d", &New->MATH, sizeof(New->MATH));				//수학 성적 입력
	
		if (New->MATH >= 0 && New->MATH <= 100) break;
		else
		{
			printf("점수를 다시 입력하세요!\n");
			fflush(stdin);
		}
	}
	calculation(head);												//총점, 평균, 석차 산출
}

void calculation(student *head)
{
	student *temp = head->next;

	while (temp != NULL)											//연결리스트 끝까지 반복
	{
		temp->total = (temp->KOR + temp->MATH);						//총점 산출
		temp->average = temp->total / 2;							//평균 산출
		Ranking(head);												//석차 산출
		temp = temp->next;
	}
}