#include "mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   a.setStyle("windowsvista");

   QTranslator translator;

   // Substitua pelo caminho real do seu arquivo de tradução
   if(translator.load("./translations/qt_pt_BR.qm")) {
      a.installTranslator(&translator);
      } else {
       qWarning("Failed to load translation file.");
       }


   MainWindow w;

   w.show();
   return(a.exec());
}
