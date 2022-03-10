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

int main()
{
    int n, p = 1;
    // p(value) = index -> 숫자는 순서대로 놓여있기때문
    
    scanf("%d",&n);

    // 두 가지 수행 반복 -> 2의 제곱을 기준으로 계산 
    while(p < n) p *= 2;
    
    // n이 증가할 때마다 p(2의 제곱)을 기준으로 남게 되는 짝수가 결정됨
    // 2 * n - p ->  기준 2의 제곱 값과 얼마나 차이가 나는지 계산, p >= 2n - p
    // 최종 남게되는 값 = p이하이면서 입력 값과 차이나는 정도, 홀수는 의미 없으므로 입력의 2배한다.

    // p - n ? 그 외 : 2의 제곱 일 때
    printf("%d", p - n ? 2 * n - p : p);
    return 0;
}