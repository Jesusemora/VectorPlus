# VectorPlus
Matrix library for openGL

Vector Plus is a c++ header library for use with opengl. it is meant to provide the math required to perform 3d transformations as well as usefull and easy to use classes to simplify the work of the programmer when creating an opengl engine.

This library was created as I was making my own game engine, then it grew in size and I thought about using GitHub to keep a list of changes made to the file. I'm continuing to make said game engine, so the library should continue to grow and work with no issues.

## Prerequisites
C++ 11

This library contains a class that uses the SOIL library for loading textures, so it must be included in the compiler flags. I might separate the Texture class into a different file in the future. 

## Installation
Just download the file VectorPlus.h and include it in your program

## Classes

**Vector2**: for use in 2D, UI and to store UVs.

**Vector3**: for use in 3D, to store vertex positions, normals, tangents, object positions and others.

**Vector4**: easily converted to array of `float[4]`, compatible with `Matrix4x4`. can be generated from `Vector3`.

**Quaternion**: for use in rotations.

**Matrix4x4**: stores a matrix `float[4][4]`, for use with opengl. can interact with other classes like `Vector4` and `Quaternion`.

**Texture**: RGB or RGBA texture for use in opengl. uses the `SOIL` library for loading images.

**Skybox**:*work in progress*

**Mesh**: Can store a simple mesh, supports normals, uvs, tangents and indices.
