#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int board[5][5];

void boardsetup()
{
for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
    board[i][j]==0;
        }
    }
  }


void display(){
    boardsetup();
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
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

boardsetup();
int row = rand()%5;
int column = rand()%5;
if(board[row][column]==0)
    board[row][column]=2;

}



void newgame()
{

int row = rand()%5;
int column = rand()%5;
if(board[row][column]==0){
    board[row][column]=2;
    }
    int row1 = rand()%5;
    int column1 = rand()%5;
    if(board[row1][column1]==0){
    board[row1][column1]=2;
    }
    for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
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

    
for(int i= 0;i< 5;i++ ){

for(int j=0;j<4;j++){

int temp=board[i][j];
if(temp==0)
    continue;
for(int k=j+1; k<5; k++){

    if(board[i][k]==0){

        board[i][j]+=board[i][k];
        board[i][k]=0;
    }

    else if(board[i][k]==temp ){

        board[i][j]+=board[i][k];
        board[i][k]=0;
        break;
    }
    else
    break;
}

}
}
for (int i = 0; i < 5; i++)
    {
        
        for(int j=1; j<5;j++)
        {
            
            for(int k=j;k>0;k--)
            {
                if(board[i][k-1]==0 ){
                    board[i][k-1]+=board[i][k];
                    board[i][k]=0;
                    
                }
            }
        }
    }
}


void right(){

    for(int i= 0;i< 5;i++ ){

    for(int j=4;j>0;j--){

    int temp=board[i][j];
        if(temp==0)
        continue;
        for(int k=j-1; k>=0; k--){

        if(board[i][k]==0){

        board[i][j]+=board[i][k];
        board[i][k]=0;
    }

    else if(board[i][k]==temp ){

        board[i][j]+=board[i][k];
        board[i][k]=0;
        break;
    }
    else
    break;
}

}
}

    for (int i = 0; i < 5; i++)
    {

        for(int j=3; j>=0;j--)
        {
            
            for(int k=j;k<4;k++)
            {
                if(board[i][k+1]==0 ){
                    board[i][k+1]+=board[i][k];
                    board[i][k]=0;
                    
                }
            }
        }
         
    }
    
}

void up(){

     for(int j=0;j<5;j++){

     for(int i= 0;i< 5;i++ ){

        int temp=board[i][j];
        if(temp==0)
        continue;
        for(int k=i+1; k<5; k++){

        if(board[k][j]==0){

        board[i][j]+=board[k][j];
        board[k][j]=0;
        }

            else if(board[k][j]==temp ){

        board[i][j]+=board[k][j];
        board[k][j]=0;
        break;
        }
        else
        break;
    }

}
}
   
   
    for(int j=0; j<5;j++)
    {
    
    for (int i = 1; i < 5; i++)    
        {
            
            for(int k=i;k>0;k--)
            {
                if(board[k-1][j]==0 ){
                    board[k-1][j]+=board[k][j];
                    board[k][j]=0;
                    
                }
               
            }
        }
         
    }
    
}

void down(){

     for(int j=0;j<5;j++){

     for(int i= 4;i>=0;i-- ){

        int temp=board[i][j];
        if(temp==0)
        continue;
        for(int k=i-1; k>=0; k--){

        if(board[k][j]==0){

        board[i][j]+=board[k][j];
        board[k][j]=0;
        }

            else if(board[k][j]==temp ){

        board[i][j]+=board[k][j];
        board[k][j]=0;
        break;
        }
        else
        break;
    }

}
}
    
   
    for(int j=0; j<5;j++)
    {
    
        for (int i = 3; i >=0; i--)    
        {
            
            for(int k=i;k<4;k++)
            {
                if(board[k+1][j]==0 ){
                    board[k+1][j]+=board[k][j];
                    board[k][j]=0;
                    
                }
                
            }
        }
         
    }
}

int win(){
    int flag=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(board[i][j]==2048)
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

 char command;
 int check=0;

 while(true)
 {
     
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

    else if(command=='q'){
        cout<<"THE END";
        break;
    }
    


    else{
    cout<<"Enter a valid key"<<endl;
    continue;
    }
    
    
    generate_number();
         display();

    check=win();
    if(check==1){
    cout<<"Player wins";
    break;}
      
    }
    
}