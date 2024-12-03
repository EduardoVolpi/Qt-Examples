#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QThread>
#include <teladois.h>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>
#include <QStandardPaths>


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
   , ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   // Aqui em 'ui->setupUi(this);' é tipo OnCreate fo Form


   //-----------------------------------------------------------
   // Exemplos de Modo de Conexão - SIGNALS AND SLOTS

   // String Notation: Compatível com Qt5
   //connect(ui->btnIfElse, SIGNAL(clicked(bool)), this, SLOT(btnIfElseClicado()));

   // Functor Notation: Regular Slots
   //-----(---origem----,-----signal-----------,-dest,-------slot--------------------
   //connect(ui->btnIfElse, &QPushButton::clicked, this, &MainWindow::btnIfElseClicado);

   // Functor Notation: Lambdas
   // connect(ui->btnIfElse, &QPushButton::clicked, this, [ = ](){
   //    if(ui->lblTestes->text().isEmpty()) {
   //       ui->lblTestes->setText("Testando comando if else...");
   //       } else {
   //       ui->lblTestes->setText("");
   //       }
   // });
   //-----------------------------------------------------------


   // Conexões

   connect(ui->btnIfElse, &QPushButton::clicked, this, &MainWindow::btnIfElseClicado);
   connect(ui->btnForLoop, &QPushButton::clicked, this, &MainWindow::btnForLoop_clicked);
   connect(ui->btnWhileLoop, &QPushButton::clicked, this, &MainWindow::btnWhileLoop_clicked);
   connect(ui->actionAbrirTelaDois, &QAction::triggered, this, &MainWindow::AbrirTelaDois);// ItemMenu
   connect(ui->btnAbrirTelaDois, &QPushButton::clicked, this, &MainWindow::AbrirTelaDois);
   connect(ui->btnDoWhileLoop, &QPushButton::clicked, this, &MainWindow::btnDoWhileLoop_clicked);
   connect(ui->btnSobre, &QPushButton::clicked, this, &MainWindow::btnSobre_clicked);
   connect(ui->btnSobreQt, &QPushButton::clicked, this, &MainWindow::btnSobreQt_clicked);
   connect(ui->btnInfo, &QPushButton::clicked, this, &MainWindow::btnInfo_clicked);
   connect(ui->btnErro, &QPushButton::clicked, this, &MainWindow::btnErro_clicked);
   connect(ui->btnAlerta, &QPushButton::clicked, this, &MainWindow::btnAlerta_clicked);
   connect(ui->btnQuestao, &QPushButton::clicked, this, &MainWindow::SairDaAplicacao);
   connect(ui->actionSair, &QAction::triggered, this, &MainWindow::SairDaAplicacao);
   connect(ui->btnInputTexto, &QPushButton::clicked, this, &MainWindow::GetInputTexto);
   connect(ui->btnInputSenha, &QPushButton::clicked, this, &MainWindow::GetInputSenha);
   connect(ui->btnInputInt, &QPushButton::clicked, this, &MainWindow::GetInputInt);
   connect(ui->btnInputDouble, &QPushButton::clicked, this, &MainWindow::GetInputDouble);
   connect(ui->btnInputItem, &QPushButton::clicked, this, &MainWindow::GetInputItem);
   connect(ui->btnQuestao2, &QPushButton::clicked, this, &MainWindow::SairDaAplicacao2);
   connect(ui->btnInputTexto2, &QPushButton::clicked, this, &MainWindow::GetInputTexto2);
   connect(ui->btnInputSenha2, &QPushButton::clicked, this, &MainWindow::GetInputSenha2);
   connect(ui->btnInputInt2, &QPushButton::clicked, this, &MainWindow::GetInputInt2);
   connect(ui->btnInputDouble2, &QPushButton::clicked, this, &MainWindow::GetInputDouble2);
   connect(ui->btnInputItem2, &QPushButton::clicked, this, &MainWindow::GetInputItem2);
   connect(ui->btnParaTestes, &QPushButton::clicked, this, &MainWindow::metodoParaTestes);
   connect(ui->btnPastasDoSistema, &QPushButton::clicked, this, &MainWindow::PastasDoSistema);
   connect(ui->btnDefinirEstilo, &QPushButton::clicked, this, &MainWindow::DefinirEstiloApp);

   // Para evitar que seja redimensionado pelo grip do statusbar

   this->statusBar()->setSizeGripEnabled(false);
   ui->statusbar->showMessage("Um texto na Barra de Status");
   ui->statusbar->addPermanentWidget(ui->checkBox);


   // Para evitar que seja redimensionado
   // basta setar MaximumSize e MinimumSize para p tamanho do Form. Isto
   // tambem desabilita o botão maximizar


   // ui->lblTestes->setText("");
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::btnIfElseClicado()
{
   if(ui->lblTestes->text() ==
      "std::cout << \"C++, unmatched power, control, and performance.\" << std::endl;") {
      ui->lblTestes->setText("Teste do comando if else... Clique novamente e aguarde 1 segundo!");
      } else {
       EscreveTextoTopoTela();
       }
}

void MainWindow::btnForLoop_clicked()
{
   ui->lblTestes->setText("");

   for(int i = 1; i <= 20000; i++) {
       ui->lblTestes->setText("for loop: " + QString::number(i) + " de 20000");
       qApp->processEvents();   // Para atualizar o texto da Label
       }

   EscreveTextoTopoTela();
}

void MainWindow::btnWhileLoop_clicked()
{
   ui->lblTestes->setText("");

   int i = 1;

   while(i <= 20000) {
         ui->lblTestes->setText("while loop: " + QString::number(i) + " de 20000");
         qApp->processEvents();
         i++;
         }

   EscreveTextoTopoTela();
}

void MainWindow::btnDoWhileLoop_clicked()
{
   ui->lblTestes->setText("");
   int i = 1;

   do{
      ui->lblTestes->setText("while loop: " + QString::number(i) + " de 20000");
      qApp->processEvents();
      i++;
      } while(i <= 20000);

   EscreveTextoTopoTela();
}

void MainWindow::btnSobre_clicked()
{
   QMessageBox::about(this, QApplication::applicationName(), "<h3>Desenvolvido por Eduardo Volpi</h3>"
                      "<a href='https://www.oracaodejesus.com'>Visite nosso site</a>");
}

void MainWindow::btnSobreQt_clicked()
{
   QMessageBox::aboutQt(this, QApplication::applicationName());
}

void MainWindow::btnInfo_clicked()
{
   QMessageBox::information(this, QApplication::applicationName(),
                            "Esta é uma mensagem informativa do App!");
}

void MainWindow::btnErro_clicked()
{
   QMessageBox::critical(this, QApplication::applicationName(), "Esta é uma mensagem de Erro.");
}

void MainWindow::btnAlerta_clicked()
{
   QMessageBox::warning(this, QApplication::applicationName(), "Esta é uma mensagem de Alerta");
}

void MainWindow::SairDaAplicacao()
{
   // Crio uma var do tipo standardbutton que receberá o botão clicado
   QMessageBox::StandardButton botaoClicado;

   // Criei variáveis para os textos em português
   QString mensagem = "Tem certeza que deseja fechar o programa?             ";
   QString botaoSim = "Fechar";
   QString botaoNao = "Cancelar";

   // Crie um objeto QMessageBox
   QMessageBox msgBox(QMessageBox::Question, "Exemplos", mensagem,
                      QMessageBox::Yes | QMessageBox::No, this);

   // Configure os textos dos botões diretamente no objeto msgBox
   msgBox.button(QMessageBox::Yes)->setText(botaoSim);
   msgBox.button(QMessageBox::No)->setText(botaoNao);

   // Exibe a caixa de mensagem e obtém o botão clicado
   botaoClicado = static_cast <QMessageBox::StandardButton>(msgBox.exec());

   if(botaoClicado == QMessageBox::Yes) {
      // close();
      QApplication::quit();
      }
}

void MainWindow::SairDaAplicacao2()
{
   // Este exemplo é com o uso do arquivo de tradução do qt na pasta 'translations'
   // já carregado, que já traduz os textos dos botões do messageBox e inputBox
   // para o portugues.
   QMessageBox::StandardButton botaoClicado =
      QMessageBox::question(this, "Título da App", "Tem certeza que deseja fechar o programa?",
                            QMessageBox::Yes | QMessageBox::Cancel);

   if(botaoClicado == QMessageBox::Yes) {
      QApplication::quit();
      }
}

void MainWindow::AbrirTelaDois()
{
   TelaDois frmTelaDois(this);

   frmTelaDois.exec();
}

void MainWindow::GetInputTexto()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Texto");
   dialog.setLabelText("Digite um texto:");
   // Traduzir os textos dos botões diretamente no QInputDialog
   dialog.setOkButtonText("OK");
   dialog.setCancelButtonText("Cancelar");

   if(dialog.exec() == QDialog::Accepted) {
      QString value = dialog.textValue().trimmed();
      if(!value.isEmpty()) {
         ui->lblTestes->setText(value);
         }
      }
}

void MainWindow::GetInputTexto2()
{
   QString value =
      QInputDialog::getText(this, "Input Texto", "Digite seu Nome:", QLineEdit::Normal);

   value = value.trimmed();
   if(!value.isEmpty()) {
      ui->lblTestes->setText(value);
      }
}

void MainWindow::GetInputSenha()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Senha");
   dialog.setLabelText("Informe a Senha:");
   dialog.setTextEchoMode(QLineEdit::Password);
   // Traduzir os textos dos botões diretamente no QInputDialog
   dialog.setOkButtonText("OK");
   dialog.setCancelButtonText("Cancelar");

   if(dialog.exec() == QDialog::Accepted) {
      QString value = dialog.textValue().trimmed();
      if(!value.isEmpty()) {
         ui->lblTestes->setText("Senha digitada: " + value);
         }
      }
}

void MainWindow::GetInputSenha2()
{
   QString value =
      QInputDialog::getText(this, "Input Senha", "Informe sua Senha:", QLineEdit::Password);

   value = value.trimmed();
   if(!value.isEmpty()) {
      ui->lblTestes->setText("Senha digitada: " + value);
      }
}

void MainWindow::GetInputInt()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Int");
   dialog.setLabelText("Informe sua Idade:");
   dialog.setIntValue(0);  // Valor padrão
   // Traduzir os textos dos botões diretamente no QInputDialog
   dialog.setOkButtonText("OK");
   dialog.setCancelButtonText("Cancelar");

   if(dialog.exec() == QDialog::Accepted) {
      int value = dialog.intValue();
      ui->lblTestes->setText("Número escolhido: " + QString::number(value));
      }
}

void MainWindow::GetInputInt2()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Int");
   dialog.setLabelText("Informe sua Idade:");
   dialog.setIntValue(0);  // Valor padrão

   if(dialog.exec() == QDialog::Accepted) {
      int value = dialog.intValue();
      ui->lblTestes->setText("Número escolhido: " + QString::number(value));
      }
}

void MainWindow::EscreveTextoTopoTela()
{
   QThread::sleep(1);             // Pausa por X segundos - #include <QThread>
   ui->lblTestes->setText(
      "std::cout << \"C++, unmatched power, control, and performance.\" << std::endl;");
}

void MainWindow::GetInputDouble()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Double");
   dialog.setLabelText("Informe seu Peso:");
   dialog.setDoubleValue(0.0);   // Valor padrão
   // Traduzir os textos dos botões diretamente no QInputDialog
   dialog.setOkButtonText("OK");
   dialog.setCancelButtonText("Cancelar");

   if(dialog.exec() == QDialog::Accepted) {
      double value = dialog.doubleValue();
      ui->lblTestes->setText("Peso informado: " + QString::number(value));
      }
}

void MainWindow::GetInputDouble2()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Double");
   dialog.setLabelText("Informe seu Peso:");
   dialog.setDoubleValue(0.0);    // Valor padrão

   if(dialog.exec() == QDialog::Accepted) {
      double value = dialog.doubleValue();
      ui->lblTestes->setText("Peso informado: " + QString::number(value));
      }
}

void MainWindow::GetInputItem()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Items");
   dialog.setLabelText("Qual linguagem voce prefere?:");
   dialog.setComboBoxItems(QStringList() << "C++" << "C#" << "Java" << "Visual Basic" << "Javascript");
   dialog.setOkButtonText("OK");
   dialog.setCancelButtonText("Cancelar");

   if(dialog.exec() == QDialog::Accepted) {
      QString item = dialog.textValue();
      ui->lblTestes->setText("Voce escolheu " + item);
      }
}

void MainWindow::GetInputItem2()
{
   QInputDialog dialog(this);

   dialog.setWindowTitle("Input Items");
   dialog.setLabelText("Qual linguagem voce prefere?:");
   dialog.setComboBoxItems(QStringList() << "C++" << "C#" << "Java" << "Visual Basic" << "Javascript");

   if(dialog.exec() == QDialog::Accepted) {
      QString item = dialog.textValue();
      ui->lblTestes->setText("Voce escolheu " + item);
      }
}

void MainWindow::metodoParaTestes()
{
}

void MainWindow::PastasDoSistema()
{
   QString caminho =
      "<b>Pastas do Sistema:</b><br><br>"
      "<b>Pasta do Usuário do Sistema (Home):</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "<br>" +
      "<b>Área de Trabalho:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "<br>" +
      "<b>Documentos:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "<br>" +
      "<b>Programas do Menu Iniciar:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::ApplicationsLocation) + "<br>" +
      "<b>Pasta de Dados Genéricos:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + "<br>" +
      "<b>Pasta de Config do Programa (Atual):</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + "<br>" +
      "<b>Pasta de Arquivos Temporários (Temp):</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::TempLocation) + "<br>" +
      "<b>Pasta de Dados do Programa (Atual):</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "<br>" +
      "<b>Pasta de Downloads:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "<br>" +
      "<b>Pasta de Compartilhamento Público:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::PublicShareLocation) + "<br>" +
      "<b>Pasta de Videos:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::MoviesLocation) + "<br>" +
      "<b>Pasta de Músicas:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::MusicLocation) + "<br>" +
      "<b>Pasta de Imagens:</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation) + "<br>" +
      "<b>Pasta de Cache do Programa (Atual):</b><br>" +
      QStandardPaths::writableLocation(QStandardPaths::CacheLocation) + "<br>";


   QMessageBox msgBox;

   msgBox.setText(caminho);
   msgBox.exec();
}

void MainWindow::DefinirEstiloApp()
{
   QString estiloDefinido;

   if(ui->rbFusion->isChecked() == true) {
      estiloDefinido = "Fusion";
      } else if(ui->rbPadrao->isChecked() == true) {
           estiloDefinido = "windowsvista";// Define o estilo para o padrão do sistema
           } else {
       estiloDefinido = "Windows";
       }

   // qApp->setStyle("");
   QApplication::setStyle(estiloDefinido);
}
