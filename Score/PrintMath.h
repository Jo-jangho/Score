#ifndef PRINTMATH_H
#define PRINTMATH_H

#include "Score.h"

void printMath(student *head);			//수학 성적 조회 메뉴
void overMATH(student *head);		//X점 이상 수학 성적 조회
void underMATH(student *head);		//X점 이하 수학 성적 조회
void allPrintMath(student *head);		//전체 학생 수학 성적 조회
void nameMATH(student *head);		//학생 선택 조회

#endif