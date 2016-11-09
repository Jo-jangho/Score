#include "PrintAvg.h"
#include "print.h"

void printAvg(student *head)		//학생 평균 조회 메뉴
{
	int num = 0;
	
	do{
		puts("\n================================================================================");
		puts("1. 평균 전체 조회");
		puts("2. X점 이상 조회");
		puts("3. X점 이하 조회");
		puts("4. 학생 선택 조회");
		puts("메뉴를 선택하세요(이전 : -1) : ");

		scanf_s("%d", &num, sizeof(num));

		if (num == 0)
			puts("다시 입력하시오.");

		switch (num)
		{
		case -1:								//이전 메뉴(함수 종료)
			break;
		case 1:									//1.평균 전체 조회
			fflush(stdin);						//입력함수 버퍼 초기화
			allPrintAvg(head);
			break;
		case 2:									//2.X점 이상 조회
			fflush(stdin);
			overAVG(head);
			break;
		case 3:									//3.X점 이하 조회
			fflush(stdin);
			underAVG(head);
			break;
		case 4:									//4.학생 선택 조회
			fflush(stdin);
			nameAVG(head);
			break;
		default:
			fflush(stdin);						//반복문 조건 체크(메뉴 이외의 다른 값이 들어 왔는지 확인)
			continue;
		}
	}while (num != -1);
}

void nameAVG(student *head)			//학생 선택 조회 함수
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);					//학생 이름 전체 출력

	printf("조회 할 학생의 이름을 입력하시오 :");
	scanf_s("%s", &name, sizeof(name));		//조회 할 학생 이름 입력

	printf("이름 : ");

	for (temp = head->next; temp != NULL; temp = temp->next)	//연결리스트 끝까지 탐색
	{
		if (strcmp(temp->name, name) == 0)								//연결리스트의 이름과 입력받은 이름 비교
		{
			printName(temp);														//학생 이름 출력
			puts("\n================================================================================");
			printf("평균 : ");
			printAVG(temp);														//학생 평균 출력
			break;
		}
	}

	fflush(stdin);
}

void allPrintAvg(student *head)												//학생 평균 전체 출력
{
	student *temp = head->next;
	printf("이름 : ");

	allPrintNAME(head);														//학생 이름 전체 출력

	temp = head->next;
	printf("평균 : ");
	while (temp != NULL)														//학생 평균 전체 출력
	{
		printAVG(temp);
		temp = temp->next;
	}
	puts("");
}

void overAVG(student *head)												//X점 이상 평균 출력
{
	int num;
	student *temp = head->next;

	printf("\n 몇점 이상을 조회 하시겠습니까? : ");
	scanf_s("%d", &num, sizeof(num));


	printf("이름 : ");
	while (temp != NULL)														//평균이 X점 이상인 학생 이름 출력
	{
		if (temp->average >= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("평균 : ");
	while (temp != NULL)														//평균이 X점 이상인 학생 평균 출력
	{
		if (temp->average >= num)
		{
			printAVG(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}

void underAVG(student *head)												//X점 이하 평균 출력
{
	int num;
	student *temp = head->next;

	printf("\n 몇점 이하을 조회 하시겠습니까? : ");
	scanf_s("%d", &num, sizeof(num));


	printf("이름 : ");
	while (temp != NULL)														//평균이 X점 이하인 학생 평균 출력
	{
		if (temp->average <= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("평균 : ");
	while (temp != NULL)														//평균이 X점 이하인 학생 평균 출력
	{
		if (temp->average <= num)
		{
			printAVG(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}
