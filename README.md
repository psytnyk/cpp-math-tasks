# C++ Math Tasks

Two console programs written in C++ as college coursework in higher and discrete mathematics. Each one solves a classic task: finding the inverse of a matrix and building the matrices that describe a graph.

> The text in the console is in Ukrainian.

Both programs were originally written in my 2nd year at college. The commits in this repository are small later improvements: clearer console output (aligned matrices, labels, reduced fractions) and correct display of Ukrainian text on Windows. The calculation logic is unchanged.

## Contents

- [Matrix Inverse Calculator](#matrix-inverse-calculator)
- [Graph Matrices](#graph-matrices)
- [How to run](#how-to-run)
- [Known limitations](#known-limitations)

## Matrix Inverse Calculator

`matrix.cpp`

Reads a 2x2 or 3x3 integer matrix, calculates its determinant and, if the inverse exists, prints it using the formula:

```
A^-1 = (1 / det(A)) * A*
```

where `A*` is the adjugate matrix (the transposed matrix of cofactors).

**Features**
- Determinant of 2x2 and 3x3 matrices
- Detects matrices without an inverse (determinant = 0) and reports it
- Inverse matrix shown as reduced fractions, with the minus sign always in the numerator
- Matrices are printed in aligned frames

**Example (2x2)**

Input:

```
Введіть розмір матриці (2 або 3): 2
Рядок 1: 1 2
Рядок 2: 4 6
```

Output:

```
Визначник det(A) = -2

Обернена матриця A⁻¹ (дроби скорочено):
  ┌   -3     1 ┐
  └    2  -1/2 ┘
```

Check: A × A⁻¹ gives the identity matrix.

## Graph Matrices

`graph_matrices.cpp`

Reads the number of vertices, the number of edges, the graph type and the list of edges. Then prints the adjacency matrix and the incidence matrix with labelled rows and columns (`v1, v2...` for vertices, `e1, e2...` for edges).

**Features**
- Directed (`o`) and undirected (`n`) graphs
- Adjacency matrix and incidence matrix
- Directed graphs: `1` marks the vertex an edge starts from, `-1` marks the vertex it ends in
- Supports up to 10 vertices and 20 edges, vertices are numbered from 1

**Example (undirected graph, 3 vertices, edges 1-2, 2-3, 1-3)**

Input:

```
К-ть вершин: 3
К-ть ребер: 3
Тип графа (o-орієнтований/n-неорієнтований): n
Ребро 1: 1 2
Ребро 2: 2 3
Ребро 3: 1 3
```

Output:

```
Матриця суміжності:
      │  v1  v2  v3
──────┼────────────
   v1 │   0   1   1
   v2 │   1   0   1
   v3 │   1   1   0

Матриця інцидентності:
      │  e1  e2  e3
──────┼────────────
   v1 │   1   0   1
   v2 │   1   1   0
   v3 │   0   1   1
```

## How to run

You need a C++ compiler.

**g++ (Linux, macOS, MinGW)**

```
g++ matrix.cpp -o matrix
./matrix

g++ graph_matrices.cpp -o graph_matrices
./graph_matrices
```

**Visual Studio (Windows)**

```
cl /EHsc /utf-8 matrix.cpp
.\matrix.exe

cl /EHsc /utf-8 graph_matrices.cpp
.\graph_matrices.exe
```


## Known limitations

These are learning projects, so the programs expect correct input:

- **No input validation.** Matrix size must be 2 or 3, matrix elements must be integers, the graph program supports at most 10 vertices and 20 edges, vertex numbers must be from 1 to the number of vertices, and the graph type must be a lowercase `o` or `n`.
- **Large numbers.** Values are stored as `int`, so very large matrix elements can overflow.
- **Simple graphs only.** The graph program expects no loops and no repeated edges.

Possible next step: add input validation and re-ask on invalid input.
