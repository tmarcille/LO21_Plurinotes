#include "SettingsDialog.h"
#include "ui_SettingsDialog.h"

SettingsDialog::SettingsDialog(QString sF, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog), settingsFile(sF)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::reject);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(folderSelect()));
    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::saveSettings()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    settings.setValue("folder",ui->lineEdit->text());
    qDebug()<<"file saved"<<endl;

}

void SettingsDialog::loadSettings()
{
    QSettings settings(settingsFile, QSettings::IniFormat);
    ui->lineEdit->setText(settings.value("folder", "").toString());
}

void SettingsDialog::accept()
{
    saveSettings();
    done(QDialog::Accepted);
}

void SettingsDialog::folderSelect()
{
    QString dir = QFileDialog::getExistingDirectory();
    ui->lineEdit->setText(dir);
}
