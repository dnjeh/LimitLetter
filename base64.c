#include <stdio.h>
int main() {
    int siz, i, j, a; 
    scanf("%d %d", &siz, &a);
    char sentence[siz], sentenceB[siz/3*4];
    for(i=0;i<siz;i++) {
        sentence[i]='\0';
    }
    for(i=0;i<siz/3*4;i++) {
        sentenceB[i]='\0';
    }
    for(;getchar()!='\n';);
    if(a) fgets(sentence, siz+1, stdin);
    else fgets(sentenceB, siz/3*4+1, stdin);
    for(i=0;i<siz/3*4+1&&!a;i++) {
        sentenceB[i]-=65;
    } 
    if(a) {
        for(i=0, j=0;sentence[i]&&i<siz;i++) {
            if(!(i%3)) {
                sentenceB[j]=sentence[i]>>2;
                sentenceB[j+1]+=(sentence[i]%4)<<4;
            }
            else if(i%3==1) {
                sentenceB[j]+=sentence[i]/16;
                sentenceB[j+1]+=(sentence[i]%16)<<2;
            }
            else if(i%3==2) {
                sentenceB[j]+=sentence[i]/64;
                sentenceB[j+1]+=sentence[i]%64;
                j++;
            }
            j++;
        }
    }
    else {
        for(j=0, i=0;sentenceB[j]&&j<(siz/3*4);j++) {
            if(!(j%4)) {
                sentence[i]=(sentenceB[j]%64)<<2;
                sentence[i-1]+=(sentenceB[j]%64)/16;
            }
            if(j%4==1) {
                sentence[i]=(sentenceB[j]%16)<<4;
            }
            if(j%4==2) {    
                sentence[i-1]+=(sentenceB[j]%64)/4;
                sentence[i]=(sentenceB[j]%4)<<6;
            }
            if(j%4==3) {    
                sentence[i-1]+=(sentenceB[j])%64;
                i--;
            }
            i++;
        }
    }
    for(i=0;i<siz/3*4+1;i++) {
        sentenceB[i]+=65;
    } 
    if(a) {
        for(i=0;i<siz/3*4;i++) {
            printf("%c", sentenceB[i]);
        }
    }
    else {
        for(i=0;i<siz;i++) {
            printf("%c", sentence[i]);
        }
    }
}