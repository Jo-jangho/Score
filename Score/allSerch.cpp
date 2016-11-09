#include "allSerch.h"
#include "print.h"
#include "PrintKor.h"
#include "PrintMath.h"
#include "PrintTotal.h"
#include "PrintAvg.h"
#include "PrintRank.h"

void printData(student *head)									//학생 성적 조회 메뉴
{
	int num = 0;														
	
	do{																	
		puts("\n================================================================================");
		puts("1. 학생 전체 조회");
		puts("2. 국어 성적 조회");
		puts("3. 수학 성적 조회");
		puts("4. 학생 총점 조회");
		puts("5. 학생 평균 조회");
		puts("6. 학생 석차 조회");
		puts("메뉴를 선택하세요(이전 : -1) : ");

		scanf_s("%d", &num, sizeof(num));					

		if (num == 0)												
			puts("다시 입력하세요.");

		switch (num)
		{
		case -1:														//이전 메뉴(함수 종료)
			break;
		case 1:															//1.학생 전체 조회
			fflush(stdin);												//입력함수 버퍼 초기화
			allPrint(head);
			break;
		case 2:															//2.국어 성적 조회
			fflush(stdin);
			printKor(head);
			break;
		case 3:															//3.수학 성적 조회
			fflush(stdin);
			printMath(head);
			break;
		case 4:															//4.학생 총점 조회
			fflush(stdin);
			printTotal(head);
			break;
		case 5:															//5.학생 평균 조회
			fflush(stdin);
			printAvg(head);
			break;
		case 6:															//6.학생 석차 조회
			fflush(stdin);
			printRank(head);
			break;
		default:															//반복문 조건 체크(메뉴 이외의 다른 값이 들어 왔는지 확인)
			fflush(stdin);
			continue;
		}
	}while (num != -1);
}

void allPrint(student *head)										//학생의 모든 정보를 출력
{
	student *temp = head->next;									//연결리스트를 순차적으로 탐색하는 변수
	printf("이름 : ");
	while (temp != NULL)											//연결리스트의 마지막까지 반복
	{
		printName(temp);												//학생 이름 출력
		temp = temp->next;											//연결리스트의 다음 노드로 이동
	}
	puts("\n================================================================================");

	temp = head->next;
	printf("국어 : ");
	while (temp != NULL)
	{
		printKOR(temp);												//학생 국어 성적 출력
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("수학 : ");
	while (temp != NULL)
	{
		printMATH(temp);											//학생 수학 성적 출력
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("총점 : ");
	while (temp != NULL)
	{
		printTOTAL(temp);											//학생 총점 출력
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("평균 : ");
	while (temp != NULL)
	{
		printAVG(temp);												//학생 평균 출력
		temp = temp->next;
	}
	puts("");

	temp = head->next;
	printf("석차 : ");
	while (temp != NULL)
	{
		printRANKING(temp);										//학생 석차 출력
		temp = temp->next;
	}
	puts("");
}


