#include <iostream>
using namespace std;

int find_max(int* x, int position, int max)
{
    if(position<0)
        return max;

    else
    {
        if(x[position]>=max)
            max=x[position];

        return find_max(x, position-1, max);
    }
}

int find_min(int* x, int position, int min)
{
    if(position<0)
        return min;

    else
    {
        if(x[position]<=min)
            min=x[position];

        return find_min(x, position-1, min);
    }
}


int main()
{
    int x[] = {10, 1, 6, 12, 17, 3};
    int max = x[0];
    int min = x[0];
    cout<<find_max(x, sizeof(x)/sizeof(x[1])-1, max)<<endl;
    cout<<find_min(x, sizeof(x)/sizeof(x[0])-1, min)<<endl;
}
