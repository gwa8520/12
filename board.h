#define BOARDSTATUS_OK	1
#define BOARDSTATUS_NOTOK 0


int borad_initBoard(void);
int board_printBoardStatus(void);

int board_getBoardCoin(int pos); 
int board_getSharkPosition(void);

int board_stepShark(void);
int board_getBoardStatus(int pos);
