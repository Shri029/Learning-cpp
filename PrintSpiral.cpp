//Code to print a matrix in spiral form
#include <iostream>
using namespace std;

#define r 3
#define c 6

void PrintSpiral(int a[r][c], int m,int n){
    int i,k=0,l=0;
    
    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            cout<<a[k][i]<<" ";
        }
        k++;
 
        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            cout<<a[i][n-1]<<" ";
        }
        n--;
 
        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                cout<<a[m-1][i]<<" ";
            }
            m--;
        }
 
        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                cout<<a[i][l]<<" ";
            }
            l++;    
        }        
    }
    
}

int main() {
int a[r][c] = { {1,  2,  3,  4,  5,  6},
        {7,  8,  9,  10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };
 
    cout<<"Matrix:\n";
    for(int i=0;i<3;i++){
       for(int j=0;j<6;j++){
           cout<<a[i][j]<<" ";
       }
       cout<<endl;
    }
    PrintSpiral(a,r,c);
    return 0;
}
