#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
#define Coffe_tree 0
#define Tea_tree 1
struct Point {
    double x;
    double y;
};
struct Tree {
    Point location;
    int type;
};
struct Plantation {
    Tree* trees;
    int NumOfTree = 0;
};
int countTrees(Plantation p, int type);
int countCoffeeTrees(Plantation p);
int countTeaTrees(Plantation p);


Point findUpperLeft(Plantation);
Point findLowerRight(Plantation);
Point findPump(Plantation , int , double);//Georaphy Median
double findDistance(Point, Point);
double calcTotalLength(Plantation);

Plantation ReadFile();
void WriteFile(Plantation);