#include "save.h"

void save(student *head)
{
	FILE * f_Student;										//FILE형 f_Student변수 선언
	fopen_s(&f_Student, "Score.txt", "w+");		//파일 쓰기용으로 열기

	if (f_Student == NULL)								//제대로 열렸는지 체크
	{
		puts("파일 에러");
		return;
	}

	student *temp = head->next;

	puts("학생 성적 저장");
	while (temp != NULL)								//연결리스트의 끝까지 반복
	{
		fprintf_s(f_Student, "/ \n %s \n %d \n %d \n %d \n %.2f \n %d \n", temp->name, temp->KOR, temp->MATH, temp->total, temp->average, temp->ranking);	//파일에 학생 데이터 저장 순서대로(/ 이름 국어성적 수학성적 총점 평균 석차)
		fflush(stdin);										//입력 버퍼 초기화
		temp = temp->next;
	}

	if (fclose(f_Student) == EOF)						//제대로 닫혔는지 체크
		puts("파일 닫기 에러");
}