#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditInput->setValidator(new QIntValidator(this));
    ui->lineEditOutput->setReadOnly(true);

    DisableAllFields(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonT1_clicked()
{
    int32_t num = ui->lineEditInput->text().toInt();
    auto bit_pos = ui->spinBoxT1->text().toInt();

    bool bit = (num >> bit_pos) & 1;

    ui->lineEditOutput->setText(QString::number(bit));
}

void MainWindow::on_pushButtonT2_clicked()
{
    int32_t num = ui->lineEditInput->text().toInt();
    auto bit_pos = ui->spinBoxT2->text().toInt();

    bool bit = (num >> bit_pos) & 1;
    int32_t bit_num = 1;
    bit_num = bit_num << bit_pos;
    if (bit){
        bit_num = ~bit_num;
        num = num & bit_num;
    } else {
        num = num | bit_num;
    }
    ui->lineEditOutput->setText(QString::number(num));
}

void MainWindow::on_pushButtonT3_clicked()
{
    int32_t num = ui->lineEditInput->text().toInt();
    auto bit_pos_1 = ui->spinBoxT3_1->text().toInt();
    auto bit_pos_2 = ui->spinBoxT3_2->text().toInt();

    bool bit_1 = (num >> bit_pos_1) & 1;
    bool bit_2 = (num >> bit_pos_2) & 1;

    if ((bit_pos_1 != bit_pos_2) && (bit_1 != bit_2)) {

        int32_t bit_num_1 = 1;
        int32_t bit_num_2 = 1;

        bit_num_1 = bit_num_1 << bit_pos_1;
        bit_num_2 = bit_num_2 << bit_pos_2;


        if (bit_1){
            bit_num_1 = ~bit_num_1;
            num = num & bit_num_1;
        } else
            num = num | bit_num_1;

        if (bit_2){
            bit_num_2 = ~bit_num_2;
            num = num & bit_num_2;
        } else
            num = num | bit_num_2;
    }

    ui->lineEditOutput->setText(QString::number(num));
}


void MainWindow::on_pushButtonT4_clicked()
{
    int32_t num = ui->lineEditInput->text().toInt();
    auto bit_pos = ui->spinBoxT4->text().toInt();

    int32_t bit_num = 0;
    for (int i = 0; i <= bit_pos; i++) {
        //qDebug() << bit_num;
        bit_num = (bit_num << 1) | 1;
    }
    bit_num = ~bit_num;

    num = bit_num & num;
    ui->lineEditOutput->setText(QString::number(num));
}

void MainWindow::on_lineEditInput_textChanged(const QString &arg1)
{
    if (ui->lineEditInput->text().isEmpty()){
        DisableAllFields(true);
    } else
        DisableAllFields(false);
}

void MainWindow::DisableAllFields(bool disable)
{
    if (disable) {
        ui->pushButtonT1->setEnabled(false);
        ui->pushButtonT2->setEnabled(false);
        ui->pushButtonT3->setEnabled(false);
        ui->pushButtonT4->setEnabled(false);

        ui->spinBoxT1->setEnabled(false);
        ui->spinBoxT2->setEnabled(false);
        ui->spinBoxT3_1->setEnabled(false);
        ui->spinBoxT3_2->setEnabled(false);
        ui->spinBoxT4->setEnabled(false);
    }
    else {
        ui->pushButtonT1->setEnabled(true);
        ui->pushButtonT2->setEnabled(true);
        ui->pushButtonT3->setEnabled(true);
        ui->pushButtonT4->setEnabled(true);

        ui->spinBoxT1->setEnabled(true);
        ui->spinBoxT2->setEnabled(true);
        ui->spinBoxT3_1->setEnabled(true);
        ui->spinBoxT3_2->setEnabled(true);
        ui->spinBoxT4->setEnabled(true);
    }
}

