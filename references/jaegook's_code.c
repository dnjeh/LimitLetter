#include <stdio.h>
#include <windows.h>
#include <io.h>


//main
int main(){
    //value
    printf("");
    int min, max, i;
    char yn;
    char name[100];
    //scanf
    printf("please input file name and minimum question number and maximum question number(file name example: name.cpp)\n");
    scanf("%s %d %d", &name, &min ,&max);

    

    //문제 검사
    if (min > max){
        printf("The minimum question number cannot be greater than the maximum question number.");
        return 0;
    }

    if((access(name, 0) != -1)){ //파일?존재?여부?체크????
        printf("The file already exists. initialize? (y/n)\n");
        fflush(stdin);
        scanf("%c", &yn);
        if (yn == 'y' || yn == 'Y') {
            printf("initialize and writing");
        } 
        else if(yn == 'n' || yn == 'N') {
            printf("stop writing");
            return 0;
        }
    }

    FILE* fp = fopen( name , "w");
    //정상 확인
    if (fp == NULL) {
        printf("file cannot be created.");
    } 
    else {   
        //작성
        fprintf(fp, "#include <stdio.h>");
        for (i = min; i <= max; i++) {
            fprintf(fp, "\n\nvoid exam%d(){\n\n}", i);

        }
        fprintf(fp, "\n\n\n\n\nmain(){\n	int num;\n	while(1){\n    	printf(\"\\n문제 번호: \");\n		scanf(\"%%d\", &num);\n		printf(\"%%d번 문제========================================================================\\n\", num);\n		switch(num){");
        for (i = min; i <= max; i++) {
            fprintf(fp, "\n			case %d: exam%d(); break;", i, i);
        }
        fprintf(fp, "\n            default: return 0 ;\n		}\n	}\n}");

        printf("successfully created\nmade by msg|ide: vsc|lan: C/CPP");
        fclose(fp);
    }
}