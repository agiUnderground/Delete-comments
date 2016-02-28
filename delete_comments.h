/*
 * Created by Alexander Lemeza on 12/8/15.
 *
 * Класс CommentDeleter принимает два аргумента:
 * первый - полный путь к файлу(включая имя), который будет отформатирован [обязательный аргумент]
 * второй - полный путь к результирующему файлу                            [необязательный аргумент]
 * В случает если второй аргумент не будет указан, в директории откуда была вызвана программа
 * будет создан стандартный результирующий файл defaultOutput.txt
 *
 * Объект класса CommentDeleter вызывает метод deteleComment(arg), где arg - 0, 1, 2
 * 0 - удаление и однострочных и многострочных комментариев
 * 1 - удаление только однострочных комментариев
 * 2 - удаление только многострочных комментариев
 *
 * Пример использования:
 *
 * CommentDeleter myDeleter{"/home/agi/input.txt"};
 * myDeleter.deleteComment();                           // по умолчанию будет использован режим 0
 */
#ifndef TESTPROJECT_DELETE_COMMENTS_H
#define TESTPROJECT_DELETE_COMMENTS_H

#include <iostream>


class CommentDeleter{
private:
    int mode_;
    std::string inputFile_;
    std::string outputFile_;
    std::string buffer;
    std::string secondBuffer;
public:
    CommentDeleter( const std::string inputFile, const std::string outputFile = "defaultOutput.txt" );
    virtual bool deleteComment( int mode = 0 );
};

#endif //TESTPROJECT_DELETE_COMMENTS_H