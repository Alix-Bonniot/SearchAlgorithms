#include "CBreadthFirstSearch.h"
#include "CMaze.h"
#include "utility.h"
#include "Timer.h"

#include <iostream>
#include <string_view>


int main()
{
    std::string_view mazeFile
    {
        "---G--\n"
        "-####-\n"
        "--#---\n"
        "#---#-\n"
        "--I#--\n"
    };


    {
        CBreadthFirstSearch bfs{};
        CMaze maze{ mazeFile, 5, 6 };

        Timer timer{};
        bfs.Search(maze);
        std::cout << "Time elapsed: " << timer.GetElapsedTime() << '\n';
    }

    _CrtDumpMemoryLeaks();
    return 0;
};