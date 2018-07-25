#include "MainWindow.h"

//下落
void MainWindow::dropbox()
{
	clearOldBlock();
    y++;
	putNewBlock();
}
//左移
void MainWindow::leftbox()
{
	clearOldBlock();
    x--;
	putNewBlock();
}
//右移
void MainWindow::rightbox()
{
	clearOldBlock();
    x++;
	putNewBlock();
}
//变换
void MainWindow::switchbox()
{
	clearOldBlock();
	currentPos++;
    currentPos=currentPos%4;
	putNewBlock();
}
//清除旧图形
void MainWindow::clearOldBlock()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(shapes[currentShape][currentPos][i][j])
            {
                box[y+i][x+j]=0;
            }
        }
    }
}
//添加新图形
void MainWindow::putNewBlock()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(shapes[currentShape][currentPos][i][j])
            {
                box[y+i][x+j]=1;
            }
        }
    }
}
