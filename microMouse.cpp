/*Authors: Sachin Gupta and Gurbinder Singh Gill */

# include<iostream>
#include<time.h>
# include<stdio.h>
# include<conio.h>
# include "newds.h"                                  //data structurein which element are added to the end and removed also from the end is used for storing the cells which have more than one opening    
using namespace std;

struct map                                                 //structure used to store the info of a particular cell
{
       char left;
       char top;
       char right;
       char bottom;
};
int nop(map cells[],int pos)                              //number of openings in a particular cell
{
    int i=0;
    if(cells[pos].left=='1')
    i++;
    if(cells[pos].top=='1')
    i++;
    if(cells[pos].right=='1')
    i++;
    if(cells[pos].bottom=='1')
    i++;
    return i;                                                  //function returns the number of openings in the cell
}

int main()

{
    clock_t start=clock();                                      //initialization of clock
    int i,j;
    SQueue <int> Q;                                                  
    int row,column;                                           //rows and columns in the maze
    cout<<"Enter the number of rows"<<endl;
    cin>>row;
    cout<<"Enter the number of Columns"<<endl;
    cin>>column;
    int sizeofmaze;                                                      
    sizeofmaze=row*column;                                       //calculating the number of cells
    struct map cell[sizeofmaze];                                  //an array of structure map  
    cout<<"Enter the map of the maze"<<endl;
    for(int i=0;i<sizeofmaze;i++)                                //input the map of the maze    
    {
           
            cin>>cell[i].left;
           
            cin>>cell[i].top;
            
            cin>>cell[i].right;
            
            cin>>cell[i].bottom;
    }                                                                 
    
      int pos=0;                                                      //initialize cellpos to 0i.e starting
     int flag=0,flag2=0,exitgates=0;                           
    cell[pos].left='0';
    int temp= pos+1;
    Q.Enqueue(temp);
    
    if(cell[pos].right=='1')
    {                                                                                                                                            
                          cell[pos].right='0';
                          flag=1;
                          pos=pos+1;
                       
    }
    
    else
    {
        cell[pos].bottom='0';
        pos=pos+column;
        flag=2;
    
    }
    do
    {
        
        do
        {
         if(flag==1)
         cell[pos].left='0';
         else if(flag==2)
         cell[pos].top='0';
         else if(flag==3)
         cell[pos].right='0';
         else if(flag==4)
         cell[pos].bottom='0';
         else                                        // just to fill the else codition basically it does nothing
         {
                                                    
           flag++;
            flag--;
         }
                 
         Q.Enqueue(pos+1);
         if(cell[pos].left=='1')                      //condition for cell to have its left end open
         {
                          cell[pos].left='0';
                          flag=3;
                          i=(pos)/row;
                          j=(pos)%column;
                          j--;
                          if(j<0)
                          {flag2=1;}
                          else
                          {pos=pos-1;}
         }
         else if(cell[pos].top=='1')                             //condition for the cell to have its top end open 
         {
                          cell[pos].top='0';
                          flag=4;
                          i=(pos)/row;
                          j=(pos)%column;
                          i--;
                          if(i<0)
                          
                          {flag2=1;}
                          
                          else
                          
                          {pos=pos-column;}                         
         }
         else if(cell[pos].right=='1')                       //condition for the cell to have its right end open
         {
                          cell[pos].right='0';
                          flag=1;
                          i=(pos)/row;
                          j=(pos)%column;
                          
                          j++;
                          if(j>=column)
                          {flag2=1;}
                          else
                          {pos=pos+1;}
         }
         else if(cell[pos].bottom=='1')                                                      //condition for the cell to have its bottom end open
         {
                          cell[pos].bottom='0';
                          flag=2;
                          i=(pos)/row;
                          j=(pos)%column;
                          i++;
                          if(i>=row)
                          {flag2=1;}
                          else
                          {pos=pos+column;}
         }
         else                                                   //code changed here for blocked path; rest is same
         {
                 flag2=2;
                 cout<<"Dead end"<<endl;
                 Q.display();                          //displaying the dead end}
         }
        }while(flag2==0);                                //this is the condition when the mouse exits the maze
        
        if(flag2==1)
        {
                    exitgates++;
                    cout<<exitgates<<" exit path is"<<endl;
                    Q.display();
        }
        flag2=0;
        int check;
        do                                                                //loop checks the number of openings available in the cell and returns to the cell where more than one path exists                                                            
        {       pos=Q.Deque();
                pos=pos-1;
                check=nop(cell,pos);
              
        }while(check==0&&Q.isEmpty()==0);                                   //for inner loop to check if any way in a particular cell is left unexplored
        flag=0;
        
    }while(Q.isEmpty()==0);                                                   //for outer loop when the queue goes empty

    cout<<"Total number of exit gates are "<<exitgates<<endl;                     //displays the number of exit gates
    printf("Time : %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
    system("pause");
    return 0;
}
        
        
        
        
        
        
        
     
