#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define MAX_DIE	6



void opening(void){
	
	printf("====================================\n");	 
	printf("====================================\n");
	printf("   &**      SHARK GAME     &**      \n");
	printf("====================================\n");
	printf("====================================\n\n\n");
	
}

int rolldie(void){
	
	return srand()%MAX_DIE+1;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int pos=0;
	
	srand((unsigned)time(NULL));
	
	opening();
	
	//1. 초기화 하기/ 플레이어 입력
	board_initBoard();
	
	//2. 반복문 돌리기 플레이어 턴
	do{
		int step= rolldie();
		int coinResult;
		
		board_printBoadStatus();
		pos += step;
		coinResult = board_getBoardCoin(pos);
		
		printf("press any key to continue");
		//scanf("%d",&c);
		fflush(stdin);		
		
		//2-1. 플레이어의 상태 출력
	  //2-2. 주사위 던지기 
	  //2-3. 이동하기
	  //2-4. 동전 줍기
	  //2-5. 다음턴으로 
	  //2-6. 상어 동작 if(모든 플레이어가 한번 씩 턴을 돈다.) 
		
	}
	while(1);
	 
	//3. 정리(승자 계산, 출력 등) 

	
	
	
	
	return 0;
}
