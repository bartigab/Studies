#include <iostream>
using namespace std;

int main()
{
    /*   int number;
       cin >> number;
       bool first_jedynka = false;
       unsigned int mask=0, mask2=0;

       for (unsigned int tempmask = 0x80000000; tempmask; tempmask >>= 1)
       {
           if (number & tempmask) {

               mask = tempmask;
               first_jedynka = true;
               break;
           }
       }


       first_jedynka = false;
       for (unsigned int tempmask2 = 0x00000001; tempmask2<0x80000000; tempmask2 <<= 1)
       {
           if (number & tempmask2) {
               mask2 = tempmask2;
               first_jedynka = true;
               break;
           }
       }

       int zerocounter = 0;
       for (int i=mask; i>=mask2 ; i >>= 1)
       {
           if (i&number) //znalezienie 1
           {
               continue;
           }
           else
           {
               zerocounter++;
           }
       }


       cout << zerocounter;

   }*/
    int num;
    cin >> num;
    bool notSAME = false;

    unsigned int leftmask = 0x80000000;
    unsigned int rightmask = 0x00000001;

    for (int i = 0; i < 16; i++)
    {


        if ((num & leftmask) != 0) {
            if ((num & rightmask) != 0) {
                    leftmask >>= 1;
                    rightmask <<= 1;
                }
            }
            else if ((num & leftmask) == 0 and (num & rightmask) == 0)
            {
                leftmask >>= 1;
                rightmask <<= 1;
            }
            else
            {
                notSAME = true;
                break;
            }
    }

    if (notSAME) {
        cout << "0";
    }
    else {
        cout << "1";
    }

    return 0;
}