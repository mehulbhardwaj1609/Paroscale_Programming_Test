#include <iostream>
#include <filesystem>
using namespace std;

void countFilesAndDir(const filesystem::path& dirPath, int& fileCount, int& dirCount) {
    for (const auto& entry : filesystem::directory_iterator(dirPath)) {
        if (entry.is_regular_file()) {
            fileCount++;
        } else if (entry.is_directory()) {
            dirCount++;
            countFilesAndDir(entry.path(), fileCount, dirCount);
        }
    }
}

int main() {
    filesystem::path Path = "";//enter your path directory here

    int totalFile = 0;
    int totalDir = 0;

    countFilesAndDir(Path, totalFile, totalDir);

    cout << "Total files: " << totalFile << endl;
    cout << "Total directories: " << totalDir << endl;

    return 0;
}
