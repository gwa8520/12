#include<stdio.h>
#include<stdlib.h>

#define N_BOARD	20
#define BOARDSTATUS_OK	1
#define BOARDSTATUS_NOTOK 0

#define N_COINPOS	14
#define MAX_COIN	5

static int board_status[N_BOARD];
static int board_coin[N_BOARD];

static int board_shark_position;

int borad_initBoard(void){
	
	int i;
	for(i=0;i<N_BOARD;i++){
		board_status[i]= BOARDSTATUS_OK;
		board_coin[i]= 0;
		
	}
	for(i=0;i<N_COINPOS;i++){
		
		int flag=0;
		while(flag == 0){
			
			int allocpos = rand()%N_BOARD;
			if(board_coin[allocpos]==0){
				
				board_coin[allocpos] = rand()%MAX_COIN+1;
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
			printf("O");
			
	}
	
	printf("|\n");
	printf("-------------------------------\n");

return 0;
}


int board_getBoardCoin(int pos){
	
	int coin = board_coin[pos];
	board_coin[pos]=0
	return board_coin[pos]; //return 후 함수는 반환되기에 함수가 더 있으면 안됨 
	 
	
}

//int board_getSharkPosition(void);

//int board_stepShark(void);

int board_getBoardStatus(int pos){

	return board_status[pos];

}
