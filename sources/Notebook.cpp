#include <iostream>
#include "Notebook.hpp"
#include <string>
#include "Direction.hpp"

int const LOWLIMIT = 32;
int const HIGHLIMIT = 126;
int const LINELIMIT1 = 100;
int const LINELIMIT2 = 99;

using namespace std;


namespace ariel{

    void Notebook::write(int page, int row, int col, Direction dir, string str){
        if(page < 0 || row < 0 || col < 0 || col > LINELIMIT2){
            throw invalid_argument("Invalid arguments");
        }

        for(unsigned int i = 0; i < str.length(); i++){
            if(str[i] == '~' || str[i] < LOWLIMIT || str[i] > HIGHLIMIT){
                throw invalid_argument("Can not use this char");   
            }
        }

        if(str.length() + (unsigned int)col > LINELIMIT1 && dir == Direction::Horizontal){
            throw invalid_argument("Out of bounds");
        }

        if(str.length() <= 0){
            throw invalid_argument("The text is empty");
        }

        if(!this->notebook.contains(page)){
            Page new_page;
            this->notebook.insert({page, new_page});
        }
        this->notebook[page].write(row, col, dir, str);
    }

    string Notebook::read(int page, int row, int col, Direction dir, int size){
        string read;
        if(page < 0 || row < 0 || col < 0 || col > LINELIMIT2){
            throw invalid_argument("Invalid arguments");
        }

        if(col + size > LINELIMIT1 && dir == Direction::Horizontal){
            throw invalid_argument("Invalid place");
        }

        if(size < 0){
            throw invalid_argument("The size of the text not valid");
        }

        if(!this->notebook.contains(page)){
            for(int i = 0; i < size; i++){
                if(dir == Direction::Vertical){
                    read += "_\n";
                }
                else{
                    read += "_";
                }
            }
            return read;
        }
        return this->notebook[page].read(row, col, dir, size);
    }

    void Notebook::erase(int page, int row, int col, Direction dir, int size){
        if(page < 0 || row < 0 || col < 0 || size < 0 || col > LINELIMIT2){
            throw invalid_argument("Invalid arguments");
        }

        if(size + col > LINELIMIT1 && dir == Direction::Horizontal){
            throw invalid_argument("Out of bounds");   
        }

        if(!this->notebook.contains(page)){
            Page new_page;
            this->notebook.insert({page, new_page});
        }
        this->notebook[page].erase(row, col, dir, size);
    }

    string Notebook::show(int page){
        if(page < 0){
            throw invalid_argument("Such a page does not exist");
        }
        return this->notebook[page].show(page);
    }
}