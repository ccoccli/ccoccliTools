#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

#include <QWidget>
#include <QLabel>
#include <QScreen>
#include <QHeaderView>
#include <QStringList>
#include <QTableWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QGuiApplication>
#include "config.h"

namespace fs = std::filesystem;

struct FileInfo
{
    std::string path;
    std::size_t size;
    std::size_t lineCount;
};
typedef enum class _code_type_e
{
    CANDCPP,
    ASSEMBLY,
    JAVA,
    PYTHON
} CODE_TYPE;

class codeStatisticsWidget : public QWidget
{
    Q_OBJECT
public:
    codeStatisticsWidget( QWidget *parent = nullptr, CODE_TYPE pType = CODE_TYPE::CANDCPP );
    ~codeStatisticsWidget();

    void traverseAndCollectFileInfo( const fs::path &directory, std::vector<FileInfo> &files );

private:
    CODE_TYPE _type;
    unsigned int _code_statistics_table_current_index;
};
