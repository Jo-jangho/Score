#ifndef INSERT_H
#define INSERT_H

#include "Score.h"

void newStudent(student *head);								//�л� �̸� �߰�
void scoreInsert(student *head, student *New);			//����, ���� ���� �Է�
void resetRanking(student *head);							//���� �ʱ�ȭ
void Ranking(student *head);									//���� ���ϱ�
void calculation(student *head);								//����, ���, ���� ���ϱ�

#endif