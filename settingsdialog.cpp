#include "settingsdialog.hpp"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QextPortInfoList& ports, AppSettings &settings, QWidget *parent) :
	QDialog(parent), ui(new Ui::SettingsDialog), m_settings(settings)
{
	ui->setupUi(this);

	foreach(QextPortInfo info, ports)
		ui->comPort->addItem(info.friendName);

	ui->comPort->setCurrentIndex(ui->comPort->findText(m_settings.portName));
	ui->baudRate->setCurrentIndex(ui->baudRate->findText(QString::number(m_settings.baudRate)));
	ui->deviceNumber->setCurrentIndex(ui->deviceNumber->findText(QString::number(m_settings.deviceNumber)));
	ui->atnPin->setCurrentIndex(ui->atnPin->findText(QString::number(m_settings.atnPin)));
	ui->dataPin->setCurrentIndex(ui->dataPin->findText(QString::number(m_settings.dataPin)));
	ui->clockPin->setCurrentIndex(ui->clockPin->findText(QString::number(m_settings.clockPin)));
	ui->resetPin->setCurrentIndex(ui->resetPin->findText(QString::number(m_settings.resetPin)));
	ui->imageFilters->setText(m_settings.imageFilters);
	ui->showDirs->setChecked(m_settings.showDirectories);
} // ctor


SettingsDialog::~SettingsDialog()
{
	delete ui;
} // dtor


void SettingsDialog::on_Ok_clicked()
{
	m_settings.deviceNumber = ui->deviceNumber->currentText().toUInt();
	m_settings.baudRate = ui->baudRate->currentText().toUInt();
	m_settings.portName = ui->comPort->currentText();
	m_settings.atnPin = ui->atnPin->currentText().toUInt();
	m_settings.dataPin = ui->dataPin->currentText().toUInt();
	m_settings.clockPin = ui->clockPin->currentText().toUInt();
	m_settings.resetPin = ui->resetPin->currentText().toUInt();
	m_settings.imageFilters = ui->imageFilters->text();
	m_settings.showDirectories = ui->showDirs->isChecked();

	accept();
} // on_Ok_clicked
