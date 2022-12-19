#ifndef VERTEX_BUFFER_CLASS
#define VERTEX_BUFFER_CLASS

#include "glad/glad.h"
#include "GLFW/glfw3.h"



class vertexBuffer{


public:
    unsigned int ID;
    vertexBuffer();
    ~vertexBuffer();

    void addData(const void* data,unsigned int size, unsigned int usage) const;
    void bind() const;
    void unBind() const;
    void Delete() const;

};


#endif