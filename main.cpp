#include <iostream>
#include <fstream>

using namespace std;

#define SIZE 200

class desert
{
public:
    desert(int nodes, int edges)
    {
        fstream output;
        this->nodes = nodes;
        this->edges = edges;
    }
    void inputNodes();
    void inputEdges();
    void matrixPower(int);
    void searchMap();
    void printMap();

    int map[SIZE][SIZE] = {0};
    bool nodeList[SIZE] = {0};
    int nodes;
    int edges;
};

void desert::inputNodes()
{
    for (int i = 0; i < nodes; i++)
    {
        cin >> nodeList[i];
    }
}

void desert::inputEdges()
{
    for (int i = 0; i < edges; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        // if (nodeList[p1] != 0 || nodeList[p2] != 0)
        // {
        //     map[p1][p2] = 1;
        //     map[p2][p1] = 1;
        // }
        if (!(nodeList[p1] == 0 && nodeList[p2] == 0))
        {
            map[p1][p2] = 1;
            map[p2][p1] = 1;
        }
    }
}

void desert::matrixPower(int power)
{

    int temp[SIZE][SIZE] = {0};
    int temp2[SIZE][SIZE] = {0};

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            temp[i][j] = map[i][j];
        }
    }
    for (int p = 1; p < power; p++)
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                temp2[i][j] = map[i][j];
            }
        }
        for (int column = 0; column < nodes; column++)
        {
            for (int roll = 0; roll < nodes; roll++)
            {
                int sum = 0;
                for (int i = 0; i < nodes; i++)
                {
                    sum += temp2[column][i] * temp[i][roll];
                }
                if (sum != 0)
                {
                    map[column][roll] += sum / sum;
                }
            }
        }
    }
}

void desert::printMap()
{
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void desert::searchMap()
{
    int p1, p2;
    while (cin >> p1 >> p2)
    {
        if(p1==p2)
        {
            cout << "Yes" << endl;
            continue;
        }
        if (map[p1][p2] == 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    desert D(nodes, edges);
    D.inputNodes();
    D.inputEdges();
    D.matrixPower(edges + 1);
    D.searchMap();
}