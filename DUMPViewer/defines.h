#ifndef DEFINES
#define DEFINES

#include <QApplication>


#define TEXTURES_DIR QApplication::applicationDirPath()+"/../../DUMPViewer/models/textures"
#define SHADERS_DIR QApplication::applicationDirPath()+"/../../DUMPViewer/shaders"
#define MODEL_MATRIX_BUFFER_SIZE sizeof(glm::mat4)*2
#define MAT_BUFFER_SIZE sizeof(glm::vec3)*4+sizeof(float)
#define LIGHT_BUFFER_SIZE sizeof(glm::vec4)*5+sizeof(float)*5
#define NUM_BONES_PER_VERTEX 4

typedef float texCoordinates;
typedef unsigned int arraySize;
typedef float vertexCoordinates;

//макрос проверки на отсутствие указателя ядра. Должен выполнятся первым в функциях, обращающихся к ядру
#define IS_CORE_POINTER if(core==NULL){\
                            qWarning("Core pointer is not defined.");\
                            return;\
                        };

enum meshType{
    MESH_NOMESH,
    MESH_ORIGINAL,
    MESH_MAIN_MESH,
    MESH_LOD1,
    MESH_LOD2,
    MESH_LOD3,
    MESH_LOD4
};




#endif // DEFINES

