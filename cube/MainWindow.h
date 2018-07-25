﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QTimer>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	void keyPressEvent(QKeyEvent *event);
private slots:
	void gameEvent();
	void on_StartGame_clicked();
private:
	Ui::MainWindow *ui;
	QTimer *timer;					//计时器
	QLabel *stage[20][10];			//高20宽10:舞台
    QLabel *tipbox[4][4];			//高4宽4提示窗口
    int box[20][10];		//纯数字舞台
    int Speed;                      //速度
    int Level;                      //等级
	//7种图形4个方向4个高4个宽
    int shapes[7][4][4][4]={{{{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
                              {{1,1,0,0},{0,1,1,0},{0,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}}},
                             {{{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}},
                              {{0,1,1,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}},
                             {{{1,1,0,0},{0,1,0,0},{0,1,0,0},{0,0,0,0}},
                              {{1,1,1,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,0,0,0},{1,0,0,0},{1,1,0,0},{0,0,0,0}},
                              {{0,0,1,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}}},
                             {{{1,1,0,0},{1,0,0,0},{1,0,0,0},{0,0,0,0}},
                              {{1,0,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{0,1,0,0},{1,1,0,0},{0,0,0,0}},
                              {{1,1,1,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}}},
                             {{{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
                              {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{0,1,0,0},{0,1,0,0},{0,1,0,0}},
                              {{0,0,0,0},{1,1,1,1},{0,0,0,0},{0,0,0,0}}},
                             {{{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}},
                              {{1,1,0,0},{1,1,0,0},{0,0,0,0},{0,0,0,0}}},
                             {{{0,0,0,0},{1,1,1,0},{0,1,0,0},{0,0,0,0}},
                              {{1,0,0,0},{1,1,0,0},{1,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{1,1,1,0},{0,0,0,0},{0,0,0,0}},
                              {{0,1,0,0},{1,1,0,0},{0,1,0,0},{0,0,0,0}}}};
    int x=3,y=0;//当前图形位置00位置
	int nextShape,currentShape;	//下一个图形,当前图形
	int nextPos,currentPos;		//下一个图形姿态,当前图形姿态
	int Score=0;					//当前分数

	bool hitTest(int x, int y, int xshift, int yshift, int shape, int pos);//碰撞检测
	bool downOK();					//图形是否可以下落
	bool leftOK();					//是否可以左移
	bool rightOK();					//是否可以右移
	bool switchOK();				//是否可以变换
	bool addOK();					//是否可以添加
	void clearOldBlock();			//清除旧图形
	void putNewBlock();				//添加新图形
    void randombox();				//随机下一个
    void addbox();				//添加图形
    void drawStage();				//绘制舞台
    void dropbox();				//图形下落
    void leftbox();				//图形左移
    void rightbox();				//图形右移
    void switchbox();				//图形变换
    void score();			//消除并计算分数
    void clearrow(int row);			//消除某行
};

#endif // MAINWINDOW_H
