#ifndef SCORE_H
#define SCORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[8];			//�̸�
	int KOR;				//����
	int MATH;				//����

	int total;				//����
	double average;			//���
	int ranking;			//����

	student *next;			//�ڱ� ���� ���Ḯ��Ʈ
}student;

#endif