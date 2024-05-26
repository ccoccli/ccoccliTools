#pragma once

#include <string>
#include <QString>

namespace config
{
    const std::string WINDOW_TITLE = "超级工具 ";

    namespace database
    {
        const QString SYSTEMINFO_DATABASE = "systemInfo.db";
    }
    namespace image
    {
        const QString WINDOW_CURSOR = ":image/cursor.png";
        const QString WINDOW_ICON   = ":image/icon.png";
    }
    namespace menu
    {
        const std::string MENU_FILE    = "文件 ";
        const std::string MENU_EDIT    = "编辑 ";
        const std::string MENU_VIEW    = "视图 ";
        const std::string MENU_SETTING = "设置 ";
        const std::string MENU_TOOL    = "工具 ";
        const std::string MENU_HELP    = "帮助 ";
        const std::string MENU_ABOUT   = "关于 ";

        namespace file
        {
            const std::string FILE_NEW = "新建 ";
            const std::string FILE_OPEN = "打开 ";


        }
        namespace edit
        {

        }
        namespace view
        {
            const std::string VIEW_STATUSBAR = "状态栏 ";

        }
        namespace setting
        {

        }
        namespace tool
        {
            const std::string TOOL_COLOR_PACKER = "取色器 ";
        }
        namespace help
        {

        }
        namespace about
        {

        }
    }
}