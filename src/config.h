#pragma once

#include <string>
#include <QString>

namespace config
{
    const std::string WINDOW_TITLE = "超级工具 ";

    const std::string WINDOW_MSGBOX_INFO_TITLE = "提示 ";
    const std::string WINDOW_MSGBOX_WARN_TITLE = "警告 ";
    const std::string WINDOW_MSGBOX_ERROR_TITLE = "错误 ";

    const unsigned int SYTEM_MAX_RANDOM_BYTES_NUM = 40;
    
    namespace database
    {
        const QString SYSTEMINFO_USER_DATABASE = "userInfo.db";
    }
    namespace image
    {
        const QString WINDOW_CURSOR = ":image/cursor.png";
        const QString WINDOW_ICON = ":image/icon.png";
    }
    namespace menu
    {
        const std::string MENU_FILE = "文件 ";
        const std::string MENU_EDIT = "编辑 ";
        const std::string MENU_VIEW = "视图 ";
        const std::string MENU_SETTING = "设置 ";
        const std::string MENU_TOOL = "工具 ";
        const std::string MENU_HELP = "帮助 ";
        const std::string MENU_ABOUT = "关于 ";
        const std::string MENU_USER = "用户 ";
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
            const std::string TOOL_CODE_STATISTICS = "代码统计 ";
            namespace colorPacker
            {
                const int COLOR_PACKER_PACKLIST_COLUMN_NUM = 3;
                const int COLOR_PACKER_PACKLIST_HEIGHT = 20;
                const std::string COLOR_PACKER_TITLE = "当前颜色 ";
                const std::string COLOR_PACKER_PACKLIST_TITLE = "颜色提取记录 ";
                const QString COLOR_PACKER_PACKLIST_HEAD_RGB = "RGB";
                const QString COLOR_PACKER_PACKLIST_HEAD_ARGB = "ARGB";
                const QString COLOR_PACKER_PACKLIST_HEAD_HEX = "HEX";

                const QString DEFAULT_COLOR_HEX = "0xffffff";
                const unsigned int DEFAULT_COLOR_A = 0;
                const unsigned int DEFAULT_COLOR_R = 0;
                const unsigned int DEFAULT_COLOR_G = 0;
                const unsigned int DEFAULT_COLOR_B = 0;

                const QString DEFAULT_COLOR_BLOCK_CLOR = "white";
            }
            namespace codeStatistics
            {
                const std::string CODESTATISTICS_DIRECTOR_DIALOG_TITLE = "请选择文件夹 ";
                const std::string CODESTATISTICS_C_CPP = "C/C++";
                const std::string CODESTATISTICS_JAVA = "Java";
                const std::string CODESTATISTICS_PYTHON = "Python";
                const std::string CODESTATISTICS_ASSEMBLY = "Assembly";

                const std::string CODESTATISTICS_RESULT_TABLE_TITLE = "统计结果 ";

                const std::string CODESTATISTICS_RESULT_TABLE_HEAD_1 = "路径 ";
                const std::string CODESTATISTICS_RESULT_TABLE_HEAD_2 = "行数 ";
                const std::string CODESTATISTICS_RESULT_TABLE_HEAD_3 = "大小 ";

                const unsigned int CODESTATISTICS_RESULT_TABLE_COLUMN_NUM = 3;
                const int CODESTATISTICS_RESULT_TABLE_HEIGHT = 20;
            }
        }
        namespace help
        {

        }
        namespace about
        {

        }
        namespace user
        {
            const std::string USER_LOGIN = "登录 ";
            const std::string USER_SIGNUP = "注册 ";
            const std::string USER_CENTER = "个人中心 ";
            const std::string USER_LOGOUT = "退出登录 ";

            const std::string USER_NOT_LOGIN_1 = "用户未登录，请先登录再操作。 ";
            const std::string USER_NOT_LOGIN_2 = "用户未登录，无需退出登录操作。 ";
            const std::string USER_HAS_LOGINED = "用户已登录，请勿重复操作。 ";
        }
    }
    namespace statusbar
    {
        const QString DEFAULT_BACKGROUND_COLOR = "gray";
    }
}