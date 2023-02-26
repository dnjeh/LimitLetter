#include <stdio.h>
#include <stdlib.h> // exit()
#include <io.h>
#include <errno.h>

int main() {
    struct _finddatai64_t c_file;
    intptr_t hFile;
    char path[] = "*";
    if((hFile = _findfirsti64(path, &c_file))==-1L) {
        switch(errno) {
            case ENOENT:
                printf("이 폴더에 파일이 존재하지 않습니다\n"); break;
            case EINVAL:
                fprintf(stderr, "편지 형식의 파일을 찾을 수 없습니다 (임의로 번경하셨나요?)\n"); exit(1); break;
            case ENOMEM:
                fprintf(stderr, "파일 이름이 너무 깁니다\n"); exit(1); break;
            default:
                fprintf(stderr, "알 수 없는 오류입니다.\n"); exit(1); break;
        }
    }
    else {
        printf("-- 편지 목록 --\n");
        do {
            printf("%s\n", c_file.name);
        } while(_findnexti64(hFile, &c_file)==0);
        _findclose(hFile); // _findfirsti64(), _findnexti64()에 사용된 메모리를 반환
    }
    return 0;
}