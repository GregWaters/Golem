#include <fstream>
#include <string>
#include <iostream>
#include "tokenize.hpp"
#include "parse.hpp"

int main(int argc, char** argv)
{
    std::fstream file;
    for (int i = 1; i < argc; ++i)
    {
        // File (only the latest file is read from)
        if (argv[0] != '-')
        {
            file.open(argv[i]);
            continue;
        }

        // Flag
        for (int j = 1; argv[i][j] != '\0'; ++j)
        {
            switch (argv[i][j])
            {
                // Detect flags and set their respective variables
            }
        }
    }

    
}