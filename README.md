# VectorPlus
Matrix library for openGL

Vector Plus is a c++ header library for use with opengl. it is meant to provide the math required to perform 3d transformations as well as usefull and easy to use classes to simplify the work of the programmer when creating an opengl engine.

This library was created as I was making my own game engine, then it grew in size and I thought about using GitHub to keep a list of changes made to the file. I'm continuing to make said game engine, so the library should continue to grow and work with no issues.

## Prerequisites
This library contains a class that uses the SOIL library for loading textures, so it must be included in the compiler flags. I might separate the Texture class into a different file in the future. 

## Installation
Just download the file VectorPlus.h and include it in your program

## Global variables
`const double PI`

`const double radian`

`const double TOLERANCE`

## Classes
***
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

___
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

`Vector3 Cross(Vector3 a, Vector3 b)` returns the cross product of a and b

`Vector3 Lerp(Vector3 a, Vector3 b)` returns the middle point between a and b, equivalent to glsl mix(a, b, 0.5) or cg lerp(a, b, 0.5)

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

___
### Vector4

#### Variables

`float pos[4]` naked array containing the values of Vector4

`float &x` reference to the first  element of `pos[]`. can be used as `myVector4.x`.

`float &y` reference to the second element of `pos[]`. can be used as `myVector4.y`.

`float &z` reference to the third  element of `pos[]`. can be used as `myVector4.z`.

`float &w` reference to the fourth element of `pos[]`. can be used as `myVector4.w`.

#### public methods

`void toArray(float (&obj)[4])` fills a float array of size 4 `obj` with the values of the current `Vector4`

`float Magnitude()` returns non sqr magnitude of current `Vector4`

`float sqrMagnitude()` returns sqr magnitude of current `Vector4`

`void Normalize()` normalizes current `Vector4`

`void QNormalize()` normalizes current `Vector4` treating it as a quaternion

`Vector3 normalized` returns the normalized version of current `Vector3`

#### static methods

`float fastDistance(Vector4 a, Vector4 b)` returns the distance between a and b in a tiled space ( like chess ). *probably useless since it measures in 4 dimensions*

`float Distance(Vector4 a, Vector4 b)` returns the exact distance between a and b. *probably useless since it measures in 4 dimensions*

`float Dot(Vector4 a, Vector4 b)` returns the dot product of a and b

#### constructors

`Vector4(float x, float y, float z, float w)` generates a `Vector4` containing the values `x`, `y`, `z` and `w`.

`Vector4` generates a `Vector4` filled with (0, 0, 0, 1) wihtout parameters

`Vector4(float (&obj)[4])` initializes `Vector4` from an array of `float` of size 4

#### operators

`operator+` adds two `Vector4`s

`operator-` substracts two `Vector4`s

`operator+=` adds the values of `Vector4` to current

`operator-=` substracts the values of `Vector4` from current

`operator*` multiplies current `Vector4` by a `float`

`operator/` divides current `Vector4` by a `float`

`operator+` adds `float` to every value of current `Vector4`

`operator-` substracts `float` from every value of current `Vector4`

`operator*=` multiplies every value of current Vector4 by `float`

`operator/=` divides every value of current `Vector4` by `float`

`operator==` returns `true` if two Vector4s are equal and `false` if they are different

`operator=` assigns a `Vector4` *or* array of `float` of size 4 *or* `Vector3` to the current Vector4

`operator[i]` returns the value at position `i`. *read only*

___
### Matrix4x4

#### Variables

`Vector4 pos[4]` naked array containing the values of Matrix4x4.the values are stored as an array of Vector4, so it is posible to do MyMatrix.x.x to access individual elements of the matrix or MyMatrix.x to access a Vector4. *this is mostly used internally, use x y z w whenever posible*

`Vector4 &x` reference to the first  element of `pos[]`. can be used as `myVector4.x`.

`Vector4 &y` reference to the second element of `pos[]`. can be used as `myVector4.y`.

`Vector4 &z` reference to the third  element of `pos[]`. can be used as `myVector4.z`.

`Vector4 &w` reference to the fourth element of `pos[]`. can be used as `myVector4.w`.

#### public methods

`void mulMatrix(Matrix4x4 obj)` multiplies the current `Matrix4x4` by the `Matrix4x4` obj, performing matrix multiplication. this function adds the values to the current `Matrix4x4`.

`void toArray(float (&obj)[4][4])` fills a float matrix of size `[4][4]` `obj` with the values of the current `Matrix4x4`

`void Rotate(float phi, float theta, float psi)` rotates current `Matrix4x4` using euler axes, in ranges between -1 and 1

`void Rotate(Vector3 euler)` rotates current `Matrix4x4` using euler axes, in ranges between -1 and 1

`void Rotate(Vector4 quaternion)` rotates current `Matrix4x4` using a quaternion. *currently does nothing. work in progress*

`void Translate(Vector3 translation)` translates the current `Matrix4x4` in the directions given by `Vector3`

`void Translate(float x, float y, float z)` translates the current `Matrix4x4` in the directions **x**, **y** and **z**

#### static variables

```
Matrix4x4 Identity
```

a `Matrix4x4` containing an identity matrix.

#### static methods

`Matrix4x4 Euler(float phi, float theta, float psi)` generates and returns a `Matrix4x4` given euler rotation in axes **x**, **y** and **z**

`Matrix4x4 EulerRotation(float x, float y, float z)` generates and returns a `Matrix4x4` given euler rotation in axes **x**, **y** and **z**, but using values between -1 and 1 for rotation

`Matrix4x4 QuaternionRotation(Vector4 quaternion)` converts the Quaternion quaternion into a `Matrix4x4` for use in opengl.

`Matrix4x4 QuaternionRotation(float i, float j, float k, float L)` converts the Quaternion formed by `i, j, k, L` into a `Matrix4x4` for use in opengl.

`Matrix4x4 QuaternionRotation(Vector3 euler)` generates a `Matrix4x4` from a quaternion generated from euler axes. for use in opengl.

`Matrix4x4 QuaternionRotation(float rx, float ry, float rz)` generates a `Matrix4x4` from a quaternion generated from euler axes. for use in opengl.

`Vector4 QuaternionEuler(Vector3 axes)` generates a quaternion from euler axes.

 

`Matrix4x4 Translation(float x, float y, float z)` generates and returns a translation matrix

`Matrix4x4 Translation(Vector3 translation)`       generates and returns a translation matrix

 

`Matrix4x4 Scalation(float x, float y, float z)` generates and returns an uneven scale matrix

`Matrix4x4 Scalation(Vector3 scale)` generates and returns an uneven scale matrix

`Matrix4x4 Scalation(float scale)` generates and returns an even scale matrix (equal in every direction).

 

`Matrix4x4 Perspective(float FOV, float near, float far)` generates and returns a `Matrix4x4` to be used as a perspective matrix in opengl.

`Matrix4x4 getIdentityMatrix()` returns an identity matrix

 

`Matrix4x4 LookAt(Vector3 position, Vector3 target, Vector3 upDirection)` *work in progress*

`Matrix4x4 Direction(float (&Mat)[4][4])` *work in progress*

#### constructors

`Matrix4x4(Vector4 x, Vector4 y, Vector4 z, Vector4 w)` generates a `Matrix4x4` containing the Vector4s `x`, `y`, `z` and `w`.

`Matrix4x4` generates a `Matrix4x4` containing an identity matrix, wihtout parameters

`Matrix4x4(float (&obj)[4][4])` initializes `Matrix4x4` from an matrix of `float` of size `[4][4]`

`Matrix4x4(float (&x)[4], float (&y)[4], float (&z)[4], float (&w)[4])` initializes `Matrix4x4` from 4 arrays of `float` of size 4

#### operators

`operator+` adds two `Matrix4x4`s

`operator-` substracts two `Matrix4x4`s

`operator+=` adds the values of `Matrix4x4` to current

`operator-=` substracts the values of `Matrix4x4` from current


`operator*` multiplies a `Matrix4x4` by another `Matrix4x4`, performing matrix multiplication.

`operator*` multiplies a `Matrix4x4` by a matrix of float of size `[4][4]`, performing matrix multiplication.

`operator*` multiplies a `Matrix4x4` by a `Vector4`, performing matrix multiplication and returning a `Vector4`


`operator==` returns `true` if two Matrix4x4s are equal and `false` if they are different

`operator=` assigns a `Matrix4x4` *or* matrix of `float` of size `[4][4]` to the current `Matrix4x4`

`operator[i]` returns the value at position `i`. *read only*

___
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

___
### KX_Rotation
interface for rotations
*work in progress*
### Component
*work in progress*
### KX_Vgroup
*work in progress*
___
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

___
### RawMesh
not currently in use
___
### UI_Transform
*work in progress*
