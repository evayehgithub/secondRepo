// MergeSort.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"

/* �{���d��: Ch9-3-1.c */
#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN      20           /* �̤j�}�C�ؤo */
/* ���: �X�ְ}�C */
void merge(int *data, int start, int mid, int end) {
	int left = start;              /* ���b�������� */
	int right = mid + 1;           /* �k�b�������� */
	int i, k, *finalData;
	/* �t�m�X�ְϬq�һݪ��O����Ŷ� */
	finalData = (int*)malloc(sizeof(int)*(end - start + 1));
	/* �X�֥��k��b�����Ϭq���j�� */
	for (i = 0; i < (end - start + 1); i++) {
		if (left > mid) {
			finalData[i] = data[right];
			right++;
		}
		else if (right > end) {
			finalData[i] = data[left];
			left++;
		}
		else if (data[left] < data[right]) {
			finalData[i] = data[left];
			left++;
		}
		else {
			finalData[i] = data[right];
			right++;
		}
	}
	/* �ƻs���l�}�C���Ϭq */
	for (i = 0; i < (end - start + 1); i++) {
		data[start + i] = finalData[i];
	} /* ��ܦX�᪺֫�}�C���e */
	printf("%d-%d-%d: ", start, mid, end);
	for (k = 0; k < (end - start + 1); k++)
		printf("[%d]", finalData[k]);
	printf("\n");
}
/* ���: �X�ֱƧǪk */
void mergeSort(int *data, int start, int end) {
	int mid;
	if (end <= start) return;    /* �פ���� */
	mid = (start + end) / 2;       /* �������� */
	mergeSort(data, start, mid);   /* ���j�Ƨǥ��b�� */
	mergeSort(data, mid + 1, end);   /* ���j�Ƨǥk�b�� */
	merge(data, start, mid, end);  /* �X�ְ}�C */
}
/* �D�{�� */
int main() {
	int data[MAX_LEN];             /* ��ư}�C */
	int i, key = 1, len = 0;       /* �}�C�ؤo */
	while (key != -1) {
		printf("��J���ƧǪ���� ==> ");
		scanf_s("%d", &key);          /* Ū����� */
		if (key > 0) {            /* �u�x�s����� */
			data[len++] = key;       /* ��s�}�C���� */
		}
	}
	mergeSort(data, 0, len - 1);     /* ����X�ֱƧǪk */
									 /* ��ܱƧǫ᪺��Ƴ��C */
	printf("\n��X�Ƨǵ��G: ");
	for (i = 0; i < len; i++)
		printf("[%d]", data[i]);
	printf("\n");
	system("PAUSE");
	return 0;
}
