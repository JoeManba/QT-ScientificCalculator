#ifndef SCIENTIFICCALCULATORDIALOG_H
#define SCIENTIFICCALCULATORDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QEvent>
#include <calculatormanager.h>

class ScientificCalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    ScientificCalculatorDialog(QWidget *parent = 0);
    ~ScientificCalculatorDialog();
private:
    QLabel *resulLabel;//结果显示区
    QLineEdit *inputEdit;//公式编辑区

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void calculatorResult();
};

#endif // SCIENTIFICCALCULATORDIALOG_H
