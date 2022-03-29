#include <iostream>
#include <string>
#include "Direction.hpp"
#include <map>
#include <stdlib.h>

using namespace std;

namespace ariel{
    class Page{
        private:
            map<int, char*> page;
        
        public:
            void write(int row, int col, Direction dir, string str);

            string read(int row, int col, Direction dir, int size);

            void erase(int row, int col, Direction d, int size);

            string show(int page);
    };
}