#ifndef PRINTTOTAL_H
#define PRINTTOTAL_H

#include "Score.h"

void printTotal(student *head);			//총점 조회 메뉴
void nameTotal(student *head);		//X점 이상 총점 조회
void allPrintTotal(student *head);		//X점 이하 총점 조회
void overTOTAL(student *head);		//전체 학생 총점 조회
void underTOTAL(student *head);		//학생 선택 조회

#endif