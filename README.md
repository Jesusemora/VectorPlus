# VectorPlus
Matrix library for openGL

Vector Plus is a c++ header library for use with opengl. it is meant to provide the math required to perform 3d transformations as well as usefull and easy to use classes to simplify the work of the programmer when creating an opengl engine.

This library was created as I was making my own game engine, then it grew in size and I thought about using GitHub to keep a list of changes made to the file. I'm continuing to make said game engine, so the library should continue to grow and work with no issues.

## Prerequisites
C++ 11

The file TexturePlus.h uses the SOIL library for loading textures into opengl, so it must be included in the compiler flags. This file is optional.

## Installation
Just download the file VectorPlus.h and include it in your program

`
#include "Object/VectorPlus.h"
`

## Classes

**Vector2**: for use in 2D, UI and to store UVs.

**Vector3**: for use in 3D, to store vertex positions, normals, tangents, object positions and others.

**Vector4**: easily converted to array of `float[4]`, compatible with `Matrix4x4`. can be generated from `Vector3`.

**Quaternion**: for use in rotations.

**Matrix4x4**: stores a matrix `float[4][4]`, for use with opengl. can interact with other classes like `Vector4` and `Quaternion`.

**Mesh**: Can store a simple mesh, supports normals, uvs, tangents and indices.

**Terrain2D**: Derived from Mesh. Stores a simple mesh and a matrix of int. For use in terrain generation and terrain editing. Can generate an *n* by *n* flat terrain. Editing of terrain is done one vertex at a time or through editing of public variables `vertices` and `uvs`.

#### TexturePlus

**Texture**: RGB or RGBA texture for use in opengl. uses the `SOIL` library for loading images.

**Skybox**:*work in progress*
