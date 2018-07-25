#include "MainWindow.h"
#include "ui_MainWindow.h"
//绘制舞台
void MainWindow::drawStage()
{
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(box[i][j]==1&&Score%4==0)
            {
                stage[i][j]->setStyleSheet("border:0px;background:#d05a6e");
            }
            if(box[i][j]==1&&Score%4==1)
            {
                stage[i][j]->setStyleSheet("border:0px;background:#7db9de");
            }
            if(box[i][j]==1&&Score%4==2)
            {
                stage[i][j]->setStyleSheet("border:0px;background:#8f77b5");
            }
            if(box[i][j]==1&&Score%4==3)
            {
                stage[i][j]->setStyleSheet("border:0px;background:#ffb11b");
            }
            if(box[i][j]==0)
            {
                stage[i][j]->setStyleSheet("border:0px;background:#FFF");
            }
        }
    }
}
