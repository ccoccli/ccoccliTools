#include "codeStatisticsWidget.hpp"

codeStatisticsWidget::codeStatisticsWidget(QWidget *parent, CODE_TYPE pType) : _type(pType), _code_statistics_table_current_index(0)
{
    QString folderPath = QFileDialog::getExistingDirectory(this, QString::fromStdString(config::menu::tool::codeStatistics::CODESTATISTICS_DIRECTOR_DIALOG_TITLE));
    if (!folderPath.isEmpty())
    {
        std::vector<FileInfo> files;
        traverseAndCollectFileInfo(folderPath.toStdString(), files);

        auto _table = new QTableWidget;

        QStringList tableHead;
        tableHead << QString::fromStdString(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_HEAD_1) << QString::fromStdString(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_HEAD_2) << QString::fromStdString(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_HEAD_3);

        _table->setColumnCount(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_COLUMN_NUM);
        _table->setHorizontalHeaderLabels(tableHead);
        _table->verticalHeader()->setVisible(false);

        _table->setColumnWidth(0, QGuiApplication::primaryScreen()->size().width() / 2 - 200);
        _table->setColumnWidth(1, 90);
        _table->setColumnWidth(2, 90);

        unsigned long totalLineCount = 0, totalSize = 0.f;
        for (const auto &file : files)
        {
            _table->insertRow(_code_statistics_table_current_index);

            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(file.path));
            //item->setTextAlignment(Qt::AlignCenter);
            _table->setItem(_code_statistics_table_current_index, 0, item);

            item = new QTableWidgetItem(QString::number(file.lineCount));
            item->setTextAlignment(Qt::AlignCenter);
            item->setForeground(QColor(Qt::red));
            _table->setItem(_code_statistics_table_current_index, 1, item);

            item = new QTableWidgetItem(QString("%1 KB").arg(QString::number(file.size / 1000.f)));
            item->setTextAlignment(Qt::AlignCenter);
            item->setForeground(QColor(Qt::red));
            _table->setItem(_code_statistics_table_current_index++, 2, item);

            totalLineCount += file.lineCount;
            totalSize += file.size;
        }

        auto title = new QLabel(QString("%1(文件总数 : %2, 总行数 : %3, 总大小 : %4KB)")
                                    .arg(QString::fromStdString(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_TITLE))
                                    .arg(QString::number(_code_statistics_table_current_index + 1))
                                    .arg(QString::number(totalLineCount))
                                    .arg(QString::number(totalSize / 1000.f)));
        title->setFixedHeight(config::menu::tool::codeStatistics::CODESTATISTICS_RESULT_TABLE_HEIGHT);

        auto layout = new QVBoxLayout;

        layout->addWidget(title, 1);
        layout->addWidget(_table, 3);

        this->setLayout(layout);
    }
    else
    {
    }
}
codeStatisticsWidget::~codeStatisticsWidget()
{
}

void codeStatisticsWidget::traverseAndCollectFileInfo(const fs::path &directory, std::vector<FileInfo> &files)
{
    for (const auto &entry : fs::recursive_directory_iterator(directory))
    {
        if (entry.is_regular_file())
        {
            auto path = entry.path();
            if (_type == CODE_TYPE::CANDCPP)
            {
                if ((path.extension() == ".cpp") || (path.extension() == ".hpp") ||
                    (path.extension() == ".cxx") || (path.extension() == ".cc") ||
                    (path.extension() == ".c") || (path.extension() == ".C") ||
                    (path.extension() == ".h") || (path.extension() == ".hxx") || (path.extension() == ".hh"))
                {
                    FileInfo fileInfo;
                    fileInfo.path = path.string();
                    fileInfo.size = fs::file_size(path);

                    std::ifstream file(path);
                    fileInfo.lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

                    files.push_back(fileInfo);
                }
            }
            else if (_type == CODE_TYPE::ASSEMBLY)
            {
                if ((path.extension() == ".asm") || (path.extension() == ".s") || (path.extension() == ".S"))
                {
                    FileInfo fileInfo;
                    fileInfo.path = path.string();
                    fileInfo.size = fs::file_size(path);

                    std::ifstream file(path);
                    fileInfo.lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

                    files.push_back(fileInfo);
                }
            }
            else if (_type == CODE_TYPE::JAVA)
            {
                if ((path.extension() == ".java"))
                {
                    FileInfo fileInfo;
                    fileInfo.path = path.string();
                    fileInfo.size = fs::file_size(path);

                    std::ifstream file(path);
                    fileInfo.lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

                    files.push_back(fileInfo);
                }
            }
            else if (_type == CODE_TYPE::PYTHON)
            {
                if ((path.extension() == ".py"))
                {
                    FileInfo fileInfo;
                    fileInfo.path = path.string();
                    fileInfo.size = fs::file_size(path);

                    std::ifstream file(path);
                    fileInfo.lineCount = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');

                    files.push_back(fileInfo);
                }
            }
        }
    }
}
