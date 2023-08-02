#include "Source.h"
int countTrees(Plantation p, int type)
{
    int count = 0;
    for (int i = 0; i < p.NumOfTree; i++)
    {
        if (p.trees[i].type = type)
        {
            count++;
        }
    }
    return count;
        
}
int countCoffeeTrees(Plantation p)
{
    {
        int count = 0;
        for (int i = 0; i < p.NumOfTree; i++)
        {
            if (p.trees[i].type == Coffe_tree)
                count++;
        }
        return count;
    }
}
int countTeaTrees(Plantation p)
{
    {
        int count = 0;
        for (int i = 0; i < p.NumOfTree; i++)
        {
            if (p.trees[i].type == Tea_tree)
                count++;
        }
        return count;
    }
}
Point findUpperLeft(Plantation p)
{
    double x_p = p.trees[0].location.x, y_p = p.trees[0].location.y;
    for (int i = 1; i < p.NumOfTree; i++)
    {
        if (p.trees[i].location.x < x_p)
            x_p = p.trees[i].location.x;

        if (p.trees[i].location.y>y_p)
            y_p = p.trees[i].location.y;
    }
    return { x_p, y_p };
}
Point findLowerRight(Plantation p)
{
    double x_p = p.trees[0].location.x, y_p = p.trees[0].location.y;
    for (int i = 1; i < p.NumOfTree; i++)
    {
        if (p.trees[i].location.x > x_p)
            x_p = p.trees[i].location.x;

        if (p.trees[i].location.y < y_p)
            y_p = p.trees[i].location.y;
    }
    return { x_p, y_p };
}
double calcFenceLength(Plantation p)
{
    Point UL = findUpperLeft(p),
          LR = findLowerRight(p);

    return ((UL.y - LR.y) + (LR.x - UL.x)) * 2;
}

Plantation ReadFile() {
    Plantation p;
    ifstream inF("Plantation.txt");
    int i = 0;
    inF >> p.NumOfTree;
   p.trees = new Tree[p.NumOfTree];
    while (i < p.NumOfTree) {
        inF >> p.trees[i].location.x;
        inF >> p.trees[i].location.y;
        inF >> p.trees[i].type;
        i++;
    }
    inF.close();
    return p;
}
void WriteFile(Plantation p){
    ofstream outF("NongTrai.txt");
    outF << countCoffeeTrees(p)<<" ";
    outF << countTeaTrees(p) << endl;
    outF << calcFenceLength(p) << endl;
    outF << calcTotalLength(p);

    outF.close();
}
double findDistance(Point a, Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
Point findPump(Plantation p, int maxIterations , double tolerance) {
    Point median = p.trees[0].location;
    for (int i = 0; i < maxIterations; i++) {
        Point numerator = { 0, 0 };
        double denominator = 0;
        for (int j = 0; j < p.NumOfTree; j++) {
            double d = findDistance(median, p.trees[j].location);
            if (d != 0) {
                numerator.x += (p.trees[j].location.x / d);
                numerator.y += (p.trees[j].location.y / d);
                denominator += 1 / d;
            }
        }
        Point newMedian = { numerator.x / denominator, numerator.y / denominator };
        if (findDistance(newMedian, median) < tolerance) {
            break;
        }
        median = newMedian;
    }
    return median;
}

double calcTotalLength(Plantation p)
{
    double totalL = 0;
    Point pump = findPump(p,1000,1e-6);
    for (int i = 0 ; i< p.NumOfTree;i++)
    {
        totalL += findDistance(pump, p.trees[i].location);
    }
    return totalL;
}



