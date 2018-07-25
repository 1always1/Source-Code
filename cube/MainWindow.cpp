#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDateTime>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    memset(box,0,sizeof(box));
	//绘制舞台格子
	QLabel *temp;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<10;j++)
        {
			temp=new QLabel(ui->stage);
			temp->setText("");
            temp->setMinimumSize(QSize(30, 30));
            temp->setMaximumSize(QSize(30, 30));
            temp->setGeometry(j*31+1,i*31+1,30,30);
			temp->setStyleSheet("border:0px;background-color:#FFF");
			stage[i][j]=temp;
		}
	}
	//绘制提示格子
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
			temp=new QLabel(ui->Tip);
			temp->setText("");
            temp->setMinimumSize(QSize(30, 30));
            temp->setMaximumSize(QSize(30, 30));
            temp->setGeometry(j*31+1,i*31+1,30,30);
			temp->setStyleSheet("border:0px;background-color:#FFF");
            tipbox[i][j]=temp;
		}
	}

    //插图
    QLabel *pg;
    pg=new QLabel(ui->bg);
    pg->setText("");
    pg->setMinimumSize(QSize(255, 453));
    pg->setMaximumSize(QSize(255, 453));
    pg->setGeometry(333,247,255,453);
    pg->setStyleSheet("background-image: url(:/bg.png);");
    pg->show();

	//计时器
	timer=new QTimer();
	connect(timer,SIGNAL(timeout()),this,SLOT(gameEvent()));
}


MainWindow::~MainWindow()
{
	delete ui;
}

//随机图形
void MainWindow::randombox()
{
    srand(time(0));
    nextShape=rand()%7;
    nextPos=rand()%4;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(shapes[nextShape][nextPos][i][j])
            {
                tipbox[i][j]->setStyleSheet("border:0px;background-color:#1b813e");
            }
            else
            {
                tipbox[i][j]->setStyleSheet("border:0px;background-color:#fff");
			}
		}
	}
}
void MainWindow::addbox()
{
		currentShape=nextShape;
		currentPos=nextPos;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                box[i][3+j]+=shapes[currentShape][currentPos][i][j];
			}
		}
        x=3;
        y=0;
}
void MainWindow::gameEvent()
{
    if(downOK())
    {
        dropbox();
    }
    else
    {
        score();
        if(addOK())
        {
            addbox();
            randombox();
        }
        else
        {
			timer->stop();
            QMessageBox::information(this,"Game Over","GAMEOVER!");
            ui->StartGame->setEnabled(true);
            ui->StartGame->setText("Again!");
        }
	}
	drawStage();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_W :
            if(switchOK()) switchbox();
        break;
        case Qt::Key_A :
            if(leftOK()) leftbox();
        break;
        case Qt::Key_D :
            if(rightOK()) rightbox();
        break;
        case Qt::Key_S :
            while(downOK()) dropbox();
        break;
    }
    drawStage();
}
void MainWindow::on_StartGame_clicked()
{
    ui->StartGame->setText("restart!");
    memset(box,0,sizeof(box));;
	Score=0;
    Speed=500;
    Level=1;
    score();
    randombox();
    addbox();
    randombox();
    drawStage();
    timer->start(Speed);
}
