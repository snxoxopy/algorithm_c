/*
---
title:  "[C] BOJ_2164"
excerpt: "https://www.acmicpc.net/problem/2164"
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

#define size 500000

int main(){
    /* write you code here */

    int n, i, rear, q[size];
    int front = 0;
    scanf("%d", &n);

    // 숫자 queue에 담기
    for(i = 0; i < n; ++i) q[i] = i + 1;
    rear = n - 1;

    while(1){
        
        // header 이동
        front = (front + 1) % n;
        if(rear == front) break;
        rear = (rear + 1) % n;

        
        // 맨위 카드 맨 아래로 옮기기
        q[rear] = q[front];

        // 맨위 카드 버리기
        front = (front + 1) % n;
        if(rear == front) break;

    }
    
    printf("%d\n", q[rear]);
    return 0;
}