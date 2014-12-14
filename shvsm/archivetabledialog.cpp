#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QSqlRelation>
#include "archivetabledialog.h"
#include "ui_archivetabledialog.h"

ArchiveTableDialog::ArchiveTableDialog(QSqlDatabase* pdb,QString ptn,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ArchiveTableDialog)
{
    ui->setupUi(this);
    isDataChanged = false;
    db = pdb;
    tableName = ptn;
    setupForm();
}

ArchiveTableDialog::~ArchiveTableDialog()
{
    delete ui;
    delete model;
}

void ArchiveTableDialog::changeLanguage(void)
{
    ui->retranslateUi(this);
}

void ArchiveTableDialog::setupForm(void)
{
    model = new QSqlRelationalTableModel(this);
    model->setJoinMode(QSqlRelationalTableModel::LeftJoin);
    if (tableName == "team")
    {
        model->setTable("team");
        model->select();
        model->setHeaderData(0, Qt::Horizontal, tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, tr("Team"));
    }
    else if (tableName == "surveyed")
    {
        model->setTable("surveyed");
        model->setRelation(2, QSqlRelation("sex", "id", "name"));
        model->setRelation(3, QSqlRelation("team", "id", "name"));
        model->setRelation(4, QSqlRelation("qualification", "id", "name"));
        model->select();

        model->setHeaderData(0, Qt::Horizontal, tr("Id"));
        model->setHeaderData(1, Qt::Horizontal, tr("Name"));
        model->setHeaderData(2, Qt::Horizontal, tr("Sex"));
        model->setHeaderData(3, Qt::Horizontal, tr("Team"));
        model->setHeaderData(4, Qt::Horizontal, tr("Qualification"));
        model->setHeaderData(5, Qt::Horizontal, tr("DOB"));
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    }
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
//    ui->tableView->horizontalHeader()->resizeSection(1, 170);

    db->transaction();

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setCurrentIndex(ui->tableView->model()->index(0, 0));
    checkButtons();
    connect(ui->tableView->model(), SIGNAL(dataChanged(const QModelIndex&, const QModelIndex&)), this, SLOT(slotOnDataChanged(const QModelIndex&, const QModelIndex&)));
}

void ArchiveTableDialog::showEvent(QShowEvent*)
{
    if (tableName == "team")
        setWindowTitle(tr("Archive of team"));
    else if (tableName == "surveyed")
        setWindowTitle(tr("Archive of surveyed"));
}

void ArchiveTableDialog::checkButtons(void)
{
    ui->tbDel->setEnabled((ui->tableView->model()->rowCount() > 0) ? true : false);
    ui->tbPost->setEnabled(isDataChanged);
    ui->tbCancel->setEnabled(isDataChanged);
}

void ArchiveTableDialog::slotOnDataChanged(const QModelIndex&, const QModelIndex&)
{
    isDataChanged = true;
    checkButtons();
}

void ArchiveTableDialog::slotAddRow(void)
{
    ui->tableView->model()->insertRow(ui->tableView->model()->rowCount());
    isDataChanged = true;
    checkButtons();
}

void ArchiveTableDialog::slotDelRow(void)
{
    int id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    if (QMessageBox::question(this,tr("Query"), tr("Are you sure?"),tr("Yes"), tr("No")))
        return;

    // Каскадное удаление
    cascadeRemove(id);
    ui->tableView->model()->removeRow(ui->tableView->selectionModel()->currentIndex().row());
    isDataChanged = true;
    checkButtons();
}

void ArchiveTableDialog::slotSaveChanges(void)
{
    ui->tableView->setCurrentIndex(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(), 0));


    model->submitAll();
    db->commit();
    model->select();
    isDataChanged = false;
    checkButtons();
}

void ArchiveTableDialog::slotCancelChanges(void)
{
    model->revertAll();
    db->rollback();
    model->select();
    isDataChanged = false;
    checkButtons();
}

void ArchiveTableDialog::cascadeRemove(int id)
{
    QSqlQuery query;

    // Удаление соответствующих обследований
    if (!query.exec(QString("DELETE FROM surveySHVSM WHERE surveyed_id=%1").arg(id)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        return;
    }
    if (!query.exec(QString("DELETE FROM surveySHVSMIntegral WHERE surveyed_id=%1").arg(id)))
    {
        QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
        return;
    }
    if (tableName == "team")
    {
        // Удаление обследуемого
        if (!query.exec(QString("DELETE FROM surveyed WHERE id=%1").arg(id)))
        {
            QMessageBox::critical(this, tr("Error"),tr("Error creating database!"), QMessageBox::Ok);
            return;
        }
    }
}
