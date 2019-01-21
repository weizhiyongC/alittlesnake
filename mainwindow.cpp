#include <QGraphicsView>
#include <QTimer>

#include "constants.h"
#include "gamecontroller.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      game(new GameController(*scene, this))  //游戏定义
{                                             //带形式参数的构造函数和无形式参数的构造函数
    setCentralWidget(view);  //设置为中心窗口组件，用于布局产生定位，因为mainwindow中间是一个空白
    resize(800, 600);

    initScene();
    initSceneBackground();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::initScene()
{
    scene->setSceneRect(0,0,400,400);  //设置场景范围，作用于左上角（-100，-100）
                                                //长宽为200的矩形
}

void MainWindow::initSceneBackground()
{
    QPixmap bg(TILE_SIZE, TILE_SIZE);  //定义了一个场景
    QPainter p(&bg);                   //定义画图工具，在场景上画图
    p.setBrush(QBrush(Qt::gray));      //定义该画图工具为画刷
    p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);  //画矩形，坐标（0，0），长宽自定
                                       //此刻得到的是一个场景图pg
    view->setBackgroundBrush(QBrush(bg));  //将该场景图铺满整个背景窗口
}
