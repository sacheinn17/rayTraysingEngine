#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "glad/glad.h"
#include <string>
#include <fstream>
#include <iostream>

class shaderProgram
{
public:
int shaderID;

shaderProgram(const char* vertexPath,const char* fragmentPath);
void use() const;

void setfloat1(const char* uniformName, float someName);
void setfloat2(const char* uniformName, float someName[]);
void setfloat3(const char* uniformName, float someName[]);
void setfloat4(const char* uniformName, float someName[]);

void setBool(const char* uniformName, bool someName);
void setInt(const char* uniformName, bool someName);
void setDouble(const char* uniformName, bool someName);



};

#endif