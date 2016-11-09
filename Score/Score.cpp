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
	int num = 0;																	//메뉴 선택을 위한 변수(0으로 초기화)

	student * head = (student *)malloc(sizeof(student));			//연결리스트의 머리 부분 동적 할당(데이터 저장은 안함)

	head->next = NULL;														//연결리스트의 끝부분을 NULL로 초기화

	
	do{																				//성적관리 프로그램의 시작 부분(메뉴 출력 및 함수 호출 대기)
		puts("\n================================================================================");
		puts("1. 학생 추가");
		puts("2. 학생 성적 조회");
		puts("3. 학생 삭제");
		puts("4. 학생 이름 수정");
		puts("5. 학생 정보 저장");
		puts("6. 학생 정보 불러오기");

		printf("메뉴를 선택하세요(종료 -1) : ");
		scanf_s("%d", &num, sizeof(num));								//메뉴 선택

		if (num == 0)																//입력이 제대로 들어왔는지 체크
			puts("다시 입력하세요.");

		switch (num)
		{
		case -1:																	//프로그램 종료
			puts("프로그램이 종료됩니다.");
			break;
		case 1:																		//1.학생 추가
			fflush(stdin);															//입력함수 버퍼 초기화
			newStudent(head);	
			break;
		case 2:																		//2.학생 성적 조회
			fflush(stdin);
			printData(head);
			break;
		case 3:																		//3.학생 삭제
			fflush(stdin);
			studentDel(head);
			break;
		case 4:																		//4. 학생 이름 수정
			fflush(stdin);
			studentUpdate(head);
			break;
		case 5:																		//5. 학생 정보 저장
			fflush(stdin);
			save(head);
			break;
		case 6:																		//6.학생 정보 불러오기
			fflush(stdin);
			load(head);
			break;
		default:																		//반복문 조건 체크(메뉴 이외의 다른 값이 들어 왔는지 확인)
			fflush(stdin);
			continue;
		}
	}while (num != -1);

	return 0;
}