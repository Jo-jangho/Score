#ifndef INSERT_H
#define INSERT_H

#include "Score.h"

void newStudent(student *head);								//학생 이름 추가
void scoreInsert(student *head, student *New);			//국어, 수학 성적 입력
void resetRanking(student *head);							//석차 초기화
void Ranking(student *head);									//석차 구하기
void calculation(student *head);								//총점, 평균, 석차 구하기

#endif