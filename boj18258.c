/*
---
title:  "[C] BOJ_18258_큐2"
excerpt: "https://www.acmicpc.net/problem/18258"
toc: true
toc_sticky: true
toc_label: "Contents"
categories:
  - algorithm
tags:
  - BOJ
  - queue
---

문제이해: 분
구현: 분
Debug: 분
참고자료
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char command[20];
    int i, n, tail = 0, head = 0;
    int* q;
    
    scanf("%d", &n);
    getchar();
    q = (int*)malloc(sizeof(int) * n);

    while(n--){
        gets(command);

        if(!strcmp(command, "pop"))
            if(head == tail) printf("-1\n");
            else printf("%d\n", q[tail++]);
        
        else if(!strcmp(command, "size"))
            printf("%d\n", head - tail);
        
        else if(!strcmp(command, "empty"))
            printf("%d\n", tail == head ? 1 : 0);
        
        else if(!strcmp(command, "front"))
            if(head == tail) printf("-1\n");
            else printf("%d\n", q[tail]);
        
        else if(!strcmp(command, "back"))
            if(head == tail) printf("-1\n");
            else printf("%d\n", q[head - 1]);
        
        else{
            q[head] = 0;
            // 문자로 받아온다. 정수형으로 변환하기 위해 ASCII TABLE의 '0' 값을 빼준다.
            for(i = strlen("push "); i < strlen(command); ++i){
                q[head] += command[i] - '0';
                // 자리수 분리를 위한 과정 ex) 12: 1 -> 10 -> 10 + 2 -> 120           
                q[head] *= 10;
            }
            q[head] /= 10; // ex) 12: 120 -> 12
            head++;
        }
    }
    return 0;
}