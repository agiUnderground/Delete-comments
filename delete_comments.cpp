//
// Created by Alexander Lemeza on 12/8/15.
//

#include "delete_comments.h"
#include <fstream>
#include <boost/regex.hpp>

CommentDeleter::CommentDeleter(const std::string inputFile, const std::string outputFile) {
    inputFile_ = inputFile;
    outputFile_ = outputFile;
}

bool CommentDeleter::deleteComment(int mode) {
    if( mode == 0 || mode == 1 || mode == 2){
        mode_ = mode;
    }else{
        mode = 0;
    }

    std::ifstream fin(inputFile_, std::ios_base::in);
    std::ofstream fout(outputFile_, std::ios_base::out | std::ios_base::trunc);
    boost::regex reg("//.*");
    boost::regex reg2("\\/\\*[^(\\/\\*.*\\*\\/)]*\\*\\/");
    std::string replace{""};

    if( !fin.is_open()){
        std::cout << "\nIO ERROR. File not exist or can`t be open" << std::endl;
        return false;
    }else {
        while (!fin.eof()) {
            getline(fin, buffer);
            secondBuffer += buffer + "\n";
        }
        switch (mode) {
            case 0:
                secondBuffer = boost::regex_replace(secondBuffer, reg, replace, boost::match_not_dot_newline | boost::format_perl);
                secondBuffer = boost::regex_replace(secondBuffer, reg2, replace, boost::match_default | boost::format_perl);
                fout << secondBuffer;
                break;
            case 1:
                secondBuffer = boost::regex_replace(secondBuffer, reg, replace, boost::match_not_dot_newline | boost::format_perl);
                fout << secondBuffer;
                break;
            case 2:
                secondBuffer = boost::regex_replace(secondBuffer, reg2, replace, boost::match_default | boost::format_perl);
                fout << secondBuffer;
                break;
        }
        fin.close();
        fout.close();
        return true;
    }
}