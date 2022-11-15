#ifndef OPENGLENGINE_FILEMANAGER_H
#define OPENGLENGINE_FILEMANAGER_H

#include <string>
#include <iostream>
#include <fstream>

class FileManager {
public:
    static std::string ReadFile(std::string path);
};


#endif //OPENGLENGINE_FILEMANAGER_H
