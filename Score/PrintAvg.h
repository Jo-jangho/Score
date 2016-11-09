#ifndef PRINTAVG_H
#define PRINTAVG_H

#include "Score.h"

void printAvg(student *head);			//평균 조회 메뉴
void overAVG(student *head);			//X점 이상 평균 조회
void underAVG(student *head);		//X점 이하 평균 조회
void allPrintAvg(student *head);		//전체 학생 평균 조회
void nameAVG(student *head);			//학생 선택 조회

#endif