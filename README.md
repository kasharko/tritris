# tritris — Triangular Tetris (Work in Progress)

A Tetris-like falling-piece game played on a triangular grid grid. Written in C++ using SFML for rendering.

## Concept

Standard Tetris uses square tiles on a rectangular grid. This project explores the same falling-piece mechanic on a grid of triangles, where pieces are composed of triangular cells arranged in triangular coordinate space.

## Current State

**Work in progress.** The project currently implements:

- Triangular grid representation
- Coordinate transformation from triangular (hexagonal representation) to Cartesian space
- Basic figure/piece definition 
- SFML window initialisation and render loop
- Rendering of triangular pieces on screen

## Dependencies

- [SFML](https://www.sfml-dev.org/) ≥ 3.0
- CMake ≥ 3.21
- g++ with C++17 support

## Build

```bash
mkdir build && cd build
cmake ..
make
```
