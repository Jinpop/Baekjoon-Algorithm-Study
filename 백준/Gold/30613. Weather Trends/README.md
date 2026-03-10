# [Gold II] Weather Trends - 30613 

[문제 링크](https://www.acmicpc.net/problem/30613) 

### 성능 요약

메모리: 2152 KB, 시간: 44 ms

### 분류

자료 구조, 세그먼트 트리, 집합과 맵, 트리를 사용한 집합과 맵, 우선순위 큐, 덱, 슬라이딩 윈도우, 덱을 이용한 구간 최댓값 트릭

### 제출 일자

2026년 2월 13일 00:49:36

### 문제 설명

<p>George is an aspiring meteorologist who is passionate about analyzing temperature data. He is tasked with finding the largest temperature increase that occurs within specific time frames. Your task is to help George develop an efficient algorithm to calculate such temperature increases for any time interval.</p>

<p>Given a sequence of daily temperature measurements over a period of n days, George is interested in finding the greatest temperature increase that occurs within a window of m days. In other words, he wants to identify the maximum temperature difference between two days, where the second day occurs no more than m days after the first one.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 664px; height: 344px;"></p>

### 입력 

 <p>The first line of input contains a single integer n, representing the number of available temperature measurements. The second line contains a single integer m, indicating the maximum time interval in days. The third line contains n temperature values, separated by spaces.</p>

### 출력 

 <p>Output a single real number, representing the maximum temperature increase that occurs within the specified m-day interval.</p>

<p>Your task is to implement an efficient algorithm that can solve this problem for George. Additionally, ensure that your output has an absolute or relative error of at most 10<sup>-6</sup>.</p>

