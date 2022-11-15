#include "FileManager.h"

using namespace std;

string FileManager::ReadFile(string path) {
    ifstream file;
    file.open(path);
    if (!file) {
        std::cerr << "Error: file not found at path: " << path << std::endl;
        exit(1);
    }
    string line;
    string res;
    while (getline(file, line)){
        res += line;
    }
    file.close();
    return res;
}

