// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of
// {"a.jpg", "b.jpg"} no global(or statics!) variables allowed
#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <new>

struct MyFile {
    FILE* file;

    MyFile(FILE* file) : file(file) {
    }

    ~MyFile() {
        fclose(file);
    }
};

class MyException : public std::exception {
  protected:
    std::string error;

  public:
    MyException(std::string error) : error(error){};
    const char* what() const noexcept override {
        return error.c_str();
    }
};

class OpenFileException : public MyException {
  public:
    OpenFileException(std::string filename) : MyException("can't open file " + filename) {
    }
};
class ReadFileException : public MyException {
  public:
    ReadFileException(std::string filename) : MyException("can't read file " + filename) {
    }
};
class WriteFileException : public MyException {
  public:
    WriteFileException(std::string filename) : MyException("can't write file " + filename) {
    }
};

class CommandManager {
  private:
    std::map<std::string, std::function<void(std::vector<std::string>)>> commands;
    std::map<std::string, unsigned> countCmd;

  public:
    void add(std::string name, std::function<void(std::vector<std::string>)> fn);
    unsigned GetCount(std::string cmd);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at
    // https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};

void CommandManager::add(std::string name, std::function<void(std::vector<std::string>)> fn) {
    commands[name] = fn;
    countCmd[name] = 0;
}

unsigned CommandManager::GetCount(std::string cmd) {
    if (commands.find(cmd) == commands.end()) {
        return 0;
    } else {
        return countCmd[cmd];
    }
}

void CommandManager::run() {
    while (true) {
        char line[100];
        std::cin.getline(line, 100);

        std::string cmd = "";
        std::vector<std::string> param;
        char* p = strtok(line, " \n");
        while (p) {
            std::string word((const char*) p);

            if (cmd == "") {
                cmd = word;
            } else {
                param.push_back(word);
            }

            p = strtok(nullptr, " \n");
        }

        if (cmd == "stop")
            break;

        if (commands.find(cmd) == commands.end()) {
            std::cout << "CAN'T FIND THE COMMAND!\n";
        } else {
            try {
                countCmd[cmd]++;
                commands[cmd](param);
            } catch (MyException& e) {
                fprintf(stderr, "%s\n", e.what());
            } catch (std::bad_alloc& e) {
                fprintf(stderr, "%s\n", e.what());
            }
        }
    }
}

int main() {
    CommandManager manager;

    // prints pong!
    auto ping = [](std::vector<std::string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](std::vector<std::string> args) { printf("counted %u args\n", (unsigned) args.size()); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [](std::vector<std::string> args) {
        std::string filename = args[0];
        FILE* file           = fopen(filename.c_str(), "a");
        if (file == 0) {
            throw OpenFileException(filename);
        } else {
            MyFile f(file);
            for (int i = 1; i < args.size(); i++) {
                if (fprintf(file, "%s ", args[i].c_str()) < 0) {
                    throw WriteFileException(filename);
                }
            }
        }
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [&manager](std::vector<std::string> args) { std::cout << manager.GetCount(args[0]) << '\n'; };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [](std::vector<std::string> args) {
        FILE* file1 = fopen(args[0].c_str(), "rb");
        if (file1 == 0) {
            throw OpenFileException(args[0]);
        }
        MyFile f1(file1);

        FILE* file2 = fopen(args[1].c_str(), "wb");
        if (file2 == 0) {
            throw OpenFileException(args[1]);
        }
        MyFile f2(file2);

        char ch[1];
        while (true) {
            int nr = fread(ch, 1, 1, file1);
            if (feof(file1))
                break;
            if (nr == 0) {
                throw ReadFileException(args[0]);
            }
            if (fwrite(ch, 1, 1, file2) != 1) {
                throw WriteFileException(args[1]);
            }
        }
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](std::vector<std::string> args) {
        std::sort(args.begin(), args.end(), [](std::string a, std::string b) { return a.length() < b.length(); });
        for_each(args.begin(), args.end(), [](std::string s) { std::cout << s << ' '; });
        std::cout << '\n';
    };
    manager.add("sort_size", sort_size);

    // add one more command of anything you'd like
    auto reverse = [](std::vector<std::string> args) {
        for (int index = args.size() - 1; index >= 0; index--) {
            std::string temp = args[index];
            std::reverse(temp.begin(), temp.end());
            std::cout << temp << ' ';
        }
        std::cout << '\n';
    };
    manager.add("reverse", reverse);

    auto alloc = [](std::vector<std::string> args) {
        int size = stoi(args[0]);
        char* myArray = new char[size];
    };
    manager.add("alloc", alloc);

    manager.run();

    /*
    Update the lambda lab solution in the following way:
    - create a class MyException that inherits std::exception, takes a std::string in the constructor, and returns the
    string in .what();
    - create 3 exception classes that inherit MyException: OpenFileException, ReadFileException, WriteFileException;
    - OpenFileException shall take the file name in the constructor, and format it into saying `can't open file {}`;
    - ReadFileException and WriteFileException shall take the file name in the constructor, and format it into saying
    'can't read/write file {}';
    - commands will not capture `number_of_errors` anymore;
    - every command will check if any IO error occurs (open, read, write), and throw the appropriate exception;
    - create a new command that if called with certain parameters will allocate a huge amount (or negative) of memory,
    in order for the allocator to throw std::bad_alloc;
    - the `run` function will catch the exceptions, and print the exception strings to stderr;
    */
}