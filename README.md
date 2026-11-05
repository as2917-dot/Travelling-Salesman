# Travelling Salesman Problem

A small C program that demonstrates the nearest-neighbour heuristic for the Travelling Salesman Problem. It randomly generates n city coordinates based on user input and prints a route that repeatedly visits the nearest unvisited city, then returns to the starting city. The heuristic is simple and fast operating on O(N^2) time complexity but does not guarantee the shortest possible route.

## Build and run

```sh
gcc travellingSalesman.c -o travellingSalesman -lm
./travellingSalesman
```
