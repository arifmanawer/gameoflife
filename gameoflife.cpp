#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using namespace std;

const int ten = 10, twenty = 20;

vector<vector<bool>> world = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int howManyNeighbors(const vector<vector<bool>> &generation, int p, int q)
{
    int numberOfNeighbors = 0;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (generation[(p + i + ten) % ten][(q + j + twenty) % twenty] == true)
                numberOfNeighbors += 1;
        }
    }
    return numberOfNeighbors - generation[p][q];
}

bool isItAliveNextGen(const vector<vector<bool>> &generation, int p, int q)
{
    int numberofneighbors = howManyNeighbors(generation, p, q);

    if (numberofneighbors < 2)
    {
        return false;
    }
    else if (generation[p][q] == false && numberofneighbors == 3)
    {
        return true;
    }
    else if (generation[p][q] == true && numberofneighbors == 2)
    {
        return true;
    }
    else if (generation[p][q] == true && numberofneighbors == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printGen(const vector<vector<bool>> &generation)
{
    for (size_t p = 0; p < generation.size(); p++)
    {
        for (size_t q = 0; q < generation[p].size(); q++)
        {
            if (generation[p][q] == 1)
                cout << "O";
            if (generation[p][q] == 0)
                cout << ".";
        }
        cout << "\n";
    }
}

int main(int argc, char *argv[])
{
    int loopamount = atoi(argv[1]);
    vector<vector<bool>> future(world);

    vector<vector<bool>> currentgen(world);
    if (argv[1] == 0)
    {
        printGen(future);
    }
    else
    {
        for (int loopnum = 0; loopnum < loopamount; loopnum++)
        {
            for (size_t p = 0; p < currentgen.size(); p++)
                for (size_t q = 0; q < currentgen[p].size(); q++)
                {
                    if (isItAliveNextGen(currentgen, p, q) == true)
                    {
                        future[p][q] = true;
                    }
                    else
                    {
                        future[p][q] = false;
                    }
                }
            currentgen = future;
            printGen(currentgen);
            cout << "\n";
        }
    }
    // testing
    //   world = future;
    printGen(currentgen);
    return 0;
}
