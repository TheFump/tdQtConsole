#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QStyledItemDelegate>
#include <QTextDocument>
#include <QPainter>
#include<QTableWidget>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QItemDelegate>
#include <QStyle>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QBrush>
#include <QPen>
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include "taches.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    void update();


public slots:
    void on_printTache_clicked();
    void on_ajouterTache_pressed();
    void on_MainWindow_quit();
};



#endif // MAINWINDOW_H
