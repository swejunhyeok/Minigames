//��� ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <string.h>

//�������� ����
int money=2000;
int Delay=1000;
int SCORE=0;
int COUNT=0;
int Q=7;
int Q1=7;
int C=0;
int strn=-1; // 3���� �迭 �� ���� �ε��� �ѹ� ������.
int mainflag=1; // ����ȭ�� ǥ�� ���� ����
int r[4]={0,1,2,3};
int bing_u[25];
int memo_num[50]={0};
int memo_cnt=0;
int bing_c[25];
int bingcnt_u=0;
int bingcnt_c=0;
int bingo_user[2][5][5]={0};
int bingo_com[2][5][5]={0};
int bing_pan[11][11]=
{{5,2,6,2,6,2,6,2,6,2,7}
,{3,0,3,0,3,0,3,0,3,0,3}
,{8,2,4,2,4,2,4,2,4,2,9}
,{3,0,3,0,3,0,3,0,3,0,3}
,{8,2,4,2,4,2,4,2,4,2,9}
,{3,0,3,0,3,0,3,0,3,0,3}
,{8,2,4,2,4,2,4,2,4,2,9}
,{3,0,3,0,3,0,3,0,3,0,3}
,{8,2,4,2,4,2,4,2,4,2,9}
,{3,0,3,0,3,0,3,0,3,0,3}
,{11,2,1,2,1,2,1,2,1,2,10}};
int five_pan[25][25]=
{{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
,{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
int pan[25][25]=
{{2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7}
,{8,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,10}};
int word1[15][15]=
{{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,1,0,0,0,0,0,0,0,0,0,0,0,1,1}
,{1,0,1,0,0,0,0,0,0,0,0,0,1,0,1}
,{1,0,0,1,0,0,0,0,0,0,0,1,0,0,1}
,{1,0,0,0,1,0,0,0,0,0,1,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};
int word2[15][2]=
{{1,1}
,{1,1}
,{0,0}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}
,{1,1}};
int word3[9][7]=
{{0,1,1,1,1,1,0}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}};
int word4[18][11]=
{{0,0,0,1,1,1,1,1,0,0,0}
,{0,0,1,0,0,0,0,0,1,0,0}
,{0,1,0,0,0,0,0,0,0,1,0}
,{1,0,0,0,0,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0}
,{1,0,0,0,0,0,0,0,0,0,0}
,{1,0,0,0,0,0,0,0,0,0,0}
,{1,0,0,0,0,0,0,0,0,0,0}
,{1,0,0,0,0,0,0,0,0,0,0}
,{1,0,0,0,1,1,1,1,1,1,1}
,{1,0,0,0,0,0,0,1,0,0,0}
,{1,0,0,0,0,0,0,1,0,0,0}
,{0,1,0,0,0,0,0,1,0,0,0}
,{0,0,1,0,0,0,0,1,0,0,0}
,{0,0,0,1,1,1,1,1,0,0,0}
,{0,0,0,0,0,0,0,1,0,0,0}
,{0,0,0,0,0,0,0,1,0,0,0}
,{0,0,0,0,0,0,0,1,0,0,0}};
int word5[9][7]=
{{0,1,1,1,0,0,0}
,{1,0,0,0,1,0,0}
,{0,0,0,0,0,1,0}
,{0,0,1,1,0,1,0}
,{0,1,0,0,1,1,0}
,{1,0,0,0,0,1,0}
,{1,0,0,0,0,1,0}
,{1,0,0,0,0,1,0}
,{0,1,1,1,1,0,1}};
int word6[8][11]=
{{0,1,1,1,1,0,1,1,1,1,0}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}
,{1,0,0,0,0,1,0,0,0,0,1}};
int word7[9][7]=
{{0,0,1,1,1,0,0}
,{0,1,0,0,0,1,0}
,{1,0,0,0,0,0,1}
,{1,0,0,0,0,0,1}
,{1,1,1,1,1,1,1}
,{1,0,0,0,0,0,0}
,{1,0,0,0,0,0,0}
,{0,1,0,0,0,0,0}
,{0,0,1,1,1,1,0}};

int board[21][24]=
{{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int block[6][4][4][4]=
{
	{
		{{0,1,1,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,1,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,1,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,1,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
	},
	{				
		{{0,0,0,0}
		,{1,1,1,1}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,0,0}
		,{0,1,0,0}
		,{0,1,0,0}
		,{0,1,0,0}}
		,
		{{1,1,1,1}
		,{0,0,0,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,0,1,0}
		,{0,0,1,0}
		,{0,0,1,0}
		,{0,0,1,0}}
	},
	{
		{{0,0,1,0}
		,{1,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{1,1,0,0}
		,{0,1,0,0}
		,{0,1,0,0}
		,{0,0,0,0}}
		,
		{{0,0,0,0}
		,{1,1,1,0}
		,{1,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,0,0}
		,{0,1,0,0}
		,{0,1,1,0}
		,{0,0,0,0}}
	},
	{
		{{0,1,1,0}
		,{1,1,0,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{1,0,0,0}
		,{1,1,0,0}
		,{0,1,0,0}
		,{0,0,0,0}}
		,
		{{0,0,0,0}
		,{0,1,1,0}
		,{1,1,0,0}
		,{0,0,0,0}}
		,
		{{0,1,0,0}
		,{0,1,1,0}
		,{0,0,1,0}
		,{0,0,0,0}}
	},
	{
		{{1,1,0,0}
		,{0,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,0,1,0}
		,{0,1,1,0}
		,{0,1,0,0}
		,{0,0,0,0}}
		,
		{{0,0,0,0}
		,{1,1,0,0}
		,{0,1,1,0}
		,{0,0,0,0}}
		,
		{{0,0,1,0}
		,{0,1,1,0}
		,{0,1,0,0}
		,{0,0,0,0}}
	},
	{
		{{0,1,0,0}
		,{1,1,1,0}
		,{0,0,0,0}
		,{0,0,0,0}}
		,
		{{0,1,0,0}
		,{1,1,0,0}
		,{0,1,0,0}
		,{0,0,0,0}}
		,
		{{0,0,0,0}
		,{1,1,1,0}
		,{0,1,0,0}
		,{0,0,0,0}}
		,
		{{0,1,0,0}
		,{0,1,1,0}
		,{0,1,0,0}
		,{0,0,0,0}}
	}
};
int map1_1[26][21]=
{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
,{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1}
,{1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1}
,{1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1}
,{1,1,1,1,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1}
,{0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1}
,{1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1}
,{1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1}
,{1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1}
,{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1}
,{1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1}
,{1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1}
,{1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1}
,{1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1}
,{1,0,0,0,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1}
,{1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0}
,{1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1}
,{1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,0,0,1,0,1}
,{1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,1}
,{1,0,1,1,1,1,0,0,1,1,1,0,1,0,1,1,1,1,1,1,1}
,{1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1}
,{1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1}
,{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}
,{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}
,{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int map1_2[25][21]=
{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
,{0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0}
,{1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,0,1}
,{1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1}
,{1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,1}
,{1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1}
,{1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1}
,{1,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1}
,{1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,1}
,{1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1}
,{1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1}
,{1,0,1,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1}
,{1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,1,0,0,1}
,{1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,1,1}
,{1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1}
,{1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1}
,{1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1}
,{1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,1}
,{1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1}
,{1,0,0,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1}
,{1,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,0,1,1}
,{1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,1}
,{1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,1,0,1,0,1,1}
,{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1}
,{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
int map2_1[34][27]=
{{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
,{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}
,{1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1}
,{1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1,0,1}
,{1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1}
,{1,1,1,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1}
,{1,0,0,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1}
,{1,0,1,1,1,1,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1}
,{1,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1}
,{1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1}
,{1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1}
,{1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1}
,{0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1}
,{1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1}
,{1,0,0,0,1,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1}
,{1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1}
,{1,0,1,1,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1}
,{1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1}
,{1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,0}
,{1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1}
,{1,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,0,0,0,1}
,{1,0,1,1,1,1,1,1,1,0,0,0,1,1,1,0,1,0,1,0,0,0,1,1,1,0,1}
,{1,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,1,0,1,0,1,0,1,0,0,0,1}
,{1,1,1,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,1,1,1}
,{1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1}
,{1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1}
,{1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1}
,{1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1}
,{1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1}
,{1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
,{1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1}
,{1,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1}
,{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1}
,{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
//��ȣ�������

//����Ű �ƽ�Ű�ڵ�
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define N 20
#define M 10

#define board_X 12
#define board_Y 6

//�Լ�
void gotoxy(int x, int y);
void consol_size();
void removeCusor();


void background();
void edge(int x,int y);


void game_start();
void game_main();
void mathbaseball();
void escape();
void tetris();
	void call_board(int x, int y);
	void make_block(int r[]);
	void next_block(int n[]);
	void remove_block(int n[]);
	void move_block(int x, int y,int n1,int r[]);
	void new_board(int x, int y, int n1,int n2);
	void remove_board(int x,int y, int n1, int n2,int a[]); 
	int check(int n1,int n2,int b1, int b2);
	void game_end();
void game_pan();
	void call_pan(int x,int y);
	void check_pan(int n);
	void kb_five(int x, int y,int n1);
void taja();
	void add(int num);
void bingo();
	void bing_tl(int x,int y);
	void user_num(int x,int y);
	void com_num(int x,int y);
	void check_bingo(int x,int y);
	void bing_block_user(int x,int y,int u);
	void rand_block_com(int x,int y);
	void bing_end(int x,int y,int OK);
	void call_bingopan(int x,int y);
void packman();
	void monster( int m[][20], int rx, int ry, int ran);
	int monsterX( int m[][20], int rx, int ry, int ran);
	int monsterY( int m[][20], int rx, int ry, int ran);
void bombgame();
	void mab_print( int mab[][M], int x, int y);
void randgame();
void if1();
	void kbb();
		void add3(int a,int b);
		void kbbresult(int a,int b);
	void hol();
		void add4(int a,int b);
		void holresult(int a,int b);
	void rul();
		void if2();
		void if3(int a,int b,int c);
		void rulresult();

void randgame();
void maingame_end();
void maingame_end1();

void main()
{
	removeCusor();
	consol_size();
	game_start();
	game_main();
}

//��ǥ�����Լ�
void gotoxy(int x, int y)  
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//�ܼ�â ������ �����Լ�
void consol_size()
{
	system("mode con:cols=120 lines=60");
}

//Ŀ�� ������ ���ֱ�.
void removeCusor()
{
	CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    curInfo.bVisible=0;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}



//�⺻���� ���� ���Ʋ
void background()
{
	int i;
	gotoxy(0,0);
	printf("��");
	gotoxy(118,0);
	printf("��");
	for(i=1;i<59;i++)
	{
		gotoxy(2*i,0);
		printf("��");
	}
	for(i=1;i<58;i++)
	{
		gotoxy(0,i);
		printf("��");
	}
	gotoxy(0,58);
	printf("��");
	for(i=1;i<59;i++)
	{
		gotoxy(2*i,58);
		printf("��");
	}
	for(i=1;i<58;i++)
	{
		gotoxy(118,i);
		printf("��");
	}
	gotoxy(118,58);
	printf("��");
	for(i=1;i<5;i++)
	{
		gotoxy(54+2*i,54);
		printf("��");
	}
	gotoxy(102,58);
	printf("��");
	gotoxy(102,57);
	printf("��");
	gotoxy(102,56);
	printf("��");
	gotoxy(104,56);
	printf("��");
	gotoxy(106,56);
	printf("��");
	gotoxy(108,56);
	printf("��");
	gotoxy(110,56);
	printf("��");
	gotoxy(112,56);
	printf("��");
	gotoxy(114,56);
	printf("��");
	gotoxy(116,56);
	printf("��");
	gotoxy(118,56);
	printf("��");
	gotoxy(54,54);
	printf("��");
	gotoxy(64,54);
	printf("��");
	gotoxy(54,55);
	printf("��");
	gotoxy(64,55);
	printf("��");
	gotoxy(54,56);
	printf("��");
	gotoxy(54,57);
	printf("��");
	gotoxy(64,56);
	printf("��");
	gotoxy(64,57);
	printf("��");
	gotoxy(54,58);
	printf("��");
	gotoxy(64,58);
	printf("��");
	gotoxy(58,56);
	printf("\\%d",money);
	gotoxy(104,57);
	printf("��������(q)");
}
void edge(int x,int y)
{
	int i;
	gotoxy(x,y);
	printf("��");
	gotoxy(x,y+8);
	printf("��");
	gotoxy(x+16,y);
	printf("��");
	gotoxy(x+16,y+8);
	printf("��");
	for(i=1;i<8;i++)
	{
		gotoxy(x+2*i,y);
		printf("��");
		gotoxy(x+2*i,y+8);
		printf("��");
	}
	for(i=1;i<8;i++)
	{
		gotoxy(x,y+i);
		printf("��");
		gotoxy(x+16,y+i);
		printf("��");
	}
	gotoxy(x+4,y+8);
	printf("��");
	gotoxy(x+12,y+8);
	printf("��");
	gotoxy(x+4,y+9);
	printf("��");
	gotoxy(x+12,y+9);
	printf("��");
	gotoxy(x+4,y+10);
	printf("��");
	gotoxy(x+12,y+10);
	printf("��");
	for(i=1;i<4;i++)
	{
		gotoxy(x+4+2*i,y+10);
		printf("��");
	}
	gotoxy(x+6,y+10);
	printf("��");
	gotoxy(x+10,y+10);
	printf("��");
	gotoxy(x+6,y+11);
	printf("��");
	gotoxy(x+10,y+11);
	printf("��");
	gotoxy(x+6,y+12);
	printf("��");
	gotoxy(x+10,y+12);
	printf("��");
	gotoxy(x+8,y+12);
	printf("��");
	
}




//���ӽ��۽� ȭ��
void game_start()
{
	int i,j,x,y,a;
	background();
	for(i=0;i<15;i++)
	{
		x=12;
		y=5;
		for(;;)
		{
			a=y;
			y++;
			if(y-5>15-i)
				break;
			for(j=0;j<15;j++)
				if(word1[14-i][j]==1)
				{
					gotoxy(x+(2*j),a);
					printf(" ");
					gotoxy(x+(2*j),y);
					printf("��");
				}
			for(j=0;j<2;j++)
				if(word2[14-i][j]==1)
				{
					gotoxy(x+36+(2*j),a);
					printf(" ");
					gotoxy(x+36+(2*j),y);
					printf("��");
				}
			for(j=0;j<7;j++)
				if(i>8)
					break;
				else if(word3[8-i][j]==1)
				{
					gotoxy(x+46+(2*j),a);
					printf(" ");
					gotoxy(x+46+(2*j),y);
					printf("��");
				}
			for(j=0;j<2;j++)
				if(word2[14-i][j]==1)
				{
					gotoxy(x+66+(2*j),a);
					printf(" ");
					gotoxy(x+66+(2*j),y);
					printf("��");
				}
			Sleep(20);
		}
	}
	for(i=0;i<18;i++)
	{
		x=22;
		y=25;
		for(;;)
		{
			a=y;
			y++;
			if(y-25>18-i)
				break;
			for(j=0;j<11;j++)
				if(word4[17-i][j]==1)
				{
					gotoxy(x+(2*j),a);
					printf(" ");
					gotoxy(x+(2*j),y);
					printf("��");
				}
			for(j=0;j<7;j++)
				if(i>8)
					break;
				else if(word5[8-i][j]==1)
				{
					gotoxy(x+28+(2*j),a);
					printf(" ");
					gotoxy(x+28+(2*j),y);
					printf("��");
				}
			for(j=0;j<11;j++)
				if(i>7)
					break;
				else if(word6[7-i][j]==1)
				{
					gotoxy(x+48+(2*j),a);
					printf(" ");
					gotoxy(x+48+(2*j),y);
					printf("��");
				}
			for(j=0;j<7;j++)
				if(i>8)
					break;
				else if(word7[8-i][j]==1)
				{
					gotoxy(x+76+(2*j),a);
					printf(" ");
					gotoxy(x+76+(2*j),y);
					printf("��");
				}
			Sleep(10);
		}
	}
	while(1)
	{
		gotoxy(50,48);
		printf("                         ");
		if(_kbhit())
			break;
		Sleep(200);
		gotoxy(50,48);
		printf("�ƹ� Ű �� �����ʽÿ�.");
		if(_kbhit())
			break;
		Sleep(200);
	}
}
//���� ����ȭ��
void game_main()
{
	int user;
	system("cls");
	background();

	edge(6,3);
	gotoxy(10,5);
	printf("��");
	gotoxy(18,5);
	printf("��");
	gotoxy(10,9);
	printf("��");
	gotoxy(18,9);
	printf("��");
	gotoxy(12,12);
	printf(" \\200");
	gotoxy(14,14);
	printf("��");
	edge(50,3);
	gotoxy(54,5);
	printf("��");
	gotoxy(62,5);
	printf("��");
	gotoxy(54,9);
	printf("Ż");
	gotoxy(62,9);
	printf("��");
	gotoxy(56,12);
	printf(" \\300");
	gotoxy(58,14);
	printf("��");
	edge(94,3);
	gotoxy(98,5);
	printf("��");
	gotoxy(106,5);
	printf("Ʈ");
	gotoxy(98,9);
	printf("��");
	gotoxy(106,9);
	printf("��");
	gotoxy(100,12);
	printf(" \\500");
	gotoxy(102,14);
	printf("��");
	edge(6,20);
	gotoxy(10,22);
	printf("��");
	gotoxy(18,22);
	printf("��");
	gotoxy(10,26);
	printf("��");
	gotoxy(18,26);
	printf("��");
	gotoxy(12,29);
	printf(" \\300");
	gotoxy(14,31);
	printf("��");
	edge(50,20);
	gotoxy(54,22);
	printf("Ÿ");
	gotoxy(62,22);
	printf("��");
	gotoxy(54,26);
	printf("��");
	gotoxy(62,26);
	printf("��");
	gotoxy(56,29);
	printf(" \\300");
	gotoxy(58,31);
	printf("��");
	edge(94,20);
	gotoxy(98,22);
	printf("��");
	gotoxy(106,22);
	printf("��");
	gotoxy(98,26);
	printf("��");
	gotoxy(106,26);
	printf("��");
	gotoxy(100,29);
	printf(" \\300");
	gotoxy(102,31);
	printf("��");
	edge(6,37);
	gotoxy(10,39);
	printf("��");
	gotoxy(18,39);
	printf("��");
	gotoxy(10,43);
	printf("��");
	gotoxy(18,43);
	printf("��");
	gotoxy(12,46);
	printf(" \\300");
	gotoxy(14,48);
	printf("��");
	edge(50,37);
	gotoxy(54,39);
	printf("��");
	gotoxy(62,39);
	printf("��");
	gotoxy(54,43);
	printf("��");
	gotoxy(62,43);
	printf("��");
	gotoxy(56,46);
	printf(" \\300");
	gotoxy(58,48);
	printf("��");
	edge(94,37);
	gotoxy(98,39);
	printf("��");
	gotoxy(106,39);
	printf("��");
	gotoxy(98,43);
	printf("��");
	gotoxy(106,43);
	printf("��");
	gotoxy(100,46);
	printf(" \\300");
	gotoxy(102,48);
	printf("��");
	for(;;)
	{
		user=_getch();
		if(user=='1')
		{
			if(money-200<0)
				maingame_end();
			money-=200;
			mathbaseball();
		}
		else if(user=='2')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			escape();
		}
		else if(user=='3')
		{
			if(money-500<0)
				maingame_end();
			money-=500;
			tetris();
		}
		else if(user=='4')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			game_pan();
		}
		else if(user=='5')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			taja();
		}
		else if(user=='6')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			bingo();
		}
		else if(user=='7')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			packman();
		}
		else if(user=='8')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			bombgame();
		}
		else if(user=='9')
		{
			if(money-300<0)
				maingame_end();
			money-=300;
			randgame();
		}
		else if(user=='q')
		{
			maingame_end1();
		}
	}
}

void mathbaseball()
{
	int user,us[4],use,com[4],u[4],c[4],a,b,s1,b1,count,s2,b2,x,y,non;
	x=2;
	y=1;
	system("cls");
	background();
	srand(time(NULL));
	gotoxy(x,y++);
	printf("���ھ߱������� �����մϴ�.\n");
	gotoxy(x,y++);
	printf("õ�� �ڸ������� �ϳ��� �Է����ֽʽÿ�.\n");
	for(;;)
	{
		gotoxy(x,y++);
		printf("���� ����:");
		scanf_s("%d",&user);
		us[3]=user%10;
		us[0]=user/1000;
		a=user%1000;
		us[1]=a/100;
		b=a%100;
		us[2]=b/10;
		if(us[0]==0)
		{
			gotoxy(x,y++);
			printf("ù��° �ڸ��� 0�� �Է��Ҽ� �����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
		}
		else if(user>9999)
		{
			gotoxy(x,y++);
			printf("õ�� �ڸ������� �ϳ��� �Է����ֽʽÿ�.\n");
		}
		else if(us[0]==us[1]||us[0]==us[2]||us[0]==us[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
		}
		else if(us[1]==us[0]||us[1]==us[2]||us[1]==us[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
		}
		else if(us[2]==us[1]||us[2]==us[0]||us[2]==us[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
		}
		else if(us[3]==us[1]||us[3]==us[2]||us[3]==us[0])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
		}
		else
			break;
	}
	com[0]=rand()%9+1;
	do
	{
		com[1]=rand()%10;
	}while(com[1]==com[0]);
	do
	{
		com[2]=rand()%10;
	}while(com[2]==com[0]||com[2]==com[1]);
	do
	{
		com[3]=rand()%10;
	}while(com[3]==com[0]||com[3]==com[1]||com[3]==com[2]);
	

	count=0;
	for(;;)
	{
		s1=b1=0;
		s2=b2=0;
		gotoxy(x,y++);
		printf("����Ǵ� ��ǻ���� ���ڸ� �Է��Ͻʽÿ�:");
		scanf_s("%d",&use);
		u[3]=use%10;
		u[0]=use/1000;
		a=use%1000;
		u[1]=a/100;
		b=a%100;
		u[2]=b/10;
		if(u[0]==0)
		{
			gotoxy(x,y++);
			printf("ù��° �ڸ��� 0�� �Է��Ҽ� �����ϴ�. �ٽ� �Է��Ͻʽÿ�.\n");
			continue;
		}
		else if(use>9999)
		{
			gotoxy(x,y++);
			printf("õ�� �ڸ������� �ϳ��� �Է����ֽʽÿ�.\n");
			continue;
		}
		else if(u[0]==u[1]||u[0]==u[2]||u[0]==u[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
			continue;
		}
		else if(u[1]==u[0]||u[1]==u[2]||u[1]==u[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
			continue;
		}
		else if(u[2]==u[1]||u[2]==u[0]||u[2]==u[3])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
			continue;
		}
		else if(u[3]==u[1]||u[3]==u[2]||u[3]==u[0])
		{
			gotoxy(x,y++);
			printf("������ ���ڸ� �ι� ����Ҽ������ϴ�.\n");
			continue;
		}
		count++;
		if(u[0]==com[0]&&u[1]==com[1]&&u[2]==com[2]&&u[3]==com[3])
		{
			y++;
			gotoxy(x,y++);
			printf("��ǻ���� ���ڸ� ���缭 �¸��Ͽ����ϴ�.");
			gotoxy(x,y++);
			printf("�� �õ��� Ƚ���� %d�Դϴ�.\n",count);
			gotoxy(x,y++);
			printf("300��ȹ��!");
			money+=300;
			gotoxy(x,y++);
			printf("�ƹ�Ű�������ø� ����ȭ������ ���ư��ϴ�.");
			non=_getch();
			game_main();
		}
		if(u[0]==com[0])
			s1++;
		if(u[1]==com[1])
			s1++;
		if(u[2]==com[2])
			s1++;
		if(u[3]==com[3])
			s1++;
		if(u[0]==com[1]||u[0]==com[2]||u[0]==com[3])
			b1++;
		if(u[1]==com[0]||u[1]==com[2]||u[1]==com[3])
			b1++;
		if(u[2]==com[0]||u[2]==com[1]||u[2]==com[3])
			b1++;
		if(u[3]==com[1]||u[3]==com[2]||u[3]==com[0])
			b1++;
		gotoxy(x,y++);
		printf("������� ���: %d�� %d��Ʈ����ũ\n",b1,s1);
		c[0]=rand()%9+1;
		do
		{
			c[1]=rand()%10;
		}while(c[1]==c[0]);
		do
		{
			c[2]=rand()%10;
		}while(c[2]==c[0]||c[2]==c[1]);
		do
		{
			c[3]=rand()%10;
		}while(c[3]==c[0]||c[3]==c[1]||c[3]==c[2]);

		if(c[0]==us[0]&&c[1]==us[1]&&c[2]==us[2]&&c[3]==us[3])
		{
			y++;
			gotoxy(x,y++);
			printf("��ǻ�Ͱ� ����� ���ڸ� ���缭 �й��Ͽ����ϴ�.");
			gotoxy(x,y++);
			printf("�� �õ��� Ƚ���� %d�Դϴ�.\n",count);
			break;
			gotoxy(x,y++);
			printf("�ƹ�Ű�������ø� ����ȭ������ ���ư��ϴ�.");
			non=_getch();
			game_main();
		}
		if(c[0]==us[0])
			s2++;
		if(c[1]==us[1])
			s2++;
		if(c[2]==us[2])
			s2++;
		if(c[3]==us[3])
			s2++;
		if(c[0]==us[1]||c[0]==us[2]||c[0]==us[3])
			b2++;
		if(c[1]==us[0]||c[1]==us[2]||c[1]==us[3])
			b2++;
		if(c[2]==us[0]||c[2]==us[1]||c[2]==us[3])
			b2++;
		if(c[3]==us[1]||c[3]==us[2]||c[3]==us[0])
			b2++;
		gotoxy(x,y++);
		printf("��ǻ���� ���: %d�� %d��Ʈ����ũ\n",b2,s2);
	}
}


void escape()
{
	int i,j,x,y,d1,d2,count;
	char move,non;
	system("cls");
	background();
	gotoxy(12,4);
	printf("�̵�Ƚ�� 60�� �ʰ��� ����.");
	for(i=0;i<26;i++)
		for(j=0;j<21;j++)
			if(map1_1[i][j]==1)
			{
				gotoxy(12+2*j,6+i);
				printf("��");
			}
	gotoxy(12,11);
	printf("��");
	x=12;
	y=11;
	j=0;
	i=5;
	count=0;
	for(;;)
	{
		d1=x;
		d2=y;
		move=_getch();
		if(move=='q')
			game_main();
		if(move==UP)
		{
			i--;
			if(i<0||i>25)
			{
				i++;
				continue;
			}
			else if(map1_1[i][j]==1)
			{
				i++;
				continue;
			}
			y--;
		}
		else if(move==DOWN)
		{
			i++;
			if(i<0||i>25)
			{
				i--;
				continue;
			}
			else if(map1_1[i][j]!=0)
			{
				i--;
				continue;
			}
			y++;
		}
		else if(move==LEFT)
		{
			j--;
			if(j<0||j>20)
			{
				j++;
				continue;
			}
			else if(map1_1[i][j]!=0)
			{
				j++;
				continue;
			}
			x-=2;
		}
		else if(move==RIGHT)
		{
			j++;
				if(j<0||j>20)
			{
				j--;
				continue;
			}
			else if(map1_1[i][j]!=0)
			{
				j--;
				continue;
			}
			x+=2;
		}
		else
			continue;
		gotoxy(d1,d2);
		printf(" ");
		gotoxy(x,y);
		printf("��");
		count++;
		if(i==15&&j==20)
			break;
	}
	if(count<=60)
	{
		gotoxy(80,20);
		printf("1 ��������Ŭ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		gotoxy(80,23);
		printf("\\100�� ȹ��");
		money+=100;
		non=_getch();
	}
	else
	{
		gotoxy(80,20);
		printf("1 �������� ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		non=_getch();
		game_main();
	}

	system("cls");
	background();
	gotoxy(12,4);
	printf("�̵�Ƚ�� 110�� �ʰ��� ����.");
	for(i=0;i<25;i++)
		for(j=0;j<21;j++)
			if(map1_2[i][j]==1)
			{
				gotoxy(12+2*j,6+i);
				printf("��");
			}
	gotoxy(12,7);
	printf("��");
	x=12;
	y=7;
	j=0;
	i=1;
	count=0;
	for(;;)
	{
		d1=x;
		d2=y;
		move=_getch();
		if(move==UP)
		{
			i--;
			if(i<0||i>24)
			{
				i++;
				continue;
			}
			else if(map1_2[i][j]!=0)
			{
				i++;
				continue;
			}
			y--;
		}
		else if(move==DOWN)
		{
			i++;
			if(i<0||i>24)
			{
				i--;
				continue;
			}
			else if(map1_2[i][j]!=0)
			{
				i--;
				continue;
			}
			y++;
		}
		else if(move==LEFT)
		{
			j--;
			if(j<0||j>20)
			{
				j++;
				continue;
			}
			else if(map1_2[i][j]!=0)
			{
				j++;
				continue;
			}
			x-=2;
		}
		else if(move==RIGHT)
		{
			j++;
				if(j<0||j>20)
			{
				j--;
				continue;
			}
			else if(map1_2[i][j]!=0)
			{
				j--;
				continue;
			}
			x+=2;
		}
		else
			continue;
		gotoxy(d1,d2);
		printf(" ");
		gotoxy(x,y);
		printf("��");
		count++;
		if(i==1&&j==20)
			break;
	}

	if(count<=110)
	{
		gotoxy(80,20);
		printf("2 ��������Ŭ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		gotoxy(80,23);
		printf("\\100�� ȹ��");
		money+=100;
		non=_getch();
	}
	else
	{
		gotoxy(80,20);
		printf("2 �������� ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		non=_getch();
		game_main();
	}

	system("cls");
	background();
	gotoxy(12,4);
	printf("�̵�Ƚ�� 90�� �ʰ��� ����.");
	for(i=0;i<34;i++)
		for(j=0;j<27;j++)
			if(map2_1[i][j]==1)
			{
				gotoxy(12+2*j,6+i);
				printf("��");
			}
	gotoxy(12,18);
	printf("��");
	x=12;
	y=18;
	j=0;
	i=12;
	count=0;
	for(;;)
	{
		d1=x;
		d2=y;
		move=_getch();
		if(move==UP)
		{
			i--;
			if(i<0||i>33)
			{
				i++;
				continue;
			}
			else if(map2_1[i][j]!=0)
			{
				i++;
				continue;
			}
			y--;
		}
		else if(move==DOWN)
		{
			i++;
			if(i<0||i>33)
			{
				i--;
				continue;
			}
			else if(map2_1[i][j]!=0)
			{
				i--;
				continue;
			}
			y++;
		}
		else if(move==LEFT)
		{
			j--;
			if(j<0||j>26)
			{
				j++;
				continue;
			}
			else if(map2_1[i][j]!=0)
			{
				j++;
				continue;
			}
			x-=2;
		}
		else if(move==RIGHT)
		{
			j++;
				if(j<0||j>26)
			{
				j--;
				continue;
			}
			else if(map2_1[i][j]!=0)
			{
				j--;
				continue;
			}
			x+=2;
		}
		else
			continue;
		gotoxy(d1,d2);
		printf(" ");
		gotoxy(x,y);
		printf("��");
		count++;
		if(i==18&&j==26)
			break;
	}
	if(count<=90)
	{
		gotoxy(80,20);
		printf("3 ��������Ŭ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		gotoxy(80,23);
		printf("\\100�� ȹ��");
		money+=100;
		non=_getch();
		game_main();
	}
	else
	{
		gotoxy(80,20);
		printf("3 �������� ����");
		gotoxy(80,21);
		printf("Please press any key.");
		gotoxy(80,22);
		printf("�� �̵�Ƚ�� :%d",count);
		non=_getch();
		game_main();
	}
}


void tetris()
{
	int i,j;
	system("cls");
	for(i=0;i<19;i++)
		for(j=0;j<10;j++)
			board[i][j+1]=0;
	SCORE=COUNT=0;
	background();
	call_board(board_X,board_Y);
	make_block(r);
} 
// �Ѱ� : ������ �κ� �̸� ǥ���ϴ� ����߰��߿� ���� �߻����� ����. ��Ʈ���� ������ ������ �ٸ��� ǥ���ϰ������ ���ĺ���. ���� ����� ���Ѱ͵��� �����������Ͽ� �ڵ��� �ټ� �������ϰ� ���ʿ��� �ݺ��� ����.
	void call_board(int x,int y)
	{
		int i,j;
		for(i=0;i<20;i++)
			for(j=0;j<24;j++)
				if(board[i][j]==1)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
		gotoxy(x+24,y+17);
		printf("����:%d",SCORE);
		gotoxy(x+26,y);
		printf("NEXT");
		gotoxy(x+38,y);
		printf("HOLD");
		gotoxy(x+36,y+5);
		printf("HOLD->Z");
		gotoxy(x+36,y+6);
		printf("��ȸ��->A");
		gotoxy(x+36,y+7);
		printf("��ȸ��->D");
		gotoxy(x+36,y+8);
		printf("��������->");
		gotoxy(x+36,y+9);
		printf("�����̽���");
		gotoxy(x+36,y+10);
		printf("�̵�->");
		gotoxy(x+36,y+11);
		printf("����Ű");
		gotoxy(x+36,y+12);
		printf("1000����");
		gotoxy(x+36,y+13);
		printf("100��ȹ��");
		
	}
	void make_block(int r[])
	{
		int i,j,x,y,ox;
		while(1)
		{
			srand(time(NULL));
			x=board_X+8;
			y=board_Y;
			if(COUNT!=0)
			{
				r[3]=rand()%6;
			}
			COUNT++;
			if(r[0]==0)
			{
			
				ox=check(0,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[0][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,0,r);
			}
			if(r[0]==1)
			{
				ox=check(1,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[1][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,1,r);
			}
			if(r[0]==2)
			{
				ox=check(2,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[2][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,2,r);
			}
			if(r[0]==3)
			{
				ox=check(3,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[3][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,3,r);
			}
			if(r[0]==4)
			{
				ox=check(4,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[4][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,4,r);
			}
			if(r[0]==5)
			{
				ox=check(5,0,0,4);
				if(ox==1)
					game_end();
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[5][0][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				next_block(r);
				move_block(x,y,5,r);
			}
			remove_block(r);
		}
	}
	void next_block(int n[])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(block[n[1]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+1+i);
				printf("��");
			}
				if(block[n[2]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+6+i);
				printf("��");
			}
					if(block[n[3]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+11+i);
				printf("��");
			}
		}
}
	void remove_block(int n[])
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(block[n[1]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+1+i);
				printf(" ");
			}
			if(block[n[2]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+6+i);
				printf(" ");
			}
			if(block[n[3]][0][i][j]==1)
			{
				gotoxy(board_X+24+(2*j),board_Y+11+i);
				printf(" ");
			}
		}
	for(i=0;i<3;i++)
			n[i]=n[i+1];
	make_block(n);
}
	void move_block(int x,int y,int n1,int r[])
	{
		int a,b,ox,i,j,kb,n2=0,e;
		while(1)
		{
			ox=0;
			a=x;
			b=y;
			e=n2;
			/*
			d=y1=y;
			if(count!=0)
				for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							if(block[n1][e][i][j]==1)
							{
								gotoxy(x+(2*j),c+i);
								printf(" ");
							}
			e=n2;
			count++;
			*/
			if(_kbhit())
			{
				kb=_getch();
				if(kb=='q')
				{
					game_main();
				}
				if(kb==LEFT)
				{
					ox=check(n1,n2,y-board_Y,(x-2-board_X)/2);
					if(ox==0)
					{
						x-=2;
						/*
						for(;;)
						{
							ox=0;
							d=y1;
							ox=check(n1,n2,y1+1-board_Y,(x-board_X)/2);
							if(ox==1)
							{
								c=y1;
								break;
							}
							y1++;
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),d+i);
										printf(" ");
									}
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),y1+i);
										printf("��");
									}
						}
						*/
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}
					
					}
				}
				else if(kb==RIGHT)
				{
					ox=check(n1,n2,y-board_Y,(x+2-board_X)/2);
					if(ox==0)
					{
						x+=2;
						/*
						for(;;)
						{
							ox=0;
							d=y1;
							ox=check(n1,n2,y1+1-board_Y,(x-board_X)/2);
							if(ox==1)
							{
								c=y1;
								break;
							}
							y1++;
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),d+i);
										printf(" ");
									}
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),y1+i);
										printf("��");
									}
						}
						*/
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}	
					}
				}
				else if(kb==DOWN)
				{
					ox=check(n1,n2,y+1-board_Y,(x-board_X)/2);
					if(ox==0)
					{
						y++;
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}	
					}
				}
				else if(kb=='a'||kb=='A')
				{
					ox=check(n1,(n2+1)%4,y-board_Y,(x-board_X)/2);
					if(ox==0)
					{
						e=n2;
						n2++;
						n2=n2%4;
						/*
						for(;;)
						{
							ox=0;
							d=y1;
							ox=check(n1,n2,y1+1-board_Y,(x-board_X)/2);
							if(ox==1)
							{
								c=y1;
								break;
							}
							y1++;
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),d+i);
										printf(" ");
									}
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),y1+i);
										printf("��");
									}
						}
						*/
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][e][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}
					}
				}
				else if(kb=='d'||kb=='D')
				{
					if(n2==0)
						ox=check(n1,3,y-board_Y,(x-board_X)/2);
					else
						ox=check(n1,n2-1,y-board_Y,(x-board_X)/2);
					if(ox==0)
					{
						
						e=n2;
						n2--;
						if(n2==-1)
							n2=3;
						/*
						for(;;)
						{
							ox=0;
							d=y1;
							ox=check(n1,n2,y1+1-board_Y,(x-board_X)/2);
							if(ox==1)
							{
								c=y1;
								break;
							}
							y1++;
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),d+i);
										printf(" ");
									}
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),y1+i);
										printf("��");
									}
						}
						*/
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][e][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}
					}
				}
				else if(kb==SPACE)
				{
					for(;;)
					{
						ox=0;
						a=x;
						b=y;
						ox=check(n1,n2,y+1-board_Y,(x-board_X)/2);
						if(ox==1)
						{
							/*
							for(i=0;i<4;i++)
								for(j=0;j<4;j++)
									if(block[n1][n2][i][j]==1)
									{
										gotoxy(x+(2*j),c+i);
										printf(" ");
									}
							*/
							break;
						}
						y++;
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(x+(2*j),y+i);
									printf("��");
								}
					}
				}
				else if(kb=='z'||kb=='Z')
				{
					if(Q==7)
					{
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][0][i][j]==1)
								{
									gotoxy(board_X+38+(2*j),board_Y+1+i);
									printf("��");
								}
						Q=n1;
						Q1=n1;
						remove_block(r);
					}
					else
					{
						Q1=Q;
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[Q1][0][i][j]==1)
								{
									gotoxy(board_X+38+(2*j),board_Y+1+i);
									printf(" ");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][0][i][j]==1)
								{
									gotoxy(board_X+38+(2*j),board_Y+1+i);
									printf("��");
								}
						for(i=0;i<4;i++)
							for(j=0;j<4;j++)
								if(block[n1][n2][i][j]==1)
								{
									gotoxy(a+(2*j),b+i);
									printf(" ");
								}
						Q=n1;
						r[0]=Q1;
						COUNT=0;
						/*
						move_block(board_X+8,board_Y,Q1,r);
						*/
						make_block(r);
					}
				}
			}
			else		
			{
				ox=check(n1,n2,y+1-board_Y,(x-board_X)/2);
				if(ox==1)
				{
					/*
					for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							if(block[n1][n2][i][j]==1)
							{
								gotoxy(x+(2*j),c+i);
								printf("��");
							}
							*/
					break;
				}
				/*
				for(;;)
				{
					ox=0;
					d=y1;
					ox=check(n1,n2,y1+1-board_Y,(x-board_X)/2);
					if(ox==1)
					{
						c=y1;
						break;
					}
					y1++;
					for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							if(block[n1][n2][i][j]==1)
							{
								gotoxy(a+(2*j),d+i);
								printf(" ");
							}
					for(i=0;i<4;i++)
						for(j=0;j<4;j++)
							if(block[n1][n2][i][j]==1)
							{
								gotoxy(x+(2*j),y1+i);
								printf("��");
							}
				}
				*/
				y++;
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[n1][n2][i][j]==1)
						{
							gotoxy(a+(2*j),b+i);
							printf(" ");
						}
				for(i=0;i<4;i++)
					for(j=0;j<4;j++)
						if(block[n1][n2][i][j]==1)
						{
							gotoxy(x+(2*j),y+i);
							printf("��");
						}
				Sleep(Delay);
			}

		}
		new_board(((x-board_X)/2),(y-board_Y),n1,n2);
	}
	void new_board(int x,int y,int n1,int n2)
	{
		int i,j,a[19]={0},count;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(block[n1][n2][i][j]==1)
					board[y+i][x+j]=1;
		for(i=0;i<19;i++)
		{
			count=0;
			for(j=0;j<12;j++)
				if(board[i][j]==1)
					count++;
			if(count==12)
				a[i]++;
		}
		remove_board(x,y,n1,n2,a);
	}
	void remove_board(int x, int y, int n1, int n2, int a[])
	{
		int i,j,k,count;
		count=0;
		for(i=0;i<19;i++)
			if(a[i]==1)
			{
				count++;
				for(j=0;j<10;j++)
					board[i][j+1]=0;
				for(k=i;k>0;k--)
					for(j=0;j<10;j++)
						board[k][j+1]=board[k-1][j+1];
			}
		if(count!=0)
		{
			SCORE+=50*(count+1);
			for(i=1;i<=20;i++)
			{
				if(SCORE>=(1000*i)&&C==(i-1))
				{
					C++;
					Delay-=50;
					money+=100;
				}
			}
			/*
			for(i=0;i<20;i++)
				for(j=0;j<12;j++)
				*/
			for(i=0;i<19;i++)
				for(j=1;j<11;j++)
				{
					gotoxy(board_X+(2*j),board_Y+i);
					printf(" ");
				}
			background();
			call_board(board_X,board_Y);
		}
	
	}
	int check(int n1,int n2,int b1, int b2)
	{
		int ox=0,i,j;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				if(block[n1][n2][i][j]!=0&&board[b1+i][b2+j]!=0)
					ox=1;
		return ox;
	}
	void game_end()
	{
		int non;
		system("cls");
		gotoxy(40,20);
		printf("GAME OVER");
		gotoxy(40,21);
		printf("PLEASE PRESS ANY KEY");
		non=_getch();
		game_main();
	}

void game_pan()
{
	int x,y,user1x,user1y,user2x,user2y;
	system("cls");
	for(x=0;x<25;x++)
		for(y=0;y<25;y++)
			five_pan[x][y]=0;
	background();
	x=board_X;
	y=board_Y;
	call_pan(x,y);
	while(1)
	{
		user1x=x+24;
		user1y=y+12;
		gotoxy(user1x,user1y);
		printf("��");
		kb_five(user1x,user1y,1);
		check_pan(1);
		user2x=x+24;
		user2y=y+12;
		gotoxy(user2x,user2y);
		printf("��");
		kb_five(user2x,user2y,2);
		check_pan(2);
	}
} 
// �Ѱ� ������, ��Ǳ��, �ð����ѱ��,6���� ������
	void check_pan(int n)
	{
		int i,j,k,cnt;
		char ch;
		for(i=0;i<25;i++)
			for(j=0;j<21;j++)
			{
				cnt=0;
				for(k=0;k<5;k++)
					if(five_pan[i][j+k]==n)
						cnt++;
				if(cnt==5)
				{
					gotoxy(16,4);
					printf("����ϼ�!");
					ch=_getch();
					game_main();
				}
			}
		for(i=0;i<21;i++)
			for(j=0;j<25;j++)
			{
				cnt=0;
				for(k=0;k<5;k++)
					if(five_pan[i+k][j]==n)
						cnt++;
				if(cnt==5)
				{
					gotoxy(16,4);
					printf("����ϼ�!");
					ch=_getch();
					game_main();
				}
			}
		for(i=0;i<21;i++)
			for(j=0;j<21;j++)
			{
				cnt=0;
				for(k=0;k<5;k++)
					if(five_pan[i+k][j+k]==n)
						cnt++;
				if(cnt==5)
				{
					gotoxy(16,4);
					printf("����ϼ�!");
					ch=_getch();
					game_main();
				}
			}
		for(i=4;i<25;i++)
			for(j=0;j<21;j++)
			{
				cnt=0;
				for(k=0;k<5;k++)
					if(five_pan[i-k][j+k]==n)
						cnt++;
				if(cnt==5)
				{
					gotoxy(16,4);
					printf("����ϼ�!");
					ch=_getch();
					game_main();
				}
			}
	}
	void call_pan(int x,int y)
	{
		int i,j;
		for(i=0;i<25;i++)
			for(j=0;j<25;j++)
				if(five_pan[i][j]==1)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(five_pan[i][j]==2)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==2)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==3)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==4)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==5)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==6)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==7)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==8)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==9)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
				else if(pan[i][j]==10)
				{
					gotoxy(x+(2*j),y+i);
					printf("��");
				}
	}
	void kb_five(int x,int y,int n1)
	{
		char ch;
		int a,b;
		while(1)
		{
			a=x;
			b=y;
			ch=_getch();
			if(ch=='q')
				game_main();
			if(ch==LEFT)
				x-=2;
			else if(ch==RIGHT)
				x+=2;
			else if(ch==UP)
				y--;
			else if(ch==DOWN)
				y++;
			else if(ch==SPACE)
			{
				if(five_pan[y-board_Y][(x-board_X)/2]!=1&&five_pan[y-board_Y][(x-board_X)/2]!=2)
				{
					five_pan[y-board_Y][(x-board_X)/2]=n1;
					gotoxy(10,40);
					printf("                               ");
					break;
				}
				else
				{
					gotoxy(10,40);
					printf("���� �̹� ������ �ִ� �ڸ��Դϴ�.");
				}
			}

			if(a!=x||b!=y)
				if(x<board_X||x>board_X+48)
					x=a;
				else if(y<board_Y||y>board_Y+24)
					y=b;
				else if(five_pan[b-board_Y][(a-board_X)/2]==1)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(five_pan[b-board_Y][(a-board_X)/2]==2)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==2)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==3)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==4)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==5)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==6)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==7)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==8)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==9)
				{
					gotoxy(a,b);
					printf("��");
				}
				else if(pan[b-board_Y][(a-board_X)/2]==10)
				{
					gotoxy(a,b);
					printf("��");
				}

				if(n1==1)
				{
					gotoxy(x,y);
					printf("��");
				}
				else if(n1==2)
				{
					gotoxy(x,y);
					printf("��");
				}
		}
	}
void taja()
{
	
	char word[3][N][20]=
	/*
	{
		{"","","","","","","","","","","","","","","","","","","",""},
		{"","","","","","","","","","","","","","","","","","","",""},
		{"","","","","","","","","","","","","","","","","","","",""}
	};
	*/
	{
		{"���","��","Ȯ��","â��","����","�ڹ�","��ǻ��","����","���","���",
	    	"��", "�Ϳ���", "���", "�ڽ�", "�����", "�ڱ���", "���б�", "����", "ȣ����", "�Ǿ�"},
		{"����","ȭ���","������","����","��ġ�","�ᳪ��","���","��","���","�����ϴ�",
		"�뷡��","����ũ","�������","�ʰ���","������","īǪġ��","�������","����","��","��ž"},
		{"�������","���ٴϴ�","�����","���","����ɴ�","������Ʈ","ĭ����","����","�׸���","��������",
		"����","��ٸ���","���ø�","������ũ","�����","�ø�","¥���","����û","����","������"}
	};
	char quiz[3][N][15]; // ����ڰ� �Է��� �� ���
	char button; // �� ȭ������ �Ѿ �� ����ϴ� ����
	int i,j,a,cnt,cnt2,cnt3; // i,j for�� ����� �� ���; a �ܾ� �Ѹ��� x��ǥ ������
							 // cnt : ���� ���� �ľǽ� ���, cnt2 : ���� ���� �ľǽ� ���, cnt3 : cnt2�� �̿��Ͽ� life�� ���� ��, ���н� ���̵� �ȿö󰡰� ����.
	int index[N],overflag; // 
	system("cls");
	background();
	if(mainflag==1) {
		while(!_kbhit())
		{
   			gotoxy(3,8); printf("������  ��    ��������  ��    ������  �� ��     ����     ��");  
			gotoxy(3,9); printf("��          ��          ��        ��           ��   �� ��    ��    ��    ��");
			gotoxy(3,10);printf("��          ��         ���       ��          ��    �� ��    ��    ��    ��");
			gotoxy(3,11);printf("������  ���      ��  ��      ���       ��   ��� ��     ����     ��");
			gotoxy(3,12);printf("��          ��       ��    ��     ��        ��      �� ��      �������");
			gotoxy(3,13);printf("��          ��      ��      ��    ��       ��       �� ��      ��        ��");
			gotoxy(3,14);printf("������  ��     ��        ��   ��      ��        �� ��      �������");
		

			gotoxy(45,18);
				printf("< �����Ϸ��� �ƹ�Ű�� ��������. >");
			Sleep(1000);

			gotoxy(45,18);
				printf("                                 ");
			Sleep(1000);
		}
		system("cls");
	}
	background();

	if(strn<3){
		add(1);
		gotoxy(32,11);
		printf("Ÿ�ڰ��� ���̵� %d ", strn+1);
		gotoxy(22,12);
		printf("<��Ģ : ��Ÿ �Է��� %dȸ���� �����ȴ�.> ",-strn+3);
		button=_getch();
		system("cls");

	

		background();
		gotoxy(55,6);
		printf("********* �� Ģ ********* ");
		gotoxy(55,7);
		printf("1.ȭ�鿡 ���̴�");
		gotoxy(55,8);
		printf("  �ܾ �Է��Ͽ�,");
		gotoxy(55,9);
		printf("  �ܾ �����ϴ� ����");
		gotoxy(55,10);
		printf("2.Ÿ���� ��Ȯ����");
		gotoxy(55,11);
		printf("  �ø��� ���� ��������,");
		gotoxy(55,12);
		printf("  ��Ÿ�Է� ������ �ѰԵǸ�");
		gotoxy(55,13);
		printf("  ������ ����˴ϴ�.");
		gotoxy(55,14);
		printf("*************************");


		gotoxy(4,1);
		printf("Life");
		for(i=2;i<-strn+5;i++){
			gotoxy(5,i);
			printf("��");
		}
		for(i=1;i<26;i++){
			if(i==22){
				gotoxy(10,i);
				printf("��");
			}
			else{
				gotoxy(10,i);
				printf("��");
			}
		}
	
		for(i=12;i<52;i+=2){
			gotoxy(i,22);
			printf("��");
		}

		for(i=1;i<26;i++){
			if(i==22){
				gotoxy(52,i);
				printf("��");
			}
			else{
				gotoxy(52,i);
				printf("��");
			}
		}

		srand(time(NULL));

		for(i=0;i<N;i++)
		{
			do{
				overflag=0;
				index[i]=rand()%N+1;
				for(j=0;j<i;j++){
					if(index[j]==index[i])
						overflag=1;
				}
			}while(overflag);
		}

	
			for(i=0;i<N;i++)
			{
				a=i%4;
				gotoxy((a+1)*10+2,index[i]);
				printf("%s  ",word[strn][i]);
			}
			cnt=0;  cnt3=0;
			for(;;){
					gotoxy(27,24);
					gets(quiz[strn][1]);
					cnt2=0;				
					for(i=0;i<N;i++){
						if(!strcmp( quiz[strn][1],word[strn][i])){
							a=i%4;
							gotoxy((a+1)*10+2,index[i]);
							printf("          ");
							cnt++;
							}
						else
							cnt2++;
	
						gotoxy(27,24);
						printf("          ");
						}
		
					if(cnt2==N){
						cnt3++;
						gotoxy(5,cnt3+1);
						printf("  ");
					}
			

					if(cnt3>-strn+3){
						add(-1);
						system("cls");
						mainflag=0;
						game_main();
					}
					if(cnt==N)
						break;
		
			}
			if(strn<2){
				mainflag=0;
				system("cls");
				background();
				gotoxy(26,10);
				printf("���� ���̵��� �Ѿ�ϴ�. ");
				gotoxy(20,11);
				printf("<��� �����Ϸ��� �ƹ�Ű�� ��������. >");
				button=_getch();
				game_main();
			}
	}
	system("cls");
	background();
	gotoxy(30,10);
	printf("��罺������ Ŭ����");
	gotoxy(18,11);
	printf("< ó��ȭ������ ���ư����� �ƹ�Ű�� ��������. >");
	strn=-1;
	mainflag=1;
	button=_getch();
	game_main();
	
		
}
	void add(int num)
	{
		strn=strn+num;
	}

void bingo()
{
	int x,y,user,i,j,OK;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			bingo_user[0][i][j]=0;
			bingo_user[1][i][j]=0;
			bingo_com[0][i][j]=0;
			bingo_com[1][i][j]=0;
		}
	memo_cnt=bingcnt_u=bingcnt_c=0;
	for(i=0;i<25;i++)
	{
		bing_c[i]=bing_u[i]=0;
	}
	for(i=0;i<50;i++)
	{
		memo_num[i]=0;
	}
	x=board_X+12;
	y=board_Y+14;
	system("cls");
	background();
	bing_tl(x-4,y-2);
	call_bingopan(x,y);
	call_bingopan(x+40,y);
	user_num(x,y);
	com_num(x+40,y);
	gotoxy(x+70,y+12);
	printf("���Ǻ���:%d",bingcnt_u);
	gotoxy(x+70,y+13);
	printf("������:%d",bingcnt_c);
	while(1)
	{	
		for(;;)
		{
			OK=1;
			gotoxy(x+30,y+12);
			scanf_s("%d",&memo_num[memo_cnt]);
			gotoxy(x+30,y+12);
			printf("       ");
			for(i=0;i<memo_cnt;i++)
				if(memo_num[memo_cnt]==memo_num[i])
				{
					OK=0;
					gotoxy(x+26,y+14);
					printf("                     ");
					gotoxy(x+26,y+14);
					printf("�̹� �Է��Ѽ����Դϴ�.");
				}
				else if(memo_num[memo_cnt]<1||memo_num[memo_cnt]>50)
				{
					OK=0;
					gotoxy(x+26,y+14);
					printf("                      ");
					gotoxy(x+26,y+14);
					printf("1~50������ ���ڸ� �Է��ϼ���.");
				}
			if(OK)
			{
				user=memo_num[memo_cnt];
				memo_cnt++;
				break;
			}
		}
		gotoxy(x+26,y+14);
		printf("                           ");
		bing_block_user(x,y,user);
		check_bingo(x,y);
		gotoxy(x+70,y+12);
		printf("      ");
		gotoxy(x+70,y+12);
		printf("���Ǻ���:%d",bingcnt_u);
		gotoxy(x+70,y+13);
		printf("      ");
		gotoxy(x+70,y+13);
		printf("������:%d",bingcnt_c);
		Sleep(500);
		rand_block_com(x,y);
		check_bingo(x,y);
		gotoxy(x+70,y+12);
		printf("      ");
		gotoxy(x+70,y+12);
		printf("���Ǻ���:%d",bingcnt_u);
		gotoxy(x+70,y+13);
		printf("      ");
		gotoxy(x+70,y+13);
		printf("������:%d",bingcnt_c);
	}
}
	void rand_block_com(int x,int y)
	{
		int cnt,r,i,j,save,OK;
		cnt=0;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo_com[0][i][j]!=0)
					cnt++;
		r=rand()%cnt+1;
		cnt=0;
		OK=0;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(bingo_com[0][i][j]!=0)
					cnt++;
				if(cnt==r)
				{
					save=bingo_com[0][i][j];
					OK=1;
					break;
				}
			}
			if(OK==1)
				break;
		}
		memo_num[memo_cnt++]=save;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo_com[0][i][j]==save)
				{
					gotoxy(x+42+4*j,y+1+2*i);
					printf(" ");
					gotoxy(x+42+4*j,y+1+2*i);
					printf("��");
					bingo_com[0][i][j]=0;
				}
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo_user[0][i][j]==save)
				{
					gotoxy(x+2+4*j,y+1+2*i);
					printf(" ");
					gotoxy(x+2+4*j,y+1+2*i);
					printf("��");
					bingo_user[0][i][j]=0;
				}
	}
	void check_bingo(int x,int y)
	{
		int i,j,cnt1,cnt2;
		for(i=0;i<5;i++)
		{
			cnt1=cnt2=0;
			for(j=0;j<5;j++)
			{
				if(bingo_user[0][i][j]==0)
					cnt1++;
				if(bingo_user[1][i][j]==2)
					cnt2++;
			}
			if(cnt1==5&&cnt2!=5)
			{
				for(j=0;j<5;j++)
					bingo_user[1][i][j]=2;
				bingcnt_u++;
			}
		}
		//--------------------------------------
		for(i=0;i<5;i++)
		{
			cnt1=cnt2=0;
			for(j=0;j<5;j++)
			{
				if(bingo_user[0][j][i]==0)
					cnt1++;
				if(bingo_user[1][j][i]==2)
					cnt2++;
			}
			if(cnt1==5&&cnt2!=5)
			{
				for(j=0;j<5;j++)
					bingo_user[1][j][i]=2;
				bingcnt_u++;
			}
		}
		//------------------------------------
		cnt1=cnt2=0;
		for(i=0;i<5;i++)
		{
			if(bingo_user[0][i][i]==0) 
				cnt1++;
			if(bingo_user[1][i][i]==2)
				cnt2++;
		}
		if(cnt1==5&&cnt2!=5)
		{
			for(i=0;i<5;i++)
				bingo_user[1][i][i]=2;
			bingcnt_u++;
		}
		//------------------------------------
		cnt1=cnt2=0;
		for(i=0;i<5;i++)
		{
			if(bingo_user[0][i][4-i]==0) 
				cnt1++;
			if(bingo_user[1][i][4-i]==2)
				cnt2++;
		}
		if(cnt1==5&&cnt2!=5)
		{
			for(i=0;i<5;i++)
				bingo_user[1][i][4-i]=2;
			bingcnt_u++;
		}
		//-------------------------------------
		//-------------------------------------
		if(bingcnt_u==3)
			bing_end(x,y,0);
		//------------------------------------
		//------------------------------------
		for(i=0;i<5;i++)
		{
			cnt1=cnt2=0;
			for(j=0;j<5;j++)
			{
				if(bingo_com[0][i][j]==0)
					cnt1++;
				if(bingo_com[1][i][j]==2)
					cnt2++;
			}
			if(cnt1==5&&cnt2!=5)
			{
				for(j=0;j<5;j++)
					bingo_com[1][i][j]=2;
				bingcnt_c++;
			}
		}
		//--------------------------------------
		for(i=0;i<5;i++)
		{
			cnt1=cnt2=0;
			for(j=0;j<5;j++)
			{
				if(bingo_com[0][j][i]==0)
					cnt1++;
				if(bingo_com[1][j][i]==2)
					cnt2++;
			}
			if(cnt1==5&&cnt2!=5)
			{
				for(j=0;j<5;j++)
					bingo_com[1][j][i]=2;
				bingcnt_c++;
			}
		}
		//------------------------------------
		cnt1=cnt2=0;
		for(i=0;i<5;i++)
		{
			if(bingo_com[0][i][i]==0) 
				cnt1++;
			if(bingo_com[1][i][i]==2)
				cnt2++;
		}
		if(cnt1==5&&cnt2!=5)
		{
			for(i=0;i<5;i++)
				bingo_com[1][i][i]=2;
			bingcnt_c++;
		}
		//------------------------------------
		cnt1=cnt2=0;
		for(i=0;i<5;i++)
		{
			if(bingo_com[0][i][4-i]==0) 
				cnt1++;
			if(bingo_com[1][i][4-i]==2)
				cnt2++;
		}
		if(cnt1==5&&cnt2!=5)
		{
			for(i=0;i<5;i++)
				bingo_com[1][i][4-i]=2;
			bingcnt_c++;
		}
		//----------------------------------
		if(bingcnt_c==3)
			bing_end(x,y,1);
	}
	void bing_end(int x,int y,int OK)
	{
		char ch;
		system("cls");
		background();
		gotoxy(24,15);
		if(OK==0)
		{
			printf("Game Win");
			money+=500;
		}
		else
		{
			printf("Game Lose");
		}
		Sleep(500);
		ch=_getch();
		game_main();
	}
	void bing_block_user(int x,int y,int u)
	{
		int i,j;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo_user[0][i][j]==u)
				{
					gotoxy(x+2+4*j,y+1+2*i);
					printf(" ");
					gotoxy(x+2+4*j,y+1+2*i);
					printf("��");
					bingo_user[0][i][j]=0;
				}
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
				if(bingo_com[0][i][j]==u)
				{
					gotoxy(x+42+4*j,y+1+2*i);
					printf(" ");
					gotoxy(x+42+4*j,y+1+2*i);
					printf("��");
					bingo_com[0][i][j]=0;
				}
	}
	void bing_tl(int x,int y)
	{
		int i;
		gotoxy(x,y);
		printf("��");
		for(i=0;i<35;i++)
			printf("��");
		printf("��");
		for(i=0;i<6;i++)
			printf("��");
		printf("��");
		for(i=0;i<18;i++)
		{
			gotoxy(x,y+1+i);
			printf("��");
			gotoxy(x+72,y+1+i);
			printf("��");
			gotoxy(x+86,y+1+i);
			printf("��");
		}
		gotoxy(x,y+19);
		printf("��");
		for(i=0;i<35;i++)
			printf("��");
		printf("��");
		for(i=0;i<6;i++)
			printf("��");
		printf("��");
		gotoxy(x+30,y+15);
		for(i=0;i<5;i++)
			printf("��");
	}
	void call_bingopan(int x,int y)
	{
		int i,j;
		for(i=0;i<11;i++)
			for(j=0;j<11;j++)
				if(bing_pan[i][j]==0)
				{
					gotoxy(x+2*j,y+i);
					printf(" ");
				}
				else if(bing_pan[i][j]==1)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==2)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==3)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==4)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==5)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==6)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==7)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==8)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==9)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==10)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
				else if(bing_pan[i][j]==11)
				{
					gotoxy(x+2*j,y+i);
					printf("��");
				}
	}
	void user_num(int x,int y)
	{
		int cnt,OK,i,j;
		srand(time(NULL));
		bing_u[0]=rand()%50+1;
		OK=0;
		for(cnt=1;cnt<25;cnt++)
			while(1)
			{
				OK=0;
				bing_u[cnt]=rand()%50+1;
				for(i=0;i<cnt;i++)
					if(bing_u[i]==bing_u[cnt])
						OK=1;
				if(OK==0)
					break;
			}
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
			{
				gotoxy(x+2+4*j,y+1+2*i);
				printf("%d",bing_u[5*i+j]);
				bingo_user[0][i][j]=bing_u[5*i+j];
			}
	}
	void com_num(int x,int y)
	{
		int cnt,OK,i,j;
		bing_c[0]=rand()%50+1;
		OK=0;
		for(cnt=1;cnt<25;cnt++)
			while(1)
			{
				OK=0;
				bing_c[cnt]=rand()%50+1;
				for(i=0;i<cnt;i++)
					if(bing_c[i]==bing_c[cnt])
						OK=1;
				if(OK==0)
					break;
			}
		for(i=0;i<5;i++)
			for(j=0;j<5;j++)
			{
				gotoxy(x+2+4*j,y+1+2*i);
				printf("��");
				bingo_com[0][i][j]=bing_c[5*i+j];
				//printf("%d",bing_c[5*i+j]);
			}
	}

void packman()
{
	int mab[20][20]=
	{
	 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	 {1,2,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,0,0,1,0,0,0,1,1,1,1,1,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,1,1},
	 {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1},
	 {1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1},
	 {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1},
	 {1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1},
	 {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
	 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1},
	 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	int i,j;
	char button;
	int x,y;
	int rx,ry,ran;
	int rx2,ry2,ran2;
	int rx3,ry3,ran3;
	int cnt,cnt2;
	
	system("cls");
	background();
	gotoxy(12,6);
	printf("�Ѹ� ����\n");
	gotoxy(12,7);
	printf("<�ƹ�Ű�� ��������.>");
	button=_getch();
	system("cls");
	cnt=0; // 0�� ����
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			if(mab[i][j]==0){
				printf("��");
				cnt++;
			}
			else
				printf("��");
		}
		printf("\n");
	}

	srand(time(NULL));

	
	rx=32; ry=1;
	gotoxy(rx,ry);
	printf("��");

	rx2=2; ry2=14;
	gotoxy(rx2,ry2);
	printf("��");

	rx3=16; ry3=8;
	gotoxy(rx3,ry3);
	printf("��");

	x=2; y=1;
	gotoxy(x,y);
	printf("��");


	while(1){
		ran=rand()%4;
		ran2=rand()%4;
		ran3=rand()%4;
		
	    monster(mab, rx, ry, ran);
		rx=monsterX(mab, rx, ry,ran);
		ry=monsterY(mab, rx, ry,ran);
		
		monster(mab, rx2, ry2,ran2);
		rx2=monsterX(mab, rx2, ry2,ran2);
		ry2=monsterY(mab, rx2, ry2,ran2);

		monster(mab, rx3, ry3,ran3);
		rx3=monsterX(mab, rx3, ry3,ran3);
		ry3=monsterY(mab, rx3, ry3,ran3);

		if(_kbhit()){
			gotoxy(x,y);	
			button=_getch();
			if(button=='q')
			{
				game_main();
			}
			if(button=='6'){
				if( mab[y][x/2+1]!=1){
					if( (x==rx && y==ry ) || (x==rx2 && y==ry2) || (x==rx3 && y==ry3)){ //������ �����̱� �� ��ġ�� ���Ͱ� ������ �� ������ �������
						gotoxy(x,y);
						printf("��");
					}
					else{
						gotoxy(x,y);
						printf("  ");
					}
					mab[y][x/2+1]=2;
					x+=2;
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2+1]==1){
					gotoxy(x,y);
					printf("��");
				}

			}
			else if(button=='4'){
				if( mab[y][x/2-1]!=1){
					if( (x==rx && y==ry ) || (x==rx2 && y==ry2) || (x==rx3 && y==ry3)){
						gotoxy(x,y);
						printf("��");
					}
					else{
						gotoxy(x,y);
						printf("  ");
					}
					mab[y][x/2-1]=2;
					x-=2;
					gotoxy(x,y);
					printf("��");
				}
				else if( mab[y][x/2-1]==1){
					gotoxy(x,y);
					printf("��");
				}
			}

			else if(button=='2'){
				if(mab[y+1][x/2]!=1){
					if( (x==rx && y==ry ) || (x==rx2 && y==ry2) || (x==rx3 && y==ry3)){
						gotoxy(x,y);
						printf("��");
					}
					else{
						gotoxy(x,y);
						printf("  ");
					}
					mab[y+1][x/2]=2;
					y++;
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y+1][x/2]==1){
					gotoxy(x,y);
					printf("��");
				}

			}
			else if(button=='8'){
				if(mab[y-1][x/2]!=1){
					if( (x==rx && y==ry ) || (x==rx2 && y==ry2) || (x==rx3 && y==ry3)){
						gotoxy(x,y);
						printf("��");
					}
					else{
						gotoxy(x,y);
						printf("  ");
					}
					mab[y-1][x/2]=2;
					y--;
					gotoxy(x,y);
					printf("��");
				}
				else if (mab[y-1][x/2]==1)
				{
					gotoxy(x,y);
					printf("��");
				}
			}
		}
		
		// ���Ϳ� ������ ����
		if( (y==ry && x==rx) || (y==ry2 && x==rx2) || (y==ry3 && x==rx3))
		{
			system("cls");
			game_main();
			//break;
		}
		// *�� ���� ĭ ���ϱ�
		cnt2=0;
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				if(mab[i][j]==2)
					cnt2++;
		// *�� �پ��ָ� ����
		if(cnt==cnt2-1)
		{	//break;
			system("cls");
			game_main();
			money+=300;
		}
		Sleep(100);
		
	}
}
	void monster( int m[][20], int rx, int ry, int ran)
	{
		if(ran==0 && m[ry][rx/2+1]!=1){
					if(m[ry][rx/2]==0){
						gotoxy(rx,ry);
						printf("��");
					}
					else if(m[ry][rx/2]==2){
						gotoxy(rx,ry);
						printf("  ");
					}
						gotoxy(rx+2,ry);
						printf("��");
				}
		else if(ran==1 && m[ry][rx/2-1]!=1){
					if(m[ry][rx/2]==0){
						gotoxy(rx,ry);
						printf("��");
					}
					else if(m[ry][rx/2]==2){
						gotoxy(rx,ry);
						printf("  ");
					}
					gotoxy(rx-2,ry);
					printf("��");
				}

		else if(ran==2 && m[ry+1][rx/2]!=1){
					if(m[ry][rx/2]==0){
						gotoxy(rx,ry);
						printf("��");
					}
					else if(m[ry][rx/2]==2){
						gotoxy(rx,ry);
						printf("  ");
					} 
					gotoxy(rx,ry+1);
					printf("��");
				}

		else if(ran==3 && m[ry-1][rx/2]!=1){
					if(m[ry][rx/2]==0){
						gotoxy(rx,ry);
						printf("��");
					}
					else if(m[ry][rx/2]==2){
						gotoxy(rx,ry);
						printf("  ");
					}
					gotoxy(rx,ry-1);
					printf("��");
				}
	}
	int monsterX( int m[][20], int rx, int ry, int ran)
	{
		if(ran==0 && m[ry][rx/2+1]!=1)
					rx+=2;
			
		else if(ran==1 && m[ry][rx/2-1]!=1)
					rx-=2;			
		return rx;		
	}
	int monsterY( int m[][20], int rx, int ry, int ran)
	{
		if(ran==2 && m[ry+1][rx/2]!=1)
					ry++;
		else if(ran==3 && m[ry-1][rx/2]!=1)
					ry--;
		return ry;			
	}

void bombgame()
{
	int mab[M][M]={0};
	int mab2[M][M]={0};
	int bomb_x[M];
	int bomb_y[M];
	int i,j,k,l,cnt,cnt2,bomb_cnt;
	int x,y;
	int rand_index;
	int temp;
	char button;

	system("cls");
	background();
	gotoxy(12,6);
	printf("����ã�����");
	button=_getch();
	system("cls");
	
	srand(time(NULL));

	for(i=0;i<M;i++)
		bomb_x[i]=i;

	for(i=0;i<M;i++){
		rand_index=rand()%M;
		temp=bomb_x[rand_index];
		bomb_x[rand_index]=bomb_x[i];
		bomb_x[i]=temp;
	}

	for(i=0;i<M;i++)
		bomb_y[i]=i;

	for(i=0;i<M;i++){
		rand_index=rand()%M;
		temp=bomb_y[rand_index];
		bomb_y[rand_index]=bomb_y[i];
		bomb_y[i]=temp;
	}

	bomb_cnt=0;
	for(i=0;i<M;i++){
		cnt=0;
		k=rand()%(M-1);
		for(j=k;j<M && cnt<2;j++){
			mab[bomb_x[i]][bomb_y[j]]=9;
			cnt++;
			bomb_cnt+=cnt;
		}
	}

	cnt=0;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++){
			if(mab[0][0]==9)
				cnt--;
			if(mab[i][j]==9)
				cnt++;

		}
	if(mab[0][0]!=9)
		mab[0][0]=cnt;

	cnt=0;
	for(i=0;i<2;i++)
		for(j=8;j<10;j++){
			if(mab[0][9]==9)
				cnt--;
			if(mab[i][j]==9)
				cnt++;
		}
	if(mab[0][9]!=9)
		mab[0][9]=cnt;

	cnt=0;
	for(i=8;i<10;i++)
		for(j=0;j<2;j++){
			if(mab[9][0]==9)
				cnt--;
			if(mab[i][j]==9)
				cnt++;
		}
	if(mab[9][0]!=9)
		mab[9][0]=cnt;

	cnt=0;
	for(i=8;i<10;i++)
		for(j=8;j<10;j++){
			if(mab[9][9]==9)
				cnt--;
			if(mab[i][j]==9)
				cnt++;
		}
	if(mab[9][9]!=9)
		mab[9][9]=cnt;


	for(i=1;i<9;i++){
		if(mab[i][0]!=9){
			cnt=0;
			for(j=i-1;j<i+2;j++)
				for(k=0;k<2;k++)
					if(mab[j][k]==9)
						cnt++;
			mab[i][0]=cnt;	
		}
		if(mab[i][9]!=9){
			cnt2=0;
			for(j=i-1;j<i+2;j++)
				for(k=8;k<10;k++)
					if(mab[j][k]==9)
						cnt2++;
			mab[i][9]=cnt2;
		}

	}
	
	for(i=0;i<10;i+=9)
	{
		for(j=1;j<9;j++)
			if(mab[i][j]!=9){
				cnt=0;
				if(i==0){
					for(k=0;k<2;k++)
						for(l=j-1;l<j+2;l++)
							if(mab[k][l]==9)
								cnt++;
				}
				else{
					for(k=8;k<10;k++)
						for(l=j-1;l<j+2;l++)
							if(mab[k][l]==9)
								cnt++;

				}
				mab[i][j]=cnt;
			}
	}

	for(i=1;i<9;i++){
		for(j=1;j<9;j++)
			if(mab[i][j]!=9){
				cnt=0;
				for(k=i-1;k<i+2;k++)
					for(l=j-1;l<j+2;l++)
						if(mab[k][l]==9)
							cnt++;
				mab[i][j]=cnt;
			}
	}

	for(i=0;i<M;i++){
		for(j=0;j<M;j++)
			printf("��");
		printf("\n");
	}

	x=0;y=0;
	gotoxy(x,y);
	printf("��");
	cnt=0;
	while(1)
	{
		gotoxy(22,0);
		printf("                 ");
		gotoxy(22,0);
		printf("���� ���� ���� %d",20-cnt);

		button=_getch();
		
		if(button=='q')
			game_main();
		if(button=='c'){
			if(mab[y][x/2]==9)
				break;
			else
				mab2[y][x/2]=1;
		}

		if(button=='b'){
			if(mab[y][x/2]!=9)
				break;
			else
				mab2[y][x/2]=2;
		}

		if(button=='6' && x/2!=M-1 ){
			if(mab2[y][x/2]==0){
				gotoxy(x,y);
				printf("��");
			}
			else if(mab2[y][x/2]==2){
				gotoxy(x,y);
				printf("��");
				cnt++;
			}
			else
				mab_print(mab, x, y);
					
			gotoxy(x+2,y);
			printf("��");
			x+=2;
		}
		if(button=='4' && x/2!=0){
			if(mab2[y][x/2]==0){
				gotoxy(x,y);
				printf("��");
			}
			else if(mab2[y][x/2]==2){
				gotoxy(x,y);
				printf("��");
				cnt++;
			}
			else
				mab_print(mab, x, y);
			gotoxy(x-2,y);
			printf("��");
			x-=2;
			
		}
		if(button=='8' && y!=0){
			if(mab2[y][x/2]==0){
				gotoxy(x,y);
				printf("��");
			}
			else if(mab2[y][x/2]==2){
				gotoxy(x,y);
				printf("��");
				cnt++;
			}
			else
				mab_print(mab, x, y);
			gotoxy(x,y-1);
			printf("��");
			y-=1;
		}
		if(button=='2' && y!=M-1){
			if(mab2[y][x/2]==0){
				gotoxy(x,y);
				printf("��");
			}
			else if(mab2[y][x/2]==2){
				gotoxy(x,y);
				printf("��");
				cnt++;
			}
			else
				mab_print(mab, x, y);
			gotoxy(x,y+1);
			printf("��");
			y+=1;
			
		}
		cnt=0;
		for(i=0;i<M;i++)
			for(j=0;j<M;j++)
				if(mab2[i][j]==2)
					cnt++;
		
		


		if(cnt==20)
			break;
	}
	system("cls");
	button=_getch();
	game_main();
}
	void mab_print( int mab[][M], int x, int y)
	{
			if(mab[y][x/2]==0){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==1){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==2){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==3){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==4){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==5){
					gotoxy(x,y);
					printf("��");
				}
				else if(mab[y][x/2]==6){
					gotoxy(x,y);
					printf("��");
				}
	}

void randgame()
{
	system("cls");
	background();
	gotoxy(35,20);
	printf("�������忡 ���Ű� ȯ���մϴ�.");
	gotoxy(10,21);
	printf("�������忡���� ���� �����Ͽ� ���ӿ��� �̱�� �� ���� ���� ���� �� �ֽ��ϴ�.");
	gotoxy(35,25);
	printf("������ ������ ������ �ּ���.");
	gotoxy(40,27);
	printf("1. ����,����,�� (�¸��� 2��)");
	gotoxy(40,29);
	printf("2. Ȧ¦ (���߸� 1.5��)");
	gotoxy(40,31);
	printf("3. �귿 (���߸� 100,000��)");
	gotoxy(40,33);
	printf("4. �������� ���ư���");
	if1();		
}
//�������� if��
void if1()
{
	char ch;
	for(;;)
	{
		ch=_getch();
		if(ch=='1')
			kbb();
		else if(ch=='2')
			hol();
		else if(ch=='3')
			rul();
		else if(ch=='4')
			game_main();
	}
}
	//�������� ����������
	void kbb() 
				{
	
					int bat,user;
	
					system("cls");
					background();
					gotoxy(32,20);
					printf("���� ���� �� ������ �����ϼ̽��ϴ�.");
					gotoxy(13,22);
					printf("(�ִ� ���� �ݾ��� 100,000�� �̰�, -1�� ������ ��������� ���ư��ϴ�.)");
					gotoxy(35,23);
					printf("���� �Ͻ� �ݾ��� �����ּ���:"); scanf_s("%d",&bat);
					if(bat==-1)
						randgame();
					if(bat>100,000)
						kbb();
	
					gotoxy(32,25);
					printf("����(1) ����(2) ��(3)�� �������ּ���:"); scanf_s("%d",&user);

					gotoxy(20,27);
					printf("���� �Ͻűݾ� : %d�� , ���� ������: ",bat);
					if(user==1)
						printf("����(1) ");
					else if(user==2)
						printf("����(2) ");
					else if(user==3)
						printf("��(3) ");
					printf("�� �½��ϱ�?");
	
					gotoxy(40,28);
					printf("������ o / Ʋ����x");

					add3(bat,user);

	
				}
		//�������� ���������� ������
		void add3(int a,int b)
				{
					char cho;

					while(1)
					{
						cho=_getch();
						if(cho=='o')
						{
							money=money-a;
							if(money<0)
							{
								money=money+a;
								system("cls");
								gotoxy(45,20);
								printf("�ܾ��̺����մϴ�.");
								cho=_getch();
								randgame();
							}
							else
							{
								gotoxy(78,44);
								printf("��:%d",money);
								kbbresult(a,b);
							}
						}
						else if(cho=='x')
							kbb();	
					}
				}
		//�������� ���������� ���ȭ��
		void kbbresult(int a,int b)
				{
					int com=0;
					char ch;
					system("cls");
					background();
					srand((unsigned)time(NULL));
					gotoxy(30,20);
					printf("����� ����:");
					if(b==1)
						printf("����(1) ");
					else if(b==2)
						printf("����(2) ");
					else if(b==3)
						printf("��(3) ");
					gotoxy(30,21);
					printf("��ǻ���� ����:");
					com=rand()%((3-1)+1)+1;	
					if(com==1)
						printf("����(1) ");
					else if(com==2)
						printf("����(2) ");
					else if(com==3)
						printf("��(3) ");

					gotoxy(30,23);
					if(b==1)
					{
						if(com==1)
						{
							printf("�����ϴ�.");
							money=money+a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
						else if(com==2)
							printf("�й��Ͽ����ϴ�.");
						else
						{
							printf("�¸��Ͽ����ϴ�.");
							money=money+3*a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
					}
					else if(b==2)
					{
						if(com==1)
						{
							printf("�¸��Ͽ����ϴ�.");
							money=money+3*a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
						else if(com==2)
						{
							printf("�����ϴ�.");
							money=money+a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
						else
							printf("�й��Ͽ����ϴ�.");
					}
					else if(b==3)
					{
						if(com==1)
							printf("�й��Ͽ����ϴ�.");
						else if(com==2)
						{
							printf("�¸��Ͽ����ϴ�.");
							money=money+3*a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
						else
						{
							printf("�����ϴ�.");
							money=money+a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
					}
					ch=_getch();
					randgame();
				}
	//�������� Ȧ¦
	void hol()
				{
					int bat,user;
					system("cls");
					background();
					gotoxy(35,20);
					printf("Ȧ¦������ �����ϼ̽��ϴ�.");
					gotoxy(13,22);
					printf("(�ִ� ���� �ݾ��� 50,000�� �̰�, -1�� ������ ��������� ���ư��ϴ�.)");
					gotoxy(35,23);
					printf("���� �Ͻ� �ݾ��� �����ּ���:"); scanf_s("%d",&bat);
					if(bat==-1)
						randgame();

					gotoxy(33,25);
					printf("Ȧ��(1) ¦��(2)�� �������ּ���:"); scanf_s("%d",&user);

					gotoxy(20,27);
					printf("���� �Ͻűݾ� : %d�� , ���� ������: ",bat);
					if(user==1)
						printf("Ȧ��(1) ");
					else if(user==2)
						printf("¦��(2) ");
					printf("�� �½��ϱ�?");

					gotoxy(40,28);
					printf("������ o / Ʋ����x");

					add4(bat,user);
				}
		//�������� Ȧ¦ ������
		void add4(int a,int b)
				{
					char cho;

					while(1)
					{
						cho=_getch();
						if(cho=='o')
						{
							money=money-a;
							if(money<0)
							{
								money=money+a;
								system("cls");
								gotoxy(45,20);
								printf("�ܾ��̺����մϴ�.");

								cho=_getch();
								randgame();
							}
							gotoxy(78,44);
							printf("��:%d",money);
							holresult(a,b);
						}
						else if(cho=='x')
							hol();	
					}
				}
		//�������� Ȧ¦ ���ȭ��
		void holresult(int a,int b)
				{
					int com=0;
					char ch;
					system("cls");
					background();
					srand((unsigned)time(NULL));
					gotoxy(30,20);
					printf("����� ����:");
					if(b==1)
						printf("Ȧ��(1) ");
					else if(b==2)
						printf("¦��(2) ");
					gotoxy(30,21);
					printf("��ǻ���� ����:");
					com=rand()%((2-1)+1)+1;	
					if(com==1)
						printf("Ȧ��(1) ");
					else if(com==2)
						printf("¦��(2) ");

					gotoxy(30,23);
					if(b==1)
					{
						if(com==1)
						{
							printf("������ϴ�.");
							money=money+2.5*a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
						else
						{
							printf("������ ���Ͽ����ϴ�.");
						}
					}
					else if(b==2)
					{
						if(com==1)
							printf("������ ���Ͽ����ϴ�.");
						else
						{
							printf("������ϴ�.");
							money=money+2.5*a;
							gotoxy(78,44);
							printf("��:%d",money);
						}
					}
					ch=_getch();
					randgame();
				}
	//�������� �귿
	void rul()
				{
					system("cls");
					background();
					gotoxy(35,20);
					printf("�귿������ �����ϼ̽��ϴ�.");

					gotoxy(35,22);
					printf("�̿� ����� 100���Դϴ�.");

					gotoxy(35,24);
					if2();
				}
		//�������� �귿 ������
		void if2()
				{
					char cho;
					printf("�̿��Ͻðڽ��ϱ�? o/x");
					while(1)
					{
						cho=_getch();
						if(cho=='o')
						{
							if(money<0)
							{
								money=money+100;
								system("cls");
								gotoxy(45,20);
								printf("�ܾ��̺����մϴ�.");
								cho=_getch();
								randgame();
							}
							money=money-100;
							gotoxy(78,44);
							printf("��:%d",money);
							rulresult();
						}
						else if(cho=='x')
							randgame();	
					}
				}
		//�������� �귿 ������2
		void if3(int a,int b,int c)
				{
				}
		//�������� �귿 ���ȭ��
		void rulresult()
				{
					int com,x,y,z,a;
					char ch;
					com=0;
					system("cls");
					background();
					com=rand()%((999-100)+1)+100;	
					x=com/100; //100���ڸ���
					a=com%100;
					y=a/10; //10�� �ڸ���
					z=a%10; //1�� �ڸ���
					if3(x,20,5);
					if3(y,40,5);
					if3(z,60,5);
					gotoxy(30,22);
					if(com==111||com==222||com==3331||com==444||com==555||com==666||com==777||com==888||com==999)
					{
						money=money+100100;
						gotoxy(78,44);
						printf("��:%d",money);
						printf("��÷�Ǽ̽��ϴ�.");
					}
					else
						printf("�����ϼ̽��ϴ�.");
					ch=_getch();
					randgame();
				}

void maingame_end()
{
	char ch;
	system("cls");
	background();
	gotoxy(20,10);
	printf("�����Ͻ� money�� ��� �����ϼ̽��ϴ�.");
	gotoxy(20,11);
	printf("Game over");
	ch=_getch();
	exit(0);
}
void maingame_end1()
{
	char ch;
	system("cls");
	background();
	gotoxy(20,10);
	printf("������ �����մϴ�.");
	ch=_getch();
	exit(0);
}

	// 9�� Ȧ¦,����������,�ζ�
	// �������� �ڽ� �����
