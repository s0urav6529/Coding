***************Maximum Manhattan distance between a distinct pair from N coordinates******************


|Xi – Xj| + |Yi – Yj| = max( (Xi – Yi) – (Xj – Yj),  (-Xi + Yi) – (-Xj + Yj),  (-Xi – Yi) – (-Xj – Yj), (Xi + Yi) – (Xj + Yj))

Follow the below steps to solve the problem:

Initialize two arrays sum[] and diff[].
Store the sum of X and Y coordinates i.e., Xi + Yi in sum[] and their difference i.e., Xi – Yi in diff[].
Sort the sum[] and diff[] in ascending order.
The maximum of the values (sum[N-1] – sum[0]) and (diff[N-1] – diff[0]) is the required result.
