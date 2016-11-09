#ifndef PRINT_H
#define PRINT_h

#include "Score.h"

void printName(student *temp);				//학생 이름 출력
void printKOR(student *temp);				//국어 성적 출력
void printMATH(student *temp);			//수학 성적 출력
void printTOTAL(student *temp);			//학생 총점 출력
void printAVG(student *temp);				//학생 평균 출력
void printRANKING(student *temp);		//학생 석차 출력
void allPrintNAME(student *head);		//전체 학생 이름 출력

#endif