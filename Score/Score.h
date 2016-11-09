#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[8];			//이름
	int KOR;				//국어
	int MATH;				//수학

	int total;				//총점
	double average;			//평균
	int ranking;			//석차

	student *next;			//자기 참조 연결리스트
}student;

#endif