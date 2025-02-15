/*
 * Copyright (C) 2020-2022 Roy Qu (royqh1979@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <QDesktopWidget>
#include "cpudialog.h"
#include "ui_cpudialog.h"
#include "../HighlighterManager.h"
#include "../mainwindow.h"
#include "../debugger.h"
#include "../settings.h"
#include "../colorscheme.h"
#include "../iconsmanager.h"

CPUDialog::CPUDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CPUDialog)
{
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);
    setWindowFlag(Qt::WindowContextHelpButtonHint,false);
    ui->setupUi(this);
    ui->txtCode->setHighlighter(highlighterManager.getCppHighlighter());
    ui->txtCode->setReadOnly(true);
    ui->txtCode->gutter().setShowLineNumbers(false);
    ui->txtCode->setCaretUseTextColor(true);

    ui->txtCode->codeFolding().indentGuides = false;
    ui->txtCode->codeFolding().fillIndents = false;
    ui->txtCode->setGutterWidth(0);
    ui->txtCode->setUseCodeFolding(false);
    highlighterManager.applyColorScheme(ui->txtCode->highlighter(),
                                        pSettings->editor().colorScheme());
    PColorSchemeItem item = pColorManager->getItem(pSettings->editor().colorScheme(),COLOR_SCHEME_ACTIVE_LINE);
    if (item) {
        ui->txtCode->setActiveLineColor(item->background());
    }
    item = pColorManager->getItem(pSettings->editor().colorScheme(),COLOR_SCHEME_TEXT);
    if (item) {
        ui->txtCode->setForegroundColor(item->foreground());
        ui->txtCode->setBackgroundColor(item->background());
    } else {
        ui->txtCode->setForegroundColor(palette().color(QPalette::Text));
        ui->txtCode->setBackgroundColor(palette().color(QPalette::Base));
    }
    resetEditorFont(screenDPI());
    QItemSelectionModel *m=ui->lstRegister->selectionModel();
    ui->lstRegister->setModel(pMainWindow->debugger()->registerModel());
    delete m;

    ui->rdIntel->setChecked(pSettings->debugger().useIntelStyle());
    ui->chkBlendMode->setChecked(pSettings->debugger().blendMode());
    resize(pSettings->ui().CPUDialogWidth(),pSettings->ui().CPUDialogHeight());

    QList<int> sizes = ui->splitter->sizes();
    int tabWidth = pSettings->ui().CPUDialogSplitterPos();
    int totalSize = sizes[0] + sizes[1];
    sizes[0] = tabWidth;
    sizes[1] = std::max(1,totalSize - sizes[0]);
    ui->splitter->setSizes(sizes);

    onUpdateIcons();
    connect(pIconsManager,&IconsManager::actionIconsUpdated,
            this, &CPUDialog::onUpdateIcons);
}

CPUDialog::~CPUDialog()
{
    delete ui;
}

void CPUDialog::updateInfo()
{
    if (pMainWindow->debugger()->executing()) {
        // Load the registers..
        sendSyntaxCommand();
        pMainWindow->debugger()->sendCommand("-data-list-register-values", "N");
        if (ui->chkBlendMode->isChecked())
            pMainWindow->debugger()->sendCommand("disas", "/s");
        else
            pMainWindow->debugger()->sendCommand("disas", "");
    }
}

void CPUDialog::updateButtonStates(bool enable)
{
    ui->btnStepIntoInstruction->setEnabled(enable);
    ui->btnStepOverInstruction->setEnabled(enable);
}

void CPUDialog::updateDPI(float dpi)
{
    QFont font(pSettings->environment().interfaceFont());
    font.setPixelSize(pointToPixel(pSettings->environment().interfaceFontSize(),dpi));
    font.setStyleStrategy(QFont::PreferAntialias);
    setFont(font);
    for (QWidget* p:findChildren<QWidget*>()) {
        if (p!=ui->txtCode)
            p->setFont(font);
    }
    resetEditorFont(dpi);
}

void CPUDialog::setDisassembly(const QString& file, const QString& funcName,const QStringList& lines)
{
    ui->txtFunctionName->setText(QString("%1:%2").arg(file, funcName));
    int activeLine = -1;
    ui->txtCode->document()->clear();
    for (int i=0;i<lines.size();i++) {
        QString line = lines[i];
        if (line.startsWith("=>")) {
            activeLine = i;
        }
        ui->txtCode->document()->add(line);
    }
    if (activeLine!=-1)
        ui->txtCode->setCaretXYEx(true,QSynedit::BufferCoord{1,activeLine+1});
}

void CPUDialog::resetEditorFont(float dpi)
{
    QFont f=QFont(pSettings->editor().fontName());
    f.setPixelSize(pointToPixel(pSettings->editor().fontSize(),dpi));
    f.setStyleStrategy(QFont::PreferAntialias);
    ui->txtCode->setFont(f);
    QFont f2=QFont(pSettings->editor().nonAsciiFontName());
    f2.setPixelSize(pointToPixel(pSettings->editor().fontSize(),dpi));
    f2.setStyleStrategy(QFont::PreferAntialias);
    ui->txtCode->setFontForNonAscii(f2);
}

void CPUDialog::sendSyntaxCommand()
{
    // Set disassembly flavor
    if (ui->rdIntel->isChecked()) {
        pMainWindow->debugger()->sendCommand("-gdb-set", "disassembly-flavor intel");
    } else {
        pMainWindow->debugger()->sendCommand("-gdb-set", "disassembly-flavor att");
    }
}

void CPUDialog::closeEvent(QCloseEvent *event)
{
    pSettings->ui().setCPUDialogWidth(width());
    pSettings->ui().setCPUDialogHeight(height());

    QList<int> sizes = ui->splitter->sizes();
    pSettings->ui().setCPUDialogSplitterPos(sizes[0]);

    QDialog::closeEvent(event);
    emit closed();
}

void CPUDialog::on_rdIntel_toggled(bool)
{
    updateInfo();
    pSettings->debugger().setUseIntelStyle(ui->rdIntel->isChecked());
    pSettings->debugger().save();
}

void CPUDialog::on_rdATT_toggled(bool)
{
    updateInfo();
    pSettings->debugger().setUseIntelStyle(ui->rdIntel->isChecked());
    pSettings->debugger().save();
}

void CPUDialog::on_chkBlendMode_stateChanged(int)
{
    updateInfo();
    pSettings->debugger().setBlendMode(ui->chkBlendMode->isCheckable());
    pSettings->debugger().save();
}

void CPUDialog::on_btnStepOverInstruction_clicked()
{
    pMainWindow->debugger()->sendCommand("-exec-next-instruction","");
}


void CPUDialog::on_btnStepIntoInstruction_clicked()
{
    pMainWindow->debugger()->sendCommand("-exec-step-instruction","");
}

void CPUDialog::onUpdateIcons()
{
    pIconsManager->setIcon(ui->btnStepIntoInstruction, IconsManager::ACTION_RUN_STEP_INTO_INSTRUCTION);
    pIconsManager->setIcon(ui->btnStepOverInstruction, IconsManager::ACTION_RUN_STEP_OVER_INSTRUCTION);
}

