// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

#include <Windows.h>
#include <shellapi.h>

int main()
{
    std::cout << "Start QUERY_USER_NOTIFICATION_STATE Checker\n";

    QUERY_USER_NOTIFICATION_STATE pquns;
    SHQueryUserNotificationState(&pquns);

    std::cout << "current state is ";
    std::cout << pquns;
    std::cout << "\n";

    switch (pquns)
    {
    case QUERY_USER_NOTIFICATION_STATE::QUNS_NOT_PRESENT:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_NOT_PRESENT \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_BUSY:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_BUSY \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_RUNNING_D3D_FULL_SCREEN:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_RUNNING_D3D_FULL_SCREEN \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_PRESENTATION_MODE:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_PRESENTATION_MODE \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_ACCEPTS_NOTIFICATIONS:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_ACCEPTS_NOTIFICATIONS \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_QUIET_TIME :
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_QUIET_TIME \n";
        break;
    case QUERY_USER_NOTIFICATION_STATE::QUNS_APP:
        std::cout << "QUERY_USER_NOTIFICATION_STATE::QUNS_APP \n";
        break;
    default:
        std::cout << "Other State : ";
        std::cout << pquns;
        std::cout << "\n";
        break;
    }

    //5 秒待って終了する.
    Sleep(5000);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
