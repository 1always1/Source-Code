#include "MainWindow.h"
#include "ui_MainWindow.h"

//消除并计算分数
void MainWindow::score()
{
    int total=0;
    for(int i=19;i>=0;i--)
    {
        total=0;
        for(int j=0;j<10;j++) total+=box[i][j];
        if(total==10)
        {
            clearrow(i);
            Score+=1;
            if(Score<=10)
            {
                Speed=1;
                Level=1;
            }
            if(Score<=20&&Score>10)
            {
                Speed=400;
                Level=2;
            }
            if(Score<=30&&Score>20)
            {
                Speed=300;
                Level=3;
            }
            if(Score<=40&&Score>30)
            {
                Speed=200;
                Level=4;
            }
            if(Score<=50&&Score>40)
            {
                Speed=100;
                Level=5;
            }
            if(Score<=60&&Score>50)
            {
                Speed=80;
                Level=6;
            }
            if(Score<=70&&Score>60)
            {
                Speed=60;
                Level=7;
            }
            if(Score<=80&&Score>70)
            {
                Speed=40;
                Level=8;
            }
            if(Score<=90&&Score>80)
            {
                Speed=20;
                Level=9;
            }
            if(Score>90)
            {
                Speed=10;
                Level=10;
            }
			i++;
		}
	}

    ui->Score->setText("SCORE:"+QString::number(Score));
    ui->Level->setText("LEVEL:"+QString::number(Level));

    QFont font(QString::fromLocal8Bit("黑体"), 32);
    ui->Score->setFont(font);
    ui->Level->setFont(font);
    drawStage();

}

//消除某行
void MainWindow::clearrow(int row)
{
    for(int i=row;i>0;i--)
    {
        for(int j=0;j<10;j++)
        {
            box[i][j]=box[i-1][j];
        }
    }
    for(int i=0;i<10;i++)
    {
        box[0][i]=0;
    }
}
