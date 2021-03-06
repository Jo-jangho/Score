#include "PrintMath.h"
#include "print.h"

void printMath(student *head)	//학생 수학 성적 조회 메뉴
{
	int num = 0;
	
	do{
		puts("\n================================================================================");
		puts("1. 수학 성적 전체 조회");
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
		case 1:									//1.수학 전체 조회
			fflush(stdin);						//입력함수 버퍼 초기화
			allPrintMath(head);
			break;
		case 2:									//2.X점 이상 조회
			fflush(stdin);
			overMATH(head);
			break;
		case 3:									//3.X점 이하 조회
			fflush(stdin);
			underMATH(head);
			break;
		case 4:									//4.학생 선택 조회
			fflush(stdin);
			nameMATH(head);
			break;
		default:									//반복문 조건 체크(메뉴 이외의 다른 값이 들어 왔는지 확인)
			fflush(stdin);
			continue;
		}
	}while (num != -1);
}

void nameMATH(student *head)			//학생 선택 조회 함수
{
	char name[8];
	student *temp = head->next;

	allPrintNAME(head);

	printf("조회 할 학생의 이름을 입력하시오 :");
	scanf_s("%s", &name, sizeof(name));

	printf("이름 : ");

	for (temp = head->next; temp != NULL; temp = temp->next)
	{
		if (strcmp(temp->name, name) == 0)
		{
			printName(temp);
			puts("\n================================================================================");
			printf("수학 : ");
			printMATH(temp);
			break;
		}
	}

	fflush(stdin);
}

void allPrintMath(student *head)				//학생 수학 성적 전체 출력
{
	student *temp = head->next;

	allPrintNAME(head);

	temp = head->next;
	printf("수학 : ");
	while (temp != NULL)
	{
		printMATH(temp);
		temp = temp->next;
	}
	puts("");
}

void overMATH(student *head)				//X점 이상 수학 성적 출력
{
	int num;
	student *temp = head->next;

	printf("\n 몇점 이상을 조회 하시겠습니까? : ");
	scanf_s("%d", &num, sizeof(num));

	printf("이름 : ");
	while (temp != NULL)
	{
		if (temp->MATH >= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("수학 : ");
	while (temp != NULL)
	{
		if (temp->MATH >= num)
		{
			printMATH(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}

void underMATH(student *head)					//X점 이상 수학 성적 출력
{
	int num;
	student *temp = head->next;

	printf("\n 몇점 이하을 조회 하시겠습니까? : ");
	scanf_s("%d", &num, sizeof(num));

	printf("이름 : ");
	while (temp != NULL)
	{
		if (temp->MATH <= num)
		{
			printName(temp);
		}
		temp = temp->next;
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("수학 : ");
	while (temp != NULL)
	{
		if (temp->MATH <= num)
		{
			printMATH(temp);
		}
		temp = temp->next;
	}

	fflush(stdin);
}