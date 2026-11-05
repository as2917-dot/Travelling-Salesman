# Travelling Salesman

A small C program that demonstrates the nearest-neighbour heuristic for the Travelling Salesman Problem. It randomly generates 10 city coordinates and prints a route that repeatedly visits the nearest unvisited city, then returns to the starting city. The heuristic is simple and fast, but does not guarantee the shortest possible route.

## Build and run

```sh
gcc travellingSalesman.c -o travellingSalesman -lm
./travellingSalesman
```

Each run generates a different set of city coordinates.