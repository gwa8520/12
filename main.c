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
	
	//1. �ʱ�ȭ �ϱ�/ �÷��̾� �Է�
	board_initBoard();
	
	//2. �ݺ��� ������ �÷��̾� ��
	do{
		int step= rolldie();
		int coinResult;
		
		board_printBoadStatus();
		pos += step;
		coinResult = board_getBoardCoin(pos);
		
		printf("press any key to continue");
		//scanf("%d",&c);
		fflush(stdin);		
		
		//2-1. �÷��̾��� ���� ���
	  //2-2. �ֻ��� ������ 
	  //2-3. �̵��ϱ�
	  //2-4. ���� �ݱ�
	  //2-5. ���������� 
	  //2-6. ��� ���� if(��� �÷��̾ �ѹ� �� ���� ����.) 
		
	}
	while(1);
	 
	//3. ����(���� ���, ��� ��) 

	
	
	
	
	return 0;
}
