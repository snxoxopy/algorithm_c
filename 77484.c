/*
---
title:  "[C] PRGRMS_77484_로또의 최고 순위와 최저 순위"
excerpt: "https://programmers.co.kr/learn/courses/30/lessons/77484"
toc: true
toc_sticky: true
toc_label: "Contents"
categories:
  - algorithm
tags:
  - Programmers
---

문제이해: 분
구현: 분
Debug: 분
참고자료
https://velog.io/@gyeongmin/Programmers-C-%EB%A1%9C%EB%98%90%EC%9D%98-%EC%B5%9C%EA%B3%A0-%EC%88%9C%EC%9C%84%EC%99%80-%EC%B5%9C%EC%A0%80-%EC%88%9C%EC%9C%84
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 나올 수 있는 숫자
int arr_num[46];

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);

    // 순위 배열
    int arr_ord[7] = {6, 6, 5, 4, 3, 2, 1};
    int cnt_nums = 0;
    int i, j;
    
    // 나온 숫자에 해당하는 배열 값 증가시키기
    for(int i = 0; i < lottos_len; i++){
        arr_num[lottos[i]]++;
    }

    // 일치 숫자 개수 세기
    for(i = 0; i < win_nums_len; ++i){
        // arr_num[당첨번호]가 0이 아니면 맞춘 것
        if(arr_num[win_nums[i]]) cnt_nums++;
    }

    // 등수 계산 answer[0] = 최고 등수, answer[1] = 최저 등수
    // 0이 모두 정답일때 맞춘 숫자 = cnt_nums + arr_nums[0]
    answer[0] = arr_ord[cnt_nums + arr_num[0]];
    answer[1] = arr_ord[cnt_nums];

    return answer;
}

int main(void){
    int lottos[] = {44, 1, 0, 0, 31, 25};
    int win_nums[] = {31, 10, 45, 1, 6, 19};
    int i;

    // solution(lottos, sizeof(lottos)/sizeof(int), win_nums, sizeof(win_nums)/sizeof(int));
    // printf("%lu\n",sizeof(solution(lottos, sizeof(lottos)/sizeof(int), win_nums, sizeof(win_nums)/sizeof(int))))/sizeof(int);
    for(i = 0; i < 2; ++i){
        printf("%d\n", solution(lottos, sizeof(lottos)/sizeof(int), win_nums, sizeof(win_nums)/sizeof(int))[i]);
    }
    return 0;
}