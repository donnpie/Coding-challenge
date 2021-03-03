#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int particleCount) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "MainWindow::MainWindow(QWidget *parent) constructor called";
    ui->setupUi(this);
    _scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);




    //Set up controller
    _c = new Controller(particleCount);
    _c->printParticles();
    //qDebug() << "Before exportign particle list";
    _pList = _c->getParticleList();
    //qDebug() << "After exportign particle list";
    //_shapeList = new QGraphicsEllipseItem[particleCount];
    QString ftString = "";
    int x,y;
    for (int i = 0; i < particleCount; i++)
    {
        x = static_cast<int>(_pList->at(i)->getVector("Position")->getX());
        y = static_cast<int>(_pList->at(i)->getVector("Position")->getY());
        ftString = _pList->at(i)->getForceType()->getForceTypeString();
        if (ftString == "Attract")
        {
            //_painter->setBrush(_redBrush);
            _shapeList.push_back(new MyEllips(_pList->at(i)));
            _scene->addItem(_shapeList[i]);
            //_shapeList[i]->setPos(x, y);
            //_shapeList[i]->update();
            //_shapeList[i]->
            //_shapeList[i]->paint(_painter, nullptr, nullptr);
        }
        else if (ftString == "Repel")
        {
            //_shapeList.push_back(_scene->addEllipse(QRect(0, 0, 10, 10), _blackPen, _blueBrush)); //Try #1
            //_painter->setBrush(_blueBrush);
            _shapeList.push_back(new MyEllips(_pList->at(i)));
            _scene->addItem(_shapeList[i]);
            //_shapeList[i]->setPos(x, y);
            //_shapeList[i]->paint(_painter, nullptr, nullptr);
        }
        else {
            qDebug() << "Error in MainWindow::MainWindow(QWidget *parent, int particleCount) "
                     << "ForceTypeString value could not be recognised. check for typos";
            exit(-6);
        }
        //_shapeList[i]->setPos(mapToParent(QPoint(x,y)));
        _shapeList[i]->setPos(x,y);
    }

    //Create qtimer
    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(advance()));
    _timer->start(100);

    if (connect(_timer, SIGNAL(timeout()), this, SLOT(advance())))
    {
        qDebug() << "Signal/slot connected successfully";
    }
    else {
        qDebug() << "Signal/slot failed to connect. Aborting...";
        exit(-7);
    }; //Try #2

    qDebug() << "MainWindow::MainWindow(QWidget *parent) end"<<endl;
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow::~MainWindow() destructor called on " << this;
    delete ui;
    delete _scene;
    delete _c;
    //delete [] _shapeList;
}

void MainWindow::updatePositions()
{//Deprecated
    qDebug() << "***void MainWindow::updatePositions() called";
    int x,y;
    int particleCount = _pList->count();
    int shapeCount = _shapeList.count();
    if (particleCount != shapeCount)
    {
        //NB: The lengths of _pList and _shapeList should be the same. Throws exception if not.
        qDebug() << "Error in void MainWindow::updatePositions() "
                 << "Particle count and shape count is not the same";
        exit(-7);
    }

    for (int i = 0; i < particleCount; i++)
    {
        x = static_cast<int>(_pList->at(i)->getVector("Position")->getX());
        y = static_cast<int>(_pList->at(i)->getVector("Position")->getY());
        _shapeList[i]->setPos(x,y);
        //_shapeList[i]->update();  //This did not make any difference
        //_shapeList[i]->setPos(mapToParent(QPoint(x,y)));  //This did not make any difference
    }
    //Is it necesary to repaint the scene here?
    //this->show();
    _scene->update(_scene->sceneRect());
    //sleep_for(milliseconds(1000));
    qDebug() << "***void MainWindow::updatePositions() end";
}

void MainWindow::advance()
{   
    qDebug() << "***void MainWindow::runSumulation(int iterations) called";
    int x,y;
    int particleCount = _pList->count();
    int shapeCount = _shapeList.count();
    if (particleCount != shapeCount)
    {
        //NB: The lengths of _pList and _shapeList should be the same. Throws exception if not.
        qDebug() << "Error in void MainWindow::updatePositions() "
                 << "Particle count and shape count is not the same";
        exit(-7);
    }

    _c->loop(1); //Calculate new positions
//    int iterations = 1;
//    for (int j = 0; j < iterations; j++)
//    {
//        for (int i = 0; i < particleCount; i++)
//        {
//            _c->loop(1);
//            x = static_cast<int>(_pList->at(i)->getVector("Position")->getX());
//            y = static_cast<int>(_pList->at(i)->getVector("Position")->getY());
//            _shapeList[i]->setPos(x,y);
//        }
//    }
    _scene->advance();
    qDebug() << "***void MainWindow::runSumulation(int iterations) end";

}

MyEllips *MainWindow::getPointer(MyEllips *item) const
{
    return item;
}
