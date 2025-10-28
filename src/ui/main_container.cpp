#include "ui/main_container.h"
#include <QPushButton>
#include <QVBoxLayout>

MainContainer::MainContainer() {
    setLayout(new QVBoxLayout);
    static_cast<QVBoxLayout*>(layout())->addWidget(new QPushButton(tr("Launch Gamepad Stream")), 0, Qt::AlignCenter);
}