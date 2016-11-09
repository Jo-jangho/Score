#include "load.h"

void load(student *head)							//학생 데이터 불러오기
{
	FILE * f_Student;									//FILE형식의 f_Student변수 선언
	fopen_s(&f_Student, "Score.txt", "r+");	//파일을 읽기용으로 열기

	if (f_Student == NULL)							//제대로 열렸는지 체크
	{
		puts("파일 에러");
		return;
	}

	student *temp = head;
	char c;
	float a;

	puts("학생 성적 불러오기");


	while ((c = fgetc(f_Student)) != EOF)		//파일의 끝까지 반복
	{
		if (c == '/')										// '/' 문자를 읽으면 실행
		{
			student *New = (student *)malloc(sizeof(student));							//연결리스트를 새로 삽입하기 위한 동적 할당
			fscanf_s(f_Student, "%s", New->name, sizeof(New->name));			//이름 불러오기
			fscanf_s(f_Student, "%d", &New->KOR, sizeof(New->KOR));			//국어 성적 불러오기
			fscanf_s(f_Student, "%d", &New->MATH, sizeof(New->MATH));		//수학 성적 불러오기
			fscanf_s(f_Student, "%d", &New->total, sizeof(New->total));			//총점 불러오기
			fscanf_s(f_Student, "%f", &a, sizeof(a));										//평균을 변수 a에 저장
			New->average = a;																		//평균 값 대입
			fscanf_s(f_Student, "%d", &New->ranking, sizeof(New->ranking));	//석차 불러오기
			New->next = NULL;																		//연결리스트의 끝 지정
			temp->next = New;																		//머리와 연결
			temp = temp->next;																		//노드 이동
		}
	}
	if (fclose(f_Student) == EOF)																	//제대로 닫혔는지 체크
		puts("파일 닫기 에러");
}