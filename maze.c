#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define width 11
#define height 11
int maze[height][width];
int visited[height][width];
int dir[4][2]={
{0,2},
{2,0},
{0,-2},
{-2,0}
};
int is_valid(int x,int y)
{
return(x>0 && x<height-1 && y>0 && y<width-1);
}
void generate_maze(int x,int y)
{
visited[x][y]=1;
maze[x][y]=0;
for (int i = 0; i < 4; i++)
{
int r=rand() % 4;
int temp_x=dir[i][0];
int temp_y=dir[i][1];
dir[i][0]=dir[r][0];
dir[i][1]=dir[r][1];
dir[r][0]=temp_x;
dir[r][1]=temp_y;
}
for(int i=0;i<4;i++)
{
int nx=x+dir[i][0];
int ny=y+dir[i][1];
if(is_valid(nx,ny) && !visited[nx][ny])
{
maze[x+dir[i][0]/2][y+dir[i][1]/2]=0;
generate_maze(nx,ny);
}
}
}
void print_maze(int player_x, int player_y)
{
system("clear");
for (int i = 0; i < height; i++)
{
for (int j = 0; j < width; j++)
{
if (i == player_x && j == player_y)
printf("P ");
else if (i == height - 2 && j == width - 2)
printf("X ");
else printf(maze[i][j] ? "# " : "  ");
}
printf("\n");
}
}
int main()
{
srand(time(NULL));
for(int i=0;i<height;i++)
{
for(int j=0;j<width;j++)
{
maze[i][j]=1;
visited[i][j]=0;
}
}
generate_maze(1,1);
int player_x=1,player_y=1;
char move;
while(1)
{
print_maze(player_x,player_y);
printf("Move WASD:");
scanf("%c",&move);
int new_x=player_x;
int new_y=player_y;
switch(move)
{
case 'w':
new_x-=1;
break;
case 's':
new_x+=1;
break;
case 'a':
new_y-=1;
break;
case 'd':
new_y+=1;
break;
default:
printf("\nInvalid Move\n");
continue;
}
if(is_valid(new_x,new_y) && maze[new_x][new_y]==0)
{
player_x=new_x;
player_y=new_y;
}
if(player_x==height-2 && player_y==width-2)
{
print_maze(player_x,player_y);
printf("\n CONGRATULATIONS!\n");
break;
}
}
return 0;
}
