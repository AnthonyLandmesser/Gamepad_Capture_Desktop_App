#pragma once
#include <QMainWindow>

class MainContainer;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
private:
    void closeEvent(QCloseEvent* event) override;
    MainContainer* container;
};