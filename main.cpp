#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ifstream inputFile(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\ImFollowing.txt)");
    fstream outputFile(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\IMFollowingCLean.txt)");

    ifstream inputFile2(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\FollowingMe.txt)");
    fstream outputFile2(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\FollowingMeOneLine)");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    streampos fileSize = inputFile.tellg(); // Get the file size.

    if(fileSize == 0){
        string line;
        bool isProfilePictureLine = false;

        while (getline(inputFile, line)) {
            if (line.find("profile picture") != string::npos) {
                isProfilePictureLine = true;
            } else if (isProfilePictureLine) {
                outputFile << line << endl;
                isProfilePictureLine = false;
            }
        }
    }

    //Sort Following Me into single line file for find built in function
    streampos fileSize2 = inputFile2.tellg(); // Get the file size.

    if(fileSize2 == 0){
        string line;
        bool isProfilePictureLine = false;

        while (getline(inputFile2, line)) {
            if (line.find("profile picture") != string::npos) {
                isProfilePictureLine = true;
            } else if (isProfilePictureLine) {
                outputFile2 << line;
                isProfilePictureLine = false;
            }
        }
    }

    inputFile.close();
    outputFile.close();
    inputFile2.close();
    outputFile2.close();
    ifstream inputFile3(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\ImFollowing.txt)");
    fstream outputFile3(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\IMFollowingCLean.txt)");
    ifstream inputFile4(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\FollowingMe.txt)");
    fstream outputFile4(R"(C:\Users\1vinc\CLionProjects\FollowingINSTAA\FollowingMeOneLine)");

    string BigLine;
    getline(outputFile4,BigLine);


    //Is big line being printed?
    string line;
    while (getline(outputFile3, line)) {
        if (BigLine.find(line) == string::npos) {
            cout << line << " Doesn't Follow You! >:|" << endl;
        }
    }



    return 0;
}
