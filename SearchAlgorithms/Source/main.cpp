#include "CBreadthFirstSearch.h"
#include "CMaze.h"
#include "utility.h"

#include <iostream>
#include <string_view>


int main()
{
    std::string_view mazeFile
    {
        "----G\n"
        "-###-\n"
        "--#--\n"
        "#---#\n"
        "--I#-\n"
    };


    {
        CBreadthFirstSearch bfs{};
        CMaze maze{ mazeFile, 5, 5 };
        
        bfs.Search(maze);
    }

    _CrtDumpMemoryLeaks();
    return 0;
};