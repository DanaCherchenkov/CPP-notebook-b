#include <iostream>
#include <string>
#include "Direction.hpp"
#include "Page.hpp"
#include <map>

using namespace std;
namespace ariel{

    class Notebook{

        private:
            map<int, Page> notebook;

        public:

            void write(int page, int row, int col, Direction dir, string str);

            string read(int page, int row, int col, Direction dir, int size);

            void erase(int page, int row, int col, Direction dir, int size);

            string show(int page);
    };
}