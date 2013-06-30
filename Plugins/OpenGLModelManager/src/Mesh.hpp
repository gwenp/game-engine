#ifndef DEF_MESH
#define DEF_MESH

#include "../../src/api/Interfaces/OpenGL/IOpenGLModelManager.hpp"
#include "../../src/api/Interfaces/OpenGL/IOpenGL.hpp"
#include <iostream>
#include <string>

#include <glm/glm.hpp>

#include <cstdio>
#include <cstring>

class Mesh
{
public:
    Mesh();
    ~Mesh();

    void onLoad();
    void draw();

    bool loadOBJ(const char * path, std::vector < glm::vec3 > & out_vertices, std::vector < glm::vec2 > & out_uvs, std::vector < glm::vec3 > & out_normals);
private:
    GLuint uvbuffer;
    GLuint vertexbuffer;
    std::vector< glm::vec3 > vertices;
    std::vector< glm::vec2 > uvs;
    std::vector< glm::vec3 > normals; // Won't be used at the moment.
};

#endif /* DEF_MESH */
