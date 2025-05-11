// C 프로그래밍 - https://codereading101.github.io/C/
// 원본 소스파일 - https://github.com/CodeReading101/C/blob/main/Chapter17/Main.c

//#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Character.h"
#include "Map.h"

int main() {
	// 먼저 파일에서 맵을 읽고 출력
	printf( "파일이름을 입력하세요: " );
	char filename[100]="";
	scanf( "%s", filename );
	if ( readMap( filename ) == FALSE )
		return FALSE;
	writeMap();

	char direction='w';
	int row = 1, column = 1;
	do {
		// 이전 위치의 캐릭터를 지우고 이동하려는 새 위치에 캐릭터를 출력
		printf( "\033[%d;%df  ", row+2, column*2+1 );
		move( direction, &row, &column );
		printf("\033[%d;%df옷", row+2, column*2+1 );

		// 게임 종료 확인
		if( finish( row, column ) == TRUE ) {
			break;
		}
		// 게임 종료 아니면 새 이동 방향 입력 받아서 게임 계속 진행
		printf( "\033[1;1f\033[2KWASD와[Enter]를 입력하세요: " );
		// fflush( stdin );
		scanf( "\n%c", &direction );
	} while ( ( direction == 'W' ) || ( direction == 'A' ) || ( direction == 'S' ) || ( direction == 'D' )
	       || ( direction == 'w' ) || ( direction == 'a' ) || ( direction == 's' ) || ( direction == 'd' ) );

	return 0;
}

