// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stdio.h>

// add include.
#include <windows.h> //<-- winbase 等の header を include する場合に必要となる.
#include <winbase.h>
#include <string>

int main()
{
    std::cout << "Start::CreateProcessWithLogonW TestApp...\n";

    /*
    CreateProcessWithLogonW(
    _In_        LPCWSTR lpUsername,
    _In_opt_    LPCWSTR lpDomain,
    _In_        LPCWSTR lpPassword,
    _In_        DWORD dwLogonFlags,
    _In_opt_    LPCWSTR lpApplicationName,
    _Inout_opt_ LPWSTR lpCommandLine,
    _In_        DWORD dwCreationFlags,
    _In_opt_    LPVOID lpEnvironment,
    _In_opt_    LPCWSTR lpCurrentDirectory,
    _In_        LPSTARTUPINFOW lpStartupInfo,
    _Out_       LPPROCESS_INFORMATION lpProcessInformation
      );
    */

    // お客様から SAMPLE.txt を基に変数指定.
    WCHAR lpUsername[] = L"admlocal";
    WCHAR lpDomain[] = {0};
    WCHAR lpPassword[] = L"password";

    DWORD dwLogonFlags = LOGON_WITH_PROFILE;
    LPCWSTR lpApplicationName = NULL;
    WCHAR lpCommandLine[] = L"C:\temp\test.bat";
    DWORD dwCreationFlags = CREATE_DEFAULT_ERROR_MODE | CREATE_NEW_CONSOLE | CREATE_NEW_PROCESS_GROUP;
    LPVOID lpEnvironment = 0;
    LPCWSTR lpCurrentDirectory = NULL;
    STARTUPINFO lpStartupInfo = {0};
    PROCESS_INFORMATION lpProcessInformation = {0};

    lpStartupInfo.cb = sizeof(STARTUPINFO);
    lpStartupInfo.lpTitle = NULL;
    lpStartupInfo.dwX = 250;
    lpStartupInfo.dwY = 270;
    lpStartupInfo.dwXSize = 750;
    lpStartupInfo.dwYSize = 150;
    lpStartupInfo.dwFlags = 6;

    if (CreateProcessWithLogonW(
       lpUsername,
       lpDomain,
       lpPassword,
       dwLogonFlags,
       lpApplicationName,
       lpCommandLine,
       dwCreationFlags,
       lpEnvironment,
       lpCurrentDirectory,
       &lpStartupInfo,
       &lpProcessInformation
    )) {
        std::cout << "in if:: success CreateProcessWithLogonW\n";
    }
    else {
        std::cout << "in else:: faild CreateProcessWithLogonW\n";
    }

    CloseHandle(lpProcessInformation.hProcess);
    CloseHandle(lpProcessInformation.hThread);

    std::cout << "End::CreateProcessWithLogonW TestApp...\n";
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
