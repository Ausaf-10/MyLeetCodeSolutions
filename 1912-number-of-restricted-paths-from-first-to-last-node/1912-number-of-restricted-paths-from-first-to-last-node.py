from heapq import heappop, heappush
from typing import List

MOD = 10**9 + 7
LL_INF = 10**18
class Solution:
    def __init__(self):
        self.n = 0

    def dijkstra(self, distance: List[int], src: int, adj: List[List[List[int]]]):
        pq = []
        heappush(pq, (0, src))
        distance[src] = 0

        while pq:
            dis, node = heappop(pq)
            for neighbor, wt in adj[node]:
                if dis + wt < distance[neighbor]:
                    distance[neighbor] = dis + wt
                    heappush(pq, (distance[neighbor], neighbor))
    
    def memoization(self, node: int, adj: List[List[List[int]]], distance: List[int], dp: List[int]) -> int:
        if node == self.n:
            return 1
        if dp[node] != -1:
            return dp[node]
        
        ans = 0
        for neighbor, _ in adj[node]:
            if distance[neighbor] < distance[node]:
                ans = (ans + self.memoization(neighbor, adj, distance, dp)) % MOD
        
        dp[node] = ans
        return dp[node]
    def countRestrictedPaths(self, N: int, edges: List[List[int]]) -> int:
        self.n = N
        adj = [[] for _ in range(N + 1)]
        for u, v, wt in edges:
            adj[u].append([v, wt])
            adj[v].append([u, wt])
        
        distance = [LL_INF] * (N + 1)
        dp = [-1] * (N + 1)
        self.dijkstra(distance, N, adj)
        return self.memoization(1, adj, distance, dp)