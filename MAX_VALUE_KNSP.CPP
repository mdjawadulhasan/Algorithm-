#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    float value;
    float weight;
    float density;
    float chosen;
} Item;

void input(Item items[], int sizeOfItems)
{
    cout << "Enter total " << sizeOfItems << " item's values and weight" << endl;
    for (int i = 0; i < sizeOfItems; i++)
    {
        cout << "Enter " << i + 1 << " Value ";
        cin >> items[i].value;
        cout << "Enter " << i + 1 << " Weight ";
        cin >> items[i].weight;
    }
}

void display(Item items[], int sizeOfItems)
{
    cout << "values:   ";
    for (int i = 0; i < sizeOfItems; i++)
    {
        cout << items[i].value << "\t";
    }

    cout << endl
         << "weight:   ";
    for (int i = 0; i < sizeOfItems; i++)
    {
        cout << items[i].weight << "\t";
    }
    cout << endl;
}

bool compare(Item i1, Item i2)
{
    return (i1.density > i2.density);
}

float knapsack(Item items[], int sizeOfItems, int W,int RW)
{
    float total=0;
   
    for (int i = 0; i < sizeOfItems; i++)
    {
        items[i].chosen=0;
    }
   
    for (int i = 0; i < sizeOfItems; i++)
    {
        items[i].density = items[i].value / items[i].weight;
    }

    //sorting w.r.t to density using compare function
    sort(items, items + sizeOfItems, compare);
 for (int i = 0; i < sizeOfItems; i++)
    {
        cout<<"WEIGHT : "<<items[i].weight<<" VALUE : "<<items[i].value<<" DENSITY :"<<items[i].density<<endl;
    }

    int ii;


    for (ii = 0; ii < sizeOfItems; ii++)
    {
        if(RW>=items[ii].weight && items[ii].weight>0)
        {
            items[ii].chosen=items[ii].weight;
            items[ii].weight=0;
            RW=RW-items[ii].chosen;
        }
        else if(RW<items[ii].weight && items[ii].weight>0 && RW>0)
        {
            items[ii].chosen=RW;
            items[ii].weight= items[ii].weight-RW;
            RW=RW-items[ii].chosen;
        }
        // else
        // {
        //     break;
        // }
    }


    for (int i = 0; i < ii; i++)
    {
        total=total+((items[i].chosen)*(items[i].density));
    }
    

    return total;
}
int main()
{
    cout<<" Enter the number of elements : ";
    int t;
    cin>>t;
    int W;
    Item items[t];
    input(items, t);
    cout << "Entered data \n";
    display(items, t);
    cout << "Enter Knapsack weight \n";
    cin >> W;
    float mxVal = knapsack(items, t, W,W);
    cout << "---Max value for " << W << " weight is " << mxVal;

    return 0;
}


