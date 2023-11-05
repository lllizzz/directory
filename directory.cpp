#include <set>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

void dir(set<string>& directories, unordered_set<string>& paths)
{
    for (auto path : paths)
    {
        for (size_t i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
            {
                if (!directories.contains(path.substr(0, i + 1)))
                {
                    directories.insert(path.substr(0, i + 1));
                }
            }
        }
    }
}

void GetDir(set<string>& directories)
{
    for (auto directory : directories)
    {
        cout << directory << endl;
    }
}

int main()
{
    unordered_set<string> paths;
    set<string> directories;
    string path;
    while (cin >> path)
    {
        paths.insert(path);
    }
    dir(directories, paths);
    GetDir(directories);
}