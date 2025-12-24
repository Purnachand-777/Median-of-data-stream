# Median of Data Streams

## Description
Real-time median calculation for streaming data using two-heap approach. [file:2]

## Features
- Max-heap (lower half), min-heap (upper half)
- Automatic balancing (size diff ≤1)
- O(log n) addNumber/getMedian

## Algorithm
1. Add to maxHeap if ≤ top or empty; else minHeap
2. Rebalance if imbalance >1
3. Median: avg roots (even) or maxHeap.top (odd) [file:2]

## Requirements
- C++11+ compiler (g++)
- <bits/stdc++.h> for priority_queue

## Build & Run
1. `g++ median_finder.cpp -o median_finder`
2. `./median_finder`

## Applications
- Network latency monitoring
- Financial trading trends
- IoT sensor filtering [file:2]
