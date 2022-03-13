/*
---
title:  "[C] BOJ_11866_요세푸스_문제0"
excerpt: "https://www.acmicpc.net/problem/11866"
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
https://sedangdang.tistory.com/28
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1001

typedef struct{
    int queue[SIZE];
    int f, r;
}QueueType;

void init_q(QueueType* q){
    q->f = q->r = 0;
}

int is_full(QueueType* q){
    return ((q->r + 1) % SIZE == q -> r);

}

int is_empty(QueueType* q){
    return (q->f == q->r);
}

void push(QueueType* q, int e){
    if(is_full(q)) return;
    q->r = (q->r + 1) % SIZE;
    q->queue[q->r] = e;
}

int pop(QueueType* q){
    if(is_empty(q)) return -1;

    q->f = (q->f + 1) % SIZE;
    return q->queue[q->f];
}

int size(QueueType* q){
    if (q->f < q->r) return q->r - q->f;
    else return SIZE - q->f + q->r;
}

int main(){
    QueueType Q; init_q(&Q);

    int i, j, n, k, tmp;

    scanf("%d %d", &n, &k);

    // 배열 넣기
    for(i = 0; i < n; ++i){
        push(&Q, i + 1);
    }

    // q연산
    // 1234567
    // pop 12 push 12
    // pop 3
    // 456712
    // pop 45 push 45
    // pop 6
    // 71245
    // pop 71 push 71
    // pop 2
    // 4571

    printf("<");
    for(i = 0; i < n; ++i){
        for(j = 0; j < k - 1; ++j){
            tmp = pop(&Q);
            push(&Q, tmp);
        }
        if(size(&Q) == 1) break;
        tmp = pop(&Q);
        printf("%d, ", tmp);
    }
    printf("%d>", pop(&Q));
    return 0;
}