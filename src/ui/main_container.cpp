#include "ui/main_container.h"
#include <QPushButton>
#include <QVBoxLayout>

MainContainer::MainContainer() {
    QPushButton* button = new QPushButton(tr("Launch Gamepad Stream"));
    QFont buttonFont = button->font();
    buttonFont.setPointSize(buttonFont.pointSize()*4);
    button->setFont(buttonFont);
    
    QVBoxLayout* layout = new QVBoxLayout;
    setLayout(layout);
    layout->addWidget(button, 0, Qt::AlignCenter);
}