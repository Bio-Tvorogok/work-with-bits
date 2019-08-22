#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonT1_clicked();

    void on_lineEditInput_textChanged(const QString &arg1);

    void on_pushButtonT2_clicked();

    void on_pushButtonT3_clicked();

    void on_pushButtonT4_clicked();

private:
    Ui::MainWindow *ui;


    void DisableAllFields(bool);
};

#endif // MAINWINDOW_H
