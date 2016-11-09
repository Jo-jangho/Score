#ifndef PRINTKOR_H
#define PRINTKOR_H

#include "Score.h"

void printKor(student *head);			//국어 성적 조회 메뉴
void overKOR(student *head);			//X점 이상 국어 성적 조회
void underKOR(student *head);		//X점 이하 국어 성적 조회
void allPrintKor(student *head);		//전체 학생 국어 성적 조회
void nameKOR(student *head);			//학생 선택 조회

#endif