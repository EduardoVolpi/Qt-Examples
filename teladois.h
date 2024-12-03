#ifndef TELADOIS_H
#define TELADOIS_H

#include <QDialog>

namespace Ui {
class TelaDois;
}

class TelaDois : public QDialog
{
   Q_OBJECT

public:
   explicit TelaDois(QWidget *parent = nullptr);
   ~TelaDois();

private slots:
   void on_pushButton_clicked();

private:
   Ui::TelaDois *ui;
};

#endif // TELADOIS_H
