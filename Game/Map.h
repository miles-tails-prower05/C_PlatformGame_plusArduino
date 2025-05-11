// C 프로그래밍 - https://codereading101.github.io/C/
// 소스파일 - https://github.com/CodeReading101/C/blob/main/Chapter17/Map.h

#ifndef _MAP_H_
#define _MAP_H_

#define TRUE  1
#define FALSE 0

extern int map[100][100];
extern int width, height;

int readMap(char* filename);
void writeMap();

#endif