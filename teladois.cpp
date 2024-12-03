#include "teladois.h"
#include "ui_teladois.h"

TelaDois::TelaDois(QWidget *parent)
   : QDialog(parent)
   , ui(new Ui::TelaDois)
{
   ui->setupUi(this);
}

TelaDois::~TelaDois()
{
   delete ui;
}

void TelaDois::on_pushButton_clicked()
{
   close();
}
