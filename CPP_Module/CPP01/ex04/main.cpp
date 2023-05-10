#include <fstream>
#include <iostream>

void replace(std::string &line, const char *s1, const char *s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
        line.erase(pos, len1);
        line.insert(pos, s2, len2);
        pos += len2;
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Error Argument!\nUsage : ./replace [FILE NAME] [STR1] "
                     "[STR2]\n";
        exit(EXIT_FAILURE);
    }

    std::ifstream fin(av[1]);
    if (fin.fail()) {
        std::cerr << "No such file\n";
        exit(EXIT_FAILURE);
    }

    std::ofstream fout(av[1] + std::string(".replace"));
    if (fout.fail()) {
        std::cerr << "Can't create outfile\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    while (fin) {
        getline(fin, line, '\n');
        replace(line, av[2], av[3]);
        fout << line + ("\n");
    }

    fout.close();
    fin.close();
    return (EXIT_SUCCESS);
}