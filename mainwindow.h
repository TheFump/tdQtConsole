#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QStyledItemDelegate>
#include <QTextDocument>
#include <QPainter>
#include <QTableWidget>
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
#include <QTableWidgetItem>

class Programmation;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void update();
    void afficherCalendar();



private:
    Ui::MainWindow *ui;
    void displayProgrammation(const Programmation& p);


public slots:
    void on_printTache_clicked();
    void on_ajouterTache_pressed();
    void on_MainWindow_quit();
    void on_addProg_clicked();
    void on_CalendarNext_clicked();
    void on_CalendarPrevious_clicked();

};



#endif // MAINWINDOW_H
