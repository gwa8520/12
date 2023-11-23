#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_CHARNAME	200
#define MAX_DIE			6
#define N_PLAYER		4

#define PLAYERSTATUS_LIVE	0
#define PLAYERSTATUS_DIE	1
#define PLAYERSTATUS_END	2

int player_position[N_PLAYER];	//배열로 선언 
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAX_CHARNAME]={"LIVE","DIE","END"};



void opening(void){
	
	printf("====================================\n");	 
	printf("====================================\n");
	printf("   &**      SHARK GAME     &**      \n");
	printf("====================================\n");
	printf("====================================\n\n\n");
	
}

int rolldie(void){
	
	return rand()%MAX_DIE+1;
}

void printPlayerPosition(int player){
	
	int i;
	for(i=0;i<N_BOARD;i++){
		printf("|");
		if(i==player_position[player])
			printf("%c",player_name[player][0]);
		else
		{
			if(board_getBoardStatus(i)==BOARDSTATUS_NOTOK)
				printf("X");
			else
				printf(" ");
		}
		
	}
	printf("|\n");
}

void printPlayerStatus(void){
	
	int i;
	printf("player status ---\n");
	for(i=0;i<N_PLAYER;i++){
		
		printf("%s : pos %i,coin %i, status: %s\n",player_name[i], player_position[i],player_coin[i],player_statusString[player_status[i]]);
	}
	printf("-------------------\n");
}


void checkDie(void){
	
	int i;
	for(i=0;i<N_PLAYER;i++){
		
		if(board_getBoardStatus(player_position[i])==BOARDSTATUS_NOTOK)
			player_status[i]=PLAYERSTATUS_DIE;
	}
	printf("YOU DIE!!\n");
}

int game_end(void){
	
	int i;
	int flag_end=1;
	
	//players all died?
	for(i=0;i<N_PLAYER;i++){
		
		flag_end=0;
		break;
	}
	return flag_end;
}

int getAlivePlayer(void){
	
	int i;
	int cnt=0;
	for(i=0;i<N_PLAYER;i++){
		
		if(player_status[i]==PLAYERSTATUS_END)
			cnt;
	}
	
	return cnt;
}

int getWinner(void){
	
	int i;
	int winner=0;
	int max_coin=-1;
	
	for(i=0;i<N_PLAYER;i++){
		
		if(player_coin[i]>max_coin){
			max_coin=player_coin[i];
			winner=i;
		}
	}
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int pos=0;
	int i;
	int turn=0;
	int flag_end;
	
	srand((unsigned)time(NULL));
	
	opening();
	
	//1. 초기화 하기/ 플레이어 입력
	board_initBoard;
	//1-2.
	for(i=0;i<N_PLAYER;i++){
	
		 player_position[i]=0;
		 player_coin[i]=0;
		 player_status[i]=PLAYERSTATUS_LIVE;
		 
		 //player_name
		 printf("Player's name",i);
		 scanf("%s",player_name[i]);
		
	}
	
	//2. 반복문 돌리기 플레이어 턴
	do{
		int step;	//= rolldie();
		int coinResult;
		char c;
		
		if (player_status[turn] != PLAYERSTATUS_LIVE){
			
			turn= (turn+1)%N_PLAYER;
			continue;
		}
		
		
		//2-1. 플레이어의 상태 출력
		board_printBoardStatus();
	 	 for(i=0;i<N_PLAYER;i++)
	  		printPlayerPosition(i);
		printPlayerStatus();
		  
		  
		//2-2. 주사위 던지기 	  
	  	printf("%s turn!!!",player_name[turn]);
		printf("press any key to roll the dice\n");	//멈추는 용도  
		scanf("%d",&c);
		fflush(stdin);		  //키보드에 입력해서 남은 버퍼 제거 
		
	  	step=rolldie();
	 	
		 //2-3. 이동하기 	
		player_position[turn] += step;
		if(player_position[turn]>=N_BOARD){
		
			player_position[turn]=N_BOARD-1;
		}
		
		if(player_position[turn]==N_BOARD-1)
			player_status[turn]=PLAYERSTATUS_END;
			
		printf("you are going to take %i spaces!\n",step);
		
		//2-4. 동전 줍기
		coinResult = board_getBoardCoin(pos);	//?player_position??
		player_coin[turn] += coinResult;
		printf("%c get %i coin!\n",player_name[turn],player_coin[turn]);
		
	  	//2-5. 다음턴으로 
	 	 turn = (turn+1)%N_PLAYER;	//wrap around 
	  
	  	//2-6. 상어 동작 if(모든 플레이어가 한번 씩 턴을 돈다.) 
	  	if(turn==0){
	  		//shark
	  		int shark_pos = board_stepShark();
	  		printf("shark ate you\n");
	  		
	  		checkDie();

		  }
	}
	
	while(1);
	
	//3. 정리(승자 계산, 출력 등) 
	//printf("Winner is %d!!",getWinner);
	
	
	return 0;
}
