// C 프로그래밍 - https://codereading101.github.io/C/
// 소스파일 - https://github.com/CodeReading101/C/blob/main/Chapter17/Map.c

//#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Map.h"

// 전역변수 맵
int map[100][100];
int width, height;

// 맵 읽기 함수
int readMap( char *filename ) {
	// 맵 파일 열기
	FILE *inFile = NULL;
	if ( ( inFile = fopen( filename, "rt" ) ) == NULL ) {
		printf( "[오류] 파일을 열 수 없습니다!" );
		return FALSE;
	}

	// 맵 파일에서 한 줄씩 읽기
	for ( char line[1024] = ""; fgets( line, 100, inFile ) != NULL; height++ ) {
		if ( strlen( line ) < 3 ) {
			break;
		}
		else {
			for( width = 0; ( width < strlen( line ) ) && ( '0' <= line[width] ) && ( line[width] <= '9' ); width++ )
				map[height][width] = line[width] - '0';
		}
	}

	// 맵 파일 닫기
	fclose( inFile );
	return TRUE;
}

// 맵 쓰기 함수
void writeMap() {
	// 길, 벽, 옷, 문 등 출력값 설정
	char symbol[10][1024] = { "  ", "\033[44m  \033[0m", "옷", "\033[34m문\033[0m", "\033[31m♥\033[0m", "\033[33m★\033[0m", "\033[32m♣\033[0m", "\033[31m♠\033[0m", "\033[36m◆\033[0m", "\033[35m■\033[0m" };
	printf("\033[2K\033[2;1f");
	// 2차원 미로 맵을 한 칸씩 출력
	for ( int row = 0; row < height; row++ ) {
		for ( int column = 0; column < width; column++ )
			printf( "%s", symbol[map[row][column]] );
		printf( "\n" );
	}
}