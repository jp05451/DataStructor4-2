#include <iostream>

using namespace std;

#define SIZE 200

class desert
{
public:
    desert(int nodes, int edges)
    {
        this->nodes = nodes;
        this->edges = edges;
    }
    void inputNodes();
    void inputEdges();
    void matrixPower(int);

private:
    int map[SIZE][SIZE];
    bool nodeList[SIZE];
    int nodes;
    int edges;
};

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    desert D(nodes, edges);
}

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
        if (nodeList[p1] != 0 || nodeList[p2] != 0)
        {
            map[p1][p2] = 1;
            map[p2][p1] = 1;
        }
    }
}

void desert::matrixPower(int power)
{
    int temp[SIZE][SIZE] = {0};

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            temp[i][j] = map[i][j];
        }
    }
    for (int column = 0; column < nodes; column++)
    {
        for (int roll = 0; roll < nodes; roll++)
        {
            int sum = 0;
            for (int i = 0; i < nodes; i++)
            {
                sum += temp[column][i] * temp[i][roll];
            }
            map[column][roll] = sum;
        }
    }
}