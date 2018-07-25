#include "MainWindow.h"
#include <QDebug>
//下落
bool MainWindow::downOK()
{
    return !hitTest(x,y,0,1,currentShape,currentPos);
}
//左移
bool MainWindow::leftOK()
{
    return !hitTest(x,y,-1,0,currentShape,currentPos);
}
//右移
bool MainWindow::rightOK()
{
    return !hitTest(x,y,1,0,currentShape,currentPos);
}
//变换
bool MainWindow::switchOK()
{
    int pos=(currentPos+1)%4;
    return !hitTest(x,y,0,0,currentShape,pos);
}
//添加
bool MainWindow::addOK()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(box[i][3+j]&&shapes[nextShape][nextPos][i][j])
            {
                return false;
            }
        }
    }
	return true;
}
//碰撞检测
bool MainWindow::hitTest(int x, int y,int xshift,int yshift, int shape, int pos)
{
    int s[20][10];
	int test;
    memcpy(s,box,sizeof(box));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(shapes[shape][pos][i][j])
            {
                s[y+i][x+j]=0;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(shapes[shape][pos][i][j])
            {
                if(x+j+xshift<0||x+j+xshift>9||y+i+yshift<0||y+i+yshift>19)
                {
					qDebug()<<"("<<x+j<<","<<y+i<<")";
					return true;
				}
                test=s[y+i+yshift][x+j+xshift]+shapes[shape][pos][i][j];
                if(test>1)
                {
                    return true;
                }
			}
        }
    }
	return false;
}
