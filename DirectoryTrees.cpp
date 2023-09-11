// DirectoryTrees
// By: Sina Tashakkori, QVLx Labs

#include <iostream>
#include <fstream>
#include <filesystem>
#include <system_error>

/*
 * Recurse starting at the inPath and determine encountered file types and write appropriately to outFile
 */
void writeDirectoryTree(const std::filesystem::path& directoryPath, std::wofstream& outFile, int indentLevel = 0) {
    if (std::filesystem::is_directory(directoryPath)) { // Directories
        outFile << std::wstring(indentLevel * 2, L' ') << L"[D] " << directoryPath.filename() << std::endl;
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            try {
                writeDirectoryTree(entry, outFile, indentLevel + 1);
            }
            catch (const std::system_error& e) {
                std::wcerr << L"Error while processing '" << entry.path() << L"': " << e.what() << std::endl;
            }
        }
    }
    else if (std::filesystem::is_regular_file(directoryPath)) { // Files
        outFile << std::wstring(indentLevel * 2, L' ') << L"[F] " << directoryPath.filename() << std::endl;
    }
    else if (std::filesystem::is_symlink(directoryPath)) { // Symlinks
        outFile << std::wstring(indentLevel * 2, L' ') << L"[S] " << directoryPath.filename() << std::endl;
    }
    else { // Others
        outFile << std::wstring(indentLevel * 2, L' ') << L"[O] " << directoryPath.filename() << std::endl;
    }
}

/*
* Get a line of stdin from the user
*/
std::wstring getUserInput(const std::wstring& prompt) {
    std::wstring userInput;
    std::wcout << prompt;
    std::getline(std::wcin, userInput);
    return userInput;
}

/*
* Print error message then exit with error status
*/
void error(const std::wstring& message) {
    std::wcerr << message << std::endl;
    exit(1);
}

/*
* Print as many strings as you want concatenated
*/
template<typename... Args>
void printStrings(Args... args) {
    (std::wcout << ... << args) << std::endl;
}

int main() {
    std::wstring inPath = getUserInput(L"Enter the path to the directory: ");

    std::filesystem::path dirPath(inPath);

    if (!std::filesystem::exists(dirPath)) { error(L"Path does not exist."); }

    std::wstring outPath = getUserInput(L"Enter the output file or directory path: ");

    std::filesystem::path outputPath(outPath);

    std::wofstream outFile;

    if (std::filesystem::is_directory(outputPath)) { outputPath /= L"directory_tree.txt"; }

    try {
        outFile.open(outputPath, std::ios::out | std::ios::binary);

        if (!outFile.is_open()) { error(L"Failed to open the output file."); }

        writeDirectoryTree(dirPath, outFile);

        printStrings(L"Directory tree has been saved to '", outputPath.wstring(), L"'.");
    }
    catch (const std::system_error& e) {
        printStrings(L"An error occurred: ", e.what());
        return 1;
    }

    return 0;
}
