// C 프로그래밍 - https://codereading101.github.io/C/
// 소스파일 - https://github.com/CodeReading101/C/blob/main/Chapter17/Character.c

#include <stdio.h>
#include "Character.h"
#include "Map.h"

#define WALL 1
#define EXIT 3

// 맵 이동 함수
void move( char direction, int *row, int *column ) {
	// W는 위로 한칸 이동
	if ( ( ( direction == 'w' ) || ( direction == 'W' ) ) && ( *row > 0 ) && ( map[ *row-1 ][ *column ] != WALL ) )
		*row = *row-1;
	// A는 왼쪽으로 한칸 이동
	else if ( ( ( direction == 'a' ) || ( direction == 'A' ) ) && ( *column > 0 ) && ( map[ *row ][ *column-1 ] != WALL ) )
		*column = *column-1;
	// S는 아래로 한칸 이동
	else if ( ( ( direction == 's' ) || ( direction == 'S' ) ) && ( *row < ( height-1 ) ) && ( map[ *row+1 ][ *column ] != WALL ) )
		*row = *row+1;
	// D는 오른쪽으로 한칸 이동
	else if ( ( ( direction == 'd' ) || ( direction == 'D' ) ) && ( *column < ( width-1 ) ) && ( map[ *row ][ *column+1 ] != WALL ) )
		*column = *column+1;
}
// 게임 종료 확인 함수
int finish( int row, int column ) {
	// 목적지에 도착하면 종료
	if( map[row][column] == EXIT ) {
		printf( "\033[2J\033[4;15fSUCCESS!\033[7;15f" );
		return TRUE;
	}
	// 아니면 게임 계속 진행
	else {
		return FALSE;
	}
}
