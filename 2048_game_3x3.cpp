#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int board[3][3];

void boardsetup()
{
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
    board[i][j]==0;
        }
    }
  }


void display(){
    boardsetup();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==0)
            cout<<"-"<<"    ";
            else
            cout<<board[i][j]<<"    ";
        }
    cout<<endl;
    cout<<endl;
    }
}




void generate_number()
{
//srand(time(0));
boardsetup();
int row = rand()%3;
int column = rand()%3;
if(board[row][column]==0)
    board[row][column]=2;
/*for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
    }*/
}



void newgame()
{
    //srand(time(0));
//boardsetup();
int row = rand()%3;
int column = rand()%3;
if(board[row][column]==0){
    board[row][column]=2;
    }
    int row1 = rand()%3;
    int column1 = rand()%3;
    if(board[row1][column1]==0){
    board[row1][column1]=2;
    }
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        if(board[i][j]==0)
            cout<<"-"<<"    ";
            else
            cout<<board[i][j]<<"    ";
    }
    cout<<endl;
    cout<<endl;
    }
     cout<<" 'w' = Up, 's' = Down, 'a' = Left, 'd' = right, 'q' = quit"<<endl;
}



void left(){
    
    int c;
    for (int i = 0; i < 3; i++)
    {
        c=0;
        for(int j=1; j<3;j++)
        {
            for(int k=j;k>0;k--)
            {
                if(board[i][k-1]==0 ){
                    board[i][k-1]+=board[i][k];
                    board[i][k]=0;
                    
                }
                else if(c<1 && board[i][k]==board[i][k-1]){
                    board[i][k-1]+=board[i][k];
                    board[i][k]=0;
                    c++;
                }
            }
        }
         
    }
    
}

void right(){
    int c;
    for (int i = 0; i < 3; i++)
    {
        c=0;
        for(int j=1; j>=0;j--)
        {
            for(int k=j;k<2;k++)
            {
                if(board[i][k+1]==0 ){
                    board[i][k+1]+=board[i][k];
                    board[i][k]=0;
                    
                }
                else if(c<1 && board[i][k]==board[i][k+1]){
                    board[i][k+1]+=board[i][k];
                    board[i][k]=0;
                    c++;
                }
            }
        }
         
    }
    
}

void up(){
        int c;
   
    for(int j=0; j<3;j++)
    {
        c=0;
    for (int i = 1; i < 3; i++)    
        {
            for(int k=i;k>0;k--)
            {
                if(board[k-1][j]==0 ){
                    board[k-1][j]+=board[k][j];
                    board[k][j]=0;
                    
                }
                else if(c<1 && board[k-1][j]==board[k][j]){
                    board[k-1][j]+=board[k][j];
                    board[k][j]=0;
                    c++;
                }
            }
        }
         
    }
    
}

void down(){
        int c;
   
    for(int j=0; j<3;j++)
    {
        c=0;
    for (int i = 1; i >=0; i--)    
        {
            for(int k=i;k<2;k++)
            {
                if(board[k+1][j]==0 ){
                    board[k+1][j]+=board[k][j];
                    board[k][j]=0;
                    
                }
                else if(c<1 && board[k+1][j]==board[k][j]){
                    board[k+1][j]+=board[k][j];
                    board[k][j]=0;
                    c++;
                }
            }
        }
         
    }
}

int win(){
    int flag=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==32)
            flag=1;

        }
        if(flag==1)
        break;
    }
    if(flag==1)
    return 1;
    else 
    return 0;
}





int main()
{
srand(time(0));
 newgame();  
//display();
 char command;
 int check=0;

 while(true)
 {
     //srand(time(0));
     cin>>command;
     cout<<endl;
     if(command=='a'){
         left();
    }
    
    else if(command=='d'){
        right();
    }

    else if(command=='w'){
        up();
    }

    else if(command=='s'){
        down();
    }

    else if(command=='q')
    break;

    
    
    generate_number();
         display();

    check=win();
    if(check==1){
    break;}
      
    }
    cout<<"Player wins";
}