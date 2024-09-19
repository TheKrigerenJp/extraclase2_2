//
// Created by josepa on 18/09/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_hola.h" resolved
#include <cmath>
#include "hola.h"
#include "./ui_hola.h"
#include <iostream>
#include "MeasureTime.h"
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar los botones a sus slots correspondientes
    connect(ui->bubbleSortButton, &QPushButton::clicked, this, &MainWindow::onBubbleSortButtonClicked);
    connect(ui->selectionSortButton, &QPushButton::clicked, this, &MainWindow::onSelectionSortButtonClicked);
    connect(ui->mergeSortButton, &QPushButton::clicked, this, &MainWindow::onMergeSortButtonClicked);
    connect(ui->binaryTreeSearchButton, &QPushButton::clicked, this, &MainWindow::onBinaryTreeSearchButtonClicked);
    connect(ui->allSortedLinkedListSearchButton, &QPushButton::clicked, this, &MainWindow::onAllSortedLinkedListSearchButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Función para limpiar el layout antes de añadir un nuevo gráfico
void MainWindow::clearLayout(QLayout *layout)
{
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();  // Eliminar widgets añadidos previamente
        delete item;  // Eliminar los elementos del layout
    }
}

// Función para crear el gráfico basado en el algoritmo seleccionado
void MainWindow::createChart(const QString &algName) {
    // Limpiar el layout antes de agregar un nuevo gráfico
    clearLayout(ui->verticalLayout);

    string alg = algName.toStdString();

    // Series para los diferentes casos y la complejidad teórica
    QtCharts::QLineSeries *seriesBest = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesAverage = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesWorst = new QtCharts::QLineSeries();
    QtCharts::QLineSeries *seriesTheoretical = new QtCharts::QLineSeries();

    // Nombres de las series
    seriesBest->setName("Best Case");
    seriesAverage->setName("Average Case");
    seriesWorst->setName("Worst Case");
    seriesTheoretical->setName("Theoretical Case");

    // Valores de N
    int N1 = 1000;
    int N2 = 2000;
    int N3 = 3000;
    int N4 = 4000;
    int N5 = 5000;

    // Inicialización de vectores
    vector<int> best_case1(N1), worst_case1(N1), avg_case1(N1);
    vector<int> best_case2(N2), worst_case2(N2), avg_case2(N2);
    vector<int> best_case3(N3), worst_case3(N3), avg_case3(N3);
    vector<int> best_case4(N4), worst_case4(N4), avg_case4(N4);
    vector<int> best_case5(N5), worst_case5(N5), avg_case5(N5);

    // Clase para medir el tiempo de los algoritmos
    MeasureTime medida;

    // Llenado de datos para los diferentes tamaños de N y casos
    auto fillData = [&](int N, vector<int>& best_case, vector<int>& worst_case, vector<int>& avg_case, int i){
        iota(best_case.begin(), best_case.end(), 1);    // Caso mejor
        worst_case = best_case;
        reverse(worst_case.begin(), worst_case.end());  // Caso peor
        generate(avg_case.begin(), avg_case.end(), std::rand); // Caso promedio

        auto wc = medida.measureTime(alg, worst_case, 2);
        auto avg = medida.measureTime(alg, avg_case, 3);
        auto bc = medida.measureTime(alg, best_case, 1);

        seriesWorst->append(N, wc);
        seriesAverage->append(N, avg);
        seriesBest->append(N, bc);
    };

    fillData(N1, best_case1, worst_case1, avg_case1, 1);
    fillData(N2, best_case2, worst_case2, avg_case2, 2);
    fillData(N3, best_case3, worst_case3, avg_case3, 3);
    fillData(N4, best_case4, worst_case4, avg_case4, 4);
    fillData(N5, best_case5, worst_case5, avg_case5, 5);

    // Parámetros de complejidad teórica
    double C = 0.000000005;

    // Diferentes complejidades dependiendo del algoritmo
    if (algName == "BubbleSort") {
        C = 0.000000005;
        seriesTheoretical->append(N1, C*N1*N1);
        seriesTheoretical->append(N2, C*N2*N2);
        seriesTheoretical->append(N3, C*N3*N3);
        seriesTheoretical->append(N4, C*N4*N4);
        seriesTheoretical->append(N5, C*N5*N5);
    } else if (algName == "SelectionSort") {
        C = 0.000000002;
        seriesTheoretical->append(N1, C*N1*N1);
        seriesTheoretical->append(N2, C*N2*N2);
        seriesTheoretical->append(N3, C*N3*N3);
        seriesTheoretical->append(N4, C*N4*N4);
        seriesTheoretical->append(N5, C*N5*N5);
    } else if (algName == "MergeSort") {
        C = 0.00000003;
        seriesTheoretical->append(N1, C*N1*log(N1));
        seriesTheoretical->append(N2, C*N2*log(N2));
        seriesTheoretical->append(N3, C*N3*log(N3));
        seriesTheoretical->append(N4, C*N4*log(N4));
        seriesTheoretical->append(N5, C*N5*log(N5));
    } else if (algName == "AllSortedLinkedListSearch") {
        C = 0.00000001;
        seriesTheoretical->append(N1, C*N1);
        seriesTheoretical->append(N2, C*N2);
        seriesTheoretical->append(N3, C*N3);
        seriesTheoretical->append(N4, C*N4);
        seriesTheoretical->append(N5, C*N5);
    } else if (algName == "BinaryTreeSearch") {
        C = 0.00000005;
        seriesTheoretical->append(N1, C*log(N1));
        seriesTheoretical->append(N2, C*log(N2));
        seriesTheoretical->append(N3, C*log(N3));
        seriesTheoretical->append(N4, C*log(N4));
        seriesTheoretical->append(N5, C*log(N5));
    }

    // Creación del gráfico
    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(seriesBest);
    chart->addSeries(seriesAverage);
    chart->addSeries(seriesWorst);
    chart->addSeries(seriesTheoretical);

    chart->setTitle("Duración de " + algName);
    chart->createDefaultAxes();
    chart->legend()->show();
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Configuración de los ejes
    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis;
    axisX->setTitleText("Tamaño N");
    axisX->setLabelFormat("%d");
    axisX->setTickCount(5);
    chart->addAxis(axisX, Qt::AlignBottom);
    seriesBest->attachAxis(axisX);
    seriesAverage->attachAxis(axisX);
    seriesWorst->attachAxis(axisX);
    seriesTheoretical->attachAxis(axisX);

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis;
    axisY->setTitleText("Tiempo en ms");
    axisY->setLabelFormat("%d");
    axisY->setTickCount(5);
    chart->addAxis(axisY, Qt::AlignLeft);
    seriesBest->attachAxis(axisY);
    seriesAverage->attachAxis(axisY);
    seriesWorst->attachAxis(axisY);
    seriesTheoretical->attachAxis(axisY);

    // Crear el QChartView y añadirlo al layout de la ventana
    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Añadir el chartView al layout
    ui->verticalLayout->addWidget(chartView);
}

// Slots para los botones
void MainWindow::onBubbleSortButtonClicked() {
    createChart("BubbleSort");
}

void MainWindow::onSelectionSortButtonClicked() {
    createChart("SelectionSort");
}

void MainWindow::onMergeSortButtonClicked() {
    createChart("MergeSort");
}

void MainWindow::onBinaryTreeSearchButtonClicked() {
    createChart("BinaryTreeSearch");
}

void MainWindow::onAllSortedLinkedListSearchButtonClicked() {
    createChart("AllSortedLinkedListSearch");
}
