#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<Windows.h>
#define row 10//ÐÐ
#define col 10//ÁÐ
//ÉùÃ÷
void Board(char board[row][col], int ROW, int COL);
void picture(char board[row][col], int ROW, int COL);
void play(char board[row][col], int ROW, int COL);
void computerplay(char board[row][col], int ROW, int COL);
int ifwin(char board[row][col], int ROW, int COL);
