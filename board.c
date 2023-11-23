#include<stdio.h>
#include<stdlib.h>
#include "board.h"

#define N_BOARD				20
#define BOARDSTATUS_OK		1
#define BOARDSTATUS_NOTOK 	0

#define N_COINPOS			14
#define MAX_COIN			5

#define SHARK_INITPOS		-3
#define MAX_SHARKSTEP		6

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_shark_position;

int borad_initBoard(void){
	
	int i;
	for(i=0;i<N_BOARD;i++){
		board_status[i]= BOARDSTATUS_OK;
		board_coin[i]= 0;
		
	}
	
	board_shark_position=SHARK_INITPOS;
	
	for(i=0;i<N_COINPOS;i++){
		
		int flag=0;
		while(flag == 0){
			
			int allocPos = rand()%N_BOARD;
			if(board_coin[allocPos]==0){
				
				board_coin[allocPos] = rand()%MAX_COIN+1;
				flag=1;
			}
		}
	}
return 0;
}


int board_printBoardStatus(void){
	
	int i;
	
	printf("--------- BOARD STATUS ----------\n");
	for(i=0;i<N_BOARD;i++){
	
		printf("|");
		if(board_status[i] == BOARDSTATUS_NOTOK)
			printf("X");
		else
			printf(" ");
			
	}
	
	printf("|\n");
	printf("-------------------------------\n");

return 0;
}

int board_getBoardCoin(int pos){
	
	int coin = board_coin[pos];
	board_coin[pos]=0;
	return coin; //return 후 함수는 반환되기에 함수가 더 있으면 안됨 
	
}

//int board_getSharkPosition(void);

int board_stepShark(void){
	
	int i;
	int step=rand()%MAX_SHARKSTEP+1;
	
	for(i=board_shark_position+1;i<=board_shark_position+step;i++){
		
		if(i>=0 && i<N_BOARD){
			
		board_status[i]=BOARDSTATUS_NOTOK;
		}
	}	
	
	board_shark_position+=step;
	
	return board_shark_position;
}


int board_getBoardStatus(int pos){

	return board_status[pos];

}
