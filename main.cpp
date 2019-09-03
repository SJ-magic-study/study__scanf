/************************************************************
概要
	scanfの柔軟な使い方.
	Spaceも読み込みたい、など
	
参考
	スキャン集合
		http://wisdom.sakura.ne.jp/programming/c/c58.html
	
	新C言語入門 : シニア編 : 林 晴比古
		p316 - 330
		p368 - 372
************************************************************/
#include <stdio.h>
#include <string.h>

/************************************************************
************************************************************/
int main()
{
	/********************
	********************/
	enum{
		NUM_VIDEOS = 3,
		BUF_SIZE = 500,
	};
	
	char path_mov[NUM_VIDEOS][BUF_SIZE];
	
	FILE* fp;
	fp = fopen("config.txt", "r");
	if(fp == NULL) { printf("No config file\n"); return 1; }
	
	char buf[BUF_SIZE];
	while(fscanf(fp, "%s", buf) != EOF){
		if(strcmp(buf, "<mov_0>") == 0){	// まず、普通にmarkを探しに行く
			fscanf(fp, "%[ \t]", buf); 		// space & tab 読み捨て
			fscanf(fp, "%[^\n]", buf); 		// \n以外を読み取る -> \nが来るまで読み込み(space also, \nはBufferに残る)
			sprintf(path_mov[0], "%s", buf);
			
		}else if(strcmp(buf, "<mov_1>") == 0){
			fscanf(fp, "%[ \t]", buf); // space & tab 読み捨て
			fscanf(fp, "%[^\n]", buf); // \n以外を読み取る -> \nが来るまで読み込み(space also)
			sprintf(path_mov[1], "%s", buf);
			
		}else if(strcmp(buf, "<mov_2>") == 0){
			fscanf(fp, "%[ \t]", buf); // space & tab 読み捨て
			fscanf(fp, "%[^\n]", buf); // \n以外を読み取る -> \nが来るまで読み込み(space also)
			sprintf(path_mov[2], "%s", buf);
		}
	}
	
	fclose(fp);
	
	/********************
	********************/
	for(int i = 0; i < NUM_VIDEOS; i++){
		printf("path_mov%d:%s\n", i, path_mov[i]);
	}
	
	
	return 0;
}

