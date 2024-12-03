#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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

private slots:

   void btnIfElseClicado();
   void btnForLoop_clicked();
   void btnWhileLoop_clicked();
   void AbrirTelaDois();
   void btnDoWhileLoop_clicked();
   void btnSobre_clicked();
   void btnSobreQt_clicked();
   void btnInfo_clicked();
   void btnErro_clicked();
   void btnAlerta_clicked();
   void SairDaAplicacao();
   void GetInputTexto();
   void GetInputSenha();
   void GetInputInt();
   void EscreveTextoTopoTela();
   void GetInputDouble();
   void GetInputItem();
   void SairDaAplicacao2();
   void GetInputTexto2();
   void GetInputSenha2();
   void GetInputInt2();
   void GetInputDouble2();
   void GetInputItem2();
   void metodoParaTestes();
   void PastasDoSistema();
   void DefinirEstiloApp();

private:
   Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
