# VectorPlus
Matrix library for openGL

Vector Plus is a c++ header library for use with opengl. it is meant to provide the math required to perform 3d transformations as well as usefull and easy to use classes to simplify the work of the programmer when creating an opengl engine.

This library was created as I was making my own game engine, then it grew in size and I though about using GitHub to keep a list of changes made to the file. I'm continuing to make said game engine, so the library should continue to grow and work with no issues.

## Prerequisites
This library contains a class that uses the SOIL library for loading textures, so it must be included in the compiler flags. I might separate the Texture class into a different file in the future. 

## Installation
Just download the file VectorPlus.h and include it in your program

## Global variables
`const double PI`

`const double radian`

`const double TOLERANCE`

## Classes
### Vector2
#### Variables

`float &x` reference to the first element of `pos[]`. can be used as `myVector2.x`.

`float &y` reference to the second element of `pos[]`. can be used as `myVector2.y`.

#### public methods

`float Magnitude()` returns non sqr magnitude of current `Vector2`

`float sqrMagnitude()` returns sqr magnitude of current `Vector2`

`void Normalize()` normalizes current `Vector2`

`Vector2 normalized` returns the normalized version of current `Vector2`

#### static variables

```
Vector2 up, down, left, right, zero
```

use these to quickly obtain a "vector" in a given direction, or a `Vector2` filled with 0

#### static methods

`float fastDistance(Vector2 a, Vector2 b)` returns the distance between a and b in a tiled space ( like chess )

`float Distance(Vector2 a, Vector2 b)` returns the exact distance between a and b

`float Dot(Vector2 a, Vector2 b)` returns the dot product of a and b

`Vector2 Lerp(Vector2 a, Vector2 b)` returns the middle point between a and b, equivalent to glsl mix(a, b, 0.5) or cg lerp(a, b, 0.5)

#### constructors

`Vector2(float x, float y)` generates a `Vector2` containing the values `x` and `y`.

#### operators

`operator+` adds two `Vector2`s

`operator-` substracts two `Vector2`s

`operator+=` adds the values of `Vector2` to current

`operator-=` substracts the values of `Vector2` from current

`operator*` multiplies current `Vector2` by a `float`

`operator/` divides current `Vector2` by a `float`

`operator+` adds `float` to every value of current `Vector2`

`operator-` substracts `float` from every value of current `Vector2`

`operator*=` multiplies every value of current Vector2 by `float`

`operator/=` divides every value of current `Vector2` by `float`

`operator==` returns `true` if two Vector2s are equal and `false` if they are different

### Vector3

#### Variables

`float pos[3]` naked array containing the values of Vector3

`float &x` reference to the first  element of `pos[]`. can be used as `myVector3.x`.

`float &y` reference to the second element of `pos[]`. can be used as `myVector3.y`.

`float &z` reference to the third  element of `pos[]`. can be used as `myVector3.z`.

#### public methods

`float Magnitude()` returns non sqr magnitude of current `Vector3`

`float sqrMagnitude()` returns sqr magnitude of current `Vector3`

`void Normalize()` normalizes current `Vector3`

`Vector3 normalized` returns the normalized version of current `Vector3`

#### static variables

```
Vector3 up, down, left, right, forward, back, zero
```

use these to quickly obtain a "vector" in a given direction, or a `Vector3` filled with 0

#### static methods

`float fastDistance(Vector3 a, Vector3 b)` returns the distance between a and b in a tiled space ( like chess )

`float Distance(Vector3 a, Vector3 b)` returns the exact distance between a and b

`float Dot(Vector3 a, Vector3 b)` returns the dot product of a and b

`Vector2 Lerp(Vector3 a, Vector3 b)` returns the middle point between a and b, equivalent to glsl mix(a, b, 0.5) or cg lerp(a, b, 0.5)

#### constructors

`Vector3(float x, float y, float z)` generates a `Vector3` containing the values `x`, `y` and `z`.

`Vector3` generates a `Vector3` filled with 0 wihout parameters

#### operators

`operator+` adds two `Vector3`s

`operator-` substracts two `Vector3`s

`operator+=` adds the values of `Vector3` to current

`operator-=` substracts the values of `Vector3` from current

`operator*` multiplies current `Vector3` by a `float`

`operator/` divides current `Vector3` by a `float`

`operator+` adds `float` to every value of current `Vector3`

`operator-` substracts `float` from every value of current `Vector3`

`operator*=` multiplies every value of current Vector3 by `float`

`operator/=` divides every value of current `Vector3` by `float`

`operator==` returns `true` if two Vector3s are equal and `false` if they are different

### Vector4
### Matrix4x4
### Texture
Loads a texture in memory. it also has functions for binding textures to opengl and swaping textures. work in progress
#### Variables
`int width` width of the image

`int height` height of the image

`unsigned char* imageO` stores loaded image

`bool isAlpha` used to selected between GL_RGB and GL_RGBA

#### public methods

`void createTex(char* filePath)` loads a texture from file as RGB
`void createTex(char* filePath, bool alpha)` when alpha is used, loads a texture from file as RBGA

`void BindTexture(int id, GLuint *textureID)` binds the current texture to the location `id` using a `GLuint textureID` previously generated with `glGenTextures(`*size*`, textureID)`

`void SwapTexture(int id, GLuint *textureID)` used during render loop. assigns the current texture to the location `id` (`GL_TEXTURE0 + id`)

### KX_Rotation
interface for rotations
work in progress
### Component
work in progress
### KX_Vgroup
work in progress
### Mesh
#### Variables

`vector<float> vertices` vector containing vertex position, they are stored in the format: x y z x y z x y z

`vector<float> normals` vector containing vertex normal information, they are stored in the format: x y z x y z x y z

`vector<float> uvs` vector containing vertex uv information, they are stored in the format: u v u v u v

`vector<float> tangents` vector containing vertex tangent information, this is generated by the function `GetTangents` or `GetTangentsTriangles`. It is stored in the format: x y z x y z x y z

`vector<GLuint> indices` vector containing triangle indices, they are stored in the format: v0 v1 v2 v0 v1 v2 v0 v1 v2

`int numverts` used during loading of mesh, it contains a number equal to the sum of the size of `vertices`, `normals` and `uvs`, which divided by 8 can be multiplied by 2 or 3 to get the size of `vertices` or `uvs`.

`int numindices` number of indices, used in `glDrawElements`. Equivalent to `indices.size()`

`string name` name of the mesh

#### public methods

`void GetTangents()` generates tangents and fills the vector `tangents`. used with `glDrawElements`

`void GetTangentsTriangles()` generates tangents when `vertices` is divisible by 3. used with `glDrawArrays`. Gives bad results, should be removed eventually.

`string debug()` returns a string with the sizes of the vectors of Mesh, used for testing of model loading and general debuging.

### RawMesh
not currently in use
### UI_Transform
work in progress
