//
// Created by josepa on 18/09/24.
#ifndef HOLA_H
#define HOLA_H


#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

#include <QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void clearLayout(QLayout *layout);

    private slots:
        //void on_pushButton_clicked();

        void onBubbleSortButtonClicked();

    void onSelectionSortButtonClicked();

    void onMergeSortButtonClicked();

    void onBinaryTreeSearchButtonClicked();

    void onAllSortedLinkedListSearchButtonClicked();

private:
    Ui::MainWindow *ui;
    void createChart(const QString &algName);
};

#endif //HOLA_H
