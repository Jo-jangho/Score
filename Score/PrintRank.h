#ifndef PRINTRANK_H
#define PRINTRANK_H

#include "Score.h"

void printRank(student *head);			//석차 조회 메뉴
void overRANK(student *head);			//X등 이상 석차 조회
void underRANK(student *head);		//X등 이하 석차 조회
void allPrintRank(student *head);		//전체 학생 석차 조회
void nameRANK(student *head);		//학생 선택 조회

#endif