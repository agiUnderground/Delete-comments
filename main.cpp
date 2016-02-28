#include <iostream>
#include "delete_comments.h"

using namespace std;

int main() {
    string path;
    cout << "Enter a full path to the file: ";
    cin >> path;

    CommentDeleter myDeleter{path};
    if(myDeleter.deleteComment())
        std::cout << "\nAll comments was deleted successfuly" << endl;
    return 0;
}