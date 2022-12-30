#include<iostream>
#include<queue>

using namespace std;

/*
NOTE: Important question from interview point of view 
      Lecture 61 --> Time stamp : 1:11:28 --> Some important points!
*/

class Station
{
    public: 
    int petrol;
    int distance;

    Station()
    {
        petrol = 0;
        distance = 0;
    }

    Station(int p, int d)
    {
        petrol = p;
        distance = d;
    }
};

int startingPos(Station s[], int n)
{
    int balance = 0; // petrol - distance
    int deficit = 0; // deficiency of petrol on previous stations
    int start = 0;  // starting position of the truck

    for(int i=0; i<n; i++)
    {
        balance += s[i].petrol - s[i].distance;

        if(balance < 0)
        {
            deficit += balance; // summing up the deficiency of petrol
            start = i+1;        // switching to the next station
            balance = 0;
        }
    }

    if((deficit + balance) >= 0)  // In order to avoid the double traversing of stations
    {                             // the deficiency of previous stations would be compensated
        return start;
    }
    else{
        return -1;
    }
}

int main()
{
    Station s[3];
    s[0].petrol = 2;
    s[0].distance = 3;
    s[1].petrol = 2;
    s[1].distance = 3;
    s[2].petrol = 5;
    s[2].distance = 1;

    cout<<"Index is "<<startingPos(s, 3);
    
    return 0;
}

