#pragma once

#include "../Global/Define/KGDefine.h"

/*
 * 파일 시스템이란?
 * - 파일을 제어 할 수 있는 기능을 의미한다. (즉, 파일 시스템을 활용하면 반영구적으로 보관 가능한 데이터를 처리하는 것이 가능하다.)
 * 따라서, 프로그램이 재시작 되었을 때 이전에 사용했던 데이터를 재활용하기 위해서는 파일 시스템을 사용해야한다는 것을 알 수 있다.
 * 
 * 스트림이란?
 * - 데이터가 지나 다닐 수 있는 통로를 의미한다. (즉, 스트림을 활용하면 데이터를 특정 프로그램에 입력으로 전달하거나 가져오는 것이 가능하다.)
 * 
 * C 파일 관련 함수
 * - fopen/fclose		<- 파일과 데이터를 주고 받을 수 있는 스트림을 생성 및 제거하는 역할
 * - fprintf/fscanf
 * - fputs/fgets
 * - fwrite/fread
 * 
 * C 파일 스트림 생성 방법
 * - fopen("파일 경로", "파일 모드")
 * 
 * C 파일 모드 (파일 입/출력 모드 + 파일 개방 모드) 종류
 * // 파일 입/출력 모드
 * - r		<- 읽기 모드
 * - w		<- 쓰기 모드
 * - a		<- 추가 모드
 * 
 * // 파일 개방 모드
 * - t		<- 텍스트 모드
 * - b		<- 바이너리 모드
 * 
 * Ex)
 * fopen("A.txt", "rt")		<- 읽기 + 텍스트 모드
 * fopen("A.txt", "rb")		<- 읽기 + 바이너리 모드
 * 
 * read 모드 vs write 모드
 * - read 모드는 파일 스트림을 생성하기 위한 대상이 존재하지 않을 경우 스트림 생성이 되지 않는 반면, write 모드는 대상이 존재하지 않을 경우 해당 대상 (파일) 을 생성 후
 * 파일 스트림을 생성하는 특징이 존재한다. (즉, read 모드는 대상 파일이 없을 경우 스트림 생성이 실패한다는 것을 의미한다.)
 * 
 * write 모드 vs append 모드
 * - write 모드는 파일에 존재하는 데이터를 모두 지우는 반면, append 모드는 파일에 데이터를 지우지 않고 파일 스트림만 생성하는 차이점이 존재한다.
 * 
 * 텍스트 모드 vs 바이너리 모드
 * - 텍스트 모드는 개행 문자 (\n) 에 대한 보정이 존재하는 반면, 바이너리 모드는 입/출력하는 데이터에 대한 어떠한 보정도 하지 않는 차이점이 존재한다. (즉, 운영체제 별로
 * 개행으로 인식하는 문자가 서로 다르기 때문에 텍스트 모드로 개행 문자를 입/출력하면 각 운영체제에 맞는 개행 문자로 변경이 발생한다는 것을 알 수 있다.)
 * 
 * 따라서, 텍스트 모드로 개행 문자를 입/출력했을 경우 \n <-> \r\n 간에 변환가 발생하기 때문에 특정 파일의 사본 파일을 생성하는 행위를 하기 위해서는 바이너리 모드를
 * 사용해야한다는 것을 알 수 있다.
 */
namespace E11 {
	/** Example 11 */
	int Example_11(int argc, char* args[]);
}
