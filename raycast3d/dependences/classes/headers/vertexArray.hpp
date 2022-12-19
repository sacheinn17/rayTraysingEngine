#ifndef VERTEX_ARRAY_HEADER
#define VERTEX_ARRAY_HEADER

#include "vertexBuffer.hpp"

class vertexArray
{

public:
    unsigned int ID;
    vertexArray();
    ~vertexArray();

    void addBuffer(vertexBuffer vb, unsigned int layout,unsigned int count, unsigned int TYPE, unsigned int NORMALIZED,unsigned int offset);

    void enable() const;
    void create() const;
    void bind() const;
    void unbind() const;
    void deleteVao() const;

};

#endif