#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class matrix
{
    public:
        matrix();
        virtual ~matrix();
        int type;
        void load(const std::string&);

        int k;
        int l;
        std::vector<int> vec;

    protected:
    private:
};

#endif // MATRIX_H