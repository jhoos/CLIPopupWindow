#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>
#include <QStyle>
#include <QDesktopWidget>

#include <qtermwidget5/qtermwidget.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    if (app.arguments().length() == 1) {
        return 1;
    }
    QMainWindow *mainWindow = new QMainWindow();

    QTermWidget *console = new QTermWidget(false);

    QFont font = QApplication::font();
#ifdef Q_OS_MACOS
    font.setFamily(QStringLiteral("Menlo"));
#elif defined(Q_WS_QWS)
    font.setFamily(QStringLiteral("fixed"));
#else
    font.setFamily(QStringLiteral("Monospace"));
#endif
    font.setPointSize(12);

    console->setTerminalFont(font);
    console->setColorScheme("Tango");
    QStringList arguments = app.arguments();
    QStringList arguments2;
    for (int i = 2; i < arguments.length(); i++) {
        arguments2 << arguments.at(i);
    }
    console->setShellProgram(arguments.at(1));
    console->setArgs(arguments2);
    console->startShellProgram();
    QObject::connect(console, SIGNAL(finished()), mainWindow, SLOT(close()));

    console->setScrollBarPosition(QTermWidget::ScrollBarRight);

    mainWindow->setCentralWidget(console);
    mainWindow->resize(600, 400);
    mainWindow->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight, Qt::AlignCenter, mainWindow->size(), app.desktop()->availableGeometry()
        )
    );
    mainWindow->setWindowTitle(arguments.at(1));
    mainWindow->show();
    return app.exec();
}

