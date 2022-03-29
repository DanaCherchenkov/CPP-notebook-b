#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Page.hpp"

int const LINELIMIT = 100;
int const LIMIT = 101;

using namespace std;

namespace ariel{
    
    void Page::write(int row, int col, Direction dir, string str){
        int curr_row = row;
        int curr_col = col;
        for(int i = 0; i < str.length() ; i++){
            if(!this->page.contains(curr_row)){
                char* new_row = new char[LIMIT];
                for(unsigned int i = 0; i < LIMIT; i++){
                    new_row[i] = '_';
                }
                new_row[LINELIMIT] = '\0';
                this->page.insert({curr_row, new_row});
            }
            if(this->page[curr_row][curr_col] != '_'){
                throw invalid_argument("This place is taken, can not write here!");
            }
              if(dir == Direction::Horizontal){
                curr_col++;
            } else {
                curr_row++;
            }
        }    
        for(unsigned int i = 0 ; i < str.length(); i++){
            this->page[row][col] = str[i];
            if(dir == Direction::Horizontal){
                col++;
            }else{
                row++;
            }
        }
    }


    string Page::read(int row, int col, Direction dir, int size){
        string read;
        for(int i = 0; i < size; i++){
            if(!this->page.contains(row)){
                read += '_';
            }
            else{
                read += this->page[row][col];
                if(dir == Direction::Horizontal){
                    col++;
                }
                else{
                    row++;    
                }
            }
        }
        return read;
    }

    void Page::erase(int row, int col, Direction dir, int size){
        for(int i = 0; i < size; i++){
            if(!this->page.contains(row)){
                char* new_row = new char[LIMIT];
                for(unsigned int j = 0; j < LIMIT; j++){
                    new_row[j] = '_';
                }
                new_row[LINELIMIT] = '\0';
                this->page.insert({row, new_row});
            }
            this->page[row][col] = '~'; 
            if(dir == Direction::Horizontal){
                col++;
            }
            else {
                row++;
            }
        }
    }

    string Page::show(int page){
        string ans;
        map<int, char*>::iterator it = this->page.begin();
        while(it != this->page.end()){
            ans += to_string(it->first);
            ans += '\n';
            ans += it->second;
            it++;
        }
        return ans;
    }
}