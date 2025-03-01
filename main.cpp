#include <QApplication>
#include "application.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Application application;
    application.show();

    application.setMinimumHeight(600);
    application.setMinimumWidth(800);
    application.setMaximumHeight(768);
    application.setMinimumWidth(1024);

    return app.exec();
}
