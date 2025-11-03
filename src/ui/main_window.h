#pragma once
#include <QMainWindow>
#include "ui/main_container.h"

class MainWindow : public QMainWindow {
public:
    MainWindow();
private:
    void closeEvent(QCloseEvent* event) override;
    MainContainer* container;
};